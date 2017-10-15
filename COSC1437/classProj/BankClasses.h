#include<iostream>
#include<array>
#include<random>
using namespace std;

template <class T>
T prompt(string msg) {
    T result;
    cout << msg << " ";
    cin >> result;
    return result;
}

class bankAccount{
    protected:
        int accountNumber;
        int depositCount;
        int withdrawalCount;
        int month;
        double intAccrued;
        double totalSC;
    public:
        virtual void DisplayInfo() = 0;
        virtual void CalcInt() = 0;
        virtual void MonthlyProc() = 0;
        virtual void Deposit() = 0;
        virtual void Withdraw() = 0;
        bankAccount();
};

bankAccount::bankAccount(){
    depositCount = 0;
    intAccrued = 0;
    totalSC = 0;
    withdrawalCount = 0;
    month = 1;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1000000,9999999);
    accountNumber = distribution(generator);
}

class savingsAccount : public bankAccount{
    protected:
        double balance;
        int depositCount;
        double interest;
        double serviceCharge;
        int withdrawalCount;
    public:
        void DisplayInfo() override;
        void CalcInt() override;
        void MonthlyProc() override;
        void Deposit() override;
        void Withdraw() override;
        savingsAccount(double amount, double monthlyInt, double monthlySC);
};

void savingsAccount::MonthlyProc(){
    CalcInt();
    balance -= serviceCharge;
    totalSC += serviceCharge;
}
void savingsAccount::CalcInt(){
    double monthlyInt = balance * (interest / 100);
    intAccrued += monthlyInt;
    balance += monthlyInt;
}
void savingsAccount::DisplayInfo(){
    MonthlyProc();
    cout << "Savings Account #" << accountNumber << " Banking Summary\n\n";
    cout << "Current Account balance is $" << balance << "\n";
    cout << "Number of Deposits this month " << depositCount << "\n";
    cout << "Number of Withdrawals this month " << withdrawalCount << "\n";
    cout << "Account has aged " << month << " month(s).\n";
    cout << "Total interest accrued since account creation is $" << intAccrued << "\n";
    cout << "Total payed in service charges $" << totalSC << "\n";
    cout << "\n\n";
    month++;
    depositCount = 0;
    withdrawalCount = 0;
}

void savingsAccount::Deposit(){
    balance += prompt<double>("Please enter an amount to be deposited: $");
    depositCount++;
}

void savingsAccount::Withdraw(){
    balance -= prompt<double>("Please enter an amount to be withdrawn: $");
    withdrawalCount++;
}

savingsAccount::savingsAccount(double amount = 0.0, double monthlyInt = 10, double monthlySC = 50){
    balance = amount;
    depositCount = 0;
    withdrawalCount = 0;
    interest = monthlyInt;
    serviceCharge = monthlySC;
}

class minBalSavingsAccount : public savingsAccount{
    protected:
        double minBalance;
    public:
        void Withdraw() override;
        minBalSavingsAccount(double min);
};

void minBalSavingsAccount::Withdraw(){
    if (balance > minBalance){
        balance -= prompt<double>("Please enter an amount to be withdrawn: $");
    }
    else{
        cout << "Cannot make withdrawals while account balance is below minimum balance!\n\n";
    }
}
minBalSavingsAccount::minBalSavingsAccount(double min = 25){
    minBalance = min;
}

class checkingAccount : public bankAccount{
    protected:
        double balance;
        int depositCount;
        int withdrawalCount;
        double interest;
        double serviceCharge;
    public:
        void DisplayInfo() override;
        void CalcInt() override;
        void MonthlyProc() override;
        void Deposit() override;
        void Withdraw() override;
        checkingAccount(double amount, double monthlyInt, double monthlySC);
};

void checkingAccount::MonthlyProc(){
    CalcInt();
    balance -= serviceCharge;
    totalSC += serviceCharge;
}
void checkingAccount::CalcInt(){
    double monthlyInt = balance * (interest / 100);
    intAccrued += monthlyInt;
    balance += monthlyInt;
}
void checkingAccount::DisplayInfo(){
    cout << "Checking Account #" << accountNumber << " Banking Summary\n\n";
    cout << "Current Account balance is $" << balance << "\n";
    cout << "Number of Deposits this month " << depositCount << "\n";
    cout << "Number of Withdrawals this month " << withdrawalCount << "\n";
    cout << "Account has aged " << month << " month(s).\n";
    cout << "Total interest accrued: $" << intAccrued << "\n";
    cout << "Total paid in service charges: $" << totalSC << "\n";
    cout << "\n\n";
    month++;
    depositCount = 0;
    withdrawalCount = 0;
}

void checkingAccount::Deposit(){
    balance += prompt<double>("Please enter an amount to be deposited: $");
    depositCount++;
}

void checkingAccount::Withdraw(){
    balance -= prompt<double>("Please enter an amount to be withdrawn: $");
    withdrawalCount++;
}

checkingAccount::checkingAccount(double amount = 0.0, double monthlyInt = 10, double monthlySC = 50){
    balance = amount;
    depositCount = 0;
    withdrawalCount = 0;
    interest = monthlyInt;
    serviceCharge = monthlySC;
}