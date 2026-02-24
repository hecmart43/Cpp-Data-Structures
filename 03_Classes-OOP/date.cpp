#include <iostream>//For input/output
#include <string>//For month names
// Date class definition
class Date 
{
private:
    int month;//Month number (1-12)
    int day;//Day of the month (01-31)
    int year;//Year
public:
    //Below Block: Constructor to initialize the date
    Date(int m, int d, int y) 
    {
        month = m;
        day = d;
        year = y;
    }
    //Below Block: Function to print date in numeric format
    void print()//Will display the date as mm/dd/yyyy
    {
        std::cout << month << "/" << day << "/" << year << "\n";
    }
    // Function to print date in long format
    void printLong()//Key for the full name of the months 
    {
        std::string monthNames[12] = 
        {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        }
        ;
        if (month >= 1 && month <= 12) 
        {
            std::cout << "The date entered is " 
                      << monthNames[month - 1] << " " 
                      << day << ", " << year << ".\n";
        } 
        else 
        {
            std::cout << "Invalid month.\n";
        }
    }
};

int main() 
{
    int m, d, y;

    // Prompt user for the date
    std::cout << "Enter month (1-12): ";
    std::cin >> m;

    std::cout << "Enter day: ";
    std::cin >> d;

    std::cout << "Enter year: ";
    std::cin >> y;

    // Create Date object with user input
    Date userDate(m, d, y);

    // Output the date in numeric format
    userDate.print();

    // Output the date in long format
    userDate.printLong();

    return 0;
}