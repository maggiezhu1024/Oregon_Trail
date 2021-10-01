// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
using namespace std;

#ifndef MILESTONES_H
#define MILESTONES_H

class Milestones
{
    private:
        int distance;
        string milestone_name; //make these into an array

    public:

        Milestones(); //default

        Milestones(int distance_1, string milestone_name_1); //parameterized

        int getDistance(); //returns the distance

        void setDistance(int distance_1); //sets distance

        string getMilestoneName(); //returns name of milestone

        void setMilestoneName(string milestone_name_1); //sets milestone name

        
};

#endif