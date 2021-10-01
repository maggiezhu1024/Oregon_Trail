// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
#include "CurrentSupplies.h"
using namespace std;

CurrentSupplies :: CurrentSupplies() //default
{
    int food = 0;
    int oxen = 0;
    int bullets = 0;
    int wagon = 0;
    int med_kit = 0;
    int wagonParts = 0;
}

CurrentSupplies :: CurrentSupplies(int food_1, int oxen_1, int bullets_1, int wagon_1, int med_kit_1, int wagonParts_1) //parameterized
{
    int food = food_1;
    int oxen = oxen_1;
    int bullets = bullets_1;
    int wagon = wagon_1;
    int med_kit = med_kit_1;
    int wagonParts = wagonParts_1;
}

int CurrentSupplies :: getFood() //returns food inventory
{
    return food;
}
       
void CurrentSupplies :: setFood(int food_1) //sets food inventory
{
    food = food_1;
}

int CurrentSupplies :: getOx() //returns ox
{
    return oxen;
}

void CurrentSupplies :: setOx(int oxen_1) //sets new ox
{
    oxen = oxen_1;
}

int CurrentSupplies :: getBullets() //returns bullet inventory
{
    return bullets;
}
       
void CurrentSupplies :: setBullets(int bullets_1) //sets bullets inventory
{
    bullets = bullets_1;
}
       
int CurrentSupplies :: getWagon() //returns wagon inventory
{
    return wagon;
}
       
void CurrentSupplies :: setWagon(int wagon_1) //sets wagon inventory
{
    wagon = wagon_1;
}

int CurrentSupplies :: getWagonParts()
{
    return wagonParts;
}

void CurrentSupplies :: setWagonParts(int wagonParts_1)
{
    wagonParts = wagonParts_1;
}
       
int CurrentSupplies :: getMedKit() //returns med kit inventory
{
    return med_kit;
}
       
void CurrentSupplies :: setMedKit(int med_kit_1) //sets med kit inventory
{
    med_kit = med_kit_1;
}



