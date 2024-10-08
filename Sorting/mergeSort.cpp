#include<iostream>
using namespace std;
void merge(int* arr,int s,int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int* front = new int[len1];
    int* back = new int[len2];
    int k = s;
    for(int i=0; i<len1; i++){
        front[i] = arr[k++];
    }
    k = mid + 1;
    for(int i=0; i<len2; i++){
        back[i] = arr[k++];
    }
    //merge 2 sorted arrays
    int i=0;
    int j=0;
    int c = s;
    while(i < len1 && j < len2){
        if(front[i] <= back[j])
            arr[c++] = front[i++];
        else
            arr[c++] = back[j++];
    }
    while(i<len1){
        arr[c++] = front[i++];
    }
    while(j<len2){
        arr[c++] = back[j++];
    }
}
void mergesort(int* arr,int s,int e){
    if(s >= e)
        return;
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);

    merge(arr,s,e);
}
int main(){
    int arr[5] = {3,8,2,1,4};
    mergesort(arr,0,4);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}