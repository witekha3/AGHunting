using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterMovement : MonoBehaviour
{
    [SerializeField]
    private Rigidbody rb;
    public float speed = 10f;
    public float jumpForce = 8f;
    CapsuleCollider col;

    public LayerMask groundLayers;

    //Animators
    public Animator animat;
    public float RunForward;

    // Start is called before the first frame update


    void Start()
    {
        col = GetComponent<CapsuleCollider>();
        rb = GetComponent<Rigidbody>();
        animat = this.gameObject.GetComponent<Animator>();

    }

    // Update is called once per frame
    void Update()
    {
        //Get Axis where to move
        float MoveX = Input.GetAxisRaw("Horizontal");
        float MoveZ = Input.GetAxisRaw("Vertical");

        Vector3 MoveHorizontal = transform.right * MoveX;
        Vector3 MoveVertical = transform.forward * MoveZ;

        //Create velocity
        Vector3 Velocity = (MoveHorizontal + MoveVertical).normalized * speed;

        //Movement
        if (Velocity != Vector3.zero)
        {
            rb.MovePosition(rb.position + Velocity * Time.deltaTime);
            animat.SetBool("IsRun", true);
            FindObjectOfType<AudioManager>().Play("Kamil");

        }
        else {
            animat.SetBool("IsRun", false);

        }

        // jumping
        if (IsGrounded() && Input.GetKeyDown(KeyCode.Space))
        {
            animat.SetTrigger("Jump");
            rb.AddForce(Vector3.up * jumpForce, ForceMode.Impulse);

        }

        if (Input.GetKey(KeyCode.Mouse0))
        {
            animat.SetBool("Attack_1",true);
        }
        else
        {
            animat.SetBool("Attack_1",false);
        }


        bool IsGrounded()
        {
            return Physics.CheckCapsule(col.bounds.center, new Vector3(col.bounds.center.x, col.bounds.min.y, col.bounds.center.z), col.radius * .9f, groundLayers);
        }
    }
}
