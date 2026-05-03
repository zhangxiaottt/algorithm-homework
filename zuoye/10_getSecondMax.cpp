#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
pair<int, int> getSecondMax(vector<int>& arr, int l, int r) {
    if (l == r) return { arr[l], INT_MIN };
    if (r - l == 1) return { max(arr[l], arr[r]), min(arr[l], arr[r]) };
    int mid = l + (r - l) / 2;
    pair<int, int> left = getSecondMax(arr, l, mid);
    pair<int, int> right = getSecondMax(arr, mid + 1, r);
    int total_max, total_second;
    if (left.first > right.first) {
        total_max = left.first;
        total_second = max(left.second, right.first);
    }
    else {
        total_max = right.first;
        total_second = max(right.second, left.first);
    }
    return { total_max, total_second };
}
int main() {
	vector<int> arr = { 5,2,9,1,7,3,8,4 };      //例子数组
    pair<int, int> res = getSecondMax(arr, 0, arr.size() - 1);
    cout << "最大值：" << res.first << endl;
    cout << "第二大值：" << res.second << endl;
    return 0;
}