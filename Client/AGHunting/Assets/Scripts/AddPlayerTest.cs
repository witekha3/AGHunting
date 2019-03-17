using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AddPlayerTest : MonoBehaviour
{
    public GameObject player;
    private GameObject playerCopy;
    public int numberOfPlayers=3;
    // Start is called before the first frame update
    void Start()
    {
        for (int i = 0; i < numberOfPlayers; i++)
        {
            playerCopy=Instantiate(player);
            playerCopy.transform.position = new Vector3(0 + i, 15, -13);
        }

    }

    // Update is called once per frame
    void Update()
    {

    }
}
