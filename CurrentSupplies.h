// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
using namespace std;

#ifndef CURRENTSUPPLIES_H
#define CURRENTSUPPLIES_H

class CurrentSupplies
{
    private:
        int food;
        int oxen;
        int bullets;
        int wagon;
        int med_kit;
        int wagonParts;

    public:
        CurrentSupplies(); //default
       
        CurrentSupplies(int food_1, int oxen_1, int bullets_1, int wagon_1, int med_kit_1, int wagonParts); //parameterized
       
        int getFood(); //returns food inventory
       
        void setFood(int food_1); //sets food inventory

        int getOx(); //returns ox

        void setOx(int oxen_1); //sets new ox
       
        int getBullets(); //returns bullet inventory
       
        void setBullets(int bullets_1); //sets bullets inventory
       
        int getWagon(); //returns wagon inventory
       
        void setWagon(int wagon_1); //sets wagon inventory

        int getWagonParts();

        void setWagonParts(int wagonParts);
       
        int getMedKit(); //returns med kit inventory
       
        void setMedKit(int med_kit_1); //sets med kit inventory

      
        


};

#endif