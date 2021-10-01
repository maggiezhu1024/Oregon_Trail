// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

#include <iostream>
#include "Date.h"
using namespace std;

Date :: Date() //default
{
    day = 0;
    month = 0;
    days_traveled=0;
}

Date :: Date(int day1, int month1, int days_traveled1) //parameterized
{
    day = day1;
    month = month1;
    days_traveled=days_traveled1;
}

int Date :: getDaysInMonth(int index) //returns the day ... keep in mind index will be month-1
{
    return daysInMonth[index];
}

void Date :: setDaysInMonth(int daysInMonth1[], int index) //set new day
{
    daysInMonth[index] = daysInMonth1[index];
}

int Date :: getDay() //returns day
{
    return day;
}

void Date :: setDay(int day1) //sets a new day
{
    day = day1;
}

int Date :: getMonth() //returns month
{
    return month;
}

void Date :: setMonth(int month1) //sets a new month
{
    month = month1;
}

int Date :: getDaysTraveled() //returns the days traveled
{
    return days_traveled;
}

void Date :: setDaysTraveled(int days_traveled1) //sets days traveled
{
    days_traveled=days_traveled1;
}


/*
* This function calculates the date and takes into account how many days are in a month
* Parameters: days passed (integer)
* Return: date (string)
*/
string Date :: calcDate(int days_passed) //find the date and returns it as a string
{
    // add days to new days passed
    day = day + days_passed;

    //find the number of days in the month that you are currently in
    int index = month -1;
    int days_month = daysInMonth[month-1];
    
    if(day > days_month) //if the number of days exeeds that days in that month, increment the month
    {
        month++; //incrementing the month
        day = day - days_month;
    }

    string date="";

    date = to_string(month) + "/" + to_string(day) + "/1847";

    return date;

}

