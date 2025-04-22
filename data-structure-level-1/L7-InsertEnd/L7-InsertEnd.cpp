#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;
};

void PrintLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    
    cout << endl;
}

void InsertAtEnd(Node* &head, int newNodeValue) {
    Node* newNode = new Node();
    
    newNode->value = newNodeValue;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } 
    else {
        Node* lastNode = head;
        
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        
        lastNode->next = newNode;
    }
}

int main() {
    Node* head = NULL;
    
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    
    PrintLinkedList(head);
    
    return 0;
}