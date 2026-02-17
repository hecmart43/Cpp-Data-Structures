#include <iostream>//cout, cin
using namespace std;//use cout and cin without std::

//Below Block: template name
template <typename T>
T my_min(T a, T b) 
{
    if (a < b)
        return a;//if a is smaller returns with a as an answer
    else if (b < a)
        return b;//if b is smaller returns with b as an answer
    else
        return a;//if equal, just returns with a
}

int main() 
{
    //Below Block: Prompts the user for two numbers/ reads them/ if input is letter it will print and exit
    cout << "Enter two integers separated by a space: ";
    int a, b;
    if (!(cin >> a >> b)) 
    {
        cout << "Invalid input.\n";
        return 1;
    }
    int result = my_min(a, b);//calls for the template
    //Below Block: if numbers are equal it print that if not it will print the smaller
    if (a == b) 
    {
        cout << "Both numbers are equal. Returning " << result << endl;
    } 
    else 
    {
        cout << "The smaller value is: " << result << endl;
    }
    return 0;
}