#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[smallest] < arr[left])
        smallest = left;
    if(right < n && arr[smallest] < arr[right])
        smallest = right;
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
void heapSort(int arr[],int n){
    while(n > 0){
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr,n,0);
    }
}
int main(){
    int n = 6;
    int arr[n] = {5,7,4,2,6,8};

    for(int i=n/2; i>=0; i--){
        heapify(arr,n,i);
    }

    heapSort(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}