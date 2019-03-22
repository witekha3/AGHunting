using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterInstantiate : MonoBehaviour
{
    public GameObject monster;
    public string monsterName;
    public int monsterHP;

    // Start is called before the first frame update
    void Start()
    {
        monsterHP = 100;
        monsterName = monster.name;
        monster = Instantiate(monster, new Vector3(0, 15, -13), Quaternion.identity) as GameObject;
        monster.tag = "Monster";

    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log(monsterHP);
    }
}
