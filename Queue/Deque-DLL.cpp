#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val){
            data = val;
            next = prev = NULL;
        }
};
class Deque{
    public:
        Node* head;
        Node* tail;
        int size;
        Deque(){
            head = tail = NULL;
            size = 0;
        }
        void push_back(int val){
            Node* newNode = new Node(val);
            size++;
            if(tail == NULL){
                head = tail = newNode;
                return;
            }
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        void push_front(int val){
            Node* newNode = new Node(val);
            size++;
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            newNode -> next = head;
            head -> prev = newNode;
            head = head -> prev;
        }
        bool empty(){
            return (head == NULL)? true : false;
        }
        void size1(){
            cout << size << endl;
        }
        void pop_back(){
            if(empty())
                return;
            size--;
            Node* temp = tail;
            tail = tail -> prev;
            tail -> next = NULL;
            delete temp;
        }
        void pop_front(){
            if(empty())
                return;
            size--;
            Node* temp = head;
            head = head -> next;
            head -> prev = NULL;
            delete temp;
        }
        void front(){
            if(!empty())
                cout << head -> data <<endl;
        }
        void rear(){
            if(!empty())
                cout << tail -> data << endl;
        }
};
int main(){
    Deque d;
    d.push_back(5);
    d.push_back(8);
    d.push_front(100);
    // d.pop_back();
    d.pop_front();
    d.rear();
    d.front();
    
}