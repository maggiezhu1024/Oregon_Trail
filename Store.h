// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
using namespace std;

#ifndef STORE_H
#define STORE_H

class Store
{
    private:

        //prices
        double food_price;
        double yoke_price;
        double box_of_bullets_price;
        double wagon_part_price;
        double med_kit_price;
        
        //number of food bought
        int food_bought;
        int yoke_bought;
        int box_of_bullets_bought;
        int wagon_part_bought;
        int med_kit_bought;

        //money
        double balance;
        double spent;

    public:
        Store(); //default
        
        Store(double food_price1, double yoke_price1, double box_of_bullets_price1, double wagon_part_price1, double med_kit_price1, int food_bought1, int yoke_bought1, int box_of_bullets_bought1, int wagon_part_bought1, int med_kit_bought1, double spent1, double balance1); //parameterized

        double getFoodPrice(); //returns price of food
        
        void setFoodPrice(double food_price1); //sets food price to input
        
        double getYokePrice(); //returns price of yoke
        
        void setYokePrice(double yoke_price1); //sets yoke price to input
        
        double getBoxOfBulletsPrice(); //returns price of box of bullets
        
        void setBoxOfBulletsPrice(double box_of_bullets_price1); //sets price of box of bullets to input
        
        double getWagonPartPrice(); //returns wagon price 
        
        void setWagonPartPrice(double wagon_part_price1); //sets wagon price to input
        
        double getMedKitPrice(); //returns med kit price
        
        void setMedKitPrice(double med_kit_price1); //sets med kit price to input

        void priceIncrease(int fort_num); //determines price increase

        int getFoodBought(); //returns food bought

        void setFoodBought(int food_bought1 ); //sets amount of food bought

        int getYokeBought(); //returns yokes bought

        void setYokeBought(int yoke_bought1); //sets amount of yokes bought

        int getBoxOfBulletsBought(); //returns number of bullet boxes bought

        void setBoxOfBulletsBought(int box_of_bullets_bought1); //sets amount of bullet boxes bought

        int getWagonPartBought(); //gets wagons bought

        void setWagonPartBought(int wagon_bought1); //sets wagons bought

        int getMedKitBought(); //gets med kits bought

        void setMedKitBought(int med_kit_bought1); //sets med kits bought

        double getSpent(); //return how much spent

        void setSpent(int food_bought1, int yoke_bought1, int box_of_bullets_bought1, int wagon_bought1, int med_kit_bought1); //calcs how much money was spent

        double getBalance(); //returns balance 

        void setBalance(double balance1); //calculates remaining balance

        void printBill(); //prints out the bill after they purchase items


};

#endif