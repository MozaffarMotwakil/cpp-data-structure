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

void InsertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node();
    
    newNode->value = value;
    newNode->next = head;
    
    head = newNode;
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

void InsertAfter(Node* previousNode, int newNodeValue) {
    if (previousNode == NULL) {
        cout << "\nPrevious Node can not be NULL\n";
        return;
    }
    
    Node* newNode = new Node();
    
    newNode->value = newNodeValue;
    newNode->next = previousNode->next;
    
    previousNode->next = newNode;
}

int main() {
    Node* head = NULL;
    
    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);
    
    PrintLinkedList(head);
    
    Node* previousNode = Find(head, 3);
    
    InsertAfter(previousNode, 2);
    
    PrintLinkedList(head);
    
    return 0;
}