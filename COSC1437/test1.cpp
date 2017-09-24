/*Robert Gibler COSC1437 9/24/2017
*
* This program is an attempt to solve the problem posed for the programming
* portion of test1. In this program a tree of inheritance is created for a variety of
* different types of bank accounts.
*/


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
        void PrintDetails();
        bankAccount();
};

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

void bankAccount::PrintDetails(){
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
        void PrintDetails();
};

//I think I might be doing something weird with my virtual functions...
//let me know if there are any glaring issues
void checkingAccount::PrintDetails(){
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
};

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
        noServiceChargeChecking();
};

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
        highInterestChecking();
};


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
        savingsAccount();
};

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
        highInterestSavings();
};

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
        void PrintDetails();
        certificateOfDeposit();
};

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

//Test function prototypes
void TestBankAccount();
void TestCheckingAccount();
void TestHighInterestChecking();
void TestCertificateOfDeposit();
void TestHighInterestSavings();

int main(){

    TestBankAccount();
    TestCheckingAccount();
    TestHighInterestChecking();
    TestHighInterestSavings();
    TestCertificateOfDeposit();
}

void TestBankAccount(){
    bankAccount testBank;
    cout << "***Testing Bank Account Class***\n";
    testBank.SetName();
    testBank.SetAccountNum();
    testBank.SetBalance();
    testBank.PrintDetails();
    cout << endl;
}

void TestCheckingAccount(){
    checkingAccount testChecking;
    cout << "***Testing Checking Account Class***\n";
    testChecking.SetName();
    testChecking.SetAccountNum();
    testChecking.SetBalance();
    testChecking.WriteCheck();
    testChecking.PrintDetails();
    cout << endl;
}

void TestHighInterestChecking(){
    highInterestChecking testHighInterest;
    cout << "***Testing High Interest Checking Account***\n";
    testHighInterest.SetName();
    testHighInterest.SetAccountNum();
    testHighInterest.SetMinBalance();
    testHighInterest.SetBalance();
    testHighInterest.WriteCheck();
    testHighInterest.PrintDetails();
    cout << endl;
}

void TestHighInterestSavings(){
    highInterestSavings testHiSavings;
    cout << "***Testing High Interest Savings***\n";
    testHiSavings.SetName();
    testHiSavings.SetAccountNum();
    testHiSavings.SetMinBalance();
    testHiSavings.SetBalance();
    testHiSavings.SetInterest();
    testHiSavings.PrintDetails();
    cout << endl;
}

void TestCertificateOfDeposit(){
    certificateOfDeposit testCert;
    cout << "***Testing Certificate of Deposit***\n";
    testCert.SetName();
    testCert.SetAccountNum();
    testCert.SetBalance();
    testCert.SetInterest();
    testCert.SetCurrentMonth();
    testCert.SetMonthsOfMaturity();
    testCert.PrintDetails();
    cout << endl;
}
