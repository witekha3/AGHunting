using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Animat : MonoBehaviour
{
    public Animator animator;
    public float RunForward;
    public float RunSide;
    public float Jump;
    PlayerHealth pHP;
    Attack attack;

    // Start is called before the first frame update
    void Start()
    {
        animator = this.gameObject.GetComponent<Animator>();
        pHP = FindObjectOfType<PlayerHealth>();
        attack = FindObjectOfType<Attack>();
    }

    // Update is called once per frame
    void Update()
    {
        RunForward = Input.GetAxis("Vertical");
        animator.SetFloat("RunForward", RunForward);

        RunSide = Input.GetAxis("Horizontal");
        animator.SetFloat("RunSide", RunSide);

        if (Input.GetKeyDown(KeyCode.Space))
        {
            animator.SetBool("Jump", true);
        }
        else
        {
            animator.SetBool("Jump", false);
        }



        if (attack.IsAttacking())
        {
            animator.SetBool("Attack", true);
        }
        else
        {
            animator.SetBool("Attack", false);
        }

        if (pHP.playerHP <= 0)
        {
            animator.SetBool("IsDie", true);
        }
        else
        {
            animator.SetBool("IsDie", false);


        }
    }
}
