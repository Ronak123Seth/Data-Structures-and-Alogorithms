#include<iostream>
using namespace std;

int power(int a,int e){
    if(e == 0)
        return 1;
    if(e == 1)
        return a;
    int ans = power(a,e/2);
    if(e % 2 == 1)
        return ans*= ans*a;
    return ans*ans;
}
int main(){
    int ans = power(2,10);
    cout<<ans<<endl;
}