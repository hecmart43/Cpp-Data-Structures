#include <iostream>//cout 
using namespace std;//cout without std::
//Below Block: radius is protected/pi is constant
class Circle 
{
protected:
    double radius;
    static constexpr double PI = 3.14;
public:
    Circle() : radius(1.0) {}//constructor sets radius to 1.0
    Circle(double r) : radius(r) {}//lets user set radius
    //Below Block: Function to calculate area of a circle
    double calcVal() 
    {
        return PI * radius * radius;
    }
};
//Below Block: inherits from circle/and adds the variable of length
class Cylinder : public Circle 
{
protected:
    double length;
public:
    Cylinder() : Circle(1.0), length(1.0) {}//sets radius=1.0, length=1.0
    Cylinder(double r, double l) : Circle(r), length(l) {}//lets user set radius and length
    //Below Block: Function to get volume/gets the area of the base and multiplies by its length
    double calcVal() 
    {
        return length * Circle::calcVal();
    }
};
int main() 
{
    //Below Block: default circle and prints its area
    Circle c1;
    cout << "Circle with radius 1.0 has area: " << c1.calcVal() << endl;
    //Below Block: creates a circle with a radius of 3 then pritns its area
    Circle c2(3.0);
    cout << "Circle with radius 3.0 has area: " << c2.calcVal() << endl;
    //Below Block: default cylinder radius and length of 1 and prints its volume
    Cylinder cyl1;
    cout << "Cylinder with radius 1.0 and length 1.0 has volume: " << cyl1.calcVal() << endl;
    //Below Block: creates a cylinder with radius of 3 and length of 5 and prints its volume
    Cylinder cyl2(3.0, 5.0);
    cout << "Cylinder with radius 3.0 and length 5.0 has volume: " << cyl2.calcVal() << endl;
    return 0;
}