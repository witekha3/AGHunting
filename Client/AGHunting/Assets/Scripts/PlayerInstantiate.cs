using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerInstantiate : MonoBehaviour
{
    public GameObject myPlayer;
    public string playerNick;
    // Start is called before the first frame update
    void Awake()
    {
        myPlayer.name = SecondPlayMeny.nick;
        myPlayer.tag = "Player";
        myPlayer=Instantiate(myPlayer, new Vector3(0, 18, -13), Quaternion.identity) as GameObject;

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
