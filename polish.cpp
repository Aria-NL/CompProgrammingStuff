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
        std::cout << "Enter the expression:";
        std::cin >> oper;
        if(oper == 'q') {
            break;
        }
        std::cin >> first >> second;

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
                std::cout << "The operator " << oper << " does not exist. Please try again. " << std::endl;
                break;
        }
    }
    return 0;   
}

