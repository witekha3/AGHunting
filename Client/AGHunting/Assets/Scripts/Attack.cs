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
    float timer;

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

    private void Start()
    {
        timer = 0;

        timer = timer < 0 ? 0 : timer;
    }

    private void Update()
    {
       IsAttacking();
        timer -= Time.deltaTime;
    }



    public bool IsAttacking()
    {
        if (!enemy || !monsterHP)
        {
            Debug.Log("No Enemy");
            return false;
        }
        else { 

            float distance = Vector3.Distance(player.transform.position, enemy.monster.transform.position);

            if(Input.GetKeyDown(KeyCode.Mouse0))
            {

                if (timer > 0f)
                {
                    return false; ;
                }

                timer = 1.5f;

                if (distance < 4f ) 
                {
                    HP -= 10;
                    healthBar.fillAmount = HP / 100;
                    monsterHP.monsterHP = HP;
                    //Debug.Log((HP / 100));
                    FindObjectOfType<AudioManager>().Play("HitMonster");
                    return true;
                }
                else
                {
                    FindObjectOfType<AudioManager>().Play("CutInAir");
                    return true;
                }
            }
            return false;
        }
    }



}
