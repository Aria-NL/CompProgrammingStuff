#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>

class Coordinate {
    public:
    Coordinate();
    int getcol();
    int getrow();
    void setrow(int newRow);
    void setcol(int newCol);
    private:
    int rowCoord, colCoord;
};

Coordinate::Coordinate() {
}
int Coordinate::getcol() { return colCoord; }
int Coordinate::getrow() { return rowCoord; }
void Coordinate::setrow(int newRow) { rowCoord = newRow; }
void Coordinate::setcol(int newCol) { colCoord = newCol; }

class Layout {
    public:
    Layout();
    int getheight();
    int getwidth();
    void setheight(int newheight);
    void setwidth(int newwidth);
    char getMapChar(int row, int col);
    void readLayout(std::ifstream &input);

    private:
    int height, width;
    std::vector<std::vector<char>> mazeMap;
};

Layout::Layout() {
}
int Layout::getheight() { return height; }
int Layout::getwidth() { return width; }
void Layout::setheight(int newheight) { height = newheight; }
void Layout::setwidth(int newwidth) { width = newwidth; }
char Layout::getMapChar(int row, int col) { return mazeMap.at(row).at(col); }
void Layout::readLayout(std::ifstream &input) {
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


class Maze {
    public:
    Maze();
    Maze(int height, int width);

    void setheight(int newHeight);
    void setwidth(int newWidth);
    int getheight();
    int getwidth();
    void readLayout(std::ifstream &input);
    std::string getinstr();
    void setinstr(std::string newInstr);
    void setCoords(int startRow, int startCol, int finishRow, int finishCol);
    bool verifyMoves(std::ifstream &input);
    void printCurrent();
    void solveMaze(std::ifstream &input, std::string instructions);


    private:
    Coordinate currentCoords, start, finish;
    std::string instructions;
    Layout mazeLayout;
    int verifyCoords();
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
void Maze::setheight(int newHeight) { mazeLayout.setheight(newHeight);}
void Maze::setwidth(int newWidth) { mazeLayout.setwidth(newWidth); }
int Maze::getheight() { return mazeLayout.getheight(); }
int Maze::getwidth() { return mazeLayout.getwidth(); }
void Maze::readLayout(std::ifstream &input) { mazeLayout.readLayout(input); }
std::string Maze::getinstr() { return instructions; }
void Maze::setinstr(std::string newInstr) { instructions = newInstr; }
void Maze::setCoords(int startRow, int startCol, int finishRow, int finishCol) {
    start.setrow(startRow);
    start.setcol(startCol);
    finish.setrow(finishRow);
    finish.setcol(finishCol);
    currentCoords.setrow(startRow);
    currentCoords.setcol(startCol);
}
bool Maze::verifyMoves(std::ifstream &input) {
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
void Maze::printCurrent() {
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
void Maze::solveMaze(std::ifstream &input, std::string instructions) {
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
int Maze::verifyCoords() {
    if(mazeLayout.getMapChar(currentCoords.getrow(),currentCoords.getcol()) == 'l' || currentCoords.getrow() > mazeLayout.getheight() || currentCoords.getcol() > mazeLayout.getwidth()) {
        return 1;
    }
    if(mazeLayout.getMapChar(finish.getrow(),finish.getcol()) == 'l' || finish.getrow() > mazeLayout.getheight() || finish.getcol() > mazeLayout.getwidth()) {
        return 2;
    }
    return 0;
}


int main(int argc, char* argv[]) {
    std::ifstream input;
    std::vector<int> testVector(4);
    try {
        if(argc != 2) {
            throw std::runtime_error("no input filename given");
        }
        
        input.open(argv[1]);
        if(!input.is_open()) {
            std::string filename = static_cast<std::string>(argv[1]);
            std::string error = ("could not open input file " + filename);
            throw std::runtime_error(error);
        }

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
        input.close();
    }
    catch(std::runtime_error &excpt) {
        std::cout << "an error occurred: " << excpt.what() << std::endl;
        return 1;
    }
    return 0;
}