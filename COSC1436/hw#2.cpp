/* Robert Gibler COSC 1436-11492
   
   6/10/2017

   Assignment 2 & Program 2
   Program Exercise No. 20 Chapter 2

   This program scans in an hourly wage and hours worked per week from terminal and
   returns total amount of money earned assuming the user works for 5 weeks and also
   prints the amount of money the user invested in clothes school supplies and savings
   bonds.
*/



#include<iostream>
#include <cmath>
using namespace std;

int main() {
   //initializing variables
   double hourlyWage = 0;
   int hoursPerWeek = 0;
   int weeksWorked = 5;
   double totalBeforeTax = 0;
   double totalTaxed = 0;
   double totalAfterTax = 0;
   const double TAX_PERCENT = 0.14;
   double totalSpentClothes = 0;
   double totalSpentSchool = 0;
   const double CLOTHES_PERCENT = 0.10;
   const double SCHOOL_SUPP = 0.01;
   const double SAVINGS_BONDS_PER = 0.25;
   const double PARENT_INVEST_BONDS = 0.5;
   double savingsBonds = 0;
   double parentSavingBonds = 0;
   double totalRemaining = 0;

   //Requesting and scanning in hourly wage and hours per week
   cout << "Enter hourly wage: ";
   cin >> hourlyWage;
   cout << "Enter number of hours worked per week: ";
   cin >> hoursPerWeek;

   //calc total spent on taxes
   totalBeforeTax =  hourlyWage * hoursPerWeek * weeksWorked;
   totalTaxed = totalBeforeTax * TAX_PERCENT;
   totalAfterTax = totalBeforeTax - totalTaxed;
   cout << endl << "You had $" << totalBeforeTax << " before taxes were taken out and you had $"; 
   cout << totalAfterTax << " after taxes.\n";
 
   //total spent on clothes and school supplies
   totalSpentClothes = totalAfterTax * CLOTHES_PERCENT;
   totalSpentSchool = totalAfterTax * SCHOOL_SUPP;
   totalRemaining = totalAfterTax - totalSpentClothes - totalSpentSchool;
   cout << endl << "You spent $" << totalSpentClothes << " on clothes and other accessories,";
   cout << " and you spent $" << totalSpentSchool << " on school supplies\n"; 

   //total you spent on savings bonds
   savingsBonds = totalRemaining * SAVINGS_BONDS_PER;
   //total your parents spent
   parentSavingBonds = floor(savingsBonds) * PARENT_INVEST_BONDS;
   cout << endl << "You spent $" << savingsBonds << " on savings bonds,";
   cout << " and your parents spent $" << parentSavingBonds << " on additional savings bonds for you.\n";
}
