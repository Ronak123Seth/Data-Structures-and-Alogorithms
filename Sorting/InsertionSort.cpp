#include<iostream>
using namespace std;

void insertionSort(int* a, int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j > -1 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    return;
}

int main() {
    int a[6] = {3, 7, 2, 5, 1, 9};
    int n = sizeof(a) / sizeof(int);

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    insertionSort(a, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
