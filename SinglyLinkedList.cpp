#include <iostream>

using namespace std;

class Node{
private:
    int value;
public:
    Node* next;

    Node(int _value){
        value = _value;
        next = NULL;
    }

    int getValue(){
        return value;
    }
};

class SinglyLinkedList{
public:
    Node* head;
    int size;
    
    SinglyLinkedList(){
        head = NULL;
        size = 0;
    }

    void insertNewNode(int _value){
        Node* newNode = new Node(_value);
        if (head == NULL) head = newNode;
        else {
            Node* ptr = head;
            while (ptr -> next != NULL) {
                ptr = ptr -> next;
            }
            ptr -> next = newNode;
        }
        ++size;
    }

    void insertNode(int pos, int _value){
        if (pos == 0) {
            Node* newNode = new Node(_value);
            newNode -> next = head;
            head = newNode;
        }
        else if (pos >= size) {
            insertNewNode(_value);
        }
        else {
            Node* newNode = new Node(_value);
            Node* ptr = head;
            for (int i = 1; i < pos; ++i){
                ptr = ptr -> next;
            }
            newNode -> next = ptr -> next;
            ptr -> next = newNode;
        }
        ++size;
    }

    void deleteNode(int pos){
        if (pos == 0) {
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
        else {
            Node* ptr = head;
            for (int i = 1; i < pos; ++i){
                ptr = ptr -> next;
            }
            Node* temp = ptr -> next;
            ptr -> next = temp -> next;
            delete temp;
        }
        --size;
    }
};

int main(){
    SinglyLinkedList* llist = new SinglyLinkedList();

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "insert") {
            int p, x;
            cin >> p >> x;
            llist -> insertNode(p, x);
        }
        if (s == "delete") {
            int p;
            cin >> p;
            llist -> deleteNode(p);
        }
    }

    for (Node* ptr = llist -> head; ptr != NULL; ptr = ptr -> next){
        cout << ptr -> getValue() << " ";
    }
    return 0;
}