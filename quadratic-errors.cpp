#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <typeinfo>

double findDiscrim(double a, double b, double c) {
    double discriminate = (pow(b,2) - (4 * a * c));
    if (discriminate > 0) {
        std::cout << "There are 2 solutions." << std::endl << std::endl;
    }
    else if (discriminate == 0) {
        std::cout << "There is 1 solution." << std::endl << std::endl;
    }
    else if (discriminate < 0) {
        std::cout << "There is no solution." << std::endl;
    }
    return discriminate;
}

std::vector<double> findSolutions(double discrim, double a, double b) {
    std::vector<double> solutions;
    if(discrim > 0) {
        solutions.push_back((-b + sqrt(discrim)) / (2*a));
        solutions.push_back((-b - sqrt(discrim)) / (2*a));
        return solutions;
    }
    if(discrim == 0) {
        solutions.push_back((-b + sqrt(discrim)) / (2*a));
        return solutions;
    }
    else {
        return solutions;
    }
}



int main() {
    double userA;
    double userB;
    double userC;
    std::vector<double> result;

    try {
        std::cout << "Please enter the values of a, b, and c: ";
        std::cin >> userA;
        if(userA == 0) {
            throw std::runtime_error("a must not be zero");
        }
        std::cin >> userB >> userC;
        if(typeid(userA) != typeid(double) || typeid(userB) != typeid(double) || typeid(userC) != typeid(double)) {
            throw std::runtime_error("Malformed user input");
        }
        result = findSolutions((findDiscrim(userA,userB,userC)),userA,userB);
        switch(result.size()) {
            case 2:
               std::cout << "The solutions are: " << result.at(0) << " and " << result.at(1) << std::endl;
            break;
            case 1:
                std::cout << "The solution is: " << result.at(0) << std::endl;
                break;
        }
    }
    catch (std::runtime_error& excpt) {
        std::cout << "An error occurred: " << excpt.what() << std::endl;
    }

    return 0;
}