#include <iostream>//For cin and cout
#include <iomanip>//Manipulators for formatting numbers
class BankAccount 
{
public:
    //Below Block: Constructor for initial balance ensuring its not negative
    explicit BankAccount(double initialBalance)
        : balance{0.0} 
        {
        if (initialBalance >= 0.0) 
        {
            balance = initialBalance;
        } 
        else 
        {
            std::cout << "Invalid initial balance; setting balance to 0.00\n";
        }
    }
    //Below Block: Begins the credit
    void credit(double amount)
    {
        if (amount < 0.0) 
        {
            std::cout << "Cannot credit a negative amount.\n";
            return;
        }
        balance += amount;//adds the deposit to current balance
    }
    //Below Block: The debit portion
    bool debit(double amount) 
    {
        if (amount < 0.0) 
        {
            std::cout << "Cannot debit a negative amount.\n";
            return false;
        }
        if (amount > balance)//Verifies if withdrawel amount is more than balance
        {
            std::cout << "The balance is less than the debit amount.\n";
            return false;//Message for insufficent funds
        }
        balance -= amount;//Subtracts the withdrawel from balance
        return true;
    }
    //Below Block: Retreives Balance
    double getBalance() const 
    { 
        return balance; 
    }
protected:
    double balance;
};
//Below Block: Savings Portion
class Savings : public BankAccount 
{
public:
    Savings(double initialBalance, double interestRatePct)//Constructor with balance and rate
        : BankAccount(initialBalance), rate//Initialize base and rate
        {interestRatePct} {}
    //Below Block: Start of interest calculation
    double calculateInterest() const 
    {
        return balance * (rate / 100.0);//Formula for interest
    }
private:
    double rate;//Interest rate
};
//Below Block: Checking Class
class Checking : public BankAccount 
{
public:
    Checking(double initialBalance, double feePerTxn)//Constructor with balance and fee
        : BankAccount(initialBalance), fee{feePerTxn} {}//Initialize base and fee
    void credit(double amount)//Override deposit 
    {
        double before = balance;//Stores old balance
        BankAccount::credit(amount);
        if (balance != before) 
        {
            subtractFee();//Charge Fee
        }
    }
    bool debit(double amount) 
    {
        if (BankAccount::debit(amount))//Call base withdrawel and check 
        {
            subtractFee();//Charge fee if successful
            return true;
        }
        return false;
    }
private:
    void subtractFee()//Fee helper
    {
        balance -= fee;//Subtract fee
    }
    double fee;//Fee variable
};
int main() 
{
    std::cout.setf(std::ios::fixed);//Decimal formatting
    std::cout << std::setprecision(2);//Two decimal places
    //Below Block: User inputs
    double baseBal, savBal, chkBal, interestRate, fee;//Declares balances, rate, fee
    double debitAmount, creditAmount;//Declares the amount for transactions
    //Below Block: User input for initial
    std::cout << "Enter initial balance for BankAccount: ";
    std::cin >> baseBal;
    //Below Block: User input for initial balance for savings
    std::cout << "Enter initial balance for Savings: ";
    std::cin >> savBal;
    ////Below Block: User input for interest rate
    std::cout << "Enter interest rate (%) for Savings: ";
    std::cin >> interestRate;
    //Below Block: User input for initial balance for checking
    std::cout << "Enter initial balance for Checking: ";
    std::cin >> chkBal;
    //Below Block: User input for tranasction fee
    std::cout << "Enter transaction fee for Checking: ";
    std::cin >> fee;
    //Below Block: User input for debits to all accounts
    std::cout << "Enter amount to debit from all accounts: ";
    std::cin >> debitAmount;
    //Below Block: User input for credits to all accounts
    std::cout << "Enter amount to credit to all accounts: ";
    std::cin >> creditAmount;
    //Below Block: Create accounts
    BankAccount base{baseBal};
    Savings sav{savBal, interestRate};
    Checking chk{chkBal, fee};
    //Below Block: Printed Results for balances
    std::cout << "\nInitial balances:\n";
    std::cout << "  BankAccount: $" << base.getBalance() << '\n';
    std::cout << "  Savings:     $" << sav.getBalance() << '\n';
    std::cout << "  Checking:    $" << chk.getBalance() << "\n\n";
    //Below Block: Printed results for Debits
    std::cout << "Debiting $" << debitAmount << " from each...\n";
    base.debit(debitAmount);
    sav.debit(debitAmount);
    chk.debit(debitAmount);
    std::cout << "\nBalances after debits:\n";
    std::cout << "  BankAccount: $" << base.getBalance() << '\n';
    std::cout << "  Savings:     $" << sav.getBalance() << '\n';
    std::cout << "  Checking:    $" << chk.getBalance() << "\n\n";
    //Below Block: Printed results for Credits
    std::cout << "Crediting $" << creditAmount << " to each...\n";
    base.credit(creditAmount);
    sav.credit(creditAmount);
    chk.credit(creditAmount);
    std::cout << "\nBalances after credits:\n";
    std::cout << "  BankAccount: $" << base.getBalance() << '\n';
    std::cout << "  Savings:     $" << sav.getBalance() << '\n';
    std::cout << "  Checking:    $" << chk.getBalance() << "\n\n";
    //Below Block: Printed results for Interest
    double interest = sav.calculateInterest();
    std::cout << "Savings interest earned: $" << interest << '\n';
    sav.credit(interest);
    std::cout << "Savings new balance:     $" << sav.getBalance() << '\n';
    return 0;
}