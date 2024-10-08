#include<iostream>
using namespace std;

void sortSelection(int* arr,int n){
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        if(minIdx != i)
            swap(arr[i],arr[minIdx]);
    }
}
int main(){
    int arr[6] = {3,6,2,7,4,1};
    int n=6;
    sortSelection(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}