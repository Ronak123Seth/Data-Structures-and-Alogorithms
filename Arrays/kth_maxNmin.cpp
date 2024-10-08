/*#include <iostream>
#include <algorithm>
using namespace std;

void find(int a[],int size,int k){
    sort(a,a+size);
    cout<<k<<"th"<<" Max element is "<<a[size-k]<<endl;
    cout<<k<<"th"<<" Min element is "<<a[k-1]<<endl;
}
int main(){
    int a[6]={1,8,4,2,9,-2};
    find(a,6,3);
    return 0;
}*/

//2nd Method (QuickSelect Algo)
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> a,int size,int k){
    int pivot=a[0];
    vector<int> left;
    vector<int> right;
    vector<int> equal;
    for(int i=0;i<size;i++){
        if(a[i]<pivot)
            left.push_back(a[i]);
        else if(a[i]>pivot)
            right.push_back(a[i]);
        else
            equal.push_back(a[i]);
    }
    if(k<=left.size())
        return find(left,left.size(),k);
    else if(k<=(left.size()+equal.size()))
        return pivot;
    else
        return find(right,right.size(),k-left.size()-equal.size());
}
int main(){
    int k;
    cout<<"Enter the value of k."<<endl;
    cin>>k;
    vector<int> vec1 = {1,8,4,2,9,-2};
    int size=6;
    int min=find(vec1,size,k);
    int max=find(vec1,size,size-k+1);  //size-k+1;
    cout<<k<<"th"<<" Max element is "<<max<<endl;
    cout<<k<<"th"<<" Min element is "<<min<<endl;
}
