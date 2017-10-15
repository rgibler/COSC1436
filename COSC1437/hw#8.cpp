/*Robert Gibler
* COSC 1437
*
* In this program a function is used to make bowtie star patterns when given
* non-negative integer inputs.*/

#include<iostream>
#include<cmath> //allows for the use of the abs() function
using namespace std;

//Declaring my functions
int PromptUsr();
void MakePattern(int n, int);

int main(){
    int n;
    n = PromptUsr();
    int temp = n; //My flag for finding a stopping point for MakePattern()
    MakePattern(n, temp);
}

//Prompts usr for value and ensures value is positive
int PromptUsr(){
    int n;
    cout << "Please enter a non-negative integer for a pattern to be ";
    cout << "generated around: ";
    cin >> n;
    while (n < 0){
        cout << "Integer negative please enter a positive value: ";
        cin >> n;
    }
    return n;
}

void MakePattern(int n, int temp){
    //ensures function stays symmetric
    if (n >= -temp){
        for (int i = 0; i <abs(n); i++){
            //stops repeated single star in pattern
            if (n !=-1)
                cout << "*";
        }
        if (abs(n) > 0 && n != -1){
            cout << endl;
        }
        //Recursive call forming pattern
        MakePattern(n-1, temp);
    }
    else{
        return;
    }
}
    


