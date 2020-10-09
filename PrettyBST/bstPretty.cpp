#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "matrix.h"

class Node{
    public:
        Node();
        Node(int val);
        ~Node();
        Node *left;
        Node *right;
        int value;
    private:
};

Node::Node(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
}
Node::Node() {
    left = nullptr;
    right = nullptr;
}
Node::~Node() {
    delete left;
    delete right;
}

class BST{
    public:
        BST();
        ~BST();
        void insertKey(int newKey);
        bool hasKey(int searchKey);
        std::vector<int> inOrder();
        int getHeight();
        void prettyPrint();
    private:
        void doKey(Node *&root, int newKey);
        std::vector<int> doInOrder(Node *root, std::vector<int> &sorted);
        bool doHasKey(Node *root, int searchKey);
        Node *root;
        int doGetHeight(Node *root);
        int countNodes(Node *root);
        char checkSides(Node *root);
};

BST::BST() {
    root = nullptr;
}
BST::~BST() {
    delete root;
}
void BST::prettyPrint() {
    if(getHeight() == 0) {
        return;
    }
    Matrix mat(getHeight(), countNodes(root), INT_MAX);
    mat.at(0,0) = root->value;
    mat.at(countNodes(root->left),0) = mat.at(0,0);
    std::cout << mat.at(countNodes(root->left),0) << std::endl;
}

void BST::insertKey(int newKey) { doKey(root, newKey); }
void BST::doKey(Node *&root, int newKey) {
    if(root == nullptr) {
        root = new Node(newKey);
        return;
    }
    else if(newKey < root->value) {
        doKey(root->left, newKey);
    }
    else {
        doKey(root->right, newKey);
    }
}

bool BST::hasKey(int searchKey) { return doHasKey(root, searchKey); }
bool BST::doHasKey(Node *root, int searchKey) {
    if(root == nullptr) {
        return false;
    }
    else if(searchKey == root->value) {
        return true;
    }
    else if (searchKey < root->value) {
        return doHasKey(root->left, searchKey);
    }
    else {
        return doHasKey(root->right, searchKey);
    }
}

std::vector<int> BST::inOrder() {
    std::vector<int> sorted;
    doInOrder(root, sorted); 
    return sorted;
}
std::vector<int> BST::doInOrder(Node *root, std::vector<int> &sorted) {
    if(root != nullptr) {
        doInOrder(root->left, sorted);
        sorted.push_back(root->value);
        doInOrder(root->right, sorted);
        return sorted;
    }
    else {
        return sorted;
    }
}
int BST::getHeight() { return doGetHeight(root); }
int BST::doGetHeight(Node *root) {
    if(root == nullptr) {
        return 0;
    }

    int lHeight = doGetHeight(root->left);
    int rHeight = doGetHeight(root->right);
    if(lHeight > rHeight) {
        return lHeight + 1;
    }
    else {
        return rHeight + 1;
    }

}
int BST::countNodes(Node *root) {
    if(root == nullptr) {
        return 0;
    }
    int count = 1;
    count += countNodes(root->left);
    count += countNodes(root->right);
    return count;
}


char BST::checkSides(Node *root) {
    int code;
    if(root->left != nullptr && root->right == nullptr) {
        code == 'l';
    }
    if(root->right != nullptr && root->left == nullptr) {
        code == 'r';
    }
    else {
        code == 'b';
    }
    return code;
}




int main() {
    int buffer;
    int search;
    std::vector<int> vals;
    BST tree;
    std::cout << "Enter the numbers to be stored (end with a letter): ";
    while(true) {
        if(std::cin.fail()) {
            std::cin.clear();
            break;
        }
        std::cin >> buffer;
        vals.push_back(buffer);
    }
    for(int i = 0; i < vals.size() - 1; i++) {
        tree.insertKey(vals.at(i));
    }
    std::cin.ignore();
    std::cout << "Which number do you want to look up? ";
    std::cin >> search;
    std::cout << search << " is in the tree: ";
    if(tree.hasKey(search)) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }
    std::cout << "The numbers in sorted order: ";
    for(int i = 0; i < tree.inOrder().size(); i++) {
        std::cout << tree.inOrder().at(i) << " ";
    }
    std::cout << std::endl << "Height of the tree: " << tree.getHeight() << std::endl;
    tree.prettyPrint();
    return 0;
}


