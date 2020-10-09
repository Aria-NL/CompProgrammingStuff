#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <climits>
#include "matrix.h"

class Node{
    public:
        Node();
        Node(int val, int layer);
        ~Node();
        Node *left;
        Node *right;
        int value;
        int layer;
    private:
};

Node::Node(int val, int layr) {
    value = val;
    layer = layr;
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
        void doKey(Node *&root, int newKey, int &layer);
        std::vector<int> doInOrder(Node *root, std::vector<int> &sorted);
        bool doHasKey(Node *root, int searchKey);
        Node *root;
        int doGetHeight(Node *root);
        int countNodes(Node *root);
        std::vector<int> layers;
        std::vector<int> getLayers(Node *root, std::vector<int> &layers);
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
    getLayers(root, layers);
    for(int i = 0; i < countNodes(root); i++) {
        mat.at(layers.at(i),i) = inOrder().at(i);
    }
    
    for(int i = 0; i < mat.rows(); i++) {
        for(int j = 0; j < mat.columns(); j++) {
            std::cout << "-----"; 
        }
        std::cout << "-" << std::endl << "|";
        for(int j = 0; j < mat.columns(); j++) {
            if(mat.at(i,j) != INT_MAX) {
                std::cout << std::setw(4) << mat.at(i,j) << "|";
            }
            else {
                std::cout << "    " << "|";
            }
        }
        std::cout << std::endl;
    }
    for(int j = 0; j < mat.columns(); j++) {
            std::cout << "-----"; 
    }
    std::cout << "-" << std::endl;
}
void BST::insertKey(int newKey) { 
        int layer;
        doKey(root, newKey, layer); 
    }
void BST::doKey(Node *&root, int newKey, int &layer) {
    if(root == nullptr) {
        root = new Node(newKey, layer);
        return;
    }
    else if(newKey < root->value) {
        layer++;
        doKey(root->left, newKey, layer);
    }
    else {
        layer++;
        doKey(root->right, newKey, layer);
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
std::vector<int> BST::getLayers(Node *root, std::vector<int> &layers) {
    if(root != nullptr) {
        getLayers(root->left,layers);
        layers.push_back(root->layer);
        getLayers(root->right, layers);
        return layers;
    }
    else {
        return layers;
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
int main() {
    int buffer;
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
    std::cout << "The numbers in sorted order: ";
    for(int i = 0; i < tree.inOrder().size(); i++) {
        std::cout << tree.inOrder().at(i) << " ";
    }
    std::cout << std::endl;
    tree.prettyPrint();
    return 0;
}