/*Robert Gibler COSC 1436 06-20-2017
* Assignment 3
*
* Program reads in a file containing 3 employees' first and lastnames
* their respective salaries and their expected percent raise. This program
* Then calculates the salaries afterthe percent increase and prints the 
* firstnames last names and updated salaries of each person on to an output
* file. */


#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;

int main(){

    //Definig and initializing variables
    ifstream inFile;
    ofstream outFile;
 
    string lastName1 = "";
    string lastName2 = "";
    string lastName3 = "";
    string firstName1 = "";
    string firstName2 = "";
    string firstName3 = "";

    double salary1 = 0.0;
    double salary2 = 0.0;
    double salary3 = 0.0;
    double payIncrease1 = 0.0;
    double payIncrease2 = 0.0;
    double payIncrease3 = 0.0;
    double newSalary1 = 0.0;
    double newSalary2 = 0.0;
    double newSalary3 = 0.0;

    //Openning the input and output files
    inFile.open("Ch3_Ex7Data.txt");
    outFile.open("Ch3_Ex7Output.dat");

    //Checking for file openning errors
    if (inFile == NULL){
	cout << "ERROR! Unable to open Ch3_Ex7Data.txt\n";
    }

    if (outFile == NULL){
        cout << "ERROR! Unable to open Ch3_Ex7Output.dat\n";
    } 

    //Assigning the data in input files to variables	
    inFile >> lastName1 >> firstName1 >> salary1 >> payIncrease1;
    inFile >> lastName2 >> firstName2 >> salary2 >> payIncrease2;
    inFile >> lastName3 >> firstName3 >> salary3 >> payIncrease3;

    //Calculating updated salary
    newSalary1 = salary1 * ((payIncrease1 / 100) + 1);
    newSalary2 = salary2 * ((payIncrease2 / 100) + 1);
    newSalary3 = salary3 * ((payIncrease3 / 100) + 1);


    //Printing first and last names and updated salary to output file
    outFile << setprecision(7) << firstName1 << " " << lastName1 << " " << newSalary1 << endl;
    outFile << endl;
    outFile << firstName2 << " " << lastName2 << " " << newSalary2 << endl;
    outFile << endl;
    outFile << firstName3 << " " << lastName3 << " " << newSalary3 << endl;

    //Closing the input and output files
    inFile.close();
    outFile.close();

    return 0;
}
