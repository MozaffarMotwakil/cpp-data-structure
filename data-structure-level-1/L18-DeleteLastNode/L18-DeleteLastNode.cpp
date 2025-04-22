#include <iostream>

using namespace std;

class Node {
    public: 
    int value;
    Node* prev;
    Node* next;
};

void InsertAtEnd(Node* &head, int value) {
    Node* newNode = new Node();
    
    newNode->value = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    }
    else {
        Node* lastNode = head;
        
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        
        newNode->prev = lastNode;
        lastNode->next = newNode;
    }
}

void PrintLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    
    cout << endl;
}

bool DeleteLastNode(Node* &head) {
    if (head == NULL) return false;
    
    Node* lastNode = head;
    
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    
    if (lastNode->prev != NULL) {
        lastNode->prev->next = NULL;
    }
    else {
        head = NULL;
    }
    
    delete lastNode;
    
    return true;
}

int main() {
    Node* head = NULL;
    
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    
    PrintLinkedList(head);
    
    DeleteLastNode(head);
    
    PrintLinkedList(head);
    
    return 0;
}