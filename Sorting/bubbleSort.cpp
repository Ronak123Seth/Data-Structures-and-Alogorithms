#include<iostream>
using namespace std;

void sortBubble(int* arr,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
int main(){
    int arr[6] = {3,6,2,7,4,1};
    int n=6;
    sortBubble(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}