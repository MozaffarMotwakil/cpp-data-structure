#include <iostream>

using namespace std;

class Node {
    public: 
    int value;
    Node* prev;
    Node* next;
};

int main() {
    Node* head = NULL;
    
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    
    head = node1;
    
    node1->prev = NULL;
    node1->value = 10;
    node1->next = node2;
    
    node2->prev = node1;
    node2->value = 20;
    node2->next = node3;
    
    node3->prev = node2;
    node3->value = 30;
    node3->next = NULL;
    
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    
    return 0;
}