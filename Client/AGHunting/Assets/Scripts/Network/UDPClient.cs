using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading;
using System.IO;
using UnityEngine;
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

    short clientChecksum = 0;  // CHECKSUM OF THE MESSAGE
    byte clientMethod = 0; // WHAT INFORMATION IS CONTATINED (FOR EXAMPLE 0 IS POSITION OF THE PLAYER)
    byte clientId = 0; // ID OF THE PLAYER
    byte[] clientMethodData = new byte[59]; // HERE WILL BE 
    #endregion

    private void Awake()
    {
        host = SecondPlayMeny.host;
        port = SecondPlayMeny.port;
    }

    private void Update()
    {
        SendPlayerInfo();
    }

    private void Start()
    {
        endPoint = new IPEndPoint(IPAddress.Parse(host), port);
        receivingUdpClient = new UdpClient();
        player = GameObject.FindWithTag("Player");

    }
    // ----------------- --------------- CONVERTING METHODS--------------------------------------------
    //-----------------------------------------------------------------------------------------------------------
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


    //------------------------ GETTING POSITION OF THE PLYER-------------------------------------------------
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

            clientMethod = 0;
            clientMethodData = new byte[] { b1ClientPositionX, b2ClientPositionX, b1ClientPositionY, b2ClientPositionY, b1ClientPositionZ, b2ClientPositionZ };
        }
    }

    //------------------------------- SENDING INFORMATION ABOUT PLAYER TO THE SERBER-------------------------------------------
    public void SendPlayerInfo()
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


    public void ReciveFromServer()
    {
        try
        {
            receiveBytes = receivingUdpClient.Receive(ref endPoint);

            string returnData = Encoding.ASCII.GetString(receiveBytes);

            Console.WriteLine("This is the message you received " +
                                          returnData.ToString());
            Console.WriteLine("This message was sent from " +
                                        endPoint.Address.ToString() +
                                        " on their port number " +
                                        endPoint.Port.ToString());
        }

        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }

    public void GetPlayersPosition()
    {
        if (sock == null)
        {
            return;
        }
        try
        {
            clientMethod = 1;
            byte b1ClientChecksum;
            byte b2ClientChecksum;
            FromShort(clientChecksum, out b1ClientChecksum, out b2ClientChecksum);

            byte[] message = { 0, b1ClientChecksum, b2ClientChecksum, clientId, clientMethod, 1, 1 };


            message[0] = (byte)message.Length;
            // Write byte array to socketConnection stream.                 
            sock.SendTo(message, endPoint);

            short playerPositionX;
            short playerPositionY;
            short playerPositionZ;

            if (receiveBytes == null)
            {
                return;
            }
            numberOfPlayers = receiveBytes[0];
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
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: " + socketException);
        }
    }
}
