#include <iostream>
using namespace std;

//Moving all negative to right side
void moveR(int a[],int size) {
        int nonNeg=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]>=0)
            {
                swap(a[i],a[nonNeg]);
                nonNeg++;
            }
        }
    }

//Moving all negatives to left side
void moveL(int a[],int size){
    int nonNeg=size-1;
    for(int i=size-1;i>=0;i--){
        if(a[i]>=0){
            swap(a[i],a[nonNeg--]);
        }
    }
}

void print(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int a[8] = {1, -1, 2, -2, 0, 0, -3, 1}; 
    print(a,8);
    moveL(a,8);
    print(a,8);
    moveR(a,8);
    print(a,8);
    return 0;
}