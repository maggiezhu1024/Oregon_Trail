// CS1300 Fall 2020
// Author: Maggie Zhu and Tyler Huynh
// Recitation: 510- Alici Edwards
// Project 3

//g++ -std=c++11 OregonTrail.cpp CurrentSupplies.cpp Game.cpp Date.cpp Milestones.cpp Store.cpp Player.cpp

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include "CurrentSupplies.h"
#include "Milestones.h"
#include "Player.h"
#include "Store.h"
#include "Game.h"
#include "Date.h"
using namespace std;

//split function
int split (string str, char separator, string a[], int size);

/*
* This function is the default constructor. It will be called when a game object is created and the player begins the game.
* In this function, the gameStart function is called.
* Parameters: none
* Return: none
*/
Game :: Game() //default
{
    gameStart();
}


/*
* This function starts the game. It begins by sorts the milestones. It then allows the player to enter in their leader name and companion names.
* The function allows the player to choose a starting date and visit the initial store. The function also sets the inventory to it's appropriate numbers.
* Parameters: none
* Return: none
*/
void Game :: gameStart() //function that starts the game
{
    //sorting the milestones into an array
    sortMilestones("milestones.txt", milestones1, 15);

    //printing the game introduction
    cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE," <<endl;
    cout << "MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF FIVE WILL COVER" <<endl;
    cout << "THE 2040 MILE OREGON TRAIL IN 5-6MONTHS --- IF YOU MAKE IT ALIVE." << endl;

    //enter the leader name
    cout << "PLEASE ENTER YOUR LEADER'S NAME: " << endl;
    string name1;
    getline(cin,name1);

    //entering in the companions name
    cout << "PLEASE ENTER THE NAMES OF FOUR COMPANIONS: " << endl;
    string name2;
    string name3;
    string name4;
    string name5;
    getline(cin,name2);
    getline(cin,name3);
    getline(cin,name4);
    getline(cin,name5);

    //placing the players into an array 
    players[0].setName(name1);
    players[1].setName(name2);
    players[2].setName(name3);
    players[3].setName(name4);
    players[4].setName(name5);
    
    //setting health and dead
    for(int i=0; i<5; i++)
    {
        players[i].setDead(false); //alive
    }

    //setting the starting balance to $1600
    store_1.setBalance(1600);

    //setting inventory  
    currentSupplies.setWagon(1);
    currentSupplies.setWagonParts(0); //wagon parts
    currentSupplies.setFood(0);
    currentSupplies.setBullets(0);
    currentSupplies.setOx(0);
    currentSupplies.setMedKit(0);

    //setting the prices
    store_1.setYokePrice(40);
    store_1.setFoodPrice(.5);
    store_1.setBoxOfBulletsPrice(2);
    store_1.setWagonPartPrice(20);
    store_1.setMedKitPrice(25);

    //allowing the player to chose a starting date
    bool valid = false;
    while(valid == false)
    {
        cout << "CHOOSE YOUR STARTING DATE: " << endl;
        cout << "1. DEFAULT: 03/28/1847 " << endl;
        cout << "2. CHOOSE YOUR OWN! (THE DATE YOU CHOOSE MUST BE BETWEEN 03/01/1847 AND 05/01/1847)" << endl;
        int menu_choice;
        string menu_input;
        int day_choice;
        string day_input;
        int month_choice;
        string month_input;

        getline(cin, menu_input);
        menu_choice = stoi(menu_input);

    
        switch(menu_choice)
        {
            case 1:
            {
                //set the date
                date_1.setDay(28);
                date_1.setMonth(03);
                valid = true;
                cout << "YOU HAVE NOW BEGUN YOUR JOURNEY ON THE OREGON TRAIL. GOOD LUCK!" << endl;
                cout << endl;

                break;

            }

            case 2:
            {
                cout << "PLEASE ENTER A DAY: "<< endl;
                getline(cin, day_input);
                day_choice = stoi(day_input);
                cout << "PLEASE ENTER A MONTH: "<< endl;
                getline(cin, month_input);
                month_choice = stoi(month_input);

                if(day_choice<1 || day_choice>31 || month_choice<3 || month_choice>5)
                {
                    cout << "PLEASE ENTER A DAY AND MONTH IN THE RANGE!" <<endl;
                }
                else if (day_choice>=1 || day_choice <=31 || month_choice>=3 || month_choice>=5)
                {
                    cout << "YOUR DATE HAS BEEN SET!" <<endl;
                    valid = true;
                }        

                //set the date
                date_1.setDay(day_choice);
                date_1.setMonth(month_choice);

                break;
            }

            default:
            {
                cout << "PLEASE CHOOSE A VALID OPTION!" << endl;
                break;
            }
        }
    }

    cout << "YOU HAD SAVED $1600 TO SPEND FOR THE TRIP, AND YOU HAVE A WAGON." <<endl;
    cout << "YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS: " << endl;
    cout << endl;
    store(true); //calling store function
}


/*
* This function prints out the menu and allows the player to choose what they would like to do for the turn.
* After each turn a status update is printed out.
* The function also calls the checkGameEnd function to determine whether or not the game has ended. If it has, the game end function is called.
* Parameters: none
* Return: none
*/
void Game ::  menu() 
{
    

    int menu_choice;
    string menu_input;
    bool choice_invalid = false;
    int days_passed=0; //normal days
    int days_passed2=0; //misfortunes
    int days_passed3=0; //raiders
    int tot_days=0;

    //initial status update, days should be 0;
    statusUpdate(days_passed);

    while(choice_invalid == false) //prevents user error
    {
        //call function that checks end conditions
        bool ifGameEnd = checkGameEnd(); 

        if(ifGameEnd == true) //the game has ended
        {
            gameEnd(); //call the game end to do final things
            break; //break and it ends the function or return
        } 

        //printing out the menu
        cout << "WHAT WOULD YOU LIKE TO DO?" << endl;
        cout << "1. REST" <<endl;
        cout << "2. CONTINUE" << endl;
        cout << "3. HUNT" << endl;
        cout << "4. QUIT" << endl;

        getline(cin,menu_input);
        menu_choice = stoi(menu_input);

        switch(menu_choice)
        {
            case 1: //rest
            {
                days_passed = rest();
                days_passed2 = raiders();
                days_passed3 = misfortunes();
                tot_days = days_passed + days_passed2 + days_passed3;
                statusUpdate(tot_days);
                break;
            }

            case 2: //continue
            {
                days_passed = continueOn();
                days_passed2 = raiders();
                days_passed3 = misfortunes();
                tot_days = days_passed + days_passed2 + days_passed3;
                statusUpdate(tot_days);
                break;
            }

            case 3: //hunt
            {
                days_passed = hunt();
                days_passed2 = raiders();
                days_passed3 = misfortunes();
                tot_days = days_passed + days_passed2 + days_passed3;
                statusUpdate(tot_days);
                break;
            }

            case 4: //quit
            {
                cout << "THANKS FOR PLAYING! SEE YOU LATER! " << endl;
                gameEnd();
                choice_invalid = true; //quits the menu and the game
                break;
            }
        } 
    }
}


