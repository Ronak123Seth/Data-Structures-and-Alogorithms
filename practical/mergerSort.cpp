#include<iostream>
using namespace std;

void merge(int* arr,int s,int e,int &comp){
    int mid = s + (e - s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int* front = new int[len1];
    int* back = new int[len2];

    int k = s;
    for(int i=0; i<len1; i++){
        front[i] = arr[k++];
    }
    k = mid+1;
    for(int i=0; i<len2; i++){
        back[i] = arr[k++];
    }

    //merging
    int i=0,j=0,c=s;
    while(i < len1 && j < len2){
        if(front[i] <= back[j]){
            arr[c++] = front[i++];
        }
        else{
            arr[c++] = back[j++];
        }
        ++comp;  
        
    }
    while(i < len1){
        arr[c++] = front[i++];
    }
    while(j < len2){
        arr[c++] = back[j++];
    } 

    delete []front;
    delete []back;
}
void sort(int*arr,int s,int e,int &comp){
    if(s >= e)    return;

    int mid = s + (e - s)/2;
    sort(arr,s,mid,comp);
    sort(arr,mid+1,e,comp);

    merge(arr,s,e,comp);
}
void print(int* arr,int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n = 6;
    int comp = 0;
    int arr[n] = {5,4,7,5,6,2};

    print(arr,n);
    sort(arr,0,n-1,comp);
    cout << "Number of Comparisons " << comp << endl;
    print(arr,n);
}