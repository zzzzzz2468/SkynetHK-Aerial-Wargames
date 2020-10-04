#include <iostream>
#include <stdlib.h> //Including srand and rand
#include <time.h> //Including time

using namespace std;

//Initializing different variables that the code needs
int prediction = 0, gridHighNum = 0, gridLowNum = 0, totGrid = 0, enemyPos = 0;
int binarySearchTime = 0, linearSearchTime = 0, humanSearchTime = 0, randomSearchTime = 0;
bool playing = true;
string response;

void Start()
{
    totGrid = 0;
    //For loop that creates the grid, first loop being row, second being col, this is more for if we later show off the grid
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            totGrid++;
            //cout << " " << row << "," << col << " ";
        }
        //cout << endl;
    }

    //Initilizes seed value and then calls a random number
    srand(time(NULL));
    enemyPos = rand() % (totGrid + 1);

    //Intro code that provides info
    cout << "Generating enemy location on 8x8 grid...\n";
    cout << "Enemy is located at sector #" << enemyPos << "\n";
    cout << "Skynet HK-Aerial Initializing software...\n";
    cout << "============================================\n";
}

void BinarySearch()
{
    //Sets low and high numbers
    gridLowNum = 0;
    gridHighNum = totGrid;
    prediction = 0;

    //checks if prediction is not equal to enemy position, and runs code if the it is still trying to get them to match
    while (prediction != enemyPos)
    {
        //changes prediction based of other variables
        prediction = ((gridHighNum - gridLowNum) / 2) + gridLowNum;

        //tells user number of pings
        cout << "Skynet HK-Aerial Radar sending out ping " << (binarySearchTime + 1) << "\n";

        if (prediction < enemyPos)
        {
            //if the prediction was to low, changes the lownum and gives user info
            gridLowNum = prediction + 1;
            cout << "The target location of " << prediction << " was lower than the enemy\n";
            cout << "The new low number is = " << gridLowNum;
        }
        else if (prediction > enemyPos)
        {
            //if the prediction was to high, changes the highnum and gives user info
            gridHighNum = prediction - 1;
            cout << "The target location of " << prediction << " was higher than the enemy\n";
            cout << "The new high number is = " << gridHighNum;
        }
        else
        {
            //if the prediction was right, gives the user information that they did, also breaks out of code because while is no longer true
            cout << "The enemy was hiding at sector #" << prediction << "\n";
            cout << "Skynet HK-Aerial Software took " << (binarySearchTime + 1) << " predictions to find the enemy";
        }
        //adds barriers between pings
        cout << "\n============================================\n";

        //adds 1 to the number of pings
        binarySearchTime++;
    }
}

//linear search, checks every box on the grid until prediction is = enemy pos
void LinearSearch()
{
    for (prediction = 0; prediction < totGrid; prediction++)
    {
        if (prediction == enemyPos)
            break;
    }
    linearSearchTime = prediction;
}

//randomly generates numbers until the prediction is = to the enemy pos
void RandomSearch()
{
    prediction = 0;
    while (prediction != enemyPos)
    {
        prediction = rand() % (totGrid + 1);
        randomSearchTime++;
    }
}

//checks what the user input is, and if it is equal to the enemy pos, it moves on
void HumanSearch()
{
    prediction = 0;
    while (prediction != enemyPos)
    {
        cout << "Where do you think the enemy is? ";
        cin >> prediction;
        if (prediction < 64 && prediction > 0)
            humanSearchTime++;
        else
        {
            cout << "Prediction was out of bounds...\n";
            continue;
        }
    }
}

//output after every drone has found the enemy
void Output()
{
    cout << "\nAll drones have found the enemy.";
    cout << "\nThe enemy was hiding as grid location " << enemyPos;

    cout << "\n\nThe AI using binary search took " << binarySearchTime << " guesses.";
    cout << "\n\nThe AI using linear search took " << linearSearchTime << " guesses.";
    cout << "\n\nThe AI using random search took " << randomSearchTime << " guesses.";
    cout << "\n\nYou guessing took " << humanSearchTime << " guesses.";
}

//Calls the different code that runs each drone as well as start and output code
int main()
{
    while (playing)
    {
        Start();
        BinarySearch();
        LinearSearch();
        RandomSearch();
        HumanSearch();
        Output();
        cout << "\nDo you want to play again? y/n ";
        cin >> response;
        if (response == "y")
            playing = true;
        else if (response == "n")
            playing = false;
    }

    //ends the program
    return 0;
}