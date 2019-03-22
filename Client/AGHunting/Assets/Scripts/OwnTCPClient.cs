using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using UnityEngine;

public class OwnTCPClient : MonoBehaviour
{
    public Vector3 position;
   public  GameObject player;

    public GameObject playerCopy;

    #region private members 	
    private TcpClient socketConnection;
    private Thread clientReceiveThread;
    #endregion



    void Start()
    {
        playerCopy = Instantiate(player, new Vector3(0, 15, -13), Quaternion.identity);
        ConnectToTcpServer();
    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
           // SendMessage();
            SendPlayerInfo();
        }
    }

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
    private void ListenForData()
    {
        try
        {
            socketConnection = new TcpClient("0.tcp.ngrok.io", 16520);
            Byte[] bytes = new Byte[64];
            while (true)
            {
                // Get a stream object for reading 				
                using (NetworkStream stream = socketConnection.GetStream())
                {
                    int length;
                    // Read incomming stream into byte arrary. 					
                    while ((length = stream.Read(bytes, 0, bytes.Length)) != 0)
                    {
                        var incommingData = new byte[length];
                        Array.Copy(bytes, 0, incommingData, 0, length);
                        // Convert byte array to string message. 						
                        string serverMessage = Encoding.ASCII.GetString(incommingData);
                        Debug.Log("server message received as: " + serverMessage);
                    }
                }
            }
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: " + socketException);
        }
    }

    /* private void SendMessage()
     {
         if (socketConnection == null)
         {
             return;
         }
         try
         {
             // Get a stream object for writing. 			
             NetworkStream stream = socketConnection.GetStream();
             if (stream.CanWrite)
             {
                 string clientMessage = "This is position of this player";
                 // Convert string message to byte array.                 
                 byte[] clientMessageAsByteArray = Encoding.ASCII.GetBytes(clientMessage);
                 // Write byte array to socketConnection stream.                 
                 stream.Write(clientMessageAsByteArray, 0, clientMessageAsByteArray.Length);
                 Debug.Log("Client sent his message - should be received by server");
             }
         }
         catch (SocketException socketException)
         {
             Debug.Log("Socket exception: " + socketException);
         }

     }*/

    //  string clientMethodData = "";
    //  string clientChecksum = "?";
    //  string clientId = "";
    //  string clientMethod = "";
    int clientLenght = 1000;
    int clientChecksum = 2;
    int clientId = 3;
    int clientMethod = 4;
    int clientMethodData = 0;
    public void PlayerPosition()
    {
        Vector3 isMoving = playerCopy.GetComponent<Movement>().Velocity;
        if (isMoving != Vector3.zero)
        {
            clientMethod = 4;
            clientMethodData = (int)playerCopy.transform.position.x;
        }
        
    }

    void SendPlayerInfo()
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
                byte[] message = { (byte)clientLenght, (byte)clientChecksum ,(byte)clientId, (byte)clientMethod, (byte)clientMethodData };
                // Write byte array to socketConnection stream.                 
                stream.Write(message, 0, message.Length);
                Debug.Log("sended"+ message);
            }
        }
        catch (SocketException socketException)
        {
            Debug.Log("Socket exception: "+socketException);
        }
       
    }

}