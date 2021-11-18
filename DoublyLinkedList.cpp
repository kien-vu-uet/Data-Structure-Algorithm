#include <iostream>
using namespace std;

class Node{
private: 
    int value;
public: 
    Node* next;
    Node* prev;

    Node(int _value){
        value = _value;
        next = NULL;
        prev = NULL;
    }

    int getValue(){
        return value;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    //int size;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        //size = 0;
    }

    void insertNewNode(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }

    int countTriplets() {
        if (head -> next == NULL || head -> next == tail) {
            return 0;
        }
        int res = 0;
        for (Node* ptr = head -> next; ptr -> next != NULL; ptr = ptr -> next) {
            if (ptr -> prev -> getValue() + ptr -> getValue() + ptr -> next -> getValue() == 0) {
                ++ res;
            }
        }
        return res;
    }
};

int main() {
    DoublyLinkedList* llist = new DoublyLinkedList();
    int n; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        llist -> insertNewNode(x);
    }
    cout << llist -> countTriplets() << endl;
    return 0;
}