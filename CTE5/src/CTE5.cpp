/*				Psueudocode for Critcal Thinking Exercise 5
 * 1. create function to append a file
 * 		a. open file,
 * 		b. append file
 * 		c. close file
 * 2. Create function to reverse all content
 * 		a. open file
 * 		b. read file
 * 		c.reverse content
 * 		d. write reverse content
 * 		e.close file
 * 3. create main function
 * 		a. take input from user
 * 		b. define file path for both necissary files
 * 		c. call on append function for forward file
 * 		d. reverse forward file with reverse function and append
 * 4. end of program
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// add to file function
void append(const std::string& filename, const std::string& data) {
    std::ofstream outFile(filename, std::ios::app);
    //error check
    if (!outFile) {
        std::cerr << "Error:" << filename << std::endl;
        return;
    }
    outFile << data << '\n';
}

// reverse function
void reverse(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    //error checking
    if (!inFile) {
        std::cerr << "Error: " << inputFile << std::endl;
        return;}

    std::string content;
    std::string line;
    while (std::getline(inFile, line)) {
        content += line + '\n';}

    inFile.close();

    if (!content.empty()) {
        content.pop_back();}

    //reverse content
    std::reverse(content.begin(), content.end());

    std::ofstream outFile(outputFile);
    //error checking
    if (!outFile) {
        std::cerr << "Error: " << outputFile << std::endl;
        return;}
    outFile << content;
}

// Main function
int main() {
	std::string forwardFile = "C:\\Users\\tyrjo\\Desktop\\Prog3_CTE5\\CSC450_CT5_mod5.txt";
	std::string reverseFile = "C:\\Users\\tyrjo\\Desktop\\Prog3_CTE5\\CSC450-mod5-reverse.txt";

    // user input
    std::string input;
    std::cout << "Enter desired text for file: ";
    std::getline(std::cin, input);

    append(forwardFile, input);
    reverse(forwardFile, reverseFile);

    std::cout << "Text has been saved in CSC450_CT5_mod5.txt"
    		" and reversed in CSC450-mod5-reverse.txt"  << std::endl;
    std::cout << "End of Program"  << std::endl;

    return 0;
}

