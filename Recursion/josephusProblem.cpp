#include<iostream>
using namespace std;

int solve(int n, int k){
    int winning  = 0;
    for(int i=2; i<=n; i++){
        winning = (winning + k) % i;
    }
    return winning;
}
int main(){
    int n = 5;
    int k = 2;
    cout << solve(n, k) + 1<< endl;
}