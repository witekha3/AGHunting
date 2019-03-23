using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterInstantiate : MonoBehaviour
{
    public GameObject monster;
    public string monsterName;



    // Start is called before the first frame update
    void Awake()
    {
        monster = Instantiate(monster, new Vector3(0, 15, -13), Quaternion.identity) as GameObject;
        monsterName = monster.name;
        monster.tag = "Monster";

    }

    // Update is called once per frame
    void Update()
    {
    }
}
