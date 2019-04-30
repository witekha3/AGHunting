﻿#region include
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
public class UDPClient : MonoBehaviour
{
    #region NET things	
    Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
    IPEndPoint endPoint;
    UdpClient receivingUdpClient;
    Byte[] receiveBytes;

    public string host;
    public int port;
    #endregion
    #region private Data
    public GameObject player;
    public int numberOfPlayers;

    short clientChecksum = 0;  // CHECKSUM OF THE MESSAGE (TO SERVER)
    byte clientMethod = 0; // WHAT INFORMATION IS CONTATINED (FOR EXAMPLE 0 IS POSITION OF THE PLAYER) (TO SERVER)
    byte clientId = 0; // ID OF THE PLAYER (if ID==0, then he can not join) (TO SERVER)
    byte[] clientMethodData = new byte[59]; // HERE WILL BE  (TO SERVER)

    short recivedClientChecksum = 0;  // CHECKSUM OF THE MESSAGE (TO CLIENT)
    int recivedClientMethod = 0; // WHAT INFORMATION IS CONTATINED (FOR EXAMPLE 0 IS POSITION OF THE PLAYER) (TO CLIENT)
    int recivedClientId = 0; // ID OF THE PLAYER (if ID==0, then he can not join) (TO CLIENT)
    byte[] recivedClientMethodData = new byte[59]; // HERE WILL BE  (TO CLIENT)
    #endregion

    private void Awake()
    {
        host = SecondPlayMeny.host;
        port = SecondPlayMeny.port;
    }

    private void Update()
    {
        SendInfo();
    }

    private void Start()
    {
        endPoint = new IPEndPoint(IPAddress.Parse(host), port);
        receivingUdpClient = new UdpClient();
        player = GameObject.FindWithTag("Player");
        SendJoinRequest();

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
    //-----------------------------------------------------------------------------------------------------------------

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------ GETTING POSITION OF THE PLYER-----------------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private void PlayerPosition()
    {
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

            clientMethod = 1;
            clientMethodData = new byte[] { b1ClientPositionX, b2ClientPositionX, b1ClientPositionY, b2ClientPositionY, b1ClientPositionZ, b2ClientPositionZ };
        }
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------------- SENDING INFORMATION ABOUT PLAYER TO THE SERBER-----------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void SendInfo()
    {
        if (sock == null)
        {
            return;
        }
        try
        {
            // Position of the Player
            PlayerPosition();
            // WE ARE GIVING CHECKSUM 2 BITES
            byte b1ClientChecksum;
            byte b2ClientChecksum;
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
            sock.SendTo(data, endPoint);
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: " + socketException);
        }
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------------ RECIVING INFO FROM SERVER---------------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void ReciveFromServer()
    {
        try
        {
            receiveBytes = receivingUdpClient.Receive(ref endPoint);

            byte[] returnData = receiveBytes;
            #region messagesForClient
            Console.WriteLine("This is the message you received " +
                                            returnData.ToString());
            Console.WriteLine("This message was sent from " +
                                        endPoint.Address.ToString() +
                                        " on their port number " +
                                        endPoint.Port.ToString());
            #endregion
            recivedClientId = returnData[3];
            if (recivedClientId == 0)
            {
                Debug.Log("Reject request");
                SceneManager.LoadScene("AGHunting");
            }
            ToShort(out recivedClientChecksum, returnData[1], returnData[2]);
            recivedClientId = Convert.ToInt32(returnData[4]);
            recivedClientMethod = Convert.ToInt32(returnData[5]);

            for (int i= 6; i<60; i++)
            {
                recivedClientMethodData[i] = returnData[i+6];
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------------- SENDING INFO TO JOIN TO THE SERVER-----------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void SendJoinRequest()
    {
        clientMethod = 3;
        foreach(int a in clientMethodData)
        {
            clientMethodData[a] = 0;
        }
        SendInfo();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //------------------------------- RECIVING POSITION OF THE PLAYERS__-----------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void GetPlayersPosition()
    {

        short playerPositionX;
        short playerPositionY;
        short playerPositionZ;

        numberOfPlayers = Convert.ToInt32(clientMethodData[0]);
        //______________________________FINISHED HERE_________________________
        ToShort(out playerPositionX, receiveBytes[1], receiveBytes[2]);
        ToShort(out playerPositionY, receiveBytes[3], receiveBytes[4]);
        ToShort(out playerPositionZ, receiveBytes[5], receiveBytes[6]);


        // THIS IS ONLY TEST VERSION. STILL WAINTING TILL KACPER WILL TURN ON HIS SERVER XD 
        GameObject[] players = new GameObject[numberOfPlayers];
        for (int i = 0; i < numberOfPlayers; i++)
        {
            players[i] = Instantiate(player);
            Vector3 newPos = new Vector3((float)playerPositionX, (float)playerPositionY, (float)playerPositionZ);
            players[i].transform.position = newPos;
        }
        //Debug.Log(newPos.ToString());
        //  player.transform.position = newPos;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //---------------------------------------- INFO CONTROLLER---------------------------------------------------------//
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void Controller()
    {
        switch (recivedClientMethod)
        {
            case 0: { Debug.Log("ERROR"); break; } 
            case 1: { break; }
            case 2: { break; }
        }
    }
}
