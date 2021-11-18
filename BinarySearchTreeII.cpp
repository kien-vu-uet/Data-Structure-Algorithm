#include <bits/stdc++.h>

using namespace std;

class BinarySearchTree {
public:
    map<int, vector<int>> bst;
    int root;

    BinarySearchTree(int root) {
        this -> root = root;
    }

    void insert(int value, int parent) {
        if (bst[parent].empty()) {
            bst[parent].push_back(value);
        } else {
            vector<int>* child = &(bst[parent]);
            if ((*child).size() == 1) { // has only 1 child has value = childValue
                int childValue = (*child)[0];
                if ((value - parent) * (parent - childValue) > 0) {
                    (*child).push_back(value); // child = { <old_value>, <new_value> } : unsorted
                    if (childValue > value) swap((*child)[0], (*child)[1]);
                    // cout << childValue << " " << value << "\n";
                } else {
                    insert(value, childValue);
                }
            } else if ((*child).size() == 2) {
                if (value < parent) insert(value, (*child)[0]);
                else insert(value, (*child)[1]);
            }
        }
    }

    void remove(int value) {
        if (value == root) {
            if (bst[root].empty()) {
                root = 0;
                bst.clear();
            } else if (bst[root].size() == 1) {
                int child = bst[root][0];
                bst[root].clear();
                root = child;
            } else {
                int replacement = getLeftPole(bst[root][1]);
                root = removeNotRoot(replacement, root);
                root = replacement;
            }
        } else {
            removeNotRoot(value, root);
        }
    }

    int removeNotRoot(int value, int parent) {
        if (bst[parent].empty()) return parent;
        if (bst[parent].size() == 1) {
            int childValue = bst[parent][0];
            if (childValue == value) {
                if (bst[value].empty()) bst[parent].clear();
                else if (bst[value].size() == 1) return bst[value][0];
                else {
                    int replacement = getLeftPole(bst[value][1]);
                    value = removeNotRoot(replacement, value);
                    return replacement;
                }
            } else if ((value - parent) * (parent - childVlaue) < 0)) {
                bst[parent][0] = removeNotRoot(value, childValue);   
            }
        } else {
            int left = bst[parent][0];
            int right = bst[parent][1];
            if (value == left) {
                if (bst[value].empty()) {
                    bst[parent].resize(1);
                    bst[parent][0] = right;
                } else if (bst[value].size() == 1) {
                    bst[parent][0] = bst[value][0];
                } else {
                    int replacement = getLeftPole(bst[value][1]);
                    value = removeNotRoot(replacement, value);
                }
            }
        }
        return parent;
    }

    void printBST(int parent) {
        cout << parent << " ";
        for (int i = 0; i < bst[parent].size(); i++) {
            printBST(bst[parent][i]);
        }
    }

    int getLeftPole(int parent) {
        int res = parent;
        if (bst[parent].empty()) {
            return res;
        } else if (bst[parent].size() == 1) {
            if (bst[parent][0] < parent) res = bst[parent][0];
        } else {
            res = bst[parent][0];
        }
        return res;
    }

};

int main() {
    BinarySearchTree* myBST = new BinarySearchTree(5);

    myBST -> insert(1, myBST -> root);
    myBST -> insert(9, myBST -> root);
    myBST -> insert(11, myBST -> root);
    myBST -> insert(0, myBST -> root);
    myBST -> insert(4, myBST -> root);
    myBST -> insert(2, myBST -> root);
    myBST -> insert(3, myBST -> root);
    myBST -> insert(7, myBST -> root);

    myBST -> printBST(myBST -> root);
    
    return 0;
}