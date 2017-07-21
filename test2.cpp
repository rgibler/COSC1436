/*Robert Gibler 7-7-2017
* COSC-1436
*
* This program was created to complete the requirements of the programming
* portion of CPSC 1436 Test2.
*
* This program continues to find the roots of quadratic equations whose 
* coefficients are inputted by the user until the user terminates the program 
* by typing "N".
*/

//Including Headers
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

//Declaring Functions
void GetCoeff(int eqCoeff[], int size);
void CalcRoots(int eqCoeff[], double& root1, double& root2, int& imagine);
void PrintRoots(int eqCoeff[], double root1, double root2, int imagine);

//Declaring the size of the array
const int ARRAY_SIZE = 3;

int main(){

    //Initializing and declaring variables
    int eqCoeff[ARRAY_SIZE] = {0};
    string yesOrNo = ""; 
    double root1 = 0;
    double root2 = 0;
    
    //Sets imagine to false
    int imagine = 0;
   
    do{

        //Retreives coefficients from user input
        GetCoeff(eqCoeff, ARRAY_SIZE);

        //Calculates roots based on given coefficients
        CalcRoots(eqCoeff, root1, root2, imagine);

        //Prints the roots to terminal
        PrintRoots(eqCoeff, root1, root2, imagine);
        
        //Resets imaginary to false
        imagine = 0;

        //Inputs a new condition for the while statement
        cout << "Would you like to try again? (Y or N): ";
        cin >> yesOrNo; 
     
    }
    //Loop continues until the user inputs N
    while(yesOrNo != "N");
    return 0;
}

void GetCoeff(int eqCoeff[], int size){
    cout << "The equation is in the form of ax^2 + bx + c.\n";
    cout << "Please enter three integers for the coefficients of your\n";
    cout << "equation typed in order (ex: 2 4 3): ";

    //Assigns user input to different positions in the array
    for (int i = 0; i < size; i++){
        cin >> eqCoeff[i];
    }

    cout << endl << "Your provided equation is " << eqCoeff[0] << "x^2 + ";
    cout << eqCoeff[1] << "x + " << eqCoeff[2] << endl; 
    return;
}

void CalcRoots(int eqCoeff[], double& root1, double& root2, int& imagine){

    //Casts userInput as floats
    double a = static_cast<double>(eqCoeff[0]);
    double b = static_cast<double>(eqCoeff[1]);
    double c = static_cast<double>(eqCoeff[2]);

    //Calculates value beneath the square root
    double squareRoot = pow(b,2) - (4 * a * c);

    if (squareRoot < 0){
        //if value beneath square root is negative is is made positive
        squareRoot = -squareRoot;
        //if value beneath square root is negative imagine becomes true
            imagine = 1;
    }

    if (a == 0 && b == 0){
        if (c < 0){
            imagine = 1;
            c = -c;
        }
        root1 = sqrt(c);
        return;
    } 
    //Calculates the roots of the equation
    root1 = (-b + sqrt(squareRoot))/(2 * a);
    root2 = (-b - sqrt(squareRoot))/(2 * a);

    return;
}

void PrintRoots(int eqCoeff[], double root1, double root2, int imagine){

    //Checks if equation has a single root
    if (eqCoeff[0] == 0 && eqCoeff[1] == 0){
        if (imagine == 1){
            cout << "Your equation has an imaginary solution of " << root1 << "i"; 
            cout << endl << endl;
            return;
        }
        cout << "Your equation has a single real solution of " << root1 << endl;
        cout << endl;
    }
    //Checks if roots are imaginary    
    else if (imagine == 1){
        cout << "Your solutions are the imaginary numbers" << root1 << "i and ";
        cout << root2 << "i\n" << endl;
    }
    //Solution of eq OrdofMag = 1
    if (eqCoeff[0] == 0 && eqCoeff[1] != 0){
        double solution = 0;
        solution = -eqCoeff[2]/eqCoeff[1];
        cout << "Your solution is " << solution << endl;
    }
    //TODO:Write code for finding complex roots
    else{
        cout << "Your solutions are real numbers" << root1 << " and " << root2;
        cout << endl << endl; 
    }
    return;
}
