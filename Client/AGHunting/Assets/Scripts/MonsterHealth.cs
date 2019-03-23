using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MonsterHealth : MonoBehaviour
{
    public float monsterHP;
    public Image healthBar;


    // Start is called before the first frame update
    void Awake()
    {

        monsterHP = new int();
        monsterHP = 100;
    }

    // Update is called once per frame
    void Update()
    {
    }
}
