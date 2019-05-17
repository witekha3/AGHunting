#region include
using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
#endregion


public class UDPconnection : MonoBehaviour
{
    #region NET
    private UdpClient  client;
    private IPEndPoint endpoint;

    public string host;
    public int port;

    short clientChecksum = 0;  // CHECKSUM OF THE MESSAGE (TO SERVER)
    byte clientMethod = 0; // WHAT INFORMATION IS CONTATINED (FOR EXAMPLE 0 IS POSITION OF THE PLAYER) (TO SERVER)
    byte clientId = 0; // ID OF THE PLAYER (if ID==0, then he can not join) (TO SERVER)
    byte[] clientMethodData = new byte[59]; // HERE WILL BE  (TO SERVER)

    short recivedClientChecksum = 0;  // CHECKSUM OF THE MESSAGE (TO CLIENT)
    int recivedClientMethod = 0; // WHAT INFORMATION IS CONTATINED (FOR EXAMPLE 0 IS POSITION OF THE PLAYER) (TO CLIENT)
    byte recivedClientId = 0; // ID OF THE PLAYER (if ID==0, then he can not join) (TO CLIENT)
    byte[] recivedClientMethodData = new byte[59]; // HERE WILL BE  (TO CLIENT)
    #endregion

    public GameObject player;

    private void Start()
    {
        Init();
        SendJoinRequest();
    }

    private void Update()
    {
        PlayerPosition();
        GetPlayersPosition();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ----------------- --------------- INIT   -----------------------------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private void Init()
    {
        host = SecondPlayMeny.host;
        port = SecondPlayMeny.port;
        player = GameObject.FindWithTag("Player");
        client = new UdpClient();
        endpoint = new IPEndPoint(IPAddress.Parse(host), port);
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------------- SENDING INFORMATION TO THE SERVER------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private void SendToServer(int method)
    {
        try
        {
            // WE ARE GIVING CHECKSUM 2 BITES
            byte b1ClientChecksum;
            byte b2ClientChecksum;
            clientMethod = (byte)method;
            FromShort(clientChecksum, out b1ClientChecksum, out b2ClientChecksum);
            // CREATING MESSAGE FOR THE SERVER
            byte[] message = { 0, b1ClientChecksum, b2ClientChecksum, clientId, clientMethod };

            // ADDING TO THE MESSAGE INFORMATION ABOUT METHOD (FOR EXAMPLE POSITION OF THE PLYAER)
            var data = new byte[clientMethodData.Length + message.Length];
            message.CopyTo(data, 0);
            clientMethodData.CopyTo(data, message.Length);
            // SETTING THAT FIRST BITE IS INFOMATION ABOUT MESSAGE LENGHT
            data[0] = (byte)data.Length;
            // SENDING MESSAGE
            client.Send(data, data.Length, endpoint);

        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------------ RECIVING INFO FROM SERVER---------------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private void ReciveFromServer()
    {
        try
        {
           Byte[] returnData = client.Receive(ref endpoint);
            ToShort(out recivedClientChecksum, returnData[1], returnData[2]);
            recivedClientId = returnData[3];
            recivedClientMethod = Convert.ToInt32(returnData[4]);

            string returnData2 = Encoding.ASCII.GetString(returnData);
            Debug.Log(returnData2.ToString());
            // if recived client id == 0 then we can not join
            if (recivedClientId == 0)
            {
                SceneManager.LoadScene("AGHunting");
                Debug.Log("Reject request");

            }
            // The rest of the comming data is method data
            for (int i = 5; i < 60; i++)
            {
                recivedClientMethodData[i] = returnData[i + 5];
            }
            
        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ----------------- --------------- CONVERTING METHODS------------------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Converting from short to bytes
    static void FromShort(short number, out byte byte1, out byte byte2)
    {
        byte2 = (byte)(number >> 8);
        byte1 = (byte)(number & 255);
    }

    //Converting from 2 bytes to short
    static void ToShort(out short number, byte byte1, byte byte2)
    {
        number = BitConverter.ToInt16(new byte[] { byte1, byte2 }, 0);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------------- SENDING INFO TO JOIN TO THE GAME-------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void SendJoinRequest()
    {
        int method = 3;
        foreach (int a in clientMethodData)
        {
            clientMethodData[a] = 0;
        }
        SendToServer(method);
        ReciveFromServer();
        clientId = recivedClientId;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------ GETTING POSITION OF THIS PLAYER---------------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private void PlayerPosition()
    {
        int method = 1;
        Vector3 isMoving = player.GetComponent<Movement>().Velocity;
        if (isMoving != Vector3.zero)
        {
            byte b1ClientPositionX;
            byte b2ClientPositionX;
            byte b1ClientPositionY;
            byte b2ClientPositionY;
            byte b1ClientPositionZ;
            byte b2ClientPositionZ;
            FromShort((short)player.transform.position.x, out b1ClientPositionX, out b2ClientPositionX);
            FromShort((short)player.transform.position.y, out b1ClientPositionY, out b2ClientPositionY);
            FromShort((short)player.transform.position.z, out b1ClientPositionZ, out b2ClientPositionZ);

            clientMethodData = new byte[] { b1ClientPositionX, b2ClientPositionX, b1ClientPositionY, b2ClientPositionY, b1ClientPositionZ, b2ClientPositionZ };
        }
        SendToServer(method);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------------- RECIVING POSITION OF ALL PLAYERS AND CREATING THEM-------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void GetPlayersPosition()
    {
        ReciveFromServer();
        if (recivedClientMethod == 2)
        {
            //first bite from server is a number of the players
            int numberOfPlayers = recivedClientMethodData[0];

            short playerPositionX;
            short playerPositionY;
            short playerPositionZ;

            PlayerCopy[] playerCopy = new PlayerCopy[numberOfPlayers];

            // Comming data: NumberOfPlayers + ID + X+Y+Z + ID + X+Y+Z + ID+X+Y+Z but X, Y, Z have 2 bites so distance is 7 bites that is why:
            for (int i = 0; i < numberOfPlayers; i++)
            {
                ToShort(out playerPositionX, recivedClientMethodData[2 + (7 * i)], recivedClientMethodData[3 + (7 * i)]);
                ToShort(out playerPositionY, recivedClientMethodData[4 + (7 * i)], recivedClientMethodData[5 + (7 * i)]);
                ToShort(out playerPositionZ, recivedClientMethodData[6 + (7 * i)], recivedClientMethodData[7 + (7 * i)]);
                // Creating instantiate of players
                playerCopy[i].player = Instantiate(player);
                playerCopy[i].ID = recivedClientMethodData[1 + (7 * i)];
                playerCopy[i].transform.position = new Vector3(playerPositionX, playerPositionY, playerPositionZ);

            }
        }
       
    }

}
