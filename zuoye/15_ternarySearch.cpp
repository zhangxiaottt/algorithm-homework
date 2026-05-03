#include <iostream>
#include <vector>
using namespace std;
int ternarySearch(vector<int>& arr, int target, int l, int r) {
    if (l > r) return -1;
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;

    if (arr[mid1] == target) return mid1;
    if (arr[mid2] == target) return mid2;

    if (target < arr[mid1]) return ternarySearch(arr, target, l, mid1 - 1);
    else if (target > arr[mid2]) return ternarySearch(arr, target, mid2 + 1, r);
    else return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
}
int main() {
    vector<int> arr;
    for (int i = 0; i < 27; i++) arr.push_back(i * 2);
    int target = 16;
    int res = ternarySearch(arr, target, 0, arr.size() - 1);
    if (res != -1) {
        cout << "目标值下标：" << res << endl;
    }
    else {
        cout << "未找到目标值" << endl;
    }
    cout << "时间复杂度：O(log3 n)" << endl;
    return 0;
}