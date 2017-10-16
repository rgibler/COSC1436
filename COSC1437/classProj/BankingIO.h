#include<iostream>
#include<string>
#include"BankClasses.h"
using namespace std;

struct Accounts{
    savingsAccount saveAccount;
    checkingAccount checkAccount;
    void DisplayAccountDeets();
};

void Accounts::DisplayAccountDeets(){
    saveAccount.DisplayInfo();
    checkAccount.DisplayInfo();
}

int PromptUsr(){
    cout << "******** BANK ACCOUNT MENU ********\n\n\n";
    cout << "1. Savings Account Deposit\n";
    cout << "2. Checking Account Deposit\n";
    cout << "3. Savings Account Withdrawal\n";
    cout << "4. Checking Account Withdrawal\n";
    cout << "5. Update and Display Account Details\n";
    cout << "6. Exit\n\n";
    auto usrChoice = prompt<int>("Please select your desired operation (1-6): ");
    while(usrChoice < 1 || usrChoice > 6){
        usrChoice = prompt<int>("Invalid input! Please enter a value between 1 and 6: ");
    }
    cout << endl;
    return usrChoice;
}

void UsrDecision(Accounts account){
    int usrChoice = 0;
    do{
        usrChoice = PromptUsr();
        switch(usrChoice){
        case 1:
                account.saveAccount.Deposit();
            break;
        case 2:
                account.checkAccount.Deposit();
            break;
        case 3:
                account.saveAccount.Withdraw();
            break;
        case 4:
                account.checkAccount.Withdraw();
            break;
        case 5:
            account.DisplayAccountDeets();
            break;
        default:
            cout << "Exiting Program...\n";
        }
    }while(usrChoice != 6);
}