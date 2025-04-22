#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

void PrintLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
}

void InsertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node();
    
    newNode->data = data;
    newNode->next = head;
    
    head = newNode;
}

int main() {
    Node* head = NULL;
    
    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);
    
    PrintLinkedList(head);
    
    return 0;
}