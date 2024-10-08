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
            size+=1;
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
        void deleteH(){
            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i<size){
                int left = 2*i;
                int right = 2*i + 1;
                if(left <= size && arr[i] < arr[left]){
                    swap(arr[left],arr[i]);
                    i = left;
                }
                if(right <= size && arr[i] < arr[right]){
                    swap(arr[i],arr[right]);
                    i = right;
                }
                else    return;
            }
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    Heap h;
    h.insert(5);
    h.insert(10);
    h.insert(3);
    h.insert(15);
    h.insert(99);
    h.insert(18);
    h.deleteH();
    h.print();
}