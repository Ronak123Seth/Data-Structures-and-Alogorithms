#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }
};
class Queue{
    public:
        Node* head;
        Node* tail;
        int size;
        Queue(){
            head = tail = NULL;
            size = 0;
        }
        void push_back(int val){
            Node* newNode = new Node(val);
            size++;
            if(tail == NULL){
                head = tail = newNode;
                tail -> next = head;
                return;
            }
            newNode -> next = head;
            tail -> next = newNode;
            tail = newNode;
        }
        void pop_front(){
            if(head == NULL){
                cout << "Queue Underflow" << endl;
                return;
            }
            if(size == 1){
                head = tail = NULL;
                size--;
                return;
            }
            size--;
            Node* temp = head;
            head = head -> next;
            tail -> next = head;
            delete temp;
        }
        bool empty(){
            return (head == NULL) ? true : false;
        }
        void front(){
            if(empty())
                cout<<"No Output"<<endl;
            else
                cout << head->data<<endl;
        }
        void back(){
            if(!empty())
                cout << tail -> data <<endl;
            else
                cout << "No Output" << endl;
        }
        int size1(){return size;}
};
int main(){
    Queue q;
    // q.push_back(5);
    q.push_back(6);
    q.push_back(54);
    q.push_back(99);
    q.pop_front();
    q.front();
    q.back();
    cout<<q.empty() << endl;
    q.pop_front();
    q.pop_front();
    q.front();
    q.back();
    cout<<q.empty() << endl;
}