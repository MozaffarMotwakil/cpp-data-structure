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

Node* Find(Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
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
    
    Node* node = Find(head, 5);
    
    if (node != NULL) {
        cout << "\nNode is Found\n";
    } 
    else {
        cout << "\nNode is not Found\n";
    }
    
    return 0;
}