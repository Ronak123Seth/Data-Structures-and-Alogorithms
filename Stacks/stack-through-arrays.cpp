#include<iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int top;
        int size;
    public:
        Stack(int size){
            this->size = size;
            top = -1;
            arr = new int[size];
        }
        void push(int val){
            if(top == size-1)
                cout<<"Stack is full."<<endl;
            else{
                top++;
                arr[top] = val;
            }
        }
        void pop(){
            if(top == -1)
                cout<<"Stack is empty."<<endl;
            else{
                top--;
            }
        }
        void peak(){
            if(top >= 0)
                cout<<arr[top]<<endl;
            else
                cout<<"Stack is empty."<<endl;
        }
        void empty(){
            if(top == -1)
                cout<<"Stck is empty."<<endl;
            else
                cout<<"Not empty"<<endl;
        }
};
int main(){
    Stack s1(5);
    s1.push(10);
    s1.push(10);
    s1.push(10);
    s1.push(10);
    s1.push(100);
    s1.push(59);
    s1.peak();
}