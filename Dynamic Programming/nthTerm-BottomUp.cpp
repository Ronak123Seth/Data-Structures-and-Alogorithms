//Tableuation Method
#include<iostream>
#include<vector>
using namespace std;

int fib(int n){
    vector<int> dp(n+1,-1);
    dp[1] = 0;
    dp[2] = 1;
    
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

}
int main(){
    int n;
    cout <<"Enter the nth Term "<<endl;
    cin >> n;

    cout << fib(n) << endl;
}