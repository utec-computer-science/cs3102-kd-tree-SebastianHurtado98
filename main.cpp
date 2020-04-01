#include <iostream>
#include "kdtree.h"
#include <vector>

typedef std::vector<int> container;

int main() {
    //al kd tree solo le pasas contenedores.
    
    KdTree<container> tree(2);
    
    container myContainer;
    myContainer.push_back(2);
    myContainer.push_back(2);
    
    tree.insert(myContainer);

    container myContainer2;
    myContainer2.push_back(3);
    myContainer2.push_back(3);
    
    tree.insert(myContainer2);

    tree.print();

    return 0;
}
