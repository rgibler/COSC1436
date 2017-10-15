/*Robert Gibler COSC1437 9/24/2017
*
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
//Needs to be purely abstract
class bankAccount{
    protected:
        string name;
        int accountNumber;
        double balance;
    public:
        virtual void SetName() = 0;
        virtual void SetAccountNum() = 0;
        virtual void SetBalance() = 0;
        virtual void Deposit() = 0;
        virtual void Withdraw() = 0;
        virtual void PrintDetails() = 0;
        virtual void Setup() = 0;
};


//Derived class a type of bank account
//Also needs to be purely abstract
class checkingAccount : public bankAccount{
    protected:
        string personReceiving;
        double amountSent;
        int checksWritten;
    public:
        virtual void WriteCheck() = 0;
};

//inherits checking account members
class serviceChargeChecking : public checkingAccount{
    protected:
        double serviceCharge;
    public:
        void SetServiceCharge();
        serviceChargeChecking();
        void SetName() override;
        void SetAccountNum() override;
        void SetBalance() override;
        void Deposit() override;
        void Withdraw() override;
        void WriteCheck() override;
        void PrintDetails();
        void Setup();
};

void serviceChargeChecking::SetName(){
    cout << "Enter a name for the account: ";
    cin >> name;
}

void serviceChargeChecking::SetAccountNum(){
    cout << "Enter a number for the account: ";
    cin >> accountNumber;
}

void serviceChargeChecking::SetBalance(){
    cout << "Enter a balance for the Account: ";
    cin >> balance;
}

void serviceChargeChecking::Deposit(){
    double money;
    cout << "Enter amount to be deposited into account: $";
    cin >> money;
    balance += money;
    cout << "New account balance is $" << balance << endl;
}

void serviceChargeChecking::Withdraw(){
    double money;
    cout << "Enter amount to be withdrawn: $";
    cin >> money;
    balance -= money;
    cout << "New Balance is $" << balance << endl;
}

void serviceChargeChecking::PrintDetails(){
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

void serviceChargeChecking::WriteCheck(){
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


serviceChargeChecking::serviceChargeChecking(){
    serviceCharge = 0;
}
    
class noServiceChargeChecking : public checkingAccount{
    protected:
        double interest;
        double minBalance;
    public:
        void SetName() override;
        void SetAccountNum() override;
        void SetInterest();
        void SetMinBalance();
        void Deposit() override;
        void Withdraw() override;
        void SetBalance() override;
        void WriteCheck() override;
        void Setup() override;
        void PrintDetails();
        noServiceChargeChecking();
};

void noServiceChargeChecking::SetName(){
    cout << "Enter a name for the account: ";
    cin >> name;
}

void noServiceChargeChecking::SetAccountNum(){
    cout << "Enter a number for the account: ";
    cin >> accountNumber;
}

void noServiceChargeChecking::Deposit(){
    double money;
    cout << "Enter amount to be deposited into account: $";
    cin >> money;
    balance += money;
    cout << "New account balance is $" << balance << endl;
}

void noServiceChargeChecking::Withdraw(){
    double money;
    cout << "Enter amount to be withdrawn: $"; 
    cin >> money;
    balance -= money;
    cout << "New Balance is $" << balance << endl;
}


void noServiceChargeChecking::WriteCheck(){
    cout << "***** Writing out Check*****\n";
        cout << "Enter name of person the check is for: ";
        cin >> personReceiving;
        cout << "Enter amount to be sent: ";
        cin >> amountSent;
        checksWritten++;
}


void noServiceChargeChecking::PrintDetails(){
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
        void SetName() override;
        void SetAccountNum() override;
        void SetBalance() override;
        void Deposit() override;
        void Withdraw() override;
        void SetInterest();
        void Setup() override;
        void PrintDetails() override;
        savingsAccount();
};

void savingsAccount::SetName(){
    cout << "Enter a name for the account: ";
    cin >> name;
}

void savingsAccount::SetAccountNum(){
    cout << "Enter a number for the account: ";
    cin >> accountNumber;
}

void savingsAccount::SetBalance(){
    cout << "Enter a balance for the Account: ";
    cin >> balance;
}

void savingsAccount::Deposit(){
    double money;
    cout << "Enter amount to be deposited into account: $";
    cin >> money;
    balance += money;
    cout << "New account balance is $" << balance << endl;
}

void savingsAccount::Withdraw(){
    double money;
    cout << "Enter amount to be withdrawn: $"; 
    cin >> money;
    balance -= money;
    cout << "New Balance is $" << balance << endl;
}


void savingsAccount::PrintDetails(){
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
        void SetBalance() override;
        void SetInterest();
        void PrintDetails();
        void Setup() override;
        highInterestSavings();
};

void highInterestSavings::PrintDetails(){
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
        void SetName();
        void SetAccountNum();
        void SetBalance();
        void Deposit() override;
        void Withdraw() override;
        void SetInterest();
        void SetCurrentMonth();
        void SetMonthsOfMaturity();
        void Setup() override;
        void PrintDetails();
        certificateOfDeposit();
};

void certificateOfDeposit::SetName(){
    cout << "Enter a name for the account: ";
    cin >> name;
}

void certificateOfDeposit::SetAccountNum(){
    cout << "Enter a number for the account: ";
    cin >> accountNumber;
}

void certificateOfDeposit::SetBalance(){
    cout << "Enter a balance for the Account: ";
    cin >> balance;
}

void certificateOfDeposit::Deposit(){
    double money;
    cout << "Enter amount to be deposited into account: $";
    cin >> money;
    balance += money;
    cout << "New account balance is $" << balance << endl;
}

void certificateOfDeposit::Withdraw(){
    double money;
    cout << "Enter amount to be withdrawn: $"; 
    cin >> money;
    balance -= money;
    cout << "New Balance is $" << balance << endl;
}


void certificateOfDeposit::Setup(){
    cout << "Setting up Certificate of Deposit...\n";
    SetName();
    SetAccountNum();
    SetBalance();
    SetInterest();
    SetCurrentMonth();
    SetMonthsOfMaturity();
}


void certificateOfDeposit::PrintDetails(){
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
    savingsAccount b1;
    noServiceChargeChecking b2;
    serviceChargeChecking b3;
    highInterestChecking b4;
    highInterestSavings b5;
    certificateOfDeposit b6;

    //creates an array of pointers which point to addresses of the test variables
    array<bankAccount*, 6> accounts { &b1, &b2, &b3, &b4, &b5, &b6};
    //loops through array and points to specific functions facilitates use of virtual functions
    for (bankAccount* account : accounts) {
        //accesses member functions of account
        account->Setup();
        account->Deposit();
        account->Withdraw();
        account->PrintDetails();
        cout << endl; 
    }
}

