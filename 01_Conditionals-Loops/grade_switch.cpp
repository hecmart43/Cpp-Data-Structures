#include <iostream>//for cin and cout
using namespace std;//avoids having to use std::
//Below Block: allows change to the original vairable in main
void getScore(int& score) 
{
    cout << "Enter your numerical score (0 - 100): ";
    cin >> score;//Prompts suer for input and then stores it
    cout << "You entered score: " << score << endl;
}
//Below Block: Receives scor as value then determine sthe letter grade
void printGrade(int score) 
{
    cout << "Your letter grade is: ";
    
    //Below Block: Convert numerical score to grade range
    switch (score / 10) 
    {
        case 10:
        case 9:
            cout << "A" << endl;
            break;
        case 8:
            cout << "B" << endl;
            break;
        case 7:
            cout << "C" << endl;
            break;
        case 6:
            cout << "D" << endl;
            break;
        default:
            cout << "F" << endl;//Any score below 60 is given F
    }
}
int main() 
{
    //Below Block: Retrieves and prints letter grade from value input
    int score = 0;
    getScore(score);
    printGrade(score);

    return 0;
}