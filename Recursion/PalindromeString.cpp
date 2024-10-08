#include<iostream>
using namespace std;

bool reverse(string &str,int i,int j){
    if(i>j)
        return true;
    if(str[i] != str[j])
        return false;
    else
        reverse(str,i+1,j-1);
}
int main(){
    string s;
    cout<<"Enter "<<endl;
    cin >> s;
    bool flag = reverse(s,0,s.length()-1);
    if(flag)
        cout<<"yes"<<endl;
    else
        cout<<"No"<<endl;
}