#include <iostream>
using namespace std;

void sort(int a[],int start,int end){
    while(start<end){
        if(a[start]==0 && a[end]==0)
            start++;
        else if(a[start]==0 && a[end]==1){
            start++;
            end--;
        }
        else if(a[start]==1 && a[end]==0)
            swap(a[start++],a[end--]);
        else
            end--;
    }
}
void print(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int a[6]={1,1,0,0,1,0};
    print(a,6);
    sort(a,0,6-1);
    print(a,6);
    return 0;
}
