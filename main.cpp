#include <iostream>
#include "kdtree.h"
#include <vector>

int main() {
    std::cout << "Hello World! \n";
    KdTree TwoDTree(2);
    TwoDTree.insert();
    TwoDTree.print();
    
    return 0;
}
