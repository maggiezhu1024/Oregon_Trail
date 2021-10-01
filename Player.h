// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    private:
        string name;
        bool dead;

    public:
        Player(); //default constructor
        
        Player(string name_1, bool dead_1); //parameterized constructor

        string getName(); //returns the name

        void setName(string name_1); //sets the name

        bool getDead(); //returns whether or not player has died

        void setDead(bool dead_1); //sets boolean to true or false

};

#endif