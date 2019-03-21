using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerStats : MonoBehaviour
{
    GameObject player;
    public int playerID;
    public string playerNick;
    public int playerHP;

    // Start is called before the first frame update
    void Awake()
    {
        player = this.gameObject;
        playerID = 69;
        playerHP = 100;
        playerNick = player.name;
        player.tag = "Player";
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
