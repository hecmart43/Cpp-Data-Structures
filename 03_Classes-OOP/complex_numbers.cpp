#include <iostream>//Input/output
#include <sstream>//Stringstream
#include <string>//String handling
class Complex 
{
//Below Block: The private vairables that store the real and imaginary part
private:
    double real;
    double imag;
public:
    //Below Block: Constructor with default values (1,1)
    Complex(double r = 1, double i = 1) 
    {
        real = r;
        imag = i;
    }
    //Below Block: Returns a new complex object that is the sum of two complex numbers
    Complex add(const Complex& other) const 
    {
        return Complex(real + other.real, imag + other.imag);
    }
    //Below Block: Retuyrns the difference of two complex numbers
    Complex subtract(const Complex& other) const 
    {
        return Complex(real - other.real, imag - other.imag);
    }
    //Below Block: Converts the complex number into a string format
    std::string toString() const 
    {
        std::ostringstream output;
        output << "(" << real << "," << imag << ")";
        return output.str();
    }
};
int main() 
{
    //Below Block: Stores user inoput as a string
    std::string input1, input2;
    double r1, i1, r2, i2;
    //Below Block: Prompt user for first complex number
    std::cout << "Enter a Complex number with the real and imaginary parts separated by a comma: ";
    std::getline(std::cin, input1);//Reads the entire line from user
    //Below Block: If input is empty, use default (1,1)
    if (input1.empty()) 
    {
        r1 = 1;
        i1 = 1;
    } 
    else 
    {
        char comma;
        std::stringstream ss(input1);//Parses input
        ss >> r1 >> comma >> i1;
    }
    //Below Block: Prompt user for second complex number
    std::cout << "Enter a Complex number with the real and imaginary parts separated by a comma: ";
    std::getline(std::cin, input2);//Reads the entire line from user
    //Below Block: If input is empty, use default (1,1)
    if (input2.empty()) 
    {
        r2 = 1;
        i2 = 1;
    } else 
    {
        char comma;
        std::stringstream ss(input2);//Parses input
        ss >> r2 >> comma >> i2;
    }
    //Below Block: Create two Complex objects
    Complex c1(r1, i1);
    Complex c2(r2, i2);
    //Below Block: Performs addition and subtraction
    Complex sum = c1.add(c2);
    Complex diff = c1.subtract(c2);
    //Below Block: Prints results
    std::cout << "The sum of the two complex numbers is " << sum.toString()
              << " and the difference is " << diff.toString() << "." << std::endl;

    return 0;
}