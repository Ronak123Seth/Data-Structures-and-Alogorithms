#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s;
    cout<<"enter any string "<<endl;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    string ans="";
    while(!st.empty()){
        char ch = st.top();
        ans+=ch;
        st.pop();
    }
    cout<<ans<<endl;
}