/*
* This function prints out the status update.
* Parameters: days passed (integer)
* Return: none
*/
void Game :: statusUpdate(int days_passed)
{
    cout << endl;
    cout << "HERE IS YOUR STATUS UPDATE!" << endl;
    cout << "DATE: " << date_1.calcDate(days_passed) << endl;
    cout << "MILES TRAVELED : " << progress1.getDistance() << endl;
    cout << "DISTANCE UNTIL NEXT MILESTONE: " << fromMilestone(progress1.getDistance()) <<" MILES" << endl;
    cout << "FOOD: " << currentSupplies.getFood() << " LBS" << endl;
    cout << "BULLETS: " << currentSupplies.getBullets() << " BULLETS" << endl;
    cout << "BALANCE: " << store_1.getBalance() << " DOLLARS" << endl;
    cout << endl;
}


/*
* This function is called when the player chooses to rest.
* The days and food are updated.
* Parameters: none
* Return: number of days passed (integer)
*/
int Game :: rest() 
{
    int days_passed = rand()%3+1; //how many days they rest for

    int tot_days = date_1.getDaysTraveled() + days_passed; //cumulative days
    date_1.setDaysTraveled(tot_days);

    int count=0; //number of players that are alive!
    bool alive;

    for(int i=0; i<5; i++)
    {
        if(players[i].getDead() == false) //checking if the player is alive
        {
            count++;
        }
    }

    int food_total = currentSupplies.getFood() - (3*days_passed*count); //updating food
    currentSupplies.setFood(food_total);

    return days_passed;
}


/*
* This function is called when a player chooses to continue.
* The days, food, and distance are updated. The ifMilestone function is called to check if there is a milestone on their journey.
* Parameters: none
* Return: number of days passed (integer)
*/
int Game :: continueOn() 
{
    int days_passed = 14;
    int tot_days = date_1.getDaysTraveled() + days_passed;
    date_1.setDaysTraveled(tot_days);

    int count=0; //number of players that are alive!
    for(int i=0; i<5; i++)
    {
        if(players[i].getDead() == false) //checking if the player is alive
        {
            count++;
        }
    }
    int food_total = currentSupplies.getFood() - (3*days_passed*count);
    currentSupplies.setFood(food_total);

    //checking to see if there is a milestone on the way
    int total_distance = ifMilestone(progress1.getDistance(), progress1.getDistance() + rand()%140+70); 
    progress1.setDistance(total_distance);

    return days_passed;
}


