#include <iostream>//For input and output
#include <limits>//For clearing bad input
#include <string>//For storing the decision text
//Below Block: Function to get the borrowing score (reference parameter)
void getScore(int& score) 
{
    while (true) 
    {
        std::cout << "Enter borrowing score (1-5): ";//Prompt for user
        if (std::cin >> score)//Reads user input 
        { 
            //Below Block: If input is an integer
            if (score >= 1 && score <= 5)//Checks the range from 1 to 5 
            {
                std::cout << "Score entered: " << score << "\n";
                return;//Exit if valid
            } 
            //Below Block: Prints error message
            else 
            {
                std::cout << "Invalid score. Please enter a number from 1 to 5.\n";
            }
        } 
        else 
        {
            std::cout << "Invalid input. Please enter an integer from 1 to 5.\n";
            std::cin.clear();//Clears error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Removes bad input from the buffer
        }
    }
}
//Below Block: Based ont he value the one of the following will print
void printDecision(int score) 
{
    std::string assessment;
    switch (score) 
    {
        case 5: assessment = "Provide mortgage at 5% interest rate"; break;
        case 4: assessment = "Provide mortgage at 6% interest rate"; break;
        case 3: assessment = "Provide mortgage at 7% interest rate"; break;
        case 2:
        case 1: assessment = "Do not provide mortgage"; break;
        default: assessment = "Unknown assessment";
    }
    //Below Block: Prints from the following
    std::cout << "The entered borrowing score of " << score
              << " is considered to be " << assessment
              << " for the current loan application.\n";
}
int main() 
{
    int score{};//Declares and initializes score to 0
    getScore(score);//Calls function, passing score by reference
    printDecision(score);//Calls the function, passing score by value
    return 0;//Ends program
}