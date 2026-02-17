#include <iostream>//cout
#include <fstream>//for ifstream, ofstream
#include <cctype>//for toupper, isspace
using namespace std;//to use cout and idstram without using std::
int main() 
{
    ifstream infile("input.txt");//opens the input file for reading
    ofstream outfile("output.txt");//opens the output file for writing
    //Below Block: if files fail error message will be printed
    if (!infile || !outfile) 
    {
        cout << "Error opening file.\n";
        return 1;
    }
    char ch;//holds each character from the file
    bool newWord = true;
    while (infile.get(ch))//reads each character and loops until it reaches the end of the file
    { 
         //Below Block: if we hit space/newline/tab, it ends the current word
        if (isspace(ch)) 
        {
            newWord = true;
            outfile.put(ch);
        } 
        else 
        {
            //Below Block: Uppercases the A's
            if (newWord && (ch == 'a' || ch == 'A')) 
            {
                ch = toupper(ch);
            }
            outfile.put(ch);
            newWord = false;
        }
    }
    //Below Block: closes both files
    infile.close();
    outfile.close();
    //Below Block: prints the contents of output.txt for verification
    ifstream result("output.txt");
    cout << "Contents of output.txt:\n";
    while (result.get(ch)) 
    {
        cout << ch;
    }
    result.close();
    return 0;
}