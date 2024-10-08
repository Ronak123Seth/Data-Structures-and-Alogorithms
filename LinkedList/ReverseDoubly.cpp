#include<iostream>
using namespace std;

class Node{
    public:
        Node* next;
        Node* prev;
        int data;
        Node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};
class Doubly{
    public:
        Node* head;
        Node* tail;
        int size;
        Doubly(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        void atHead(int val){
            Node* newNode = new Node(val);
            ++size;
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
        void atTail(int val){
            Node* newNode=  new Node(val);
            ++size;
            if(tail == NULL){
                head = tail = newNode;
                return;
            }
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        void deleteAtHead(){
            if(head == NULL){
                cout << "Nothing to delete." << endl;
                return;
            }
            Node* temp = head;
            head = head -> next;
            head -> prev = NULL;
            temp -> next = NULL;
            delete temp;
        }
        void deleteAtTail(){
            if(tail == NULL){
                cout <<"Nothing to delete." << endl;
                return;
            }
            Node* temp = tail;
            tail = tail -> prev;
            tail -> next = NULL;
            temp -> prev = NULL;
            delete temp;
        }
        void display(){
            if(head == NULL){
                cout <<"Nothing to display"<<endl;
                return;
            }
            Node* temp = head;
            while(temp != NULL){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
        void reverse(){
            if(head == NULL)
                return;
            Node* temp = tail;
            while(temp != NULL){
                cout << temp -> data << " ";
                temp = temp -> prev;
            }
            cout << endl;
        }
};
int main(){
    Doubly d;
    d.atHead(5);
    d.atTail(6);
    d.atHead(7);
    d.atHead(8);
    // d.deleteAtTail();
    // d.deleteAtHead();
    d.display();
    d.reverse();
    d.display();
    return 0;
}