// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
    private:

    int daysInMonth[12] {31,28,31,30,31,30,31,31,30,31,30,31};//array of the months and their days, value is days, index is month
    
    int day; //day in the date?
    
    int month; //month in the date
    
    int days_traveled; //total days?

    public:
    Date(); //default
    Date(int day1, int month1, int days_traveled1); //parameterized

    int getDaysInMonth(int index); //returns the day ... keep in mind index will be month-1
    void setDaysInMonth(int daysInMonth1[12], int index); //set new day

    int getDay(); //returns day of the date
    void setDay(int day1); //sets a new day of the date

    int getMonth(); //returns month
    void setMonth(int month1); //sets a new month

    int getDaysTraveled(); //returns the days traveled
    void setDaysTraveled(int days_traveled1); //sets days traveled

    string calcDate(int daysPassed); //prints the date

};

#endif