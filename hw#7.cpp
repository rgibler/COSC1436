/*Robert Gibler   7-6-2017
* COSC1436
*
* This program was written to perform the tasks required of Assignment 7.
*
* It allows the user to input 5 names and a corresponding number of votes.
* The program then calculates the percenatge of the total votes each person
* received and outputs a chart showing the person's name, their votes, their 
* percentage of the total votes, and the winner of the election.
*/

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//Declaring Functions
string GetName();
int GetNumVotes();

int main(){
    //Setting sizes for arrays and decaring variables
    string candidates[5];
    int votes[5];
    int totalVotes = 0;
    double percentVotes[5];
    double max = 0.0;
    string winner = "";

    //Retreive names and # of votes from user
    for (int i = 0; i < 5; i++){ 
        candidates[i] = GetName();
        votes[i]= GetNumVotes();
        totalVotes += votes[i];
    }
    //Calculates the percent votes for each candidate and finds winner
    for (int j = 0; j < 5; j++){
        percentVotes[j] = 100 * (static_cast<double>(votes[j]) / totalVotes);
        if (percentVotes[j] > max){
            max = percentVotes[j];
            winner = candidates[j];
        }
    }

    cout << endl << "Candidates" << setw(18) << "Votes Received"; 
    cout << setw(24) << "\% of Total Votes\n";

    //Loops through both arrays and arranges data into columns
    for (int k = 0; k < 5; k++){
        cout << candidates[k] << setw(18 - candidates[k].length()); 
        cout << votes[k] << setw(24) << percentVotes[k] << endl;
    }

    //Outputs total number of votes and announces the winner of the election
    cout << endl << "Total Votes:" << setw(6) << totalVotes << endl;
    cout << "The winner of the election was: " << winner << endl;    

    return 0;
}

//Function for getting name of candidates
string GetName(){
    string name;
    cout << "Please enter the name of a candidate: ";
    cin >> name;
    return name;
}

//Function for getting # of votes per candidate
int GetNumVotes(){
    int numVotes = 0;
    cout << "Please enter the number of votes this candidate received: ";
    cin >> numVotes;
    return numVotes;
}




