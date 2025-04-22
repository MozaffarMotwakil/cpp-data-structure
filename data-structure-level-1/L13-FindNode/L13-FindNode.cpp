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
    
    Node* node = Find(head, 1);
    
    if (node != NULL) {
        cout << "\nNode is Found\n";
    } 
    else {
        cout << "\nNode is not Found\n";
    }
    
    return 0;
}