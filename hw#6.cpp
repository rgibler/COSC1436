/*Robert Gibler    7-6-2017 
* COSC 1436
*
* This program was created to perform the procedure outlined in 
* Assignment 6. 
*
* The user is initially given a random two digit number and is then
* asked whether or not to perform a number of different operations on
* their initial value. The value returned after each operation is the 
* value that is used in the following operations. Any response to the
* prompts requesting yes or no to be inputted that is not yes or Yes will
* result in the operation being skipped.
*/

#include<cstdlib>
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>

using namespace std;

//Function Declarations
string GetResponse();
int GetRandNum();
int DoubleNum(int userNum);
int ReverseDigits(int userNum);
int RaisePower(int userNum);
void IsPrime(int userNum);
int SumDigits(int userNum);
int DigitPower(int userNum);


int main(){

    //selecting a different seed allows for variation in random numbers that are generated 
    //otherwise random number is always going to be 83   
    int seed = 0;
    cout << "What value would you like to seed rand() with? ";
    cin >> seed;
    //this seeds the random number generator at userdefined value
    srand(seed);
    int randNum = 0;
    randNum = GetRandNum();
    
    cout << "Your random number is " << randNum << endl;
    cout << endl;

    cout << "In order for the following processes to be performed the user ";
    cout << "must type yes in response to the prompts.\n" << endl;

    randNum = DoubleNum(randNum);
    cout << endl;
    randNum = ReverseDigits(randNum);
    cout << endl;
    randNum = RaisePower(randNum);
    cout << endl;
    randNum = SumDigits(randNum);    
    cout << endl;
    randNum = DigitPower(randNum);
    cout << endl;

    return 0;
}

string GetResponse(){
    string userResponse = "";
    cin >> userResponse;

    //Continues looping until user inserts proper response
    while ((userResponse != "yes") || (userResponse != "no")){
        if (userResponse == "yes" || userResponse == "no")
            break;
        else if (userResponse == "Yes" || userResponse == "No")
            break;

        cout << "Please type yes or no: ";
        cin >> userResponse;
    }
    return userResponse;
}


//function that creates 2 digit random number for user
int GetRandNum(){
    int randNum = rand() % 100;
    if (randNum < 10)
        randNum = randNum + 10;
    return randNum;

    //Checks whether or not generated number is prime
    IsPrime(randNum);
}

int DoubleNum(int userNum){
    string userResponse = "";
    int doubleNum = 0;
    cout << "Would you like to double your given random number? ";
    userResponse = GetResponse();
    
    if (userResponse == "Yes" || userResponse == "yes"){
        doubleNum = userNum + userNum;
        cout << "Your number is now " << doubleNum << endl;
        IsPrime(doubleNum);
        return doubleNum;
    }
    //If yes is not typed process is skipped    
    return userNum;
}

int ReverseDigits(int userNum){

    string userResponse = "";
    cout << "Would you like to reverse the digits of your number? ";
    userResponse = GetResponse();

    int firstDigit = 0;
    int secondDigit = 0;
    int thirdDigit = 0;    
 
    if (userResponse == "Yes" || userResponse == "yes"){
        //Case for 2 digit input
        if (userNum > 9 && userNum < 100){
            firstDigit = floor(userNum / 10);
            secondDigit = userNum % ( 10 * firstDigit);
            int newNum = 10 * secondDigit + firstDigit;
            cout << "Your number is now " << newNum << endl;
            
            //Ensures that output is greater than 10 if not adds 10 to returned value
            if (newNum > 9){
                IsPrime(newNum);
                return newNum;
            }
            else{
                IsPrime(newNum + 10); 
                return newNum + 10;
            }
        }
        //Case for 3 digit input
        else if (userNum >= 100 && userNum <= 999){
            firstDigit = floor(userNum / 100);
            secondDigit = (floor(userNum / 10)) - (firstDigit * 10);
            thirdDigit = userNum - (firstDigit * 100 + secondDigit * 10);
            int newNum = thirdDigit * 100 + 10 * secondDigit + firstDigit;

            cout << "The digits of your number were " << firstDigit << " ";
            cout << secondDigit << " " << thirdDigit << ".\n";
            cout << "The new number after digits were reversed is " << newNum << endl;
            if (newNum < 10){
                IsPrime(newNum + 10);
                return (newNum + 10); 
            }else{
                IsPrime(newNum);
                return newNum;
            }
        }else{    
            cout << "Number must have either two  or three digits\n";
            return userNum;
        }
    }

    return userNum;
    
}

int RaisePower(int userNum){
    string userResponse = "";
    cout << "Would you like to raise the power of your number by 2, 3, or 4? ";
    userResponse = GetResponse();

    if (userResponse == "Yes" || userResponse == "yes"){
        int userPower = 0;
        cout << "What power would you like to raise your number by?\n";
        do{
            cout << "(Please enter either 2, 3, or 4): ";
            cin >> userPower;
        }//Loop continues until proper power is inputted
        while(userPower < 2 || userPower > 4);
        int powNum = pow(userNum, userPower);
        if (powNum > 0){
            cout << " Your new value is " << powNum << endl;
            IsPrime(powNum);
            return powNum;        
        }else{
            cout << "!!!ERROR!! Result of operation was too large for  an integer variable to hold\n";
            cout << "Operation was skipped; user's number is still " << userNum << endl;
            return userNum;
        }
    }
    return userNum;

}

void IsPrime(int userNum){

    int primeNum = 1;
    //Loops through all potential factors to ensure that value is prime
    for (int i = 2; i < userNum; i++){
        primeNum = userNum % i;
        if (primeNum == 0){
            cout << "This value is not prime\n";
            return;
        }
    }
    cout << "This value is prime\n";
    return;
}

int SumDigits(int userNum){

    string userResponse;
    cout << "Would you like to find the sum of the digits of your number? ";   
    userResponse = GetResponse();

    if (userResponse == "Yes" || userResponse == "yes"){
        
        int digitSum = 0;
        int numDigits = 0;
        int tmpVal = 0;

        //Loops through all powers of 10 less than userNum to determine number of digits        
        for (int i = 0; tmpVal <= userNum; i++){
            tmpVal = pow(10,i);
            if (tmpVal <= userNum)
                numDigits++;
            else
                break;
        }   
        cout << userNum << " has " << numDigits << " digits\n";

        //Finds the value of each digit and finds the sum of all digits
        for (int j = numDigits; j > 0; j--){
            tmpVal = floor(userNum / pow(10, j-1));
            userNum = userNum - tmpVal * pow(10, j-1);
            digitSum = digitSum + tmpVal;
        }   

        cout << "The sum of the digits in the number is " << digitSum << endl;
    
        //ensures that value is atleast 2 digits
        if (digitSum > 9){
            IsPrime(digitSum);
            return digitSum;
        }else{
            IsPrime(digitSum + 10);
            return digitSum + 10;
        }
    }

    return userNum;
}

int DigitPower(int userNum){
    int firstDigit;
    int secondDigit;
    int thirdDigit;
    int digitPower = 0;
    int firstTwoDigits = 0;
    string userResponse;
    cout << "Would you like to raise the first digit to the power of the last digit? ";
    userResponse = GetResponse();
    if (userResponse == "Yes" || userResponse == "yes"){

        //Case for 2 digit number raises first number to power of second
        if (userNum > 9 && userNum < 100){
            firstDigit = floor(userNum / 10);
            secondDigit = userNum - firstDigit * 10;
            digitPower = pow(firstDigit, secondDigit);

            cout << "Your number is " << userNum << endl;
            cout << firstDigit << " raised to the " << secondDigit << "th power";
            cout << " is " << digitPower << endl;
            IsPrime(digitPower);
            return digitPower;
        }

        //Case for 3 digit number raises integer made up of first 2 digits to the power
        //of the last digit
        if (userNum > 99 && userNum < 1000){
            firstDigit = floor(userNum / 100);
            secondDigit = floor((userNum - firstDigit * 100) / 10);
            thirdDigit = userNum - (firstDigit * 100) - (secondDigit * 10);

            //ensures that third digit does not exceed 4 before performing operation
            if (thirdDigit >= 0 && thirdDigit <= 4){
                firstTwoDigits = (firstDigit * 10) + secondDigit;
                digitPower = pow(firstTwoDigits, thirdDigit);
                cout << "Your number is " << userNum << endl;
                cout << firstTwoDigits << " raised to the ";
                cout << thirdDigit << " is " << digitPower << endl;
                IsPrime(digitPower);
                return digitPower;
            }else{
                cout << "The last digit must be less than or equal to 4 ";
                cout << " to perform this operation, but your last digit is ";
                cout << thirdDigit << endl;
                return userNum;
            }
        }
    }
    return userNum;
}
