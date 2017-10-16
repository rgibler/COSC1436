#include<iostream>
#include<string>
#include<fstream>
#include"BankingIO.h"
using namespace std;

//Declaring functions from BankingIO.h
int PromptUsr();
void UsrDecision(bankAccount*);

int main(){
    Accounts a;
    UsrDecision(a);
}

