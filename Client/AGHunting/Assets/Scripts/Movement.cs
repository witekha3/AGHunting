using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField]
    private Rigidbody rb;
    public float speed = 10f;
    public float jumpForce = 8f;
    CapsuleCollider col;

    public LayerMask groundLayers;
    // Start is called before the first frame update


    void Start()
    {
        col = GetComponent<CapsuleCollider>();
        rb = GetComponent<Rigidbody>();
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
        }

        // jumping


        if (IsGrounded() && Input.GetKeyDown(KeyCode.Space))
        {
            rb.AddForce(Vector3.up * jumpForce, ForceMode.Impulse);

        }


        bool IsGrounded()
        {
            return Physics.CheckCapsule(col.bounds.center, new Vector3(col.bounds.center.x, col.bounds.min.y, col.bounds.center.z), col.radius * .9f, groundLayers);
        }
    }
}
