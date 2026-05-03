#include <iostream>
#include <vector>
using namespace std;
int countNum(vector<int>& arr, int x, int l, int r) {
    if (l > r) return 0;
    if (l == r) return arr[l] == x ? 1 : 0;
    int mid = l + (r - l) / 2;
    int left_cnt = countNum(arr, x, l, mid);
    int right_cnt = countNum(arr, x, mid + 1, r);
    return left_cnt + right_cnt;
}
int main() {
    vector<int> arr = { 1,3,5,3,7,3,9,3,2,2,2,2,2};
    int x = 2;
    cout << "元素" << x << "出现次数：" << countNum(arr, x, 0, arr.size() - 1) << endl;
    return 0;
}