using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterStats : MonoBehaviour
{
    GameObject monster;
    public string monsterName;
    public int monsterHP;
    // Start is called before the first frame update
    void Awake()
    {
        monster = this.gameObject;
        monsterHP = 100;
        monsterName = monster.name;
        monster.tag = "Player";
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
