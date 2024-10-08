#include<iostream>
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
class Stack{
    public:
        Node* head;
        int size;
        int stackSize;
        Stack(){
            head = NULL;
            size = 0;
            stackSize = 5;
        }
        void push(int val){
            if(stackSize == size){
                cout << "Overflow" << endl;
                return;
            }
            Node* newNode = new Node(val);
            ++size;
            if(head == NULL){
                head = newNode;
                return;
            }
            newNode -> next = head;
            head = newNode;
        }
        void pop(){
            if(size == 0){
                cout << "Underflow" << endl;
                return;
            }
            size--;
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
        bool empty(){
            return !head;
        }
        void top(){
            if(empty()){
                cout << "Stack Underflow" << endl;
                return;
            }
            cout << head -> data << endl;
        }
};
int main(){
    Stack s;
    s.push(5);
    s.push(7);
    s.top();
    cout << s.empty() <<endl;
    s.pop();
    s.top();
    s.pop();
    s.pop();
}