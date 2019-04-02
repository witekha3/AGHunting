using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.IO;
using UnityEngine;

public class OwnTCPClient : MonoBehaviour
{
    private Vector3 position;
     public  GameObject player;

    private Byte[] bytes;
    private Byte[] incommingData;

    //NET
    public string host;
    public int port;

    #region private members 	
    private TcpClient socketConnection;
    private Thread clientReceiveThread;
    private NetworkStream stream;
    #endregion

    private void Awake()
    {
        host = SecondPlayMeny.host;
        port = SecondPlayMeny.port;
        socketConnection = new TcpClient(host, port);
        stream = socketConnection.GetStream();
    }

    void Start()
    {
        player = GameObject.FindWithTag("Player");
        //player = FindObjectOfType<PlayerInstantiate>().gameObject;

        bytes = new Byte[64];
        ConnectToTcpServer();
    }

    private void Update()
    {
        GetPlayersPosition();
    }

    // CONNECTING TO THE SERVER
    private void ConnectToTcpServer()
    {
        try
        {
            clientReceiveThread = new Thread(new ThreadStart(ListenForData));
            clientReceiveThread.IsBackground = true;
            clientReceiveThread.Start();
        }
        catch (Exception e)
        {
            Debug.Log("On client connect exception " + e);
        }
    }

    /// Runs in background clientReceiveThread; Listens for incomming data. 	

    #region private Data
    short clientChecksum = 222;
    byte clientMethod = 4;
    byte clientId = 3;
    byte[] clientMethodData=new byte[59];
    #endregion


    //______________________SENDING INFORMATION TO THE SERVER_________________________________


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


    // Method for sending player position to the server
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
            clientMethodData = new byte []{ b1ClientPositionX , b2ClientPositionX, b1ClientPositionY , b2ClientPositionY, b1ClientPositionZ, b2ClientPositionZ };
        }
        
    }


    // Sending all infro to the server
    public void SendPlayerInfo()
    {
        if (socketConnection == null)
        {
            return;
        }
        try
        {
            // Position of the Player
            // Get a stream object for writing. 			
            NetworkStream stream = socketConnection.GetStream();
            if (stream.CanWrite)
            {
                PlayerPosition();
                byte b1ClientChecksum;
                byte b2ClientChecksum;
                FromShort(clientChecksum, out b1ClientChecksum, out b2ClientChecksum);
                
                byte[] message = { 0, b1ClientChecksum, b2ClientChecksum, clientId, clientMethod };

                // Adding message to the clientMethodData
                var data = new byte[clientMethodData.Length + message.Length];
                message.CopyTo(data, 0);
                clientMethodData.CopyTo(data, message.Length);

                data[0] = (byte)data.Length;
                    
                // Write byte array to socketConnection stream.                 
                stream.Write(data, 0, data.Length);
                //Debug.Log("sended ");
            }
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: "+socketException);
        }
    }

    //____________________ GETTING INFORMATION FROM SERVER_________________________________________

    private void ListenForData()
    {
        try
        {
            while (true)
            {
                // Get a stream object for reading 				
                using (NetworkStream stream = socketConnection.GetStream())
                {
                    int length;
                    // Read incomming stream into byte arrary. 					
                    while ((length = stream.Read(bytes, 0, bytes.Length)) != 0)
                    {
                        incommingData = new byte[length];
                        Array.Copy(bytes, 0, incommingData, 0, length);
                        // Convert byte array to string message. 						
                        string serverMessage = Encoding.ASCII.GetString(incommingData);
                    }
                }
            }
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: " + socketException);
        }
    }
    

    public void GetPlayersPosition()
    {
        if (socketConnection == null)
        {
            return;
        }
        try
        {
                NetworkStream stream = socketConnection.GetStream();
                if (stream.CanWrite)
                {
                    clientMethod = 1;
                    byte b1ClientChecksum;
                    byte b2ClientChecksum;
                    FromShort(clientChecksum, out b1ClientChecksum, out b2ClientChecksum);

                    byte[] message = { 0, b1ClientChecksum, b2ClientChecksum, clientId, clientMethod, 1, 1 };


                    message[0] = (byte)message.Length;
                    // Write byte array to socketConnection stream.                 
                    stream.Write(message, 0, message.Length);
                    //Debug.Log("sended");


                    short playerPositionX;
                    short playerPositionY;
                    short playerPositionZ;

                    if (incommingData == null)
                    {
                    return;
                    }

                    ToShort(out playerPositionX, incommingData[1], incommingData[2]);
                    ToShort(out playerPositionY, incommingData[3], incommingData[4]);
                    ToShort(out playerPositionZ, incommingData[5], incommingData[6]);
                    
                    //Debug.Log("server message received as: " + serverMessage);

                    Vector3 newPos= new Vector3((float)playerPositionX,(float)playerPositionY,(float)playerPositionZ);
                   Debug.Log(newPos.ToString());

                //  player.transform.position = newPos;
                }
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: " + socketException);
        }
    }

}