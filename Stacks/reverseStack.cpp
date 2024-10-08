#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int num){
    if(s.empty()){
        s.push(num);
        return;
    }
    int a = s.top();
    s.pop();
    insertAtBottom(s,num);
    s.push(a);
}
void reverse(stack<int> &s){
    if(s.empty())
        return;
    int a = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,a);
}
int main(){
    stack<int> s;
    s.push(7);
    s.push(5);
    s.push(9);
    s.push(2);
    s.push(1);
    for(int i=1;i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    s.push(7);
    s.push(5);
    s.push(9);
    s.push(2);
    s.push(1);
    
    reverse(s);

    for(int i=1;i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}