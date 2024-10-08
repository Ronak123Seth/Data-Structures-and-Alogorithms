#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int arr[5] = {6,8,9,3,3};
    int n = 5;
    stack<int> s;
    vector<int> ans;

    for(int i=n-1; i>=0; i--){
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }
        if(s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());
        s.push(arr[i]);
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 1;
}
