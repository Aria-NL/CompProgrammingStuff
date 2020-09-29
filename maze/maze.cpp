#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <limits>

class Coordinate {
    public:
    int rowCoord;
    int colCoord;
    void printcol() {
        std::cout << colCoord;
    }
    void printrow() {
        std::cout << rowCoord;
    }
};

class Layout {
    public:
    int height;
    int width;
    std::vector<std::vector<char>> mazeMap;
    void readLayout(std::ifstream &input) {
        for(int i = 0; i < height; i++) {
            mazeMap.push_back(std::vector<char>(0));
        }
        std::string currentLine;
        std::getline(input,currentLine);
        for(int i = 0; i < mazeMap.size(); i++) {
            std::getline(input,currentLine);
            for(int j = 0; j < width; j++) {
                if(currentLine.at(j) == 'l' || currentLine.at(j) == '.') {
                    mazeMap.at(i).push_back(currentLine.at(j));
                }
                else {
                    throw std::runtime_error("could not read maze layout");
                }
            }
        }
    }
};

class Maze {
    public:
    bool solved;
    Coordinate currentCoords;
    Coordinate start;
    Coordinate finish;
    Layout mazeLayout;

    void printStart() {
        if(verifyCoords()) {
            for(int i = 0; i < mazeLayout.height; i++) {
                for(int j = 0; j < mazeLayout.width; j++) {
                    if(i == start.rowCoord && j == start.colCoord) {
                        std::cout << 'P';
                    }
                    else if(i == finish.rowCoord && j == finish.colCoord) {
                        std::cout << 'x';
                    }
                    else {
                        std::cout << mazeLayout.mazeMap.at(i).at(j);
                    }
                }
                std::cout << std::endl << std::endl;
            }
        }
    }
    private:
    bool verifyCoords() {
        if(mazeLayout.mazeMap.at(start.rowCoord).at(start.colCoord) == 'l' || start.rowCoord > mazeLayout.height || start.colCoord > mazeLayout.width) {
            throw std::runtime_error("player outside maze or off the path");
        }
        if(mazeLayout.mazeMap.at(finish.rowCoord).at(finish.colCoord) == 'l' || finish.rowCoord > mazeLayout.height || finish.colCoord > mazeLayout.width) {
            throw std::runtime_error("exit outside maze or off the path");
        }
        currentCoords.colCoord = start.colCoord;
        currentCoords.rowCoord = start.rowCoord;
        return true;
    }
};


int main(int argc, char* argv[]) {
    std::ifstream input;
    std::vector<int> testVector(4);
    try {
        if(argc != 2) {
            throw std::runtime_error("no input filename given");
        }
    }
    catch(std::runtime_error &excpt) {
        std::cout << "an error occurred: " << excpt.what() << std::endl;
        return 1;
    }

    try {
        input.open(argv[1]);
        if(!input.is_open()) {
            throw std::runtime_error("could not open input file ");
        }
    }
    catch(std::runtime_error &excpt) {
        std::cout << "an error occurred: " << excpt.what() << argv[1] << std::endl;
        return 1;
    }
    Maze maze;
    try {
        input >> maze.mazeLayout.height >> maze.mazeLayout.width;
        if(input.fail()) {
            throw std::runtime_error("could not read height and width of the maze");
        }
        maze.mazeLayout.readLayout(input);
        int test;
        input >> maze.finish.rowCoord >> maze.finish.colCoord >> maze.start.rowCoord >> maze.start.colCoord;
        if(input.fail()) {
            throw std::runtime_error("could not read coordinates");
        }
        maze.printStart();
    }
    catch(std::runtime_error &excpt) {
        std::cout << "an error occurred: " << excpt.what() << std::endl;
        return 1;
    }
    return 0;
}