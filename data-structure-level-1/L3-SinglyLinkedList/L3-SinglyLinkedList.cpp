#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
    
    return 0;
}