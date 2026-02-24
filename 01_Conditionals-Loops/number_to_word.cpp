#include <iostream>//For cin and cout
using namespace std;//Cin and cout without writing std::
//Below Block: Takes a numerical number and gives its alphatized version
void printNumberWord(int number) 
{
    if (number == 1)//Checks if the user entered 1 
    {
        cout << "You entered the number one." << endl;//Prints one
    } else if (number == 2)//If not one checks if it is two 
    {
        cout << "You entered the number two." << endl;//Prints two
    } else if (number == 3)//If not two checks if it is three 
    {
        cout << "You entered the number three." << endl;//Prints three
    } else if (number == 4)//If not three checks if it four
    {
        cout << "You entered the number four." << endl;//Prints four
    } else if (number == 5)//If not four checks if it is five 
    {
        cout << "You entered the number five." << endl;//Prints five
    } else 
    {
        //Below Block: Prints if input is out of range
        cout << "Invalid number. Please enter a number between 1 and 5." << endl;
    }
}
int main() 
{
    int input;// Variable to store user input
    cout << "Enter a number in the range 1 and 5: ";//Prompts user for input
    cin >> input;//Reads user input
    // Call the function and pass the number entered
    printNumberWord(input);//passes ther entered number to the function
    return 0; // End of program
}