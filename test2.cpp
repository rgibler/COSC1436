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
void CalcRoots(int eqCoeff[], double& root1, double& root2, int& imagine, double& img1);
void PrintRoots(int eqCoeff[], double root1, double root2, int imagine, double& img1);

//Declaring the size of the array
const int ARRAY_SIZE = 3;

int main(){

    //Initializing and declaring variables
    int eqCoeff[ARRAY_SIZE] = {0};
    string yesOrNo; 
    double root1 = 0;
    double root2 = 0;
    double img1 = 0;
    
    //Sets imagine to false
    bool imagine = false;
   
    do{

        //Retreives coefficients from user input
        GetCoeff(eqCoeff, ARRAY_SIZE);

        //Calculates roots based on given coefficients
        CalcRoots(eqCoeff, root1, root2, imagine, img1);

        //Prints the roots to terminal
        PrintRoots(eqCoeff, root1, root2, imagine, img1);
        
        //Resets imaginary to false
        imagine = 0;

        //Inputs a new condition for the while statement
        cout << "Would you like to try again? (Y or N): ";
        cin >> yesOrNo; 
     
    }
    //Loop continues until the user inputs N
    while(yesOrNo != "N");
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
}

void CalcRoots(int eqCoeff[], double& root1, double& root2, bool& imagine, double& img1){

    //Casts userInput as floats
    double a = eqCoeff[0];
    double b = eqCoeff[1];
    double c = eqCoeff[2];

    //Calculates value beneath the square root
    double squareRoot = pow(b,2) - (4 * a * c);

    if (squareRoot < 0){
        //if value beneath square root is negative is is made positive
        squareRoot = -squareRoot;
        root1 = (-b)/(2 * a);
        img1 =  sqrt(squareRoot))/(2 * a)
        //if value beneath square root is negative imagine becomes true
            imagine = true;
    }

    if (a == 0 && b == 0){
        if (c < 0){
            imagine = true;
            c = -c;
        }
    root1 = sqrt(c);
    return;
    } 
    //Calculates the roots of the equation
    root1 = (-b + sqrt(squareRoot))/(2 * a);
    root2 = (-b - sqrt(squareRoot))/(2 * a);
}

void PrintRoots(int eqCoeff[], double root1, double root2, bool imagine, double& img1){

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
        cout << "Your solutions are " << root1 << " + << img1 << "i and ";
        cout << root2 << " + " << -img1 << "i\n" << endl;
    }
    //Solution of eq OrdofMag = 1
    if (eqCoeff[0] == 0 && eqCoeff[1] != 0){
        double solution = 0;
        solution = -static_cast<double>(eqCoeff[2])/static_cast<double>(eqCoeff[1]);
        cout << "Your solution is " << solution << endl;
    }
    //TODO:Write code for finding complex roots
    else{
        cout << "Your solutions are real numbers" << root1 << " and " << root2;
        cout << endl << endl; 
    }
    return;
}
