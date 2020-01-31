#include <iostream>
#include <cmath>
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
    int amountOfCandidates;

    // Tells user what program is
    cout << "---------------\n";
    cout << "Candidates Vote\n";
    cout << "---------------\n\n";

    // User prompt to ask user how many names to enter
    cout << "How many candidates names would you like to enter: ";
    cin >> amountOfCandidates;
    cout << endl;

    // Arrays to store last name and votes
    string candidatesLastName[amountOfCandidates + 1];
    int votes[amountOfCandidates + 1];

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

    // Output the format for reading rows
    cout << left << setw(15) << "Candidate" << left << setw(15) << "Votes" << left << setw(15) << "% of Votes" << "\n";
    cout << "-------------------------------------------\n";

    // For loop for to find total votes of all candidates
    for(int ii = 1; ii <= amountOfCandidates; ii++)
    {
        totalVotes = totalVotes + votes[ii];
    }

    // For loop to output the candidates name, their votes, and their vote percentage
    for (int iii = 1; iii <= amountOfCandidates; iii++ )
    {
        cout << left
             << setw(15)
             << candidatesLastName[iii]
             << left << setw(15)
             << votes[iii]
             << left
             << setw(15)
             << setprecision(4)
             << votes[iii] / totalVotes / .01
             << endl;
    }

    // Output the total votes
    cout << left << setw(15) << "Total: " << left << setw(15) << setprecision(10) << totalVotes << endl;

    return 0;
}
