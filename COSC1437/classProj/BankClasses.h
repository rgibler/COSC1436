#include<iostream>
#include<array>
#include<random>
#include<fstream>
using namespace std;

ofstream outfile ("proj.txt");
struct LogStream 
{
    template<typename T> LogStream& operator<<(const T& mValue)
    {
        std::cout << mValue;
        outfile << mValue;
    }
};

inline LogStream& lo() { static LogStream l; return l; }

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
        double initialBal;
        bool status;
        double saveBalance;
        double minBalance;
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
    saveBalance -= serviceCharge;
    totalSC += serviceCharge;
}
void savingsAccount::CalcInt(){
    double monthlyInt = saveBalance * (interest / 100);
    intAccrued += monthlyInt;
    saveBalance += monthlyInt;
}
void savingsAccount::DisplayInfo(){
    MonthlyProc();
    lo() << "Savings Account #" << accountNumber << " Monthly Summary #" << month << "\n\n";
    lo() << "Initial balance for the month was $" << initialBal << "\n";
    lo() << "Current Account balance is $" << saveBalance << "\n";
    lo() << "Number of Deposits this month " << depositCount << "\n";
    lo() << "Number of Withdrawals this month " << withdrawalCount << "\n";
    lo() << "Account has aged " << month << " month(s).\n";
    lo() << "Total interest accrued since account creation is $" << intAccrued << "\n";
    lo() << "Total payed in service charges $" << totalSC << "\n";
    lo() << "\n\n";
    month++;
    initialBal = saveBalance;
    depositCount = 0;
    withdrawalCount = 0;
}

void savingsAccount::Deposit(){
    saveBalance += prompt<double>("Please enter an amount to be deposited: $");
    depositCount++;
    if (saveBalance > 25)
        status = true;
}

void savingsAccount::Withdraw(){
    if (saveBalance > minBalance){
        saveBalance -= prompt<double>("Please enter an amount to be withdrawn: $");
    }
    else{
        cout << "Cannot make withdrawals while account balance is below minimum balance!\n\n";
    }
    if (saveBalance < 25){
        status = false;
        cout << "Account is now inactive because the current account balance of $" << saveBalance;
        cout << " is below the minimum balance of $25.\n\n";
    }
    withdrawalCount++;
    if (withdrawalCount > 4)
        serviceCharge = withdrawalCount - 3;
}

savingsAccount::savingsAccount(double amount = 0.0, double monthlyInt = 10, double min = 25){
    initialBal = amount;
    saveBalance = amount;
    minBalance = min;
    status = true;
    depositCount = 0;
    withdrawalCount = 0;
    interest = monthlyInt;
    serviceCharge = 0;
}

class checkingAccount : public bankAccount{
    protected:
        double checkBalance;
        double initialBal;
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
    checkBalance -= (serviceCharge + 0.1 * withdrawalCount);
    totalSC += (serviceCharge + 0.1 * withdrawalCount) ;
}
void checkingAccount::CalcInt(){
    double monthlyInt = checkBalance * (interest / 100);
    intAccrued += monthlyInt;
    checkBalance += monthlyInt;
}
void checkingAccount::DisplayInfo(){
    MonthlyProc();
    lo() << "Checking Account #" << accountNumber << " Monthly Summary #" << month << "\n\n";
    lo() << "Initial Account Balance was $" << initialBal << "\n";
    lo() << "Current Account balance is $" << checkBalance << "\n";
    lo() << "Number of Deposits this month " << depositCount << "\n";
    lo() << "Number of Withdrawals this month " << withdrawalCount << "\n";
    lo() << "Account has aged " << month << " month(s).\n";
    lo() << "Total interest accrued: $" << intAccrued << "\n";
    lo() << "Total paid in service charges: $" << totalSC << "\n";
    lo() << "\n\n";
    month++;
    depositCount = 0;
    withdrawalCount = 0;
    initialBal = checkBalance;
}

void checkingAccount::Deposit(){
    checkBalance += prompt<double>("Please enter an amount to be deposited: $");
    depositCount++;
}

void checkingAccount::Withdraw(){
    double TempBalance = prompt<double>("Please enter an amount to be withdrawn: $");
    if (checkBalance - TempBalance < 0){
        checkBalance -= 25;
    }
    else{
        checkBalance -= TempBalance;
    }
    withdrawalCount++;
}

checkingAccount::checkingAccount(double amount = 0.0, double monthlyInt = 10, double monthlySC = 5){
    initialBal = amount;
    checkBalance = amount;
    depositCount = 0;
    withdrawalCount = 0;
    interest = monthlyInt;
    serviceCharge = monthlySC;
}
