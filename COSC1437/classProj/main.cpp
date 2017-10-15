#include<iostream>
#include<string>
#include"BankingIO.h"
using namespace std;

//Declaring functions from BankingIO.h
int PromptUsr();
void UsrDecision(bankAccount*);

int main(){
    minBalSavingsAccount a;
    UsrDecision(&a);
}

