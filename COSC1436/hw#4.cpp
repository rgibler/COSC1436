/*Robert Gibler 7/23/2017
* Assignment 4
*
* This program calculates a person's body fat and percent body fat
* by scanning in a users weight, sex, and a number of measurements
* depending on the sex of the user. This program then outputs the
* the user's weight in fat and the user's percent fat. */

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){

    //Defining and initializing variables
    string sex = "";
    double bodyWeight = 0.0;
    double wristMeasure = 0.0;
    double waistMeasure = 0.0;
    double hipMeasure = 0.0;
    double forearmMeasure = 0.0;
    double bodyFat = 0.0;
    double bodyFatPercent = 0.0;
    double A1, A2, A3, A4, A5, B = 0.0;
 
    //defining values for measurements shared by both sexes
    cout << "What is your body weight? \n";
    cin >> bodyWeight;
    cout << "What is the measurement of your wrist (at its ";
    cout << "fullest point)? \n";
    cin >> wristMeasure;

    //Scanning in condition for if statement
    cout << "What is your sex? \n";
    cin >> sex;

    //Starting condition for female user
    if (sex == "female" || sex == "Female"){
       	cout << "What is your waist measurement (at navel)? \n";
		cin >> waistMeasure;
		cout << "What is your hip measurement (at fullest point)? \n";
		cin >> hipMeasure;
		cout << "What is your forearm measurement (at fullest point)? \n";
		cin >> forearmMeasure;
        
        //Calculations for female body fat
        A1 = (bodyWeight * 0.732) + 8.987;
        A2 = wristMeasure / 3.140;
        A3 = waistMeasure * 0.157;
        A4 = hipMeasure * 0.249;
        A5 = forearmMeasure * 0.434;
        B = A1 + A2 - A3 - A4 + A5;
        bodyFat = bodyWeight - B;
        bodyFatPercent = (bodyFat * 100) / bodyWeight;

        //Outputing results of calculations
        cout << "Your total body fat is " << bodyFat << ".\n";
        cout << "Your percent body fat is " << bodyFatPercent << ".\n";
        
        //terminating program after results sent to terminal
        return 0;       
	}
    //the following us used if user is male
    else if ((sex == "Male") || (sex == "male")){ 

        //Provided calculation for male body fat
        A1 = (bodyWeight * 1.082) + 94.42;
        A2 = wristMeasure * 4.15;
        B = A1 - A2;
        bodyFat = bodyWeight - B;
        bodyFatPercent = (bodyFat * 100) / bodyWeight;
        
        //sending results of calculations to terminal
        cout << "Your total body fat is " << bodyFat << ".\n";
        cout << "Your percent body fat is " << bodyFatPercent << ".\n";

        //terminating program after results are sent to terminal
        return 0;
    }

    //sends error if invalid sex is provided
    else{
        cout << "!!ERROR!! Invalid sex. Choose Male or Female.\n";
        return 1;
    }
}
