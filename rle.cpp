#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

std::string compress(std::string toCompress) {
    std::string compressed;
    if(toCompress.empty()) { // edge case - if empty input, just send it back
        return toCompress;
    }
    char currentChar = toCompress.at(0);
    int countChar = 1;
    for(int i = 1; i < toCompress.length(); i++) { // iterate along string, checking for new char each time
        if(currentChar != toCompress.at(i)) {
            std::cout << countChar << currentChar;
            currentChar = toCompress.at(i);
            countChar = 1;
        }
        else {
            countChar++;
        }
    }
    std::cout << countChar << currentChar << std::endl;
    return compressed;
}

int main() {
    try{
        std::string toCompress;
        std::cout << "Enter the data to be compressed: ";
        std::cin >> toCompress;
        for(int i = 0; i < toCompress.length(); i++) {
            if((toCompress.at(i) > 64 && toCompress.at(i) < 91) || (toCompress.find_first_of("0123456789") != std::string::npos)) { // detect capital letters and numbers
                throw std::runtime_error("invalid input");
            }
        }
        std::cout << std::endl << "The compressed data is: " << compress(toCompress);
    }

    catch(std::runtime_error& excpt) {
        std::cout << "error: " << excpt.what() << std::endl;
    }

    return 0;
}