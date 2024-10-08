#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &m, vector<vector<int>> &visited) {
    if (x >= 0 && y >= 0 && x < m.size() && y < m[0].size() && m[x][y] == 1 && visited[x][y] == 0)
        return true;
    else
        return false;
}

void solve(vector<vector<int>> &m, vector<vector<int>> &visited, int x, int y, string &path, vector<string> &ans, int n) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // moveDown
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, m, visited)) {
        path.push_back('D');
        solve(m, visited, newx, newy, path, ans, n);
        path.pop_back();
    }
    // moveLeft
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, m, visited)) {
        path.push_back('L');
        solve(m, visited, newx, newy, path, ans, n);
        path.pop_back();
    }
    // moveRight
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, m, visited)) {
        path.push_back('R');
        solve(m, visited, newx, newy, path, ans, n);
        path.pop_back();
    }
    // moveUp
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, m, visited)) {
        path.push_back('U');
        solve(m, visited, newx, newy, path, ans, n);
        path.pop_back();
    }
    visited[x][y] = 0;
}

int main() {
    vector<string> ans;
    int n;
    cout << "Enter the size of the maze." << endl;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n)); // Resize and initialize the maze
    vector<vector<int>> visited(n, vector<int>(n, 0)); // Resize and initialize the visited matrix

    cout << "Enter 1 if path exists else enter 0" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    if (m[0][0] == 0) {
        cout << "False" << endl;
        return 0;
    }

    string path = "";
    solve(m, visited, 0, 0, path, ans, n);

    if (ans.empty()) {
        cout << "No paths found." << endl;
    } else {
        cout << "Paths found:" << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }

    return 0;
}
