// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
#include "Store.h"
using namespace std;

Store :: Store() //default
{
    food_price = 0;
    yoke_price = 0;
    box_of_bullets_price = 0;
    wagon_part_price = 0;
    med_kit_price = 0;
    food_bought = 0;
    yoke_bought = 0;
    box_of_bullets_bought = 0;
    wagon_part_bought = 0;
    med_kit_bought = 0;
    balance = 0; 
    spent = 0;
}
        
Store :: Store(double food_price1, double yoke_price1, double box_of_bullets_price1, double wagon_part_price1, double med_kit_price1, int food_bought1, int yoke_bought1, int box_of_bullets_bought1, int wagon_part_bought1, int med_kit_bought1, double spent1, double balance1) //parameterized
{
    food_price = food_price1;
    yoke_price = yoke_price1;
    box_of_bullets_price = box_of_bullets_price1;
    wagon_part_price = wagon_part_price1;
    med_kit_price = med_kit_price1;
    food_bought = food_bought1;
    yoke_bought = yoke_bought1;
    box_of_bullets_bought = box_of_bullets_bought1;
    wagon_part_bought = wagon_part_bought1;
    med_kit_bought = med_kit_bought1;
    balance = balance1; 
    spent = spent1;
}

double Store :: getFoodPrice() //returns price of food
{
    return food_price;
}
        
void Store :: setFoodPrice(double food_price1) //sets food price to input
{
    food_price = food_price1;
}
        
double Store :: getYokePrice() //returns price of yoke
{
    return yoke_price;
}
        
void Store :: setYokePrice(double yoke_price1) //sets yoke price to input
{
    yoke_price = yoke_price1;
}
        
double Store :: getBoxOfBulletsPrice() //returns price of box of bullets
{
    return box_of_bullets_price;
}
        
void Store :: setBoxOfBulletsPrice(double box_of_bullets_price1) //sets price of box of bullets to input
{
    box_of_bullets_price = box_of_bullets_price1;
}

double Store :: getWagonPartPrice() //returns wagon price 
{
    return wagon_part_price;
}
        
void Store :: setWagonPartPrice(double wagon_part_price1) //sets wagon price to input
{
    wagon_part_price = wagon_part_price1;
}
        
double Store :: getMedKitPrice() //returns med kit price
{
    return med_kit_price;
}
        
void Store :: setMedKitPrice(double med_kit_price1) //sets med kit price to input
{
    med_kit_price = med_kit_price1;
}

int Store :: getFoodBought() //returns food bought
{
    return food_bought;
}

void Store :: setFoodBought(int food_bought1 ) //sets amount of food bought
{
    food_bought = food_bought1;
}

int Store :: getYokeBought() //returns yokes bought
{
    return yoke_bought;
}

void Store :: setYokeBought(int yoke_bought1) //sets amount of yokes bought
{
    yoke_bought = yoke_bought1;
}

int Store :: getBoxOfBulletsBought() //returns number of bullet boxes bought
{
    return box_of_bullets_bought;
}

void Store :: setBoxOfBulletsBought(int box_of_bullets_bought1) //sets amount of bullet boxes bought
{
    box_of_bullets_bought = box_of_bullets_bought1;
}

int Store :: getWagonPartBought() //gets wagons bought
{
    return wagon_part_bought;
}

void Store :: setWagonPartBought(int wagon_part_bought1) //sets wagons bought
{
    wagon_part_bought = wagon_part_bought1;
}

int Store :: getMedKitBought() //gets med kits bought
{
    return med_kit_bought;
}

void Store :: setMedKitBought(int med_kit_bought1) //sets med kits bought
{
    med_kit_bought = med_kit_bought1;
}

double Store :: getSpent() //returns amount spent
{
    return spent;
}

void Store :: setSpent(int food_bought1, int yoke_bought1, int box_of_bullets_bought1, int wagon_bought1, int med_kit_bought1) //calcs how much money was spent
{
    spent = food_bought1*food_price + yoke_bought1*yoke_price + box_of_bullets_bought1*box_of_bullets_price + wagon_bought1*wagon_part_price + med_kit_bought1*med_kit_price;

}

double Store :: getBalance()
{
    return balance;
}

void Store :: setBalance(double balance1) //calculates remaining balance
{
    balance = balance1;
}


/*
* This function prints out the bill.
* Parameters: none
* Return: none
*/
void Store :: printBill() //prints out the bill
{
    cout << "HERE IS YOUR BILL: " << endl;
    cout << "YOKES BOUGHT: " << getYokeBought() << " " << "SPENT: $" << getYokeBought()*getYokePrice() << endl;
    cout << "FOOD BOUGHT: " << getFoodBought() << " " << "SPENT: $" << getFoodBought()*getFoodPrice() << endl;
    cout << "BOXES OF BULLETS BOUGHT: " << getBoxOfBulletsBought() << " " << "SPENT: $" << getBoxOfBulletsBought()*getBoxOfBulletsPrice() << endl;
    cout << "WAGON PARTS BOUGHT: " << getWagonPartBought() << " " << "SPENT: $" << getWagonPartBought()*getWagonPartPrice() << endl;
    cout << "MEDICAL KITS BOUGHT: " << getMedKitBought() << " " << "SPENT: $" << getMedKitBought()*getMedKitPrice() << endl;
    cout << "REMAINING BALANCE: $" << getBalance()<<endl;
    cout << endl;
}


/*
* This function determines the price increase at each fort
* Parameters: fort number (integer)
* Return: none
*/
void Store :: priceIncrease(int fort_num) 
{
    //depending on what fort they are at, there is a different multiplier
    food_price = (1+(.25*fort_num))*food_price;
    setFoodPrice(food_price);
    yoke_price = (1+(.25*fort_num))*yoke_price;
    setYokePrice(yoke_price);
    box_of_bullets_price = (1+(.25*fort_num))*box_of_bullets_price;
    setBoxOfBulletsPrice(box_of_bullets_price);
    wagon_part_price = (1+(.25*fort_num))*wagon_part_price;
    setWagonPartPrice(wagon_part_price);
    med_kit_price = (1+(.25*fort_num))*med_kit_price;
    setMedKitPrice(med_kit_price);

}