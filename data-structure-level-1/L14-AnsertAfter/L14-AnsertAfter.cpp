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
    
    cout << endl;
}

bool InsertAfter(Node* prevNode, int value) {
    if (prevNode == NULL) {
        return false;
    }
    
    Node* newNode = new Node();
    
    newNode->prev = prevNode;
    newNode->value = value;
    newNode->next = prevNode->next;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
    
    return true;
}

Node* Find(Node* head, int value) {
    while (head != NULL) {
        if (head->value == value) {
            return head;
        }
        
        head = head->next;
    }
    
    return NULL;
}

int main() {
    Node* head = NULL;
    
    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);
    
    PrintLinkedList(head);
    
    Node* prevNode = Find(head, 1);
    
    InsertAfter(prevNode, 0);
    
    PrintLinkedList(head);
    
    return 0;
}