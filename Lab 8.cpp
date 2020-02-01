#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;


int main()
{

    // Variables for recording total votes,
    // final percentage
    // and amount of candidates for user to enter names and scores for
    double totalVotes = 0;
    double votesPercentage;
    int amountOfCandidates = amountOfCandidates;

    // Tells user what program is
    cout << "---------------\n";
    cout << "Candidates Vote\n";
    cout << "---------------\n\n";

    // User prompt to ask user how many names to enter
    cout << "How many candidates names would you like to enter: ";
    cin >> amountOfCandidates;
    cout << endl;

    // Arrays to store last name and votes
    string candidatesLastName[25];
    int votes[25];

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


    // For loop for to find total votes of all candidates
    for(int i = 1; i <= amountOfCandidates; i++)
    {
        totalVotes = totalVotes + votes[i];
    }

    // Variables to save the max score of the array
    // and save the location of the max score in the array
    int maxScore = { 0 };
    int saveIndex;

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
    cout << "The Winner of the Electron is " << candidatesLastName[saveIndex] << endl;

    return 0;
}
