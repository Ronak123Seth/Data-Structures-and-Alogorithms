/*#include <iostream>
#include <algorithm>
using namespace std;

void find(int a[],int size){
    sort(a,a+size);
    cout<<"Minimum element is "<<a[0]<<" "<<"Maximum element is "<<a[size-1]<<endl;
}
int main(){
    int a[6]={1,2,3,8,5,6};
    find(a,6);
    return 0;
}*/

//2nd approach
#include <iostream>
using namespace std;

void find(int a[],int size){
    int min,max;
    if(size==1)
        min=max=a[0];
    else if(size==2){
        if(a[0]>a[1])
        {
            min=a[1];
            max=a[0];
        }
        else{
            min=a[0];
            max=a[1];
        }
    }
    else{
        min=a[0];
        max=a[1];
        for(int i=2;i<size;i++){
            if(a[i]>max)
                max=a[i];
            if(a[i]<min)
                min=a[i];
        }
    }
    cout<<"Minimum element is "<<min<<endl;
    cout<<"Maximum element is "<<max<<endl;
}
int main(){
    int a[6]={1,8,4,2,9,-2};
    find(a,6);
    return 0;
}