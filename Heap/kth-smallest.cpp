#include<iostream>
#include<queue>
using namespace std;

int kthsmallest(int arr[],int k,int n){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[5] = {1,2,5,6,3};
    int x = kthsmallest(arr,2,5);
    cout<<x<<endl;
}