/*
* This function is called when the player visits the store. The player is presented all the options and they can continuously shop until they exit.
* After each purchase, the inventory is updated and the bill is printed.
* Parameters: if_start (boolean)-->if the player is visiting the store for the first time, there are different restrictions
* Return: none
*/
void Game :: store(bool if_start) //when the player enter the store
{
    
    bool menu_flag = false;
    int menu_choice;
    string menu_input;
    int food1=0;
    int yokes1=0;
    int box_bullets1=0;
    int wagon_part1=0;
    int med_kit1=0;

    //each time you visit the store, the items bought should reset to 0
    store_1.setYokeBought(0);
    store_1.setFoodBought(0);
    store_1.setBoxOfBulletsBought(0);
    store_1.setWagonPartBought(0);
    store_1.setMedKitBought(0);

    while(menu_flag == false)
    {
        //printing out the store prompt
        cout << "1. OXEN: YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS." <<endl;
        cout << endl;
        cout << "2. FOOD: THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK." <<endl;
        cout << endl;
        cout << "3. AMMUNITION: YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD." << endl;
        cout << endl;
        cout << "4. MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS." << endl;
        cout << endl;
        cout << "5. EXIT THE STORE" <<endl;

        //user input
        getline(cin, menu_input);
        menu_choice = stoi(menu_input);

        //switch statement
        switch(menu_choice)
        { 
            case 1: //oxen
            {
                string yokes_s;
                int oxen;
                bool satisfactory = false;

                if(if_start == true) //if it is the beginning of the game
                {
                    while(satisfactory == false)
                    {
                        cout << "HOW MANY YOKES OF OXEN WOULD YOU LIKE TO BUY?" << endl;
                        cout << " 1 YOKE = 2 OXEN AND 1 YOKE COSTS $" << store_1.getYokePrice() << endl;
                        cout << "YOU MUST SPEND BETWEEN $100 - $200! THAT MEANS 3 -5 YOKES!" << endl;

                        getline(cin, yokes_s);
                        yokes1 = stoi(yokes_s);

                        if(yokes1>=3 && yokes1<=5)
                        {
                            //set yokes bought
                            store_1.setYokeBought(store_1.getYokeBought() + yokes1);

                            //setting how much they on yokes
                            store_1.setSpent(0, yokes1, 0, 0, 0);

                            //if they exceed their balance
                            if(store_1.getSpent() > store_1.getBalance())
                            {
                                cout << "YOU HAVE EXCEEDED YOUR BALANCE!" << endl;
                            }

                            else
                            {
                                //calculating num of oxen
                                oxen = yokes1*2;

                                //updating inventory
                                currentSupplies.setOx(currentSupplies.getOx() + oxen);
                                
                                //calculating balance, this will just subtract how much you spent on yokes, not in total
                                store_1.setBalance(store_1.getBalance() - store_1.getSpent());

                                //printing out the bill
                                store_1.printBill();

                                satisfactory = true;
                            }
                            
                        }

                        else
                        {
                            cout << "YOU MUST PURCHASE 3-5 YOKES. PLEASE TRY AGAIN." << endl;
                        }
                        
                    }
                }

                else if(if_start == false) //not the start
                {
                    cout << "HOW MANY YOKES OF OXEN WOULD YOU LIKE TO BUY?" << endl;
                    cout << " 1 YOKE = 2 OXEN AND 1 YOKE COSTS $" << store_1.getYokePrice() << endl;

                    getline(cin, yokes_s);
                    yokes1 = stoi(yokes_s);

                    //setting how much they on yokes
                    store_1.setSpent(0, yokes1, 0, 0, 0);

                    //if they exeed their balance
                    if(store_1.getSpent() > store_1.getBalance())
                    {
                        cout << "YOU HAVE EXCEEDED YOUR BALANCE!" << endl;
                    }

                    else
                    {
                        //set yokes bought
                        store_1.setYokeBought(store_1.getYokeBought() + yokes1);

                        //calculating num of oxen
                        oxen = yokes1*2;

                        //updating inventory
                        currentSupplies.setOx(currentSupplies.getOx() + oxen);
                        
                        //calculating balance, this will just subtract how much you spent on yokes, not in total
                        store_1.setBalance(store_1.getBalance() - store_1.getSpent());

                        //printing out the bill
                        store_1.printBill();
                        satisfactory = true;
                    }
                }

                break;
            }

            case 2: //food
            {
                //declared variables
                string food_input;
                bool satisfactory = false;

                //while loop
                while(satisfactory == false)
                {
                    //prompt
                    cout << "HOW MANY POUNDS OF FOOD WOULD YOU LIKE TO PURCHASE TODAY? 1LB = $" << store_1.getFoodPrice() << endl;
                    cout << "KEEP IN MIND THAT YOUR WAGON CAN ONLY HOLD 1000 LBS OF FOOD!" << endl;
                    
                    if(if_start == true)
                    {
                        cout << "IT IS RECOMMENDED THAT YOU PURCHASE AT LEAST 200LBS OF FOOD PER PERSON. " << endl;
                    }

                    //user input
                    getline(cin,food_input);
                    food1 = stoi(food_input);

                    //setting how much they on food
                    store_1.setSpent(food1, 0, 0, 0, 0);

                    //if they exceed their balance
                    if(store_1.getSpent() > store_1.getBalance())
                    {
                        cout << "YOU HAVE EXCEEDED YOUR BALANCE. PLEASE TRY AGAIN." << endl;
                    }

                    //if they have too much food
                    else if((currentSupplies.getFood() + food1) > 1000)
                    {
                        cout << "YOU HAVE TOO MUCH FOOD. YOUR WAGON CAN ONLY CARRY 1000 LBS" << endl;
                    }

                    //all good to go
                    else
                    {
                        //set food bought
                        store_1.setFoodBought(store_1.getFoodBought() + food1);

                        //updating inventory
                        currentSupplies.setFood(currentSupplies.getFood() + food1);
                        
                        //calculating balance, this will just subtract how much you spent on food, not in total
                        store_1.setBalance(store_1.getBalance() - store_1.getSpent());

                        //printing out the bill
                        store_1.printBill();

                        satisfactory = true;
                    }                    

                }

                break;
            }

            case 3: //ammo
            {
                //declared variables
                string box_input;
                int bullets;
                bool satisfactory = false;

                //while loop
                while(satisfactory == false)
                {
                    //prompt
                    cout << "HOW MANY BOXES OF BULLETS WOULD YOU LIKE TO BUY? EACH BOX COSTS $" << store_1.getBoxOfBulletsPrice() <<" AND HAS 20 BULLETS." << endl;

                    //user input
                    getline(cin, box_input);
                    box_bullets1 = stoi(box_input);

                    //setting how much they on bullets
                    store_1.setSpent(0, 0, box_bullets1, 0, 0);

                    //exceed balance
                    if(store_1.getSpent() > store_1.getBalance())
                    {
                        cout << "YOU HAVE EXCEEDED YOUR BALANCE. PLEASE TRY AGAIN." << endl;
                    }

                    //good to go
                    else
                    {
                        //set boxes bought
                        store_1.setBoxOfBulletsBought(store_1.getBoxOfBulletsBought() + box_bullets1);

                        bullets = 20*box_bullets1;

                        //updating inventory
                        currentSupplies.setBullets(currentSupplies.getBullets() + bullets);
                        
                        //calculating balance, this will just subtract how much you spent on bullets, not in total
                        store_1.setBalance(store_1.getBalance() - store_1.getSpent());

                        //printing out the bill
                        store_1.printBill();

                        satisfactory = true;
                    }                
                }
                break;
            }

            case 4: //misc
            {
                //declared variables
                string menu_input;
                int menu;
                string wagon_part_input;
                string medkit_input;
                bool valid = false;
                bool satisfactory = false;

                while (valid == false)
                {
                    //prompt
                    cout << "CHOOSE WHAT YOU WOULD LIKE TO BUY: " << endl;
                    cout << "1. SPARE WAGON PARTS" << endl;
                    cout << "2. MEDICAL KITS " << endl;

                    //user input
                    getline(cin, menu_input);
                    menu = stoi(menu_input);

                    //switch statement
                    switch(menu)
                    {
                        case 1: //wagon parts
                        {
                            while(satisfactory == false)
                            {
                                //prompt
                                cout << "HOW MANY SPARE WAGON PARTS WOULD YOU LIKE TO BUY?" << endl;
                                cout << " 1 WAGON PART = $ " << store_1.getWagonPartPrice() << endl;

                                //user input
                                getline(cin, wagon_part_input);
                                wagon_part1 = stoi(wagon_part_input);

                                //setting how much they on wagon parts
                                store_1.setSpent(0, 0, 0, wagon_part1, 0);

                                //if exceed
                                if(store_1.getSpent() > store_1.getBalance())
                                {
                                    cout << "YOU HAVE EXCEEDED YOUR BALANCE. PLEASE TRY AGAIN." << endl;

                                }

                                //all good to go
                                else
                                {
                                    //set wagon parts bought
                                    store_1.setWagonPartBought(store_1.getWagonPartBought() + wagon_part1);

                                    //updating inventory
                                    currentSupplies.setWagonParts(currentSupplies.getWagonParts() + wagon_part1);
                                    
                                    //calculating balance, this will just subtract how much you spent on wagon parts, not in total
                                    store_1.setBalance(store_1.getBalance() - store_1.getSpent());

                                    //printing out the bill
                                    store_1.printBill();

                                    satisfactory = true;
                                }  
                            }     

                            valid = true;
                            break;
                        }

                        case 2: //med kits
                        {
                            while(satisfactory == false)
                            {
                                //prompt
                                cout << "HOW MANY MEDICAL KITS WOULD YOU LIKE TO BUY?" << endl;
                                cout << " 1 MEDICAL KIT = $" << store_1.getMedKitPrice() << endl;

                                //user input
                                getline(cin, medkit_input);
                                med_kit1 = stoi(medkit_input);

                                //setting how much they on med kit
                                store_1.setSpent(0, 0, 0, 0, med_kit1);

                                //exceeding their balance
                                if(store_1.getSpent() > store_1.getBalance())
                                {
                                    cout << "YOU HAVE EXEEDED YOUR BALANCE. PLEASE TRY AGAIN." << endl;

                                }

                                //good to go
                                else
                                {
                                    //set med kits bought
                                    store_1.setMedKitBought(store_1.getMedKitBought() + med_kit1);
                                    
                                    //updating inventory
                                    currentSupplies.setMedKit(currentSupplies.getMedKit() + med_kit1);
                                    
                                    //calculating balance, this will just subtract how much you spent on wagon parts, not in total
                                    store_1.setBalance(store_1.getBalance() - store_1.getSpent());

                                    //printing out the bill
                                    store_1.printBill();

                                    satisfactory = true;
                                }  
                            }     

                            valid = true;
                            break;
                        }

                        default:
                        {
                            cout << "PLEASE ENTER A VALID CHOICE!" << endl;
                        }
                    }
                }
                break;
            }

            case 5: //exit
            {
                cout << "THANK YOU FOR VISITING! GOOD LUCK ON YOUR JOURNEY!" << endl;
                menu_flag = true;
                break;
            }

            default:
            {
                cout << "INVALID INPUT! PLEASE TRY AGAIN!" << endl;
                break;
            }
        }
    }
}


