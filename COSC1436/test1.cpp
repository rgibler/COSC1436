/*Robert Gibler 6-27-2017
*
* This program is the Programming portion of Test1. 
* It reads in 2 integers from "input.txt" these two numbers.
* A number of mathematical processes are performed and then
* the inital numbers and the results of the processes are printed
* onto "output.txt" */

#include <iostream>
#include <fstream>

using namespace std;

int main(){

    //Declaring variables for the input and output files
    ifstream infile;
    ofstream outfile;

    //Declaring and initializing variables
    int int1, int2 = 0; 
    int TOTAL, Multiply, Difference, Division, MUD = 0;

    //Openning the input and output files
    infile.open("input.txt");
    outfile.open("output.txt");

    //Sending error message if unable to open either of the files
    if (infile == NULL){
        cout << "!!!ERROR!!Unable to open input.txt\n";
        return 1;
    }
    if (outfile == NULL){
        cout << "!!!ERROR!! Unable to open output.txt\n";
        return 2;
    }

    //Scanning in the integers from input.txt
    infile >> int1 >> int2;

    //Performing mathematical operations and storing results into delcared variables
    TOTAL = int1 + int2;
    Difference = int1 - int2;
    Multiply = int1 * int2;
    Division = int1 / int2;
    MUD = int1 % int2;

    //Writing the scanned integers and the results of operations to output.txt
    outfile << "The scanned integers from input.txt were ";
    outfile << int1 << " " << int2 << endl << endl;
    outfile << "The sum of the two integers is " << TOTAL << endl;
    outfile << "The difference between the two integers is " << Difference << endl;
    outfile << "The product of the two integers is " << Multiply << endl;
    outfile << "The quotient of the two integers is " << Division << endl;
    outfile << "The result of the modular division of the two integers is " << MUD << endl;

    //Closing the input and output files
    infile.close();
    outfile.close();
    
    return 0;
}
