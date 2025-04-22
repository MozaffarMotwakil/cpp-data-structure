#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;
};

bool DeleteLastNode(Node* &head) {
    if (head == NULL) {
        return false;
    }
    
    Node* currentNode = head;
    Node* previousNode = head;
    
    if (currentNode->next == NULL) {
        head = currentNode->next;
        delete currentNode;
        return true;
    }
    
    while (currentNode->next != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
    previousNode->next = NULL;
    delete currentNode;
    
    return true;
}

void PrintLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    
    cout << endl;
}

void InsertAtEnd(Node* &head, int value) {
    Node* newNode = new Node();
    
    newNode->value = value;
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
    
    PrintLinkedList(head);
    
    DeleteLastNode(head);
    
    PrintLinkedList(head);
     
    return 0;
}