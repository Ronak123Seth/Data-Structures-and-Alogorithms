#include<iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int size;
        int top;
    public:
        Queue(int s){
            size = s;
            arr = new int[size];
            top = -1;
        }
        void push(int val){
            if(top == size-1){
                cout << "Queue Overflow" << endl;
                return;
            }
            arr[++top] = val;
        }
        void pop(){
            if(top == -1){
                cout << "Queue Underflow" << endl;
                return;
            }
            cout << "Deleted element is " << arr[top] << endl;
            --top;
        }
};