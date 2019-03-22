using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack : MonoBehaviour
{
    public GameObject player;
    GameObject[] Enemy;
    GameObject enemy;
    Rotation cam;
    MonsterInstantiate monsterInstantiate;
    int monsterHP;

    void Start()
    {
        player = this.gameObject;
        Enemy = GameObject.FindGameObjectsWithTag("Monster");
        enemy = GameObject.FindGameObjectWithTag("Monster");
        enemy = Enemy[0].GetComponent<MonsterInstantiate>().monster;
        monsterHP = Enemy[0].GetComponent<MonsterInstantiate>().monsterHP;
        //foreach (GameObject enem in Enemy) { enemy = GetComponent<MonsterInstantiate>().monster as GameObject; Debug.Log(enemy.transform.position.ToString()); }

        //monsterHP = GetComponent<MonsterInstantiate>().monsterHP;

    }

    private void Update()
    {
       IsAttacking();
    }

    void IsAttacking()
    {

        float distance = Vector3.Distance(player.transform.position, enemy.transform.position);

        if (distance < 4f)
        {
            if (Input.GetKeyDown(KeyCode.Mouse0))
            {
                monsterHP -= 10;
                Enemy[0].GetComponent<MonsterInstantiate>().monsterHP = monsterHP;
              //  Debug.Log("Atacked : " + monsterHP);
            }
        }
    }
}
