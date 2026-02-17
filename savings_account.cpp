#include <iostream>//Input/output
#include <iomanip>//Formatting output
class SavingsAccount 
{
private:
    double savingsBalance;//Each account's balance
    static double annualInterestRate;//Shared annual interest rate
public:
    //Below Block: Constructor to initialize savings balance
    SavingsAccount(double balance = 0.0) 
    {
        savingsBalance = balance;
    }
    //Below Block: Function to calculate monthly interest
    double calculateMonthlyInterest() const 
    { 
        return (savingsBalance * annualInterestRate) / 12.0;//Formula
    }
    //Below Block: Getter for balance
    double getBalance() const 
    {
        return savingsBalance;
    }
    //Below Block: To change interest rate
    static void modifyInterestRate(double newRate) 
    {
        annualInterestRate = newRate;
    }
};
//Below Block: Changing of blances need to be done outside of class
double SavingsAccount::annualInterestRate = 0.0;
int main() 
{
    double balance1, balance2, rate;//The two vairables
    char choice;//the variable for either y or n
    //Below Block: User input for balances
    std::cout << "Please enter the savings balance of account 1: ";
    std::cin >> balance1;
    std::cout << "Please enter the savings balance of account 2: ";
    std::cin >> balance2;
    //Below Block: Creates the two SavingsAccount objects
    SavingsAccount account1(balance1);
    SavingsAccount account2(balance2);
    //Below Block: User input for interest rate
    std::cout << "Please enter the annual interest rate: ";
    std::cin >> rate;
    //Below Block: Converts user input for interest into a decimal
    SavingsAccount::modifyInterestRate(rate / 100.0);
    //Below Bl;ock: Esnusres there is two decimal places
    std::cout << std::fixed << std::setprecision(2);
    //Below Block: Calculates interest for both accounts
    double interest1 = account1.calculateMonthlyInterest();
    double interest2 = account2.calculateMonthlyInterest();
    //Below Block: How results will be printed
    std::cout << "The interest for account 1 would be $" << interest1
              << " and the balance after one month would be $" << account1.getBalance() + interest1 << "\n";
    std::cout << "The interest for account 2 would be $" << interest2
              << " and the balance after one month would be $" << account2.getBalance() + interest2 << "\n";

    //Below Block: Ask if user wants to change the interest rate
    do 
    {
        //Below Block: User in put y or n
        std::cout << "Would you like to change the interest rate? (Y or N): ";
        std::cin >> choice;
        //Below Block: if y 
        if (choice == 'Y' || choice == 'y') 
        {
            //Below Block: Will prompt user for new interest rate
            std::cout << "Please enter the annual interest rate: ";
            std::cin >> rate;
            SavingsAccount::modifyInterestRate(rate / 100.0);//Updates the static
            //Below Block: Recalculates with new rate
            interest1 = account1.calculateMonthlyInterest();
            interest2 = account2.calculateMonthlyInterest();
            //Below Block: Prints updated results
            std::cout << "The interest for account 1 would be $" << interest1
                      << " and the balance after one month would be $" << account1.getBalance() + interest1 << "\n";
            std::cout << "The interest for account 2 would be $" << interest2
                      << " and the balance after one month would be $" << account2.getBalance() + interest2 << "\n";
        }

    } 
    //Below Block: Again asks again if interest rate needs to be changed and loops until n is input
    while (choice == 'Y' || choice == 'y');
    std::cout << "Goodbye!" << std::endl;//If n it will print goodbye
    return 0;
}