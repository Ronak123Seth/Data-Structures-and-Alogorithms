#include<iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int data;
        Node(int val){
            next = NULL;
            data = val;
        }
};
class Singly{
    public:
    Node* head;
    Node* tail;
    int size;
    
    Singly(){
        head = tail = NULL;
        size = 0;
    }
    void atHead(int val){
        Node* newNode = new Node(val);
        size++;
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    //delete a node
    void deleteAtHead(){
        if(head == NULL){
            cout << "Empty" <<endl;
            return;
        }
        size--;
        if(head -> next == NULL){
            head = tail = NULL;
            return;
        }
        head = head -> next;
    }
    void deleteAtTail(){
        if(tail == NULL){
            cout << "Empty" << endl;
            return;
        }
        size--;
        if(head -> next == NULL){
            tail = head = NULL;
            return;
        }
        Node* temp = head;
        while(temp -> next != tail){
            temp = temp -> next;
        }
        tail = temp;
        tail -> next = NULL;
    }
    void deleteAt(int pos){
        if(pos < 1 || pos > size){
            cout<<"Invalid " << endl;
            return;
        }
        if(pos == 1)
            deleteAtHead();
        else{
            int count = 1;
            Node* temp = head;
            while(count < pos-1){
                count++;
                temp = temp->next;
            }
            if(temp->next == NULL)
                deleteAtTail();
            temp->next = temp->next->next;
        }
        size--;
    }
    void display(){
        if(head == NULL)
            return;
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
    void reverse(){
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};
int main(){
    Singly s;
    s.atHead(6);
    s.atHead(4);
    s.atHead(7);
    s.atHead(77);
    s.atHead(79);
    s.atHead(76);
    s.atHead(788);
    s.deleteAt(1);
    s.deleteAt(5);
    s.display();
    return 0;
}