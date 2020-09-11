#include <iostream>
#include <cmath>
#include <vector>

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

    std::cout << "Please enter the values of a, b, and c: ";
    std::cin >> userA;
    if(userA == 0) {
         std::cout << "Sorry, but the value for a cannot be zero." << std::endl;
         return 1;
    }
    std::cin >> userB >> userC;
    result = findSolutions((findDiscrim(userA,userB,userC)),userA,userB);
    switch(result.size()) {
        case 2:
            std::cout << "The solutions are: " << result.at(0) << " and " << result.at(1) << std::endl;
            break;
        case 1:
            std::cout << "The solution is: " << result.at(0) << std::endl;
            break;
    }

    return 0;
}9