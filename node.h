#include <iostream>
#include <vector>

struct Node {
    std::vector<int> point;
    Node* left;
    Node* right;
};


void insertNewNode(int degree, Node *&node) {
    std::cout << "New Node" << std::endl;
    for (int i = 0; i < degree; i++){
        int temp;
        std::cout << i+1 <<"d: ";
        std::cin>> temp;
        node->point.push_back(temp);
    }
    std::cout << std::endl;
}