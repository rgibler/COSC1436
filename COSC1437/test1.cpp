/*Robert Gibler COSC1437 9/24/2017
*
* This program is an attempt to solve the problem posed for the programming
* portion of test1. In this program a tree of inheritance is created for a variety of
* different types of bank accounts.
*/

#include <array>
#include<iostream>
#include<string>
using namespace std;

//Setting arbitrary limit on number of checks
const int CHECK_LIMIT = 3;

//Base class
class bankAccount{
    protected:
        string name;
        int accountNumber;
        double balance;
    public:
        void SetName();
        void SetAccountNum();
        void SetBalance();
        //Creating Virtual functions
        virtual void PrintDetails() const;
        virtual void Setup();
        bankAccount();
};

void bankAccount::Setup(){
    cout << "Setting up Bank Account...\n";
    SetName();
    SetAccountNum();
    SetBalance();
}    

void bankAccount::SetName(){
    cout << "Enter a name for the account: ";
    cin >> name;
}

void bankAccount::SetAccountNum(){
    cout << "Enter a number for the account: ";
    cin >> accountNumber;
}
void bankAccount::SetBalance(){
    cout << "Enter a balance for the Account: ";
    cin >> balance;
}

void bankAccount::PrintDetails() const{
    cout << "The name on your account is " << name << endl;
    cout << "Your account number is " << accountNumber << endl;
    cout << "Your current balance is $" << balance << endl;
}

bankAccount::bankAccount(){
    name = "";
    accountNumber = 0;
    balance = 0;    
}

//Derived class a type of bank account
class checkingAccount : public bankAccount{
    protected:
        string personReceiving;
        double amountSent;
        int checksWritten;
    public:
        void WriteCheck();
        checkingAccount();
        //Overwrites PrintDetails and Setups definition in root class
        void PrintDetails() const override;
        void Setup() override;
};

void checkingAccount::Setup(){
    cout << "Setting up Checking Account...\n";
    SetName();
    SetAccountNum();
    SetBalance();
    cout << "Writing Check...\n";
    WriteCheck();
    PrintDetails();
}

void checkingAccount::PrintDetails() const{
    cout << "The name on your account is " << name << endl;
    cout << "Your account number is " << accountNumber << endl;
    cout << "Your current balance is $" << balance << endl;
    cout << "The person receiving the check is " << personReceiving << endl;
    cout << "The amount sent was $" << amountSent << endl;
}

void checkingAccount::WriteCheck(){
    cout << "***** Writing out Check*****\n";
    if (checksWritten <= CHECK_LIMIT){
        cout << "Enter name of person the check is for: ";
        cin >> personReceiving;
        cout << "Enter amount to be sent: ";
        cin >> amountSent;
        checksWritten++;
    }
    else{
        cout << "!!Error!! Maximum number of checks for this month reached!";
    }
}

checkingAccount::checkingAccount(){
    personReceiving = "";
    amountSent = 0;
    checksWritten = 0;
}

//inherits checking account members
class serviceChargeChecking : public checkingAccount{
    protected:
        double serviceCharge;
    public:
        void SetServiceCharge();
        serviceChargeChecking();
        void PrintDetails() const override;
        void Setup() override;
};

void serviceChargeChecking::PrintDetails() const{
    cout << "The name on your account is " << name << endl;
    cout << "Your account number is " << accountNumber << endl;
    cout << "Your current balance is $" << balance << endl;
    cout << "Your service charge is $" << serviceCharge << endl;
}


void serviceChargeChecking::Setup(){
    cout << "Setting up Service Charge Checking Account...\n";
    SetName();
    SetAccountNum();
    SetBalance();
    SetServiceCharge();
}  

void serviceChargeChecking::SetServiceCharge(){
    cout << "Enter value for service charge (float): ";
    cin >> serviceCharge;
}

serviceChargeChecking::serviceChargeChecking(){
    serviceCharge = 0;
}
    
class noServiceChargeChecking : public checkingAccount{
    protected:
        double interest;
        double minBalance;
    public:
        void SetInterest();
        void SetMinBalance();
        void SetBalance();
        void Setup() override;
        void PrintDetails() const override;
        noServiceChargeChecking();
};

void noServiceChargeChecking::PrintDetails() const{
    cout << "The name on your account is " << name << endl;
    cout << "Your account number is " << accountNumber << endl;
    cout << "Your minimum balance is set to $" << minBalance << endl;
    cout << "Your interest rate is set to " << interest << endl;
    cout << "Your current balance is $" << balance << endl;
}


void noServiceChargeChecking::Setup(){
    cout << "Setting up No Service Change Checking Account...\n";
    SetName();
    SetAccountNum();
    SetInterest();
    SetMinBalance();
    SetBalance();
}  

void noServiceChargeChecking::SetInterest(){
    cout << "Please enter a value for your interest rate: ";
    cin >> interest;
}

void noServiceChargeChecking::SetMinBalance(){
    cout << "Set the minimum balance for this type of account: ";
    cin >> minBalance;
}

void noServiceChargeChecking::SetBalance(){
    cout << "Enter a balance for the account: ";
    cin >> balance;
    while (balance < minBalance){
        cout << "The account balance must be greater than or equal\n";
        cout << "to the minimum account balance for this account type!\n";
        cout << "Re-enter balance: ";
        cin >> balance;
    }
}

noServiceChargeChecking::noServiceChargeChecking(){
    minBalance = 0;
    interest = 0;
}

    
class highInterestChecking : public noServiceChargeChecking{
    protected:
        double hiInterest;
        double hiMinBalance;
    public:
        void SetInterest();
        void SetMinBalance();
        void Setup() override;
        highInterestChecking();
};

