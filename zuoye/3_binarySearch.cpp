#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
int binarySearch(vector<int>& arr, int target, int l, int r) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    cnt++;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearch(arr, target, mid + 1, r);
    else return binarySearch(arr, target, l, mid - 1);
}
int main() {
    vector<int> arr = { 3,5,7,8,11,15,17,22,23,27,29,33 };
    int target = 27;
    int res = binarySearch(arr, target, 0, arr.size() - 1);
    cout << "目标值下标：" << res << endl;
    cout << "比较次数：" << cnt << endl;
    return 0;
}