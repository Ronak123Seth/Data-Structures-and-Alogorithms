#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int* arr;
        int size;
        int front;
        int rear;
    public:
        CircularQueue(int size){
            this -> size = size;
            arr = new int[size];
            front = rear = -1;
        }
        void push(int val){
            if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){    //Queue Overflow
                cout<<"Queue OverFlow"<<endl;
                return;
            } 
            else if(front == -1){   //First element
                rear = front = 0;
                arr[rear] = val;
            }
            else if(rear == size-1 && front != 0){    //cyclic queue
                rear = 0;
                arr[rear] = val;
            }
            else{
                rear++;
                arr[rear] = val;
            }
        }
        void pop(){
            if(front == -1){        //queue empty
                cout<<"Queue UnderFlow"<<endl;
                return;
            }
            else if(front == rear){
                front = rear = -1;
            }
            else if(front == size-1){
                front = 0;
            }
            else{
                front++;
            }
        }
        void print(){
            cout<<arr[rear]<<endl;
            cout<<arr[front]<<endl;
        }
};
int main(){
    CircularQueue q(5);
    q.push(10);
    q.push(15);
    q.push(8);
    q.push(3);
    q.push(4);
    q.pop();
    
    q.print();
}