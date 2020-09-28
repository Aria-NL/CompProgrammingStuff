#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>

int perfDigitalInv(int number) {
    int base = 10;
    int total = 0;
    while(number > 0) {
        total = total + pow(number % base, 2);
        number = number / base;
    }
    return total;
}

bool isHappy(int number) {
    std::set<int> seenNumbers;
    while(true){
        auto result = seenNumbers.insert(number);
        if(!result.second) {
            break;
        }
        number = perfDigitalInv(number);
    }
    return number == 1;
}

int main() {
    int inputNumber;

    std::cout << "Which number do you want to test? ";
    try {
        std::cin >> inputNumber;
        if(std::cin.fail()) {
            throw std::runtime_error("Invalid entry");
        }
        std::cout << std::endl;
        if(isHappy(inputNumber)) {
            std::cout << inputNumber << " is happy!" << std::endl;
        }
        else {
            std::cout << inputNumber << " is unhappy!" << std::endl;
        }
    }
    catch (std::runtime_error &excpt) {
        std::cout << excpt.what() << std::endl;
    }

    return 0;
}