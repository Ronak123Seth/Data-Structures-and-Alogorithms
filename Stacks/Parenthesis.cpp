#include <iostream>
#include <stack>
using namespace std;

bool check(char *a, int n) {
    stack<char> s;
    for (int i = 0; i < n; i++) {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
            s.push(a[i]);
        else {
            if (s.empty())
                return false;
            if ((s.top() == '(' && a[i] == ')') || (s.top() == '{' && a[i] == '}') || (s.top() == '[' && a[i] == ']'))
                s.pop();
            else
                return false;
        }
    }
    if(s.empty())
        return true;
    return false;
}

int main() {
    char a[16] = {'(','(','(',')','(',')','{','(','[','(',')',']',')','}',')',')'};
    if (check(a, 16))
        cout << "Correct" << endl;
    else
        cout << "Not Correct" << endl;
    return 0;
}
