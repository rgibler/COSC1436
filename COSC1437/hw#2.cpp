/*Robert Gibler COSC 1437
*
* This program reads in student information from ther terminal and uses 
* functions to perform a variety of operations. This exercise is intended 
* to get comfortable with structs and member functions.*/

#include<iostream>
#include<string>
using namespace std;

int const NUM_STUDENTS = 20;

//Defining my struct
struct studentType{
    string studentFName, studentLName;
    int testScore;
    char grade;
    studentType();
};

//Constructor for struct
studentType::studentType(){
    studentFName = "";
    studentLName = "";
    testScore = 0;
    grade = ' ';
}

//Setting struct variables for each student
void SetStudentData(studentType room[]){
    for (int i = 0; i < NUM_STUDENTS; i++){
        cout << "Please enter student's first name: ";
        cin >> room[i].studentFName;
        cout << "Please enter student's last name: ";
        cin >> room[i].studentLName;
        cout << "Please enter student's test score: ";
        cin >> room[i].testScore;
    }
}

//Using switch statement to determine letter grade
void CalcGrade(studentType room[]){
    int temp = 0;
    for (int i = 0; i < NUM_STUDENTS; i++){
        switch (room[i].testScore / 10){
            case 10: 
            case 9:
                room[i].grade = 'A';
                break;
            case 8:
                room[i].grade = 'B';
                break;
            case 7:
                room[i].grade = 'C';
                break;
            case 6:
                room[i].grade = 'D';
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                room[i].grade = 'F';
                break;
            default:
                cout << "ERROR INVALID GRADE!\n";
                break;
        }
    }
}

//Declaring functions
int FindHiScore(studentType room[]);
void PrintHiScores(studentType room[], int);
void PrintStudentDetails(studentType room[]);

int main(){
    //Creating a studentType Array
    studentType studyHall[NUM_STUDENTS];

    SetStudentData(studyHall);
    CalcGrade(studyHall);
    PrintStudentDetails(studyHall);
    PrintHiScores(studyHall, FindHiScore(studyHall));
}

//Searches through all student scores to determine highest
int FindHiScore(studentType room[]){
    int hiScore = 0;
    for (int i = 0; i < NUM_STUDENTS; i++){
        if (room[i].testScore > hiScore){
            hiScore = room[i].testScore;
        }
    }
    return hiScore;
}

//finds name of students with scores equal to the highest
void PrintHiScores(studentType room[], int hiScore){
    for (int i = 0; i < NUM_STUDENTS; i++){
        if (room[i].testScore == hiScore){
            cout << room[i].studentLName << ", " << room[i].studentFName;
            cout << " had the highest test score of " << room[i].testScore << endl;
        }
    }
    cout << endl;
}

//Prints all of the student details
void PrintStudentDetails(studentType room[]){
    for (int i = 0; i < NUM_STUDENTS; i++){
        cout << room[i].studentLName << ", " << room[i].studentFName << " scored a " << room[i].testScore;
        cout << " giving them a grade of " << room[i].grade << endl;
    }
}
