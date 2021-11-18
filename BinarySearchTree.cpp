#include <bits/stdc++.h>

using namespace std;

class Node {
private:
    int value;
    Node* left;
    Node* right;

public:
    Node() {}

    Node(int value) {
        this -> value = value;
        this -> left = NULL;
        this -> right = NULL;
    }

    bool hasChildren() {
        if (right != NULL || left != NULL) return true;
        return false;
    }

    bool hasLeft() {
        if (left == NULL) return false;
        return true;
    }

    bool hasRight() {
        if (right == NULL) return false;
        return true;
    }

    bool isFull() {
        if (hasRight() && hasLeft()) return true;
        return false;
    }

    Node* getLeft() {
        return left;
    }

    void setLeft(Node* left) {
        this -> left = left;
    }

    Node* getRight() {
        return right;
    }

    void setRight(Node* right) {
        this -> right = right;
    }

    int getValue() {
        return value;
    }

    void setValue(int value) {
        this -> value = value;
    }

    void destroy() {
        this -> value = 0;
        this -> left = NULL;
        this -> right = NULL;
    }

    int getLeftPole(Node* parent) {
        Node* result = parent;
        while (result != NULL && result -> getLeft() != NULL) {
            result = result -> getLeft();
        }
        return result -> getValue();
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = NULL;
    }

    Node* insert(int value, Node* parent) {
        cout << "inserting: ";
        if (parent == NULL) {
            parent = new Node(value);
            cout << "null -> add new\n";
        } else {
            if (value < parent -> getValue()) {
                cout << "turn left\n";
                parent -> setLeft( insert( value, parent -> getLeft() ) );
            }                
            else if (value > parent -> getValue()) {
                cout << "turn right\n";
                parent -> setRight( insert( value, parent -> getRight() ) );
            }
        }
        return parent;
    }

    Node* remove(int key, Node* parent) {
        if (parent == NULL) return parent;
        cout << "removing: ";
        if (key < parent -> getValue()) {
            cout << "turn left\n";
            parent -> setLeft( remove( key, parent -> getLeft() ) );            
        } else if (key > parent -> getValue()) {
            cout << "turn\n";
            parent -> setRight( remove( key, parent -> getRight() ) );            
        } else {
            if (!parent -> hasChildren()) {
                cout << "null and back\n";
                return NULL;
            } else if (parent -> hasLeft() && !parent -> hasRight()) {
                cout << "replace by left child\n";
                Node* leftSide = parent -> getLeft();
                parent -> destroy();                         
                return leftSide;
            } else if (!parent -> hasLeft() && parent -> hasRight()) {
                cout << "replace by right child\n";
                Node* rightSide = parent -> getRight();
                parent -> destroy();                
                return rightSide;
            } else if (parent -> isFull()) {
                cout << "replace by a min value of branch\n";
                int replacement = parent -> getLeftPole(parent -> getRight());
                parent -> setValue(replacement);
                parent -> setRight( remove( replacement, parent -> getRight() ) );                
            }
        }
        return parent;
    }

    void printBST(Node* parent) {
        if (parent == NULL) {
            cout << "null" << endl;
            return;
        }
        cout << parent -> getValue() << " ";
        if (parent -> hasLeft()) printBST(parent -> getLeft());
        if (parent -> hasRight()) printBST(parent -> getRight());
    }

};

int main() {
    BinarySearchTree* bst = new BinarySearchTree();
    bst -> root = bst -> insert(5, bst -> root);
    bst -> root = bst -> insert(1, bst -> root);
    bst -> root = bst -> insert(6, bst -> root);
    bst -> root = bst -> insert(7, bst -> root);
    bst -> root = bst -> insert(0, bst -> root);
    bst -> root = bst -> insert(2, bst -> root);
    bst -> root = bst -> insert(4, bst -> root);
    bst -> root = bst -> insert(3, bst -> root);

    bst -> root = bst -> remove(1, bst -> root);

    bst -> printBST(bst -> root);

    return 0;
}