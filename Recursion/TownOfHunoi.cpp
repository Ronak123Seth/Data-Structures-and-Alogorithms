#include<iostream>
using namespace std;

void solve(int x,char a,char b,char c){
    if(x==0)    return;
    solve(x-1,a,c,b);
    cout<<a<<"->"<<c<<endl;
    solve(x-1, b,a,c);
}

int main(){
    int rings;
    cout<<"Enter number of rings "<<endl;
    cin >> rings;
    solve(rings,'A', 'B', 'C');
}