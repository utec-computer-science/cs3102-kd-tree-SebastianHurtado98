#include "node.h"

class KdTree {
    private:
        Node *root;
        unsigned int degree;

    public:
        KdTree(unsigned int degree) {
            this->degree = degree;
            root = nullptr;
        };

        Node *search(int &elem) { 
            
        } 

        bool insert() {
            if(root != nullptr) {
                Node *newNode = new Node;
                insertNewNode(degree, newNode);
                bool notInserted = true;
                int level = 1;
                Node *current = root;
                while (notInserted) {
                    if (newNode->point[(level-1)%degree] < current->point[(level-1)%degree]) {
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
                }

            } else {
                root = new Node;
                insertNewNode(degree,root);
            }
        }

        void print() {
            for (int i = 0; i < degree; i ++) {
                std::cout << root->point[i];
            }
        }

        ~KdTree(){
            root = nullptr;
        };
};

