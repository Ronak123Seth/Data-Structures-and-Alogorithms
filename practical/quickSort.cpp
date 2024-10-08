#include<iostream>
#include<algorithm>
using namespace std;

int partition(int* arr,int s,int e,int &comp){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] < pivot){
            count++;
            comp++;
        } 
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] < pivot){
            comp++;
            i++;
        }
        while(arr[j] > pivot){
            comp++;
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i],arr[j]);
    }
    return pivotIndex;
}
void quicksort(int* arr,int s,int e,int& comp){
    if(s >= e)
        return;
    int p = partition(arr,s,e,comp);
    quicksort(arr,s,p-1,comp);
    quicksort(arr,p+1,e,comp);
}
int main(){
    int n = 5;
    int arr[n] = {3,6,1,2,5};
    int comp = 0;
    quicksort(arr,0,4,comp);
    cout << "Comparison " << comp << endl;
    for(int i=0;i<5;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}