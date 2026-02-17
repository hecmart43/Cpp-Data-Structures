#include <iostream>//For cin and cout
using namespace std;//For cout and cin without std::
//Below Block: Finds the largest number in the array
double larger(double numbers[], int size) 
{
    double max = numbers[0];//Initializes the first number as the max
    for (int i = 1; i < size; i++)//Loops through the array startring at 1 
    {
        if (numbers[i] > max)//Checks if current number is larger than max 
        {
            max = numbers[i];//If current number is larger it updates the max
        }
    }
    return max;//Returns the largest found
}
//Below Block: Finds the smallest number in the array
double smaller(double numbers[], int size)//Declares a function named smaller 
{
    double min = numbers[0];//Intializes the first number as the min
    for (int i = 1; i < size; i++)//Loops through the array startring at 1 
    {
        if (numbers[i] < min)//Checsks if current number is smalle than min 
        {
            min = numbers[i];//If current number is smaller it updates the min
        }
    }
    return min;//Returns the smallest found
}
int main()//Main entry point of the program 
{
    const int SIZE = 15;//Number of inputs required
    double numbers[SIZE];//Array to store all 15 numbers
    cout << "Enter 15 numbers one at a time:" << endl;//Prompts for 15 inputs
    for (int i = 0; i < SIZE; i++)//Begins a loop 
    {
        cin >> numbers[i];//Store each number in the array
    }
    double maxNumber = larger(numbers, SIZE);//Calls the larger function and stores the result
    double minNumber = smaller(numbers, SIZE);//Calls the smaller number and stores the result
    //Below Block: Display the results
    cout << "The largest number is " << maxNumber << endl;//Prints largest number
    cout << "The smallest number is " << minNumber << endl;//Prints the smaller number
    return 0;//End of program
}