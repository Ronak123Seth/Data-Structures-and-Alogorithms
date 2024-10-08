#include<iostream>
#include<stack>
using namespace std;

void sortedStack(stack<int> &s,int num){
    if(s.empty() || s.top() > num){
        s.push(num);
        return;
    }
    int a = s.top();
    s.pop();
    sortedStack(s,num);
    s.push(a);
}
void sort(stack<int> &s){
    if(s.empty())
        return;
    int a = s.top();
    s.pop();
    sort(s);
    sortedStack(s,a);
}
int main(){
    stack<int> s;
    s.push(7);
    s.push(5);
    s.push(9);
    s.push(2);
    s.push(1);
    sort(s);
    for(int i=1;i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}