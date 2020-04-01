#include <iostream>
#include <vector>

template<typename Container>
struct Node {
    Container point =NULL;
    Node* left =nullptr;
    Node* right =nullptr;
};


template<typename Container>
class KdTree {
    private:
        Node<Container> *root;
        unsigned int degree;

    public:
        // No creo que el degree vaya a cambiar de tipo
        KdTree(unsigned int degree) {
            this->degree = degree;
            root = nullptr;
        };

        bool equalPoints(const Container &point1, const Container &point2) {
            for (int i = 0; i < degree; i++) {
                if (point1[i] != point2[i]) return false;
            }
            return true;
        }

        
        bool search(Container &container) { 
            bool found = false;
            if(root != nullptr) {
                int level = 1;
                auto current = root;
                auto dimension = (level-1)%degree;
                while (!found) {
                    if(equalPoints(current->point, container)) {
                        found = true;
                    } else {
                        if(container[dimension] < current->point[dimension]) {
                            if (current->left==nullptr) {
                                return false;
                            } else {
                                current = current->left;
                                level++;
                            }
                        }
                        else {
                            if (current->right==nullptr) {
                                return false;
                            } else {
                                current = current->right;
                                level++;
                            }
                        }
                    }
                    dimension = (level-1)%degree;
                }

            } else {
                return false;
            }
        } 



        bool insert(Container &container) {
            auto newNode = new Node<Container>;
            //esperemos que todos los containers tengan ese operador sobrecargado
            //el container se borra después de igualarse?
            newNode->point = container;

            if(root != nullptr) {
                bool notInserted = true;
                int level = 1;
                auto current = root;
                auto dimension = (level-1)%degree;
                while (notInserted) {
                    if (newNode->point[dimension] < current->point[dimension]) {
                        if (current->left==nullptr) {
                            current->left = newNode;
                            notInserted = false;
                        } else {
                            current = current->left;
                            level++;
                        }
                    } else {
                        if (current->right==nullptr) {
                            current->right=newNode;
                            notInserted = false;
                        } else {
                            current = current->right;
                            level++;
                        }
                    }
                    dimension = (level-1)%degree;
                }

            } else {
                root = new Node<Container>;
                root->point = container;
            }
        
        }

        void print() {
            auto node = root->right;
            for (auto x: node->point) {
                std::cout<<x;
            }
        }

        ~KdTree(){
            root = nullptr;
        };
    
};

