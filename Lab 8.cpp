#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

// Forward Declarations
void Input_Names_And_Votes(int& amountOfCandidates, int votes[],string candidatesLastName[]);
void Process_The_Math(double& totalVotes, int& amountOfCandidates, int votes[],int& maxScore, int& saveIndex);
void Output_Chart_And_Winner(double& totalVotes, int& amountOfCandidates, int votes[], int& saveIndex,string candidatesLastName[]);

int main()
{
    double totalVotes; // Stores the value of all the votes entered by the user.
    int amountOfCandidates; // Store how many candidates the user wants to enter
    int votes[25]; // Allows up to max of 25 voters for the user to input
    int maxScore = { 0 }; // Used to help find the position for the highest number
    int saveIndex; // Saves position of highest number in votes[] array
    string candidatesLastName[25]; // Saves user input names

    // Tells the user what the program is and
    // to ask for how many names to input
    // from user and then read in the user input for
    // names and vote numbers
    Input_Names_And_Votes(amountOfCandidates, votes, candidatesLastName);

    // Does the math for processing the percentage for each person
    // and adds the total together, while finding the
    // person with the highest vote count and saving its
    // index to declare the winner
    Process_The_Math(totalVotes,amountOfCandidates, votes, maxScore, saveIndex);

    // Outputs all the data gathered from user input and
    // justifies all of it in a easy to read manner
    Output_Chart_And_Winner(totalVotes,amountOfCandidates, votes, saveIndex, candidatesLastName);

    return 0;
}


void Input_Names_And_Votes(int& amountOfCandidates, int votes[],string candidatesLastName[])
{
    // Tells user what program is
    cout << "---------------\n";
    cout << "Candidates Vote\n";
    cout << "---------------\n\n";

    // User prompt to ask user how many names to enter
    cout << "How many candidates names would you like to enter(1-25): ";
    cin >> amountOfCandidates;
    cout << endl;

    if (amountOfCandidates > 25)
    {
        cerr << "ERROR... INVALID AMOUNT OF CANDIDATES...EXITING" << endl;
        exit(1);
    }

    // For loop to enter candidates names and vote score
    for (int i = 1; i <= amountOfCandidates; i++)
    {
        cout << "\nEnter the last name of candidate" << "(" << i << "): ";
        cin >> candidatesLastName[i];
        cout << endl;

        cout << "Enter the amount of votes for " << candidatesLastName[i] << ": ";
        cin >> votes[i];
        cout << endl;
    }

}

void Process_The_Math(double& totalVotes, int& amountOfCandidates, int votes[], int& maxScore, int& saveIndex)
{
    // For loop for to find total votes of all candidates
    for(int i = 1; i <= amountOfCandidates; i++)
    {
        totalVotes += votes[i];
    }

    // For loop to find the max number from the votes
    for (int i = 1; i < amountOfCandidates + 1; i++)
    {
        if(votes[i] > maxScore)
        {
            maxScore = votes[i];
        }
    }

    // Saves the location of the max vote to be able
    // to use it to find the winners name
    saveIndex = distance(votes, find(votes, votes + amountOfCandidates, maxScore));
}

void Output_Chart_And_Winner(double& totalVotes, int& amountOfCandidates, int votes[],int& saveIndex,string candidatesLastName[])
{
    // Output the format for reading rows
    cout << left << setw(15) << "Candidate" << left << setw(15) << "Votes" << left << setw(15) << "% of Votes" << "\n";
    cout << "-------------------------------------------\n";

    // For loop to output the candidates name, their votes, and their vote percentage
    for (int i = 1; i <= amountOfCandidates; i++ )
    {
        cout << left
             << setw(15)
             << candidatesLastName[i]
             << left << setw(15)
             << votes[i]
             << left
             << setw(15)
             << setprecision(4)
             << votes[i] / totalVotes / .01
             << endl;
    }

    // Output the total votes and the winner
    cout << left << setw(15) << "Total: " << left << setw(15) << setprecision(10) << totalVotes << endl;
    cout << "The Winner of the Election is " << candidatesLastName[saveIndex] << endl;
}