void highInterestChecking::Setup(){
    cout << "Setting up High Interest Checking Account...\n";
    SetName();
    SetAccountNum();
    SetInterest();
    SetMinBalance();
    SetBalance();
}


void highInterestChecking::SetInterest(){
    cout << "Enter an interest rate for the account: ";
    cin >> hiInterest;
    //I need this interest rate to be higher than that of a normal checking account
    //but i am unsure how to have this function check for correctness
    while (hiInterest <= interest){
        cout << "Error interest rate must be higher than that of a ";
        cout << "normal checking account!\n";
        cout << "Re-enter interest rate: ";
        cin >> hiInterest;
    }
    interest = hiInterest;
}
       
void highInterestChecking::SetMinBalance(){
    cout << "Enter a minimum balance for the account: ";
    cin >> hiMinBalance;
    while (hiMinBalance <= minBalance){
        cout << "Error minimum balance must be higher than that of a ";
        cout << "normal checking account!\n";
        cout << "Re-enter minimum balance: ";
        cin >> hiMinBalance;
    } 
    minBalance = hiMinBalance;  
}

highInterestChecking::highInterestChecking(){
    hiMinBalance = 0;
    hiInterest = 0;
}

class savingsAccount : public bankAccount{
    protected:
        double interest;
    public:
        void SetInterest();
        void Setup() override;
        void PrintDetails() const override;
        savingsAccount();
};

void savingsAccount::PrintDetails() const{
    cout << "The name on your account is " << name << endl;
    cout << "Your account number is " << accountNumber << endl;
    cout << "Your interest rate is set to " << interest << endl;
    cout << "Your current balance is $" << balance << endl;
}


void savingsAccount::Setup(){
    cout << "Setting up Savings Account...\n";
    SetName();
    SetAccountNum();
    SetInterest();
    SetBalance();
}


void savingsAccount::SetInterest(){
    cout << "Enter an interest rate for this account: ";
    cin >> interest;
}

savingsAccount::savingsAccount(){
    interest = 0;
}

class highInterestSavings : public savingsAccount{
    protected:
        double minBalance;
        double hiInterest;
    public:
        void SetMinBalance();
        void SetBalance();
        void SetInterest();
        void PrintDetails() const override;
        void Setup() override;
        highInterestSavings();
};

void highInterestSavings::PrintDetails() const{
    cout << "The name on your account is " << name << endl;
    cout << "Your account number is " << accountNumber << endl;
    cout << "Your interest rate is set to " << hiInterest << endl;
    cout << "Your minimum balance is set to $" << minBalance << endl;
    cout << "Your current balance is $" << balance << endl;
}


void highInterestSavings::Setup(){
    cout << "Setting up High Interest Savings Account...\n";
    SetName();
    SetAccountNum();
    SetInterest();
    SetMinBalance();
    SetBalance();
}


highInterestSavings::highInterestSavings(){
    minBalance = 0;
    hiInterest = 0;
}

void highInterestSavings::SetMinBalance(){
    cout << "Set a minimum balance for this account: ";
    cin >> minBalance;
}

void highInterestSavings::SetBalance(){
    cout << "Enter a balance for the account: ";
    cin >> balance;
    while (balance < minBalance){
        cout << "Error balance must be greater than minumum balance for account type!\n";
    cout << "Re-enter account balance: ";
    cin >> balance;
    }
}

void highInterestSavings::SetInterest(){
    cout << "Enter an interest rate for this account: ";
    cin >> hiInterest;
    while (hiInterest <= interest){
        cout << "Error minimum balance must be higher than that of a ";
        cout << "normal savings account\n";
        cout << "Please re enter interest rate: ";
        cin >> hiInterest;
    }
}
        
        
class certificateOfDeposit : public bankAccount{
    protected:
        double interest;
        int monthsOfMaturity;
        int currentMonth;
    public:
        void SetInterest();
        void SetCurrentMonth();
        void SetMonthsOfMaturity();
        void Setup() override;
        void PrintDetails() const override;
        certificateOfDeposit();
};

void certificateOfDeposit::Setup(){
    cout << "Setting up Certificate of Deposit...\n";
    SetName();
    SetAccountNum();
    SetBalance();
    SetInterest();
    SetCurrentMonth();
    SetMonthsOfMaturity();
}


void certificateOfDeposit::PrintDetails() const{
    cout << "Interest is " << interest << endl;
    cout << "Current month is " << currentMonth << endl;
    cout << "Months of maturity is " << monthsOfMaturity << endl;
}

certificateOfDeposit::certificateOfDeposit(){
    interest = 0;
    monthsOfMaturity = 0;
    currentMonth = 0;
}

void certificateOfDeposit::SetInterest(){
    cout << "Enter an interest rate for the account: ";
    cin >> interest;
}

void certificateOfDeposit::SetCurrentMonth(){
    cout << "Enter a numerical value for the current month (1 = January, 12 = December): ";
    cin >> currentMonth;
    while (currentMonth < 1 || currentMonth > 12){
        cout << "Invalid value for current month. Please re-enter (1-12 only): ";
        cin >> currentMonth;
    }
}

void certificateOfDeposit::SetMonthsOfMaturity(){
    cout << "Enter the number of months since the certificate of deposit was created: ";
    cin >> monthsOfMaturity;
}

int main(){
    //Declaring test variables of different classes
    bankAccount b1;
    checkingAccount b2;
    highInterestChecking b3;
    highInterestSavings b4;
    certificateOfDeposit b5;

    //creates an array of pointers which point to addresses of the test variables
    array<bankAccount*, 5> accounts { &b1, &b2, &b3, &b4, &b5};
    //loops through array and points to specific functions facilitates use of virtual functions
    for (bankAccount* account : accounts) {
        //accesses member functions of account
        account->Setup();
        account->PrintDetails();
        cout << endl; 
    }
}

