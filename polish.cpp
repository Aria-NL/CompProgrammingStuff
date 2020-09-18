#include <iostream>
#include <cmath>

double add(double num1, double num2) {
    return (num1 + num2);
}
double subtract(double num1, double num2) {
    return (num1 - num2);
}
double multiply(double num1, double num2) {
    return (num1 * num2);
}
double divide(double num1, double num2) {
    return (num1 / num2);
}

int main() {
    char oper;
    double first;
    double second;

    while (oper != 'q') {
        try {
            std::cout << "Enter the expression:";
            std::cin >> oper;
            if(oper == 'q') {
                throw(std::runtime_error("User exit"));
            }
            std::cin >> first >> second;
            if(std::cin.fail()) {
                std::cin.clear();
                throw std::runtime_error("Invalid number input");
            }

            switch (oper) {
                case '+':
                    std::cout << first << " " << oper << " " << second << " = " << add(first,second) << std::endl;
                    break;
                case '-':
                    std::cout << first << " " << oper << " " << second << " = " << subtract(first,second) << std::endl;
                    break;
                case '*':
                    std::cout << first << " " << oper << " " << second << " = " << multiply(first,second) << std::endl;
                    break;
                case '/':
                    std::cout << first << " " << oper << " " << second << " = " << divide(first,second) << std::endl;
                    break;
                default:
                    throw std::runtime_error("Invalid operator");
                    break;
        
            }
        }
        catch (std::runtime_error& excpt) {
            std::cout << "An error occurred: " << excpt.what() << std::endl;
        }
    }
    return 0;   
}

