#include <iostream>//Printing and reading
#include <vector>//Arrays to hold accounts
#include <memory>//Smart pointers for polymorphic storage/cleanup
#include <iomanip>//Format for money output
class BankAccount 
{
protected:
    double balance;//Current Balance
public:
    //Below Block: Constructor ensures non-negative balance
    explicit BankAccount(double b) : balance(b < 0 ? 0 : b) {}
    virtual ~BankAccount() = default;
    //Below Block: Deposits positive numbers only
    virtual void credit(double x) { if (x >= 0) balance += x; }
    //Below Block: Withdraw function
    virtual bool debit(double x) 
    {
        //Below Block: Subtracts or gives message if invalid or overdrafted
        if (x >= 0 && x <= balance) { balance -= x; return true; }
        std::cout << "Debit amount exceeded account balance.\n";
        return false;
    }
    //Below Block: no interest (Savings overrides this)
    virtual double calculateInterest() const { return 0.0; }
    virtual const char* accountType() const { return "BankAccount"; }
    double getBalance() const { return balance; }//Reads balance
};
class Savings : public BankAccount 
{
    double rate;//Stores interest rate
public:
    //Below Block: Set interest rate
    Savings(double b, double r) : BankAccount(b), rate(r < 0 ? 0 : r) {}
    double calculateInterest() const override { return balance * rate; }
    const char* accountType() const override { return "Savings"; }
};
class Checking : public BankAccount 
{
    double fee;//Transaction fee
public:
    //Below Block: Forward balance
    Checking(double b, double f) : BankAccount(b), fee(f < 0 ? 0 : f) {}
    void credit(double x) override//Override deposit 
    {
        //Belwo Block: Subtracts fee if balance can cover
        if (x >= 0) { BankAccount::credit(x); if (fee <= balance) balance -= fee; }
    }
    bool debit(double x) override//Overrides withdrawel 
    {
        bool ok = BankAccount::debit(x);//Attempts withdrawel
        if (ok && fee <= balance) balance -= fee;//If possible subtracts fee
        return ok;
    }
    const char* accountType() const override { return "Checking"; }
};
int main() 
{
    std::cout << std::fixed << std::setprecision(2);//Two decimal places for currency
    int n;//Number of accounts
    std::cout << "How many accounts? ";//Asks for user input
    std::cin >> n;//Reads the count
    std::vector<std::unique_ptr<BankAccount>> v;
    //Below Block: Creates accounts
    for (int i = 0; i < n; ++i)//Lopp for each account
    {
        char t; double bal;//Type and starting balance
        std::cout << "\nAccount " << (i + 1) << " type (S/C): ";//Asks for account type
        std::cin >> t;//Reads the input
        std::cout << "Starting balance: $";//Asks for the balance
        std::cin >> bal;//Reads the input
        if (t == 'S' || t == 's')//Savings branch 
        {
            double pct;//Interests
            std::cout << "Interest rate (%) per cycle: ";//Asks for interest
            std::cin >> pct;//Reads the input
            v.emplace_back(std::make_unique<Savings>(bal, pct / 100.0));//Creates savings
        } 
        else 
        {
            double fee;//Trasnaction fee
            std::cout << "Transaction fee ($): ";//Asks for the fee
            std::cin >> fee;//Reads the input
            v.emplace_back(std::make_unique<Checking>(bal, fee));//Creates checking
        }
    }
    //Below Block: Loops over accounts
    for (std::size_t i = 0; i < v.size(); ++i) 
    {
        auto& a = v[i];//References to pointer
        std::cout << "\n=== Processing Account " << (i + 1) << " ===\n";//Section header
        std::cout << "Type: " << a->accountType() << "\n";
        std::cout << "Starting balance: $" << a->getBalance() << "\n";
        double w, d;//Withdraw and deposit amount
        std::cout << "Withdraw amount: $"; std::cin >> w;//Asks for withdrawel
        if (a->debit(w)) std::cout << "Withdrew $" << w << "\n";//Reads input
        std::cout << "Deposit amount:  $"; std::cin >> d;//Asks for for deposit
        a->credit(d); std::cout << "Deposited $" << d << "\n";
        double interest = a->calculateInterest();//Computes interest on savings only
        if (interest > 0.0) 
        {
            a->credit(interest);
            std::cout << "Interest credited: $" << interest << "\n";
        }
        //Below Block: Prints updated balance
        std::cout << "Updated balance:  $" << a->getBalance() << "\n";
    }
    std::cout << "\nAll accounts processed. Goodbye!\n";
    return 0;
}
