#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int arr[6] = {5, 6, 2, 3, 1, 7};
    int n = 6;
    stack<int> s;
    vector<int> ans;

    for(int i=n-1; i>=0; i--){
        while(!s.empty() && s.top() >= arr[i]){
            s.pop();
        }
        if(s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());
        if(!s.empty())
            s.pop();
        s.push(arr[i]);
    }
    for(int i=n-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}