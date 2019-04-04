using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerHealth : MonoBehaviour
{
    public int playerHP;
    public Image healthBar;

    // Start is called before the first frame update
    void Awake()
    {
        playerHP = 100;

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
