#include <iostream>//For cout
using namespace std;//using cout without using std::
//Below Block: Declares the function that has three arrays, computes the sum and then stores it
void addArrays(const int first[], const int second[], int sum[], int size) 
{
    for (int i = 0; i < size; ++i)//The loop that goes through each array 
    {
        sum[i] = first[i] + second[i];//Adds arrays 1 and 2 and stores it in 3
    }
}
int main() 
{
    const int SIZE = 20;//Size of arrays
    //Below Block: Declares the three arrays
    int array1[SIZE];//First array
    int array2[SIZE];//Second array
    int array3[SIZE];//Third array
    for (int i = 0; i < SIZE; ++i)//loop that initializes arrays 1 and 2 
    {
        array1[i] = i + 1;//Array 1 values from 1 to 20
        array2[i] = (i + 1) * 2;//Array 2 values, even Values
    }
    //Below Block: Call the function to compute the sum array for array 3
    addArrays(array1, array2, array3, SIZE);
    //Below Block: Prints the results
    cout << "Array 1 + Array 2 = Array 3" << endl;//Prints header line
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << array1[i] << " + " << array2[i] << " = " << array3[i] << endl;
    }
    return 0;
}