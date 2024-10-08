#include <iostream>
using namespace std;

void sort(int a[],int s,int e,int c){
    //s->start
    //e->end
    //c->current
    while(c<e){
        if(a[c]==0)
            swap(a[c++],a[s++]);
        else if(a[c]==1)
            c++;
        else
            swap(a[c],a[e--]);
    }
}
void print(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int a[8]={1,1,2,0,0,2,1,0};
    print(a,8);
    sort(a,0,8-1,0);
    print(a,8);
    return 0;
}