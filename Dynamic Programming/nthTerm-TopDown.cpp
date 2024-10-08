//Recursion + Memoization
#include<iostream>
#include<vector>
using namespace std;

int solve(int n,vector<int> &dp){
    if(n == 1 || n == 0)
        return n;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = solve(n-1,dp) + solve(n-2,dp);
    return dp[n];
}
int main(){
    int n;
    cout << "Enter the nth term " << endl;
    cin >> n;
    
    vector<int> dp(n+1,-1);
    int ans = solve(n,dp);
    cout << "Nth Term is " << ans << endl;
}