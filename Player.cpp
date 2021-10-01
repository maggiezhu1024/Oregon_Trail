// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
#include "Player.h"
using namespace std;

Player :: Player() //default constructor
{
    name = "";
    dead = false;
}
        
Player :: Player(string name_1, bool dead_1) //parameterized constructor
{
    name = name_1;
    dead = dead_1;
}

string Player :: getName() //returns the name
{
    return name;
}

void Player :: setName(string name_1) //sets the name
{
    name = name_1;
}


bool Player :: getDead() //returns whether or not player has died
{
    return dead;
}
        
void Player :: setDead(bool dead_1) //sets boolean to true or false
{
    dead = dead_1;
}


