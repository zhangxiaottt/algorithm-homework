#include <iostream>
#include <vector>
using namespace std;
long long mergeCount(vector<int>& arr, int l, int mid, int r) {
    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    long long cnt = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        }
        else {
            tmp[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];

    for (int p = 0; p < tmp.size(); p++) {
        arr[l + p] = tmp[p];
    }
    return cnt;
}
long long reverseCount(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    long long left_cnt = reverseCount(arr, l, mid);
    long long right_cnt = reverseCount(arr, mid + 1, r);
    long long cross_cnt = mergeCount(arr, l, mid, r);
    return left_cnt + right_cnt + cross_cnt;
}
long long reversePairs(vector<int>& A) {
    return reverseCount(A, 0, A.size() - 1);
}
int main() {
    vector<int> test1 = { 2,4,1,3,5 };
    cout << "示例数组逆序对个数：" << reversePairs(test1) << endl;
    return 0;
}