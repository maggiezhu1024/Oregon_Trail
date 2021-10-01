#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
void ranking() //sorting algorithm, ranks how long it took each player
{
    //write the new results to the file...whats happenning is that it rewrites to an empty file
    
    ofstream myFile;
    myFile.open("leaderboard.txt", ios::app);
    myFile << "new name" << "," << "100" << endl;
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
            nameArr[index] = arr[0]; //stores player name at collumn 1 (player name)
            cout << nameArr[index] << endl;
            cout << "2" << endl;
            distArr[index] = stoi(arr[1]); //stores player's distance in collumn 2(distance by player) 
            cout << "3" << endl;
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

    


    /*
    1. Read the leaderboard.txt 
    2. Insert the results of the leaderboard.txt file into an array
    3. Find the maximum distance placed into the array and place it into [0] (maybe use a vector instead? or count lines)
    4. Do step 3 again but only search through elements other than the sorted ones
    5. write to the file
    */
}

int main(){
    ranking();
    return 0;
}