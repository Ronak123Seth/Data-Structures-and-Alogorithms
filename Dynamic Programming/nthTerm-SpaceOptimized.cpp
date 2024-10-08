#include<iostream>
using namespace std;

int main(){
    int n;
    cout <<"Enter the term "<<endl;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;
    int curr;
    for(int i=1; i<=n-2; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << curr << endl;
}