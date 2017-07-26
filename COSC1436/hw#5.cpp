/*Robert Gibler  6-28-2017
* 
* This program was written in response to the problem posed in COSC 1436 Assignment 5
*
* The user is requested to input total rent per month when all units are filled in an 
* apartment complex, total number of units in apartment complex, how much of an 
* increase in rent results in a vacancy, and the cost of mantaining a single occupied 
* apartment.
*
* This program then outputs the maximum possible profit and the number of occupied 
* units needed for max profit.*/

#include<iostream>
#include<string>
using namespace std;

int main(){

    //Declaring and initializing scanned in variables
    int totUnits = 50;
    int rentAllUnits = 0;
    int increasePerVacant = 0;
    int maintanence = 0;
    string yesOrNo = "";

    //Scanning in necessary data
    cout << "Enter the rent per month when all units are occupied: \n";
    cin >> rentAllUnits;
    cout << "Default number of units is 50. Would you like to enter ";
    cout << "a different number? (yes or no)\n";
    cin >> yesOrNo;
    if (yesOrNo == "Yes" || yesOrNo == "yes"){ 
        cout << "Enter total number of units in the apartment complex: \n";
        cin >> totUnits;
    }
    cout << "Enter the increase in rent which would result in a single";
    cout << " vacancy: \n";
    cin >> increasePerVacant;
    cout << "Enter the total cost of maintenance per occupied unit: \n";
    cin >> maintanence;

    //Delcaring max profit and index of max profit
    int maxProfit = 0;
    int imax = 0;

    //Looping though total number of occupant to find max profit
    for (int i = totUnits; i > 0; i--){
       int totalProfit = (rentAllUnits + (increasePerVacant * (totUnits - i))) * i - maintanence * i;
       if (totalProfit > maxProfit){
            maxProfit = totalProfit;
            imax = i;
        }
    }

    cout << "Maximum profit of $" << maxProfit;
    cout << " is achieved when number of units occupied is " << imax << endl;

    return 0;
}
