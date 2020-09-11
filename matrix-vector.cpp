#include <iostream>
#include <vector>

std::vector<double> getResult(std::vector<std::vector<double>> initial, std::vector<double> rightSide) {
    std::vector<double> result{ 0.0, 0.0, 0.0 };

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result.at(i) += (initial.at(i).at(j)) * rightSide.at(j);
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<double>> initial {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    std::vector<double> rightSide(3);
    std::cout << "Please enter the three vector coefficients" << std::endl;
    std::cin >> rightSide.at(0) >> rightSide.at(1) >> rightSide.at(2);
    std::cout << std::endl;

    std::vector<double> result(3);
    result = getResult(initial, rightSide);
    std::cout << "The result vector is [" << result.at(0) << ", " << result.at(1) << ", " << result.at(2) << "]" << std::endl;

    return 0;
}