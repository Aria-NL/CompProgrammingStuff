#include <iostream>
#include <limits>
#include <vector>

class Stack {
    public:
        Stack();
        bool isEmpty() const {
            return elements.empty();
        }
        int top() const {
            return elements.back();
        }
        int pop() {
            if(isEmpty()) {
                throw std::runtime_error("stack is empty");
            }
            int hold = elements.at(elements.size() - 1);
            elements.pop_back();
            return hold;
        }
        void push(int i) {
            elements.push_back(i);
        }
        std::string toString() const {
            if(isEmpty()) {
                return "[]";
            }
            std::string printOut = "[" + std::to_string(elements.back());
            for(int i = elements.size() - 2; i >= 0; i--) {
                printOut += ("," + std::to_string(elements.at(i)));
            }
            return (printOut + "]");
        }
    private:
        std::vector<int> elements;
};

Stack::Stack() {
}



int main() {
    Stack stack;
    
    while (true) {
        try {
            std::cout << "stack> ";
            
            std::string command;
            std::cin >> command;
            
            if ( (command.compare("end") == 0) || std::cin.eof() ){
                break;
            } else if (command.compare("top") == 0) {
                std::cout << stack.top() << std::endl;
            } else if (command.compare("pop") == 0) {
                std::cout << stack.pop() << std::endl;
            } else if (command == "push") {
                if ( std::cin.eof() ) break;
                int i;
                std::cin >> i;
                bool failed = std::cin.fail();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if ( failed ){
                  throw std::runtime_error("not a number");
                }
                stack.push(i);
            } else if ( command.compare("list") == 0){
                std::cout << stack.toString() << std::endl;;
            } else {
                throw std::runtime_error("invalid command");
            }
        } catch (std::runtime_error& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}