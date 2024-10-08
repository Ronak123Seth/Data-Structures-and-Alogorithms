#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void countingSort(int* arr, int n) {
    // Find the minimum and maximum elements in the array
    int min_element = INT_MAX, max_element = INT_MIN;
    for (int i = 0; i < n; i++) {
        min_element = min(min_element, arr[i]);
        max_element = max(max_element, arr[i]);
    }

    // Create a frequency array to store the count of each element
    vector<int> count(max_element - min_element + 1, 0);

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - min_element]++;
    }

    // Build the sorted array
    int index = 0;
    for (int i = min_element; i <= max_element; i++) {
        while (count[i - min_element] > 0) {
            arr[index++] = i;
            count[i - min_element]--;
        }
    }
}

int main() {
    int arr[6] = {2, 3, 1, 2, 4, 3};
    int n = 6;
    countingSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
