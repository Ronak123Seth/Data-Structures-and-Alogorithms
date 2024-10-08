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
        void insert(int val){
            size+= 1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index/2;
                if(arr[index] < arr[parent]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else    return;
            } 
        }
        void deleteRoot(){
            if(size == 0){
                cout<<"Heap is empty."<<endl;
                return;
            }
            arr[1] = arr[size];
            size--;
            
            int i = 1;
            while(i<size){
                int left = 2*i;
                int right = 2*i + 1;
                if(arr[i] > arr[left] && left <= size){
                    swap(arr[i],arr[left]);
                    i = left;
                }
                else if(arr[i] > arr[right] && right <= size){
                    swap(arr[i],arr[right]);
                    i = right;
                }
                else    return;
            }
        }
        void print(){
            for(int  i=1; i<=size; i++){
                cout << arr[i] << " " ;
            }
            cout << endl;
        }
};
int main(){
    Heap h;
    cout << "Enter the size of the heap."<<endl;
    int s;
    cin >> s;
    int n;
    for(int i=1;i<=s;i++){
        cout<<"Enter element to be inserted."<<endl;
        cin >> n;
        h.insert(n);
        h.print();
    }
    cout<<"Deleting root node :-> "<<endl;
    h.deleteRoot();                                
    h.print();

}