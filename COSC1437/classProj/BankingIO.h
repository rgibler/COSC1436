#include<iostream>
#include<string>
#include"BankClasses.h"
using namespace std;


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

void UsrDecision(bankAccount* account){
    savingsAccount* savingPtr = dynamic_cast<savingsAccount*> (account);
    checkingAccount* checkingPtr = dynamic_cast<checkingAccount*> (account);
    int usrChoice = 0;
    do{
        usrChoice = PromptUsr();
        switch(usrChoice){
        case 1:
            if (savingPtr)
                account -> Deposit();
            else
                cout << "Account not a savings account\n\n";
            break;
        case 2:
            if (checkingPtr)
                account -> Deposit();
            else
                cout << "Account not a checking account\n\n";
            break;
        case 3:
            if (savingPtr)
                account -> Withdraw();
            else
                cout << "Account not a savings account\n\n";
            break;
        case 4:
            if (checkingPtr)
                account -> Withdraw();
            else
                cout << "Account not a checking account\n\n";
            break;
        case 5:
            account -> DisplayInfo();
            break;
        default:
            cout << "Exiting Program...\n";
        }
    }while(usrChoice != 6);
}