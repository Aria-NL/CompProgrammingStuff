#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>

class Coordinate {
    public:
    int getcol() { return colCoord; }
    int getrow() { return rowCoord; }
    void setrow(int newRow) { rowCoord = newRow; }
    void setcol(int newCol) { colCoord = newCol; }
    private:
    int rowCoord, colCoord;
};

class Layout {
    public:
    int getheight() { return height; }
    int getwidth() { return width; }
    void setheight(int newheight) { height = newheight; }
    void setwidth(int newwidth) { width = newwidth; }
    char getMapChar(int row, int col) { return mazeMap.at(row).at(col); }

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
    private:
    int height, width;
    std::vector<std::vector<char>> mazeMap;
};

class Maze {
    public:
    Maze();
    Maze(int height, int width);

    void setheight(int newHeight) { mazeLayout.setheight(newHeight);}
    void setwidth(int newWidth) { mazeLayout.setwidth(newWidth); }
    int getheight() { return mazeLayout.getheight(); }
    int getwidth() { return mazeLayout.getwidth(); }
    void readLayout(std::ifstream &input) { mazeLayout.readLayout(input); }
    std::string getinstr() { return instructions; }
    void setinstr(std::string newInstr) { instructions = newInstr; }
    void setCoords(int startRow, int startCol, int finishRow, int finishCol) {
        start.setrow(startRow);
        start.setcol(startCol);
        finish.setrow(finishRow);
        finish.setcol(finishCol);
        currentCoords.setrow(startRow);
        currentCoords.setcol(startCol);
    }

    bool verifyMoves(std::ifstream &input) {
        std::string buffer;
        getline(input,buffer);
        getline(input,buffer);
        setinstr(buffer);
        for(char c : instructions) {
            if(c != 'u' && c != 'd' && c != 'l' && c != 'r') {
                throw std::runtime_error("invalid move");
            }
        }
        return true;
    }

    void printCurrent() {
        if(verifyCoords() == 0) {
            for(int i = 0; i < mazeLayout.getheight(); i++) {
                for(int j = 0; j < mazeLayout.getwidth(); j++) {
                    if(i == start.getrow() && j == start.getcol()) {
                        if(currentCoords.getrow() != start.getrow() && currentCoords.getcol() != start.getcol()) {
                            std::cout << '.';
                        }
                        else {
                            std::cout << 'P';
                        }
                    }
                    else if(i == finish.getrow() && j == finish.getcol()) {
                        if(currentCoords.getrow() == finish.getrow() && currentCoords.getcol() == finish.getcol()) {
                            std::cout << 'P';
                        }
                        else {
                            std::cout << 'x';
                        }
                    }
                    else {
                        if(i == currentCoords.getrow() && j == currentCoords.getcol()) {
                            std::cout << 'P';
                        }
                        else {
                            std::cout << mazeLayout.getMapChar(i,j);
                        }
                    }
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        else if(verifyCoords() == 1) {
            throw std::runtime_error("player outside maze or off the path");
        }
        else if(verifyCoords() == 2) {
            throw std::runtime_error("exit outside maze or off the path");
        }
    }

    void solveMaze(std::ifstream &input, std::string instructions) {
        for(char move : instructions) {
            switch(move) {
                case 'u':
                    currentCoords.setrow(currentCoords.getrow() - 1);
                    if(verifyCoords() == 1) {
                       throw std::runtime_error("player outside maze or off the path"); 
                    }
                    break;
                case 'd':
                    currentCoords.setrow(currentCoords.getrow() + 1);
                    if(verifyCoords() == 1) {
                       throw std::runtime_error("player outside maze or off the path"); 
                    }
                    break;
                case 'l':
                    currentCoords.setcol(currentCoords.getcol() - 1);
                    if(verifyCoords() == 1) {
                           throw std::runtime_error("player outside maze or off the path"); 
                        }
                        break;
                case 'r':
                    currentCoords.setcol(currentCoords.getcol() + 1);
                    if(verifyCoords() == 1) {
                       throw std::runtime_error("player outside maze or off the path"); 
                    }
                    break;
                default:
                    throw std::runtime_error("invalid move");
            }
        }
        if(currentCoords.getcol() == finish.getcol() && currentCoords.getrow() == finish.getrow()) {
            printCurrent();
            std::cout << "The player reached the exit!" << std::endl;
        }
        else {
            printCurrent();
            std::cout << "The player did not reach the exit." << std::endl;
        }
    }


    private:
    Coordinate currentCoords, start, finish;
    std::string instructions;
    Layout mazeLayout;
    int verifyCoords() {
        if(mazeLayout.getMapChar(currentCoords.getrow(),currentCoords.getcol()) == 'l' || currentCoords.getrow() > mazeLayout.getheight() || currentCoords.getcol() > mazeLayout.getwidth()) {
            return 1;
        }
        if(mazeLayout.getMapChar(finish.getrow(),finish.getcol()) == 'l' || finish.getrow() > mazeLayout.getheight() || finish.getcol() > mazeLayout.getwidth()) {
            return 2;
        }
        return 0;
    }
};

Maze::Maze() {
    start.setrow(0);
    start.setcol(0);
    finish.setrow(0);
    finish.setrow(0);
}
Maze::Maze(int height, int width) {
    mazeLayout.setheight(height);
    mazeLayout.setwidth(width);
}


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

    try {
        int height, width, startRow, startCol, finishRow, finishCol;

        input >> height >> width;
        if(input.fail()) {
            throw std::runtime_error("could not read height and width of the maze");
        }

        Maze maze(height, width);
        maze.readLayout(input);

        input >> finishRow >> finishCol >> startRow >> startCol;
        if(input.fail()) {
            throw std::runtime_error("could not read coordinates");
        }
        maze.setCoords(startRow,startCol,finishRow,finishCol);

        if(maze.verifyMoves(input)) {
            maze.printCurrent();
            maze.solveMaze(input, maze.getinstr());
        }
    }
    catch(std::runtime_error &excpt) {
        std::cout << "an error occurred: " << excpt.what() << std::endl;
        return 1;
    }
    return 0;
}