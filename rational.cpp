#include <iostream>//For input/output
#include <string>//For string type and to_string()
#include <numeric>//For std::gcd
using namespace std;
class Rational 
{
//Below Block: Decalares the variables for numerator and denominator
private:
    int numerator;
    int denominator;
    //Below Block: Simplifies the fraction and ensures denominator is positive
    void reduce() 
    {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) 
        { 
            //Below Block: Keeps denominator positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }
public:
    //Below Block: Constructor sets values, prevents zero denominator, and reduces the fraction
    Rational(int num = 0, int den = 1) 
    {
        if (den == 0) 
        {
            cout << "Error: Denominator cannot be zero. Setting to 1.\n";
            den = 1;
        }
        numerator = num;
        denominator = den;
        reduce();
    }
    //Below Block: Arithmetic operators for overloads
    Rational operator+(const Rational& other) const 
    {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }
    Rational operator-(const Rational& other) const 
    {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }
    Rational operator*(const Rational& other) const 
    {
        return Rational(numerator * other.numerator,
                        denominator * other.denominator);
    }
    Rational operator/(const Rational& other) const 
    {
        return Rational(numerator * other.denominator,
                        denominator * other.numerator);
    }
    //Below Block: Relational/equality operators
    bool operator==(const Rational& other) const 
    {
        return (numerator == other.numerator && denominator == other.denominator);
    }
    bool operator!=(const Rational& other) const 
    {
        return !(*this == other);
    }
    bool operator<(const Rational& other) const 
    {
        return (numerator * other.denominator < other.numerator * denominator);
    }
    bool operator>(const Rational& other) const 
    {
        return (numerator * other.denominator > other.numerator * denominator);
    }
    bool operator<=(const Rational& other) const 
    {
        return !(*this > other);
    }
    bool operator>=(const Rational& other) const 
    {
        return !(*this < other);
    }
    //Below Block: Convert to string to a/b format
    string toString() const 
    {
        return to_string(numerator) + "/" + to_string(denominator);
    }
    //Below Block: Converts to decimal
    double toDouble() const 
    {
        return static_cast<double>(numerator) / denominator;
    }
};
//Below Block: Main function to test class with user input
int main() 
{
    int num1, den1, num2, den2;
    cout << "Enter numerator for first fraction: ";
    cin >> num1;
    cout << "Enter denominator for first fraction: ";
    cin >> den1;
    cout << "Enter numerator for second fraction: ";
    cin >> num2;
    cout << "Enter denominator for second fraction: ";
    cin >> den2;
    Rational r1(num1, den1);
    Rational r2(num2, den2);
    cout << "\nFirst fraction: " << r1.toString() << " (" << r1.toDouble() << ")\n";
    cout << "Second fraction: " << r2.toString() << " (" << r2.toDouble() << ")\n\n";
    cout << "Arithmetic operations:\n";
    cout << r1.toString() << " + " << r2.toString() << " = " << (r1 + r2).toString() << endl;
    cout << r1.toString() << " - " << r2.toString() << " = " << (r1 - r2).toString() << endl;
    cout << r1.toString() << " * " << r2.toString() << " = " << (r1 * r2).toString() << endl;
    cout << r1.toString() << " / " << r2.toString() << " = " << (r1 / r2).toString() << endl;
    cout << "\nComparisons:\n";
    cout << "Equal? " << (r1 == r2 ? "true" : "false") << endl;
    cout << "Not equal? " << (r1 != r2 ? "true" : "false") << endl;
    cout << "Less than? " << (r1 < r2 ? "true" : "false") << endl;
    cout << "Greater than? " << (r1 > r2 ? "true" : "false") << endl;
    return 0;
}