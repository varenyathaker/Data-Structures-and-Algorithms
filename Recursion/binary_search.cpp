#include <iostream>
using namespace std;

int bin_search(int arr[], int s, int e, int val) {
    if (s > e) return -1; 

    int m = s + (e - s) / 2;

    if (arr[m] == val) return m; 
    if (arr[m] < val) return bin_search(arr, m + 1, e, val);
    return bin_search(arr, s, m - 1, val); 
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    int res = bin_search(arr, 0, n - 1, val);
    if (res == -1) cout << "Value not found\n";
    else cout << "Value found at index " << res << endl;
    return 0;
}
