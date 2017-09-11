/*Robert Gibler  COSC1437
*
* This program was for assignment 1
*
* Thia program scans in information from a text file into various arrays.
* The arrays themselves are used to calculate the average grade for each 
* student, the students' letter grades, and the class average. Then it 
* outputs the data to the terminal*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Defining constants for the arrays
int const NUM_STUDENTS = 10;
int const NUM_TESTS= 5;

//Function declarations
void ScanInput(string names[], int grades[][NUM_TESTS]);
void CalcAverages(const int grades[][NUM_TESTS], double averages[]); 
void SetLetterGrades(double averages[], char letters[]);
double CalcClassAverage(double averages[]);
void PrintResults(const string names [], double averages[], char letters[]); 

int main(){
    //Declaring arrays and variables
    string studentNames[NUM_STUDENTS];
    int studentGrades[NUM_STUDENTS][NUM_TESTS];
    char letterGrades[NUM_STUDENTS];
    double averageGrades[NUM_STUDENTS];

    ScanInput(studentNames, studentGrades);
    CalcAverages(studentGrades, averageGrades);
    SetLetterGrades(averageGrades, letterGrades);
    PrintResults(studentNames, averageGrades, letterGrades);
 
}

//Scanning in information from text file and filling arrays
void ScanInput(string names[], int grades[][NUM_TESTS]){
    ifstream infile;
    infile.open("input.txt");

    for (int i = 0; i < NUM_STUDENTS; i++){
        infile >> names[i];
        for (int j = 0; j < NUM_TESTS; j++){
            infile >> grades[i][j];
        }
    }
}


void CalcAverages(const int grades[][NUM_TESTS], double averages[]){
    double sum;
            
    for (int i = 0; i < NUM_STUDENTS; i++){
        sum = 0;
        for (int j = 0; j < NUM_TESTS; j++){
            sum += grades[i][j];
        }
        averages[i] = sum / NUM_TESTS;
    }
}

//Uses switch statement to assign letter grade to student
void SetLetterGrades(double averages[], char letters[]){
    for (int i = 0; i < NUM_STUDENTS; i++){
        switch((int) averages[i]/NUM_STUDENTS){
            case 10:
            case 9:
                letters[i] = 'A';
                break;
            case 8:
                letters[i] = 'B';
                break;
            case 7:
                letters[i] = 'C';
                break;
            case 6:
                letters[i] = 'D';
                break;
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                letters[i] = 'F';
                break;
            default:
                cout << "ERROR GRADE INVALID!\n";
        }
    }
}

double CalcClassAverage(double averages[]){ 
    double sum, classAverage;
    sum = 0;
    for (int i = 0; i < NUM_STUDENTS; i++){
        sum += averages[i];
    }   
    classAverage = sum / NUM_STUDENTS;
    return classAverage;
}

void PrintResults(const string names[], double averages[], char letters[]){ 
    for (int i = 0; i < NUM_STUDENTS; i++){
        cout << names[i] << " received a " << letters[i] << " with an";
        cout << " average score of " << averages[i] << endl;
    }
    cout << endl <<"The class average was " << CalcClassAverage(averages);
    cout << endl;
}
 
