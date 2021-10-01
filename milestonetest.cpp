
#include <iostream>
#include <string>
#include <fstream>
#include "Milestones.h"
using namespace std;

int split (string str, char separator, string a[], int size);

void sortMilestones(string filename, Milestones milestones[], int num_of_milestones)
{
    /*
    1. Open and the read file like usual
    2. Place the milestone name and the distance in the array of milestones objects
    */

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

    for(int i=0; i<15; i++)
    {
        cout << milestones[i].getMilestoneName() << endl;
        cout << milestones[i].getDistance() << endl;

    }
}

//split function
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

int main()
{
    Milestones milestones1[30]={};
    sortMilestones("milestones.txt", milestones1 , 15);
}