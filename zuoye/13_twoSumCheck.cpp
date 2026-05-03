#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool binarySearch(vector<int>& arr, int target, int l, int r) {
    if (l > r) return false;
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return true;
    else if (arr[mid] < target) return binarySearch(arr, target, mid + 1, r);
    else return binarySearch(arr, target, l, mid - 1);
}
bool twoSumCheck(vector<int>& arr, int k, int l, int r) {
    if (l >= r) return false;
    int mid = l + (r - l) / 2;
    bool left_exist = twoSumCheck(arr, k, l, mid);
    bool right_exist = twoSumCheck(arr, k, mid + 1, r);
    if (left_exist || right_exist) return true;
    vector<int> right_arr(arr.begin() + mid + 1, arr.begin() + r + 1);
    sort(right_arr.begin(), right_arr.end());
    for (int i = l; i <= mid; i++) {
        int target = k - arr[i];
        if (binarySearch(right_arr, target, 0, right_arr.size() - 1)) {
            return true;
        }
    }
    return false;
}
int main() {
    vector<int> arr = { 1,3,5,7,9,2,4 };
    int k = 8;
    if (twoSumCheck(arr, k, 0, arr.size() - 1)) {
        cout << "存在符合条件的两个数" << endl;
    }
    else {
        cout << "不存在符合条件的两个数" << endl;
    }
    return 0;
}