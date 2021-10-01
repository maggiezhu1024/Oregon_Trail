// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
#include "Milestones.h"
#include <fstream>
using namespace std;

Milestones :: Milestones() //default
{
    distance = 0;
    milestone_name = ""; 
}

Milestones :: Milestones(int distance_1, string milestone_name_1) //parameterized
{
    distance = distance_1;
    milestone_name = milestone_name_1; 
}

int Milestones :: getDistance() //returns the distance
{
    return distance;
}

void Milestones :: setDistance(int distance_1) //sets distance
{
    distance = distance_1;
}

string Milestones :: getMilestoneName() //returns name of milestone
{
    return milestone_name;
}

void Milestones :: setMilestoneName(string milestone_name_1) //sets milestone name
{
    milestone_name = milestone_name_1;
}

