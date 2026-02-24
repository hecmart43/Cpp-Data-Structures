#include <iostream>//Input and output
#include <iomanip>//For formatting
#include <stdexcept>//For std::out_of_range
#include <string>//For Array<std::string>
template <typename T>//Class template T is the type stored
class Array 
{
//Below Block: Private members, array length, and pointer
private:
    std::size_t size;
    T* ptr;
public:
    //Below Block: Ensure size of array is graeater then zero
    explicit Array(std::size_t arraySize = 10)
        : size(arraySize > 0 ? arraySize : 10),
          ptr(new T[size]) {}
    //Below Block: Copies constructor
    Array(const Array& other)
        : size(other.size),
          ptr(new T[size]) 
          {
        for (std::size_t i = 0; i < size; ++i) 
        {
            ptr[i] = other.ptr[i];
        }
    }
    //Below Block: Destructor frees up memory
    ~Array() 
    {
        delete[] ptr;
    }
    //Below Block: Assignment operator, checks, reallocates, and copies elements
    Array& operator=(const Array& right) 
    {
        if (&right != this) 
        {
            if (size != right.size) 
            {
                delete[] ptr;
                size = right.size;
                ptr = new T[size];
            }
            for (std::size_t i = 0; i < size; ++i) 
            {
                ptr[i] = right.ptr[i];
            }
        }
        return *this;
    }
    //Below Block: Subscript operator non-const
    T& operator[](std::size_t index) 
    {
        if (index >= size) 
        {
            throw std::out_of_range("Subscript out of range");
        }
        return ptr[index];
    }
    // Subscript operator const
    const T& operator[](std::size_t index) const 
    {
        if (index >= size) 
        {
            throw std::out_of_range("Subscript out of range");
        }
        return ptr[index];
    }
    std::size_t getSize() const { return size; }//Getter for size
};
int main() 
{
    //Below Block: Integer Demo
    std::cout << "=== Integer Array ===\n";
    std::cout << "How many integers would you like to enter? ";//Asks user how many integers
    std::size_t intCount;
    std::cin >> intCount;
    //Below Block: Creates array of input size
    Array<int> intArray(intCount);
    //Below Block: Loops input integers into the array
    for (std::size_t i = 0; i < intCount; ++i) 
    {
        std::cout << "Enter integer " << (i + 1) << ": ";
        std::cin >> intArray[i];
    }
    //Below Block: Prints the integers
    std::cout << "You entered: ";
    for (std::size_t i = 0; i < intCount; ++i) 
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n\n";
    //Below Block: String Demo
    std::cout << "=== String Array ===\n";
    std::cout << "How many strings would you like to enter? ";
    std::size_t strCount;
    std::cin >> strCount;
    Array<std::string> strArray(strCount);
    for (std::size_t i = 0; i < strCount; ++i) 
    {
        //Below Block: Input string from user
        std::cout << "Enter string " << (i + 1) << ": ";
        std::cin >> strArray[i];
    }
    //Below Block: Prints the strings
    std::cout << "You entered: ";
    for (std::size_t i = 0; i < strCount; ++i) 
    {
        std::cout << strArray[i] << " ";
    }
    std::cout << "\n";
    return 0;
}