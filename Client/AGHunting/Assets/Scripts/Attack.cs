using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class Attack : MonoBehaviour
{
    public GameObject player;
    MonsterInstantiate enemy;
    MonsterHealth monsterHP;
    public Image healthBar;
    float HP;
    void Awake()
    {
        player = this.gameObject;

        enemy = FindObjectOfType<MonsterInstantiate>();
        monsterHP = FindObjectOfType<MonsterHealth>();
        if (!enemy)
        {
            Debug.Log("No Enemy");
            return;
        }
        else {
            if (!monsterHP)
            {
                Debug.Log("The is no monster");
            }
            else
            {
                healthBar = monsterHP.healthBar;
                HP = monsterHP.monsterHP;
                healthBar.fillAmount = HP;
                return;
            }
            return;
        }
    }


    private void Update()
    {
       IsAttacking();
    }



    void IsAttacking()
    {
        if (!enemy || !monsterHP)
        {
            Debug.Log("No Enemy");
        }
        else { 

            float distance = Vector3.Distance(player.transform.position, enemy.monster.transform.position);

            if (distance < 4f)
            {
                if (Input.GetKeyDown(KeyCode.Mouse0))
                {
                    HP -= 10;
                    healthBar.fillAmount = HP / 100;
                    monsterHP.monsterHP = HP;
                    //Debug.Log((HP / 100));
                    FindObjectOfType<AudioManager>().Play("HitMonster");
                }
            }
        }
    }



}
