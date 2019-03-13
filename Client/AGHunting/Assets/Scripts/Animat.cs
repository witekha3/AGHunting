using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Animat : MonoBehaviour
{
    public Animator animator;
    public float RunForward;
    public float RunSide;
    public float Jump;

    // Start is called before the first frame update
    void Start()
    {
        animator = this.gameObject.GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        RunForward = Input.GetAxis("Vertical");
        animator.SetFloat("RunForward", RunForward);

        RunSide = Input.GetAxis("Horizontal");
        animator.SetFloat("RunSide", RunSide);

        Jump = Input.GetAxis("Jump");
        animator.SetFloat("Jump", Jump);

        if (Input.GetKeyDown(KeyCode.Space))
        {
          //  animator.Play("Jump", 1, 0f);
        }
    }
}
