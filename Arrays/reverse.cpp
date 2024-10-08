#include <iostream>
using namespace std;

void reverse(int a[],int start,int end){
    while(start < end){
        swap(a[start++],a[end--]);
    }
}
void print(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int a[6]={1,2,3,4,5,6};
    print(a,6);
    reverse(a,0,5);
    print(a,6);
    return 0;
}