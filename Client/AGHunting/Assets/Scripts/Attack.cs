using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack : MonoBehaviour
{
    public Rigidbody player;
    public Rigidbody Enemy;
    public LayerMask layer;
    
    
    // Start is called before the first frame update
    void Start()
    {
        player = GetComponent<Rigidbody>();
      //  Enemy = GetComponent<Rigidbody>();

    }

    // Update is called once per frame
    void Update()
    {
        float distance = Vector3.Distance(player.position, Enemy.position);
        if (distance < 4f){
            if (Input.GetKeyDown(KeyCode.Mouse0))
            {
                Debug.Log("Atacked");
            }
        }
        
        
    }
}
