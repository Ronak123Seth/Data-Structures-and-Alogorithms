#include<iostream>
using namespace std;

class Heap{
    private:
        int arr[100];
        int size;
    public:
        Heap(){
            arr[0] = -1;
            size = 0;
        }
        void heapify(int arr[],int n,int i){
            int smallest = i;
            int left = 2*i;
            int right = 2*i + 1;
            if(left <= n && arr[smallest] > arr[left])
                smallest = left;
            if(right <= n && arr[smallest] > arr[right])
                smallest = right;
            if(smallest != i){
                swap(arr[smallest],arr[i]);
                heapify(arr,n,smallest);
            }
        }
        void heapSort(int arr[],int n){
            while(n > 1){
                swap(arr[1],arr[n]);
                n--;
                heapify(arr,n,1);
            }
        }
};
int main(){
    Heap h;
    //Create a array which is to be sorted
    int arr[6] = {-1,5,4,6,2,10};
    int size = 5;
    //Build a heap using heapify function
    for(int i = size/2;i>0;i--){
        h.heapify(arr,size,i);
    }
    //use heapSort
    h.heapSort(arr,size);
    for(int i = 1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}