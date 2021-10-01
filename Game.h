// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
#include "CurrentSupplies.h"
#include "Milestones.h"
#include "Player.h"
#include "Store.h"
#include "Date.h"
using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
    private:
       
        //think about putting these into other classes (date/milestone) so you can actually track

        Player players[5]; //include name and bool dead
        Milestones milestones1[15]; //includes name and locatiom
        Milestones progress1; //tracks the player distance
        CurrentSupplies currentSupplies; //current supplies object
        Store store_1; //store objects
        Date date_1; //date object


    //constructors: initial set up

    public:

        Game(); //default

        //no need for a parameterized constructor

        void gameStart(); //function that starts the game

        void menu(); //prints menu

        void statusUpdate(int days_passed);

        int rest();

        int continueOn();

        void store(bool if_start); //when the player enter the store

        int hunt(); //called when the player chooses to hunt, includes puzzles

        int hunt2(int animal); //this function will continue the hunting process (updating food/bullets) 

        int misfortunes(); 

        int raiders(); //includes puzzles

        bool checkGameEnd(); //this functionchecks whether or not the game ends

        void gameEnd(); //function when the player dies

        void sortMilestones(string filename, Milestones milestones[], int num_of_milestones); //store
        
        void ranking(); //sorting algorithm, ranks how long it took each player
        
        bool puzzles(int puzzle_choice); //holds all of the puzzles

        int ifMilestone(int start, int end); //checks to see if there is a milestone in their journey

        int fromMilestone(int distance); //calculates how far away you are from a milestone

    

};

#endif