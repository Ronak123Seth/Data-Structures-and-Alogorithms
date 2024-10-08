#include<iostream>
using namespace std;

void sort(int* arr,int n){
    int comparisons = 0;
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j > -1 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
            ++comparisons;
        }
        arr[j+1] = key;
    }
    cout << "Comparisons = " << comparisons << endl;
}
void print(int* arr,int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n = 6;
    int arr[n] = {5,3,6,4,7,2};

    print(arr,n);
    sort(arr,n);
    print(arr,n);

    return 0;
}