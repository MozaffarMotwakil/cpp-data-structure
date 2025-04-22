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

Node* Find(Node* head, int value) {
    while (head != NULL) {
        if (head->value == value) {
            return head;
        }
        
        head = head->next;
    }
    
    return NULL;
}

bool DeleteNode(Node* &head, int value) {
    if (head == NULL) {
        return false;
    } 
    
    Node* previousNode = head;
    Node* currentNode = head;
    
    if (currentNode->value == value) {
        head = currentNode->next;
        delete currentNode;
        return true;
    }
    
    while (currentNode != NULL && currentNode-> value != value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
    if (currentNode == NULL) {
        return false;
    }
    
    if (currentNode-> value == value) {
        previousNode->next = currentNode->next;
        delete currentNode;
        return true;
    }
    
    return false;
}

int main() {
    Node* head = NULL;
    
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    
    PrintLinkedList(head);
    
    DeleteNode(head, 2);
    
    PrintLinkedList(head);
    
    return 0;
}