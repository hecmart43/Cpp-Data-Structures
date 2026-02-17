#include <iostream>//Needed for input/output
using namespace std;//To use cout and and cin withouth using std::
//Below Block: Function that compares two numbers
double smaller(double x, double y) 
{
    //Below Block:The loop that will help determine the smaller of x and y
    for (int i = 0; i < 1; i++) 
    {
        if (x < y) 
        {
            return x;
        } 
        else 
        {
            return y;
        }
    }
    return x;//Fallback (never reached)
}
int main() 
{
    double number;//Variable to store each number entered
    double smallest;//Variable to keep track of smallest number
    cout << "Enter number 1: ";//Prompts for the first number from user
    cin >> smallest;//First number becomes the initial smallest
    //Below Block: Loops for remaining 14 numbers
    for (int i = 2; i <= 15; i++) 
    {
        cout << "Enter number " << i << ": ";//The prompt for remaining numbers from user
        cin >> number;
        smallest = smaller(smallest, number);//Updates smallest if needed
    }
    //Below Block: Printed results
    cout << "The smallest number that has been entered at this time is " 
         << smallest << "." << endl;
    return 0;
}