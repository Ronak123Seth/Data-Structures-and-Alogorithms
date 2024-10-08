#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = this;
    }

    void insertNode(Node* &tail, int element, int d) {
            Node* curr = tail;
            while (curr->data != element) {
                curr = curr->next;
                if (curr == tail) {
                    // Element not found, break to avoid infinite loop
                    break;
                }
            }
            Node* temp = new Node(d);
            temp->next = curr->next;
            curr->next = temp;
        }

    void show(Node* tail) {
        Node* temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail);
        cout << endl;
    }
};

int main() {
    Node* n1 = new Node(12);
    Node* tail = n1;
    
    n1->insertNode(tail, 12, 10);
    n1->insertNode(tail, 10, 15);
    n1->insertNode(tail, 12, 17);

    n1->show(tail);

    return 0;
}
