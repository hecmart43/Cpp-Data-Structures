#include <iostream>//std::cout and std::cin
class DivByZero 
{
public:
    static int Quotient(int numerator, int denominator)//Defines the quotient function
    {
        if (denominator == 0) 
        {
            throw DivByZero();
        }
        return numerator / denominator;//Formula for the integer division
    }
};
int main() 
{
    //Below Blokc: The two integers
    int numerator;
    int denominator;
    //Below Block: Prompts for and then read the two inputted integers
    std::cout << "Enter numerator (integer): ";
    std::cin >> numerator;
    std::cout << "Enter denominator (integer): ";
    std::cin >> denominator;
    //Below Block: Try and divide, and catch the exception if it does occur
    try 
    {
        int result = DivByZero::Quotient(numerator, denominator);
        std::cout << "Quotient: " << result << "\n";//Prints integer result
    } catch (const DivByZero& e)//Catches the exception
    {
        std::cout << "Error: attempt to divide by zero. Exiting normally.\n";//Prints error and continues
    }
    return 0;
}