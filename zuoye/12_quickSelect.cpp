#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int quickSelect(vector<int>& arr, int l, int r, int k) {
    if (l == r) return arr[l];
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    int p_idx = i + 1;
    int left_len = p_idx - l + 1;
    if (k == left_len) return arr[p_idx];
    else if (k < left_len) return quickSelect(arr, l, p_idx - 1, k);
    else return quickSelect(arr, p_idx + 1, r, k - left_len);
}
int main() {
    vector<int> arr = { 5,2,9,1,7,3,8,4,6 };
    int k = 3;
    vector<int> tmp = arr;
    cout << "µÚ" << k << "Ð¡ÔªËØ£º" << quickSelect(tmp, 0, tmp.size() - 1, k) << endl;
    return 0;
}