/*
* This function holds all the puzzles needed in other functions.
* Parameters: puzzle choice (integer)
* Return: correct (boolean) --> whether or not they answered correctly.
*/
bool Game :: puzzles(int puzzle_choice) //holds all of the puzzles
{
    bool correct = false;
   
    switch(puzzle_choice)
    {
        case 0: //guess the number
        {
            string guess;
            int num_guess;
            int answer;
            answer = rand() % 10+1; //random number between 1 and 10

            int i=0; //tracks how many times they guess
           
            while(correct == false && i<3) //allows them a maximum of 3 guesses if they do not guess correctly
            {
                cout << "GUESS A NUMBER BETWEEN 1 AND 10!" << endl;
                getline(cin,guess);
                num_guess = stoi(guess);
                
                if (num_guess == answer)
                {
                    cout << "YOU ANSWERED CORRECTLY!" << endl;
                    correct = true; //breaks out of the while loop
                }
                
                else if(num_guess != answer)
                {
                    if(i != 2)
                    {
                        cout << "WRONG ANSWER. TRY AGAIN. " << endl;
                    }
                    
                    correct = false;
                }

                i++;
            }
            
            if(correct == false)
            {
                cout << "WRONG ANSWER. THE ANSWER WAS " << answer << endl;
                correct = false;
            }
            break;
         }

        case 1: //riddle (age)
        {
            string answer_input;
            int answer;

            //question
            cout << "WHEN I WAS 6, MY SISTER WAS HALF MY AGE." << endl;
            cout << "NOW I AM 70." << endl;
            cout << "HOW OLD IS MY SISTER?" << endl;

            //input
            getline(cin,answer_input);
            answer = stoi(answer_input);

            if(answer == 67)
            {
                cout << "YAY! YOU ANSWERED CORRECTLY!" << endl;
                correct = true;
            }
            else
            {
                cout << "SORRY, YOUR ANSWER WAS INCORRECT!" << endl;
                correct = false;
            }
            
            break;

        }

        case 2: //solve a math problem
        {
            string answer_input;
            int answer;

            //question
            cout << "SOLVE: 8/2(2+2)" << endl;

            //input
            getline(cin,answer_input);
            answer = stoi(answer_input);

            if(answer == 16)
            {
                cout << "YAY! YOU ANSWERED CORRECTLY!" << endl;
                correct = true;
            }

            else
            {
                cout << "SORRY, YOUR ANSWER WAS INCORRECT!" << endl;
                correct = false;
            }
            break;
        }

    }
    return correct;
}


/*
* This is the main hunting function. The probability of each animal being encountered is calculated. Then, the helper hunt function is called.
* Parameters: none
* Return: number of days passed (integer)
*/
int Game :: hunt() 
{
    //use random function to pick an animal
    int days_passed=1;
    bool encounter = false;

    int rabbit;
    rabbit = rand()%100; //random number 0-99
    //probablity to encounter rabbit
    if (rabbit >= 0 && rabbit <= 49) //rabbit
    {
        cout << "YOU HAVE ENCOUNTERED A RABBIT!" << endl;
        days_passed = hunt2(1);
    }

    int fox;
    fox = rand()%100;
    if(fox >= 0 && fox <= 24) //fox
    {
        cout << "You HAVE ENCOUNTERED A FOX!" << endl;
        encounter = true;
        days_passed = hunt2(2);
    }

    int deer;
    deer = rand()%100;
    if(deer >=0 && deer <= 14) //deer
    {
        cout << "YOU HAVE ENCOUNTERED A DEER!" << endl;
        encounter = true;
        days_passed = hunt2(3);
    }

    int bear;
    bear = rand()%100;
    if(bear >=0 && bear <=6) //bear
    {
        cout << "YOU HAVE ENCOUNTERED A BEAR!" << endl;
        encounter = true;
        days_passed = hunt2(4);
    } 

    int moose;
    moose = rand()%100;
    if(moose <=0 && moose <= 4) //moose
    {
        cout << "YOU HAVE ENCOUNTERED A MOOSE!" << endl;
        encounter = true;
        days_passed = hunt2(5);
    }

    if(encounter == false)
    {
        cout << "SORRY YOU DID NOT ENCOUNTER ANY ANIMALS. BETTER LUCK NEXT TIME!" << endl;

    }

    return days_passed;
}


/*
* This is the helper hunting function. Based upon what animal is encountered, a puzzle is called if they want to hunt.
* If they choose to hunt, the inventory will be updated appropriately.
* At the very end, the player can choose how well they would like to eat.
* Parameters: animal (integer) --> what animal is encountered
* Return: number of days passed (integer)
*/
int Game :: hunt2(int animal)
{
    //variables
    bool satisfactory = false;
    string hunt_choice;
    int hunt;
    int days_passed=0;

    while(satisfactory == false)
    {
        cout << "WOULD YOU LIKE TO HUNT?" << endl;
        cout << "1. YES" << endl;
        cout << "2. NO " << endl;

        getline(cin, hunt_choice);
        hunt = stoi(hunt_choice);

        switch(hunt)
        {
            case 1: //yes
            {
                days_passed= 1;

                if (currentSupplies.getBullets() >=10) //able to hunt
                {
                    int puzzle_choice = rand() % 3; //picks a random number 0-2
                    bool correct = false;
                    correct = puzzles(puzzle_choice);

                    if (correct == true) //answered correctly
                    {
                        switch(animal)
                        {
                            case 1: //rabbit
                            {
                                currentSupplies.setFood(currentSupplies.getFood() + 5); //+5lbs
                                currentSupplies.setBullets(currentSupplies.getBullets() - 10); //-10 bullets
                                break;
                            }

                            case 2://fox
                            {
                                currentSupplies.setFood(currentSupplies.getFood() + 10); //+10lbs
                                currentSupplies.setBullets(currentSupplies.getBullets() - 8); //-8 bullets
                                break;
                            }

                            case 3: //deer
                            {
                                currentSupplies.setFood(currentSupplies.getFood() + 60); //+60lbs
                                currentSupplies.setBullets(currentSupplies.getBullets() - 5); //-5 bullets
                                break;
                            }

                            case 4: //bear
                            {
                                currentSupplies.setFood(currentSupplies.getFood() + 200); //+200lbs
                                currentSupplies.setBullets(currentSupplies.getBullets() - 10); //-10 bullets
                                break;
                            }

                            case 5: //moose
                            {
                                currentSupplies.setFood(currentSupplies.getFood() + 500); //+500lbs
                                currentSupplies.setBullets(currentSupplies.getBullets() - 12); //-12 bullets
                                break;
                            }
                        }

                    }

                    else //did not answer correctly
                    {
                        cout << "YOUR HUNT WAS UNSUCCESSFUL. BETTER LUCK NEXT TIME!" << endl;
                    }                  
                }

                else //they have less than 10 bullets
                {
                    cout << "YOUR HUNT WAS UNSUCCESSFUL. BETTER LUCK NEXT TIME! " << endl;
                }
                
                //figuring out how much they would like to eat!
                bool valid = false;
                while(valid == false)
                {
                    //menu
                    cout << endl;
                    cout << "HOW WELL WOULD YOU LIKE TO EAT TODAY? " << endl;
                    cout << "1. POORLY : 2LBS PER PERSON" << endl;
                    cout << "2. MODERATELY: 3LBS PER PERSON" << endl;
                    cout << "3. WELL: 5LBS PER PERSON" << endl;

                    //user input
                    string eat_input;
                    int eat;
                    getline(cin, eat_input);
                    eat = stoi(eat_input);

                    //switch
                    switch(eat)
                    {
                        case 1: //poor
                        {
                            int count=0; //number of players that are alive!
                            bool alive;

                            for(int i=0; i<5; i++)
                            {
                                if(players[i].getDead() == false) //checking if the player is alive
                                {
                                    count++;
                                }
                            }

                            int food_total = currentSupplies.getFood() - (2*count); //updating food
                            currentSupplies.setFood(food_total);

                            valid = true;
                            break;
                        }

                        case 2: //moderate
                        {
                            int count=0; //number of players that are alive!
                            bool alive;

                            for(int i=0; i<5; i++)
                            {
                                if(players[i].getDead() == false) //checking if the player is alive
                                {
                                    count++;
                                }
                            }

                            int food_total = currentSupplies.getFood() - (3*count); //updating food
                            currentSupplies.setFood(food_total);

                            valid = true;
                            break;
                        }

                        case 3: //well
                        {
                            int count=0; //number of players that are alive!
                            bool alive;

                            for(int i=0; i<5; i++)
                            {
                                if(players[i].getDead() == false) //checking if the player is alive
                                {
                                    count++;
                                }
                            }

                            int food_total = currentSupplies.getFood() - (5*count); //updating food
                            currentSupplies.setFood(food_total);

                            valid = true;
                            break;
                        }

                        default:
                        {
                            cout << "PLEASE ENTER A VALID OPTION." << endl;
                        }
                    }

                    //if they have more than 1000lbs
                    if(currentSupplies.getFood() > 1000)
                    {
                        cout << "YOU HAVE OVER 1000 LBS OF FOOD! HOWEVER, YOUR WAGON CANNOT CARRY THAT MUCH SO YOU WILL HAVE TO LEAVE SOME BEHIND!" << endl;
                        currentSupplies.setFood(1000);
                    }
                }

                satisfactory = true;
                break;
            }

            case 2: //no hunting
            {
                days_passed = 1;
                satisfactory = true;
                break;
            }

            default:
            {
                cout << "PLEASE CHOOSE A VALID CHOICE!" << endl;
                break;
            }
        }
    }
    return days_passed;
}


/*
* This function uses the random function to determine whether or not a misfortune has occurred and what misfortune occurs.
* Based upon each misfortune, inventory is updated appropriately.
* Parameters: none
* Return: number of days passed (integer)
*/
int Game :: misfortunes() 
{
    int days_passed=0; //if there is a misfortune, time must be accounted for

    int if_misfortune = rand()%99; //chooses rand number 0-100
    
    if(if_misfortune>=0 && if_misfortune<=39) //40% chance of misfortune
    {

        int what_misfortune = rand()%3; //chooses random number 0-2

        switch(what_misfortune)
        {
            case 0: //sick
            {
                int num = rand()%5; //random number 0-4
            
                cout << players[num].getName() << " HAS DYSENTERY!" << endl;

                if(currentSupplies.getMedKit() > 0) //if they have a medical kit
                {
                    int prob = rand()%100; //chooses 0-99

                    if(prob >=0 && prob<=49) //survived
                    {
                        cout << "CONGRATS! " << players[num].getName() << " HAS SURVIVED!" <<endl; 
                        cout << endl;
                    }

                    else
                    {
                        cout << "OH NO!" << players[num].getName() << " HAS DIED OF DYSENTERY!" << endl;
                        cout << endl;

                        players[num].setDead(true);
                    }
                    
                }

                else //no medical kit
                {
                    string choice_s;
                    int choice;
                    bool valid = false;

                    while(valid == false) //will break out when they have entered a valid choice
                    {
                        cout << "YOU HAVE NO MED KITS! WHAT WOULD YOU LIKE TO DO?" << endl;
                        cout << "1. REST" << endl;
                        cout << "2. PRESS ON" << endl;

                        getline(cin, choice_s);
                        choice = stoi(choice_s);

                        int if_dead = rand()%100; //0-99

                        switch(choice)
                        {
                            case 1: //resting 
                            {
                                days_passed = 2; //rest for 2 days

                                //need to update the days and food eaten
                                if(if_dead>=0 && if_dead<=29) //dead
                                {
                                    cout << players[num].getName() << " HAS DIED OF DYSENTERY! " << endl;
                                    cout << endl;
                                    players[num].setDead(true); //setting them dead
                                   
                                }
                                else
                                {
                                    cout << players[num].getName() << " HAS SURVIVED! " << endl;
                                    cout << endl;
                                }
                                valid = true;
                                break;
                            }

                            case 2: //pressing on
                            {
                                if(if_dead>=0 && if_dead<=69)
                                {
                                    cout << players[num].getName() << " HAS DIED OF DYSENTERY! " << endl;
                                    players[num].setDead(true); //setting them dead
                                    
                                }
                                else
                                {
                                    cout << players[num].getName() << " HAS SURVIVED! " << endl;
                                    cout << endl;
                                }
                                valid = true;
                                break;
                            }
                            default:
                            {
                                valid = false;
                                cout << "PLEASE ENTER A VALID CHOICE!" << endl;
                                break;

                            }
                        }
                    }
                }
                break;
            }

            case 1: //oxen dead
            {
                cout << "OH NO!!! ONE OF YOUR OXEN HAS DIED! RIP! " << endl; //message
                
                int newoxen = currentSupplies.getOx() - 1; //updating inventory
                currentSupplies.setOx(newoxen);

                cout << "YOU HAVE " << currentSupplies.getOx() << " LEFT!" << endl;
                cout << endl;

                //check if all of the oxen are dead!
                if(currentSupplies.getOx() <= 0)
                {
                    cout << "ALL OF YOUR OXEN ARE DEAD! YOU CANNOT CONTINUE! " << endl;
                    cout << endl;
    
                }
                break;
            }

            case 2: //broken wagon
            {
                
                cout << "OH NO! ONE OF YOUR WHEELS HAS BROKEN!" << endl;

                if(currentSupplies.getWagonParts() > 0) //has spare parts
                {
                    days_passed = 1; //takes 1 day to fix wagon
                    cout << "YOUR WAGON HAS BEEN FIXED!" << endl;
                    cout << endl;

                    currentSupplies.setWagonParts(currentSupplies.getWagonParts() - 1);
                }

                else if(currentSupplies.getWagonParts() <= 0)//game ends
                {
                    cout << "YOUR WAGON CANNOT BE FIXED." << endl;
                    currentSupplies.setWagon(0);
                    cout << endl;
                    
                }
                break;

            }
        }
    }

   return days_passed;

}


/*
* This function uses an equation based upon distance to determine whether the player encounters raiders.
* Based upon what option the player chooses, a different series of events occurs and inventory is updated appropriately.
* Parameters: none
* Return: number of days passed (integer)
*/
int Game :: raiders() 
{
    int days_passed=0; //must account for days passed
    
    //the probability equation (returns 5-50)
    int probability = (((pow((progress1.getDistance()/100)-4, 2)+72)/(pow((progress1.getDistance()/100)-4,2)+12))-1)/.1; 

    //using the random function
    int if_raiders = rand()%99; //gives you values 0-100
    
    //user input variables
    string suser_input;
    int user_input;

    if(if_raiders >= 0 && if_raiders<=probability) //if it is in the probability of raiders
    {
        cout << "RAIDERS AHEAD! BEWARE!" << endl; //printed message
        cout << endl;
        cout << "PICK AN OPTION: " << endl; //menu
        cout << "1. RUN " << endl;
        cout << "2. ATTACK " << endl;
        cout << "3. SURRENDER " <<endl;

        //user input
        getline(cin,suser_input);
        user_input = stoi(suser_input);

        switch(user_input)
        {
            case 1: //run
            {
                days_passed = 1;

                //update the inventory
                currentSupplies.setOx(currentSupplies.getOx() -1); //subtracting on ox
                currentSupplies.setFood(currentSupplies.getFood() - 10); //subtracting food
                currentSupplies.setWagon(currentSupplies.getWagonParts() -1); //subtracting wagon part
                
            }

            case 2: //attack
            {   
                days_passed = 2;

                int puzzle_choice = rand() % 3; //picks a random number 0-2
                bool correct = false;
                correct = puzzles(puzzle_choice);

                if (correct == true)
                {
                    cout << "YOU HAVE SUCCESSFULLY DEFEATED THE RAIDERS!" << endl;
                    cout << endl;
                    currentSupplies.setBullets(currentSupplies.getBullets() + 50); //updating bullets
                    currentSupplies.setFood(currentSupplies.getFood() + 50); //updating food
                }

                else if(correct == false)
                {
                    cout << "DARN, YOU HAVE BEEN DEFEATED BY THE RAIDERS!" << endl;
                    cout << endl;
                    currentSupplies.setBullets(currentSupplies.getBullets() - 50); //subtracting food
                    int newbalance = store_1.getBalance() - store_1.getBalance()/4; //losing 1/4
                    store_1.setBalance(newbalance); 
                    
                }
                
            }

            case 3: //surrender
            {
                days_passed = 1;

                int newbalance = store_1.getBalance() - store_1.getBalance()/4; //losing 1/4
                store_1.setBalance(newbalance); 
            }
        }
    }
    
    return days_passed;
}


/*
* This function checks all the conditions that would allow the game to end.
* Parameters: none
* Return: gameEnd (boolean) --> whether or not the game has ended
*/
bool Game :: checkGameEnd() 
{
    bool gameEnd = false;

    //party runs out of food
    if(currentSupplies.getFood() <= 0)
    {
        cout << "YOU HAVE RUN OUT OF FOOD! YOU CANNOT CONTINUE ON YOUR JOURNEY." << endl;
        cout << "GAME END!" << endl;
        gameEnd = true;
    }

    //no oxen
    else if(currentSupplies.getOx() <= 0)
    {
        cout << "YOU HAVE NO OXEN LEFT! YOU CANNOT CONTINUE ON YOUR JOURNEY." << endl;
        cout << "GAME END!" << endl;
        gameEnd = true;
    }

    //broken wagon 
    else if(currentSupplies.getWagon() <= 0)
    {
        cout << "YOUR WAGON HAS BROKEN AND YOU HAVE NO PARTS TO FIX IT!" << endl;
        cout << "GAME END!" << endl;
        gameEnd = true;
    }
    
    //leader dead
    else if(players[0].getDead() == true)
    {
        cout << "YOUR LEADER HAS DIED! YOU CANNOT CONTINUE ON YOUR JOURNEY! " << endl;
        cout << "GAME END!" << endl;
        gameEnd = true;
    }

    //if they have exceeded the date to be there
    else if(date_1.getDay()>30 && date_1.getMonth()>11)
    {
        cout << "YOU HAVE NOT REACHED YOUR DESTINATION IN TIME!" << endl;
        cout << "GAME END!" << endl;
        gameEnd = true;
    }

    //if they have reached the end(successfully!)
    else if(progress1.getDistance() >= 2040)
    {
        cout << "YOU HAVE SUCCESSFULLY REACHED YOUR DESTINATION! CONGRATS!" << endl;
        cout << "GAME END!" << endl;
        gameEnd = true;
    }

    return gameEnd;
}


/*
* This function is called when the game ends. It prints out the results and writes them to the results.txt file.
* Parameters: none
* Return: none
*/
void Game :: gameEnd() 
{
    //printing out the results
    cout << "Leader: " << players[0].getName() << endl;
    cout << "Miles Traveled: " << progress1.getDistance() << endl;
    cout << "Food Remaining: " << currentSupplies.getFood() << endl;
    cout << "Cash Remaining: " << store_1.getBalance() << endl;

    //open and create a file
    ofstream myFile("results.txt");

    //writing to the file
    myFile << "Leader: " << players[0].getName() << endl;
    myFile << "Miles Traveled: " << progress1.getDistance() << endl;
    myFile << "Food Remaining: " << currentSupplies.getFood() << endl;
    myFile << "Cash Remaining: " << store_1.getBalance() << endl;

    //closing the file
    myFile.close();

    //calling the sort
    ranking();
}


/*
* This function reads a file of milestone names and distances and sorts them into an array of object
* Parameters: filename (string), milestones[] (array of objects), number of milestones (integer)
* Return: none
*/
void Game :: sortMilestones(string filename, Milestones milestones[], int num_of_milestones)
{
    int name_index=0;
    int dist_index=0;

    //reading the file
    ifstream in_file;
    in_file.open (filename);

    string line;

    //file does not open
    if (in_file.fail())
    {
        cout << "FILE FAILED TO OPEN! " << endl;
    }

    //reading the file
    while (getline (in_file,line))
    {
        string arr[15]; //only when getting the distance

        //if it is not an empty line
        if(line.length()!=0)
        {
            if (line[0]>='A' && line[0]<='Z') //if the line is a milestone name
            {
                milestones[name_index].setMilestoneName(line);
                name_index++;
            }

            else 
            {
                split(line, 'm', arr , 1); //splits it so it just the num

                int distance2 = stoi(arr[0]);
                milestones[dist_index].setDistance(distance2);
                dist_index++;
               
            }
        }
    }
}


/*
* This function utilizes selection sort to rank the player amongst other players based upon distance
* Parameters: none
* Return: none
*/
void Game :: ranking() 
{
    //write the new results to the file
    
    ofstream myFile;
    myFile.open("leaderboard.txt", ios::app);
    myFile << players[0].getName() << "," << progress1.getDistance() << endl;
    myFile.close();

    //read the file and count lines
    ifstream myFile_1;
    myFile_1.open("leaderboard.txt");
    string line;
    int count=0;

    while(getline(myFile_1,line))
    {
        if (line != "") //counts the non empty lines
        {
            count++;
        }
    }

    int distArr[count];
    string arr[count];
    string nameArr[count];
    int index = 0;

    ifstream myFile_2;
    myFile_2.open("leaderboard.txt");

    while (getline(myFile_2, line)) //does not enter this
    {
        line = line + ",";
        if (line != "")
        {
            split(line, ',', arr, count); //using the split function to split at the comma
            nameArr[index] = arr[0]; //stores player name 
            distArr[index] = stoi(arr[1]); //stores player's distance
        }

        index++;
    }

    int max_index; //index of the max value

    for (int i = 0; i < count -1; i++) //moving the boundary of the array
    {   
        max_index = i;

        for(int j=i+1; j<count; j++) //finding the max element in the unsorted array
        {
            if(distArr[j] > distArr[max_index])
            {
                max_index = j;
            }
        }

        //swap
        int temp;
        temp = distArr[max_index];
        distArr[max_index] = distArr[i]; 
        distArr[i] = temp;
    
    
        string temp1;
        temp1 = nameArr[max_index];
        nameArr[max_index] = nameArr[i];
        nameArr[i] = temp1;
    
    }
    myFile_2.close();

    //rewrite it to the file
    ofstream myFile_3("leaderboard.txt");
    for(int i=0; i<count; i++)
    {
        myFile_3 << nameArr[i] << "," << distArr[i] <<endl;
    }
    myFile_3.close();
}


/*
* This function determines whether or not there is a milestone along the players journey.
* If there is a milestone, they get the choice to rest or continue.
* If the milestone is a fort, they can stop at the store and the price increase function is called.
* Parameters: start and end (integers)
* Return: total distance traveled (integer)
*/
int Game :: ifMilestone(int start, int end) 
{
    string user_input;
    int input;
    bool satisfactory = false;

    //checking using the array
    for(int i=0; i<15; i++)
    {
        if(milestones1[i].getDistance()>start && milestones1[i].getDistance() < end) //milestone in between
        {
            if(i==2 || i==4 || i==7 || i==10 || i==12 || 1==14) //fort
            {

                while(satisfactory == false)
                {
                    cout << "YOU WERE PREPARED TO TRAVEL " << end-start << " MILES, BUT YOU HAVE REACHED " << milestones1[i].getMilestoneName() << endl;
                    cout << "WOULD YOU LIKE TO: "<< endl;
                    cout << "1. REST" << endl;
                    cout << "2. VISIT THE STORE" << endl;
                    cout << "3. CONTINUE" << endl;

                    //input
                    getline(cin, user_input);
                    input = stoi(user_input);

                    switch(input)
                    {
                        case 1: //rest
                        {
                            progress1.setDistance(milestones1[i].getDistance()); //setting the new distance to the milestone
                            break;
                        }
                        case 2: //store
                        {
                            progress1.setDistance(milestones1[i].getDistance());

                            if(i==2) //fort kearney
                            {
                                store_1.priceIncrease(1);
                            }

                            if(i==4) //fort laramie
                            {
                                store_1.priceIncrease(2);
                            }

                            if(i==7) //fort bridger
                            {
                                store_1.priceIncrease(3);
                            }

                            if(i==10) //fort hall
                            {
                                store_1.priceIncrease(4);
                            }

                            if(i==12) //fort boise
                            {  
                                store_1.priceIncrease(5);
                            }

                            if(i==14) //fort walla walla
                            {
                                store_1.priceIncrease(6);
                            }

                            store(false); //not the start

                            break;
                        }

                        case 3: //continue
                        {
                            progress1.setDistance(end);
                            satisfactory = true;
                            break;
                        }
                        default:
                        {
                            cout << "CHOOSE A VALID OPTION" << endl;
                        }
                    }
                }
            }

            else //not a fort
            {
            
                cout << "YOU WERE PREPARED TO TRAVEL " << end-start << " MILES, BUT YOU HAVE REACHED " << milestones1[i].getMilestoneName() << endl;
                cout << "WOULD YOU LIKE TO: "<< endl;
                cout << "1. REST" << endl;
                cout << "2. CONTINUE" << endl;

                //input
                getline(cin, user_input);
                input = stoi(user_input);

                //switch
                while(satisfactory == false)
                {
                    switch(input)
                    {
                        case 1: //rest
                        {
                            progress1.setDistance(milestones1[i].getDistance()); //setting the new distance to the milestone
                            satisfactory = true;
                            break;
                        }
                        case 2: //continue
                        {
                            progress1.setDistance(end);
                            satisfactory = true;
                            break;
                        }

                        default:
                        {
                            cout << "CHOOSE A VALID OPTION" << endl;
                        }
                    }
                }
            }

            break; //if there are multiple in between it should just choose the first one
        }

        else
        {
            progress1.setDistance(end); //this will be where they would have ended up     
        }
      
    }
    return progress1.getDistance();
}


/*
* This function calculates the distance from the next milestone
* Parameters: player's current distance (integer)
* Returns: the distance from milestone (integer)
*/
int Game :: fromMilestone(int distance) //calculates distance from next milestone
{
    int nextMilestone = 0;
    int distanceFrom = 0;

    //checking to see what the next milestone is
    for(int i=0; i<15; i++)
    {
        if(milestones1[i].getDistance() >= distance) //if it is equal or the next milestone
        {
            nextMilestone = i;
            break; //breaks out of the loop so it stops when it finds the next milestone
        }
    }

    distanceFrom = milestones1[nextMilestone].getDistance() - distance;

    return distanceFrom;

}


/*
* This function splits up a string based upon the given separator and places it into an array
* Parameters: string str, char separator, string a[], int size
* Return: number of elements in the array
*/
int split (string str, char separator, string a[], int size)
{
    int count = 0; //number of splits
    string substr;
    string word = "";

    //traversing the string to find where the delimeter is 
    for (int i=0; i<str.length(); i++)
    {
        if(str[i] != ' ')
        {
            if (str[i]!=separator)
            {
                word = word + str[i]; //making the word
            }

            else if (str[i] == separator)
            {
                a[count] = word;
                count ++; 
                word = ""; //resetting what word is
            }
        }
    }
    if (word == "") //if the word is empty
    {
        return 0;
    }
    else if (str == "") // if there is an empty string
    {
        return 0;
    }
    else if (count >= size)  /// if the amount of words that are split is larger than size
    {
        return -1;
    }
    else  //putting the final word into the array
    {
    a[count] = word;
    count ++;
    }

    return count; //return value
}