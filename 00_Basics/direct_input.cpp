#include <iostream> //std::cout & cin
#include <fstream> //I/O
#include <cctype> //Char conversion
#include <map> //Char to int
#include <string>//std::string
int main() 
{
    std::string inputFileName;//User input of file name
    std::string outputFileName;
    //Below Block: Ask for filenames (getline allows spaces in names)
    std::cout << "Enter input file name: ";//Prompts for name path of input file
    std::getline(std::cin, inputFileName);//Reads the input file name
    std::cout << "Enter output file name: ";//Prompts user for the output file name
    std::getline(std::cin, outputFileName);//Reads the output file name
    std::ifstream inputFile(inputFileName);//Opens input for reading
    std::ofstream outputFile(outputFileName);//Opens or creates output for writing
    //Below Block: Validate streams ensuring they open
    if (!inputFile) 
    {
        std::cerr << "Error: Could not open input file.\n";
        return 1;
    }
    //Below Block: Ensures file opens
    if (!outputFile) 
    {
        std::cerr << "Error: Could not open output file.\n";
        return 1;
    }
    int lineCount = 0;//Creates a counter for the number of lines read
    std::map<char, int> charCount;//Creates the layout for the counter
    std::string line;//String to hold each line read
    //Below Block: Reads input file line-by-line
    while (std::getline(inputFile, line))//Reads each line and loops through until failure or EOF
    {
        ++lineCount;//Incriments the number of lines
        outputFile << line << '\n';//Writes the line exactly as read to the output file
        //Below Block: Counts the letters in a line
        for (unsigned char uc : line) 
        { 
            //Below Block: letters only (ignore digits/punct/space)
            if (std::isalpha(uc)) 
            {       
                char upper = static_cast<char>(std::toupper(uc));//Converts lowercase to uppercase
                charCount[upper]++;// map default-constructs 0 then increments
            }
        }
    }
    //Below Block: The summary layout of each letter count
    outputFile << "The number of lines in the input file is "
               << lineCount << ".\n";
    //Below Block: Inputs the counts of each letter into the file
    for (const auto& kv : charCount) 
    {
        outputFile << kv.first << " appears " << kv.second << " times.\n";//Ensures each letter has its own line
    }
    //Below Block: Saves the file
    std::cout << "Processing complete. Results saved to " << outputFileName << "\n";
    return 0;
}