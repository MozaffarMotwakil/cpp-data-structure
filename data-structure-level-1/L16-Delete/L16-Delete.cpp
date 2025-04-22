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

Node* Find(Node* head, int value) {
    while (head != NULL) {
        if (head->value == value) {
            return head;
        }
        
        head = head->next;
    }
    
    return NULL;
}

bool Delete(Node* &head, Node* &nodeToDelete) {
    if (head == NULL || nodeToDelete == NULL) {
        return false;
    }
    
    if (head == nodeToDelete) {
        head = nodeToDelete->next;
    }
    
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }
    
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    
    delete nodeToDelete;
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
    
    Node* nodeToDelete = Find(head, 1);
    
    Delete(head, nodeToDelete);
    
    PrintLinkedList(head);
    
    return 0;
}