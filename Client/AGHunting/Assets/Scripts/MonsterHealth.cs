using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MonsterHealth : MonoBehaviour
{
    public Animator animator;
    public float monsterHP;
    public Image healthBar;


    // Start is called before the first frame update
    void Awake()
    {
        animator = this.gameObject.GetComponent<Animator>();
        monsterHP = new int();
        monsterHP = 100;
    }

    // Update is called once per frame
    void Update()
    {
        if (monsterHP <= 0)
        {
            animator.SetBool("IsDead", true);
            Destroy(this.gameObject, 4);


        }
        else
        {
            animator.SetBool("IsDead", false);

        }
    }
}
