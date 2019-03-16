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
        Enemy = GetComponent<Rigidbody>();

    }

    // Update is called once per frame
    void Update()
    {

        Debug.Log(Physics.CheckCapsule(player.position, Enemy.position, layer));  // poprawa w chuj
        
        
    }
}
