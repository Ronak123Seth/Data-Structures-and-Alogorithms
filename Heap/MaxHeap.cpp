#include <iostream>
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
            void insert(int val){
                size = size + 1;
                int index = size;
                arr[index] = val;

                while(index > 1){
                    int parent = index/2;
                    if(arr[parent] < arr[index]){
                        swap(arr[parent],arr[index]);
                        index = parent;
                    }
                    else    return;
                }
            }
            void deletefromHeap(){
                if(size == 0){
                    cout<<"Nothing to delete"<<endl;
                    return;
                }
                arr[1] = arr[size];
                size--;

                int i = 1;
                while(i<size){
                    int left = 2*i;
                    int right = 2*i + 1;
                    if(left <= size && arr[i] < arr[left]){
                        swap(arr[i],arr[left]);
                        i = left;
                    }
                    else if(right <= size && arr[i] < arr[right]){
                        swap(arr[i],arr[right]);
                        i = right;
                    }
                    else    return;
                }
            }
            void heapify(int arr[],int n,int i){
                int largest = i;
                int left = 2*i;
                int right = 2*i + 1;
                if(left <= n && arr[largest] < arr[left])
                    largest = left;
                if(right <= n && arr[largest] < arr[right])
                    largest = right;
                if(largest != i){
                    swap(arr[largest],arr[i]);
                    heapify(arr,n,largest);
                }
            }
            void print(){
                for(int i = 1;i<=size;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
};
int main(){
    Heap h1;
    h1.insert(50);
    h1.insert(60);
    h1.insert(30);
    h1.insert(40);
    h1.insert(70);
    h1.print();
    h1.deletefromHeap();
    h1.print();
    int arr[6] = {-1,6,3,7,3,5};
    int n = 5;
    for(int i = n/2;i>0;i--){
        h1.heapify(arr,n,i);
    }
    for(int i = 1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}