#include <bits/stdc++.h>
#define usigned int;
using namespace std;

void swap(unsigned* a, unsigned* b) { 
    unsigned temp = *a;
    *a = *b;
    *b = temp;
}

unsigned partition(vector<unsigned> &arr, unsigned left, unsigned right, unsigned key) {
    while (left < right) {
        while (arr[left] < key) left++;
        while (arr[right] > key) right--;
        // cout << arr[left] << " " << key << " " << arr[right] << endl;
        if (left <= right) swap(&arr[left], &arr[right]);
    }
    return right;
}

void quickSort(vector<unsigned> &arr, int left, int right) {
    if (left >= right) return;
    
    unsigned key = arr[(left + right) / 2];

    unsigned pivot = partition(arr, left, right, key);

    quickSort(arr, left, pivot);
    quickSort(arr, pivot + 1, right);
}

int main() {
    vector<unsigned> arr = { 5, 4, 6, 2, 7, 8, 1, 0, 9, 3 };

    quickSort(arr, 0, arr.size() - 1);

    for (auto element : arr) {
        cout << element << " ";
    }
    return 0;
}