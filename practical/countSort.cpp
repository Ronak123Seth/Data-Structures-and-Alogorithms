#include<iostream>
#include<vector>
using namespace std;

void countSort(int* arr,int n){
    //Finding maximum element
    int maxEle = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > maxEle){
            maxEle = arr[i];
        }
    }

    //Calculating frequencies
    vector<int> v(maxEle+1,0);
    for(int i=0; i<n; i++){
        v[arr[i]]++;
    }

    //Sorting
    int c=0;
    for(int i=0; i<=maxEle; i++){
        while(v[i] > 0){
            arr[c++] = i;
            v[i]--;
        }
    }
}
int main(){
    int n = 6;
    int arr[n] = {3,3,6,2,1,2};
    countSort(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}