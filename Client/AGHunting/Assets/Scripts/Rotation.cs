using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotation : MonoBehaviour
{
    [SerializeField]
    private Rigidbody rb;
    public Camera cam;
    public float speed= 3f;
    public float speed_rot = 3f;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
     
            float yRot = Input.GetAxisRaw("Mouse X");
        Vector3 rotate = new Vector3(0, yRot, 0) * speed;
        rb.MoveRotation(rb.rotation * Quaternion.Euler(rotate));
        
        float xRot = Input.GetAxisRaw("Mouse Y");

       
            Vector3 cam_rot = new Vector3(xRot, 0, 0)*speed_rot;

    
    }
 
}
