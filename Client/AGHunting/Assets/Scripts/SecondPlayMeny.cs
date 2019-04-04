using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class SecondPlayMeny : MonoBehaviour
{
    public InputField portImput;
    public InputField hostImput;
    public InputField nickImput;

    public static string host;
    public static string nick;
    public static int port;

    //OwnTCPClient client;

    private void Awake()
    {
        GetHost();
        GetPort();
        GetNick();
    }

    public void PlayGame()
    {
        SceneManager.LoadScene("AGHunting"); 
    }

    public void GetHost()
    {
        var se = new InputField.SubmitEvent();
        se.AddListener(SubmitHost);
        hostImput.onEndEdit = se;

    }
    private void SubmitHost(string arg0)
    {
        host = arg0;
        Debug.Log(arg0);
    }
    public void GetPort()
    {
        var se = new InputField.SubmitEvent();
        se.AddListener(SubmitPort);
        portImput.onEndEdit = se;
    }
    private void SubmitPort(string arg0)
    {
        port = int.Parse(arg0);
        Debug.Log(arg0);
    }

    public void GetNick()
    {
        var se = new InputField.SubmitEvent();
        se.AddListener(SubmitNick);
        nickImput.onEndEdit = se;
    }
    private void SubmitNick(string arg0)
    {
        nick = arg0;
        Debug.Log(arg0);
    }
}
