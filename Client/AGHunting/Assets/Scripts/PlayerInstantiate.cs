using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerInstantiate : MonoBehaviour
{
    public GameObject player;

    // Start is called before the first frame update
    void Start()
    {
        player = Instantiate(player, new Vector3(0, 15, -13), Quaternion.identity);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
