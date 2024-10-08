#include<iostream>
using namespace std;

bool search(int *arr,int size,int k){
    if(size == 0)
        return false;
    if(arr[0] == k)
        return true;
    else
        return search(arr+1,size-1,k);
}
int main(){
    int arr[5] = {1,2,4,5,3};
    if(search(arr,5,7))
        cout<<"It is present"<<endl;
    else    
        cout<<"Not present"<<endl;
}