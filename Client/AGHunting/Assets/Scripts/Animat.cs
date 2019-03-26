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

    // Start is called before the first frame update
    void Start()
    {
        animator = this.gameObject.GetComponent<Animator>();
        pHP = FindObjectOfType<PlayerHealth>();
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

        if (Input.GetKeyDown(KeyCode.Mouse0))
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
