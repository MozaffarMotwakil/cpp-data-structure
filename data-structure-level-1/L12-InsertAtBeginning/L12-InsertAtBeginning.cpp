#include <iostream>

using namespace std;

class Node {
    public: 
    int value;
    Node* prev;
    Node* next;
};

void InsertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node();
    
    newNode->prev = NULL;
    newNode->value = value;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    
    head = newNode;
}

void PrintLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    
    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    
    PrintLinkedList(head);
    
    return 0;
}