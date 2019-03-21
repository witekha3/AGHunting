using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack : MonoBehaviour
{
    GameObject player;
    GameObject Enemy;
    public bool itIs = false ;
    MonsterStats monster;
    int HP;
    void Start()
    {

        player = this.gameObject;
        Enemy = GameObject.FindGameObjectWithTag("Player");
        monster = monster.GetComponent<MonsterStats>();
    }

    private void Update()
    {
        IsAttacking();
    }

    bool IsAttacking()
    {
        float distance = Vector3.Distance(player.transform.position, Enemy.transform.position);
        // Debug.Log(Enemy.position);
        if (distance < 4f)
        {
            if (Input.GetKeyDown(KeyCode.Mouse0))
            {
                itIs = true;
                HP = monster.monsterHP;
                HP -= 10;
                Debug.Log("Atacked : " + HP);
            }
        }
        return itIs;
    }
}
