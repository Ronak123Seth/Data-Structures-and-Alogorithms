#include<iostream>
#include<vector>
using namespace std;

int solve(int capacity, int *wt, int *val, int i, vector<vector<int>> &dp) {
    if (i == 0) {
        if (wt[i] <= capacity) {
            return val[i];
        } else {
            return 0;
        }
    }
    if (dp[capacity][i] != -1) {
        return dp[capacity][i];
    }
    int incl = 0;
    if (wt[i] <= capacity) {
        incl = val[i] + solve(capacity - wt[i], wt, val, i - 1, dp);
    }
    int excl = solve(capacity, wt, val, i - 1, dp);

    dp[capacity][i] = max(incl, excl);
    return dp[capacity][i];
}

int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(W + 1, vector<int>(n, -1));
    return solve(W, wt, val, n -1, dp);
}

int main() {
    int W, n;
    cout << "Enter the capacity: ";
    cin >> W;
    cout << "Enter number of items: ";
    cin >> n;

    int wt[n] = {4, 5, 1};
    int val[n] = {1, 2, 3};

    int ans = knapSack(W, wt, val, n);
    cout << "Maximum value: " << ans << endl;
}
