/*Robert Gibler  COSC1437
*
* This program is being written to solve the problem posed in Assignment 3.
*
* This program allows the user to manipulate date data inlcuding: setting
* date, printing date, returning date, etc..*/

#include<iostream>
#include<string>
using namespace std;

class dayType {
    private:
        string dayName;
        int dayNum;
    public:
        int SetDayName(string);
        void SetDay(int);
        void PrintDay(int);
        int GetDay();
        int GetNextDay();
        int GetPreviousDay();
        int CalcDay(int);
        dayType();
};

//Constructor initializes dayNum to 0
dayType::dayType(){
    dayNum = 0;
    dayName = "";
}

int dayType::SetDayName(string usrInput){
        
    if (usrInput == "Sun"){
            dayNum = 0;
    }
    else if (usrInput == "Mon"){
            dayNum = 1;
    }
    else if (usrInput == "Tues"){
            dayNum = 2;
    }
    else if (usrInput == "Wed"){
            dayNum = 3;
    }
    else if (usrInput == "Thurs"){
            dayNum = 4;
    }
    else if (usrInput == "Fri"){
            dayNum = 5;
    }
    else if (usrInput == "Sat"){
            dayNum = 6;
    }
    else{    
        cout << "!!INVALID INPUT!!\n";
        return -1;
    }
}

//SetDay changes dayNum but ensures that it stays less than 7
void dayType::SetDay(int num){
    num = num % 7;    
    dayNum = num;
}

void dayType::PrintDay(int newDay = -25){
    //If no parameters it will print dayNum
    //-25 is good initialized value because paramaters should be between
    //0 and 6
    if (newDay == -25){
        newDay = dayNum;
    }
   
    switch(newDay) {
        case 0:
            cout << "Sunday\n";
            break;
        case 1:
            cout << "Monday\n";
            break;
        case 2:
            cout << "Tuesday\n";
            break;
        case 3:
            cout << "Wednesday\n";
            break;
        case 4: 
            cout << "Thursday\n";
            break;
        case 5:
            cout << "Friday\n";
            break;
        case 6:
            cout << "Saturday\n";
            break;
        //returns error if invalid day is entered
        default:
            cout << "!!ERROR INVALID DAY!!\n";
    }
}

int dayType::GetDay(){
    return dayNum;
}

int dayType::GetPreviousDay(){
    //need to make new int so dayNum isnt changed directly
    int previousDay = (dayNum - 1) % 7;
    if (previousDay == -1){
        previousDay = 6;
    }
    return previousDay;
}

int dayType::GetNextDay(){
    int nextDay = (dayNum + 1) % 7;
    return nextDay;
}

int dayType::CalcDay(int usrNum){
    int newDay;
    newDay = (dayNum + usrNum) % 7;
    //Sends error if calculated day is less than 0
    if (newDay < 0){
        cout << "!!ERROR!! CALCULATED DAY CANNOT BE NEGATIVE!\n";
        return -1;
    }

    cout << "Day after calculation is ";
    PrintDay(newDay);
    cout <<endl;
    return newDay;
}

void RequestDay(int& dayOfWeek);
void ReqCalcDay(dayType day);

int main(){
    
    int test = 0;
    string dayOfWeek = "";
    dayType day;   

    cout << "This this program scans in the user's input for the name of a day\n";
    cout << "of the week. Then allows the user to perform a variety of operations\n";
    cout << "on the day.\n\n";
    cout << "Please type the name of the day of the week you wish to use ";
    cout << "(Sun = Sunday, Mon = Monday, Tues = Tuesday, Wed = Wednesday, and so on): ";
    cin >> dayOfWeek;    

    //tests if dayOfWeek was valid input if not it kills program
    test = day.SetDayName(dayOfWeek);
    if (test == -1){
        return -1;
    }

    cout << "Set day is "; day.PrintDay();
    cout << "Day before was "; day.PrintDay(day.GetPreviousDay());
    cout << "The day after the set date is "; day.PrintDay(day.GetNextDay());
    cout << endl;
    ReqCalcDay(day);    
}

void ReqCalcDay(dayType day){
    string response = "";
    int usrVal;    

    cout << "Would you like to calculate a new day?(y or n) ";
    cin >> response;

    while (response != "y" && response != "n"){
    cout << "Invalid response! Please enter y or n: ";
    cin >> response;
    }

    if (response == "y"){
        cout << "Please enter value you would like to adjust day by: ";
        cin >> usrVal;
        day.CalcDay(usrVal);
    }
}
