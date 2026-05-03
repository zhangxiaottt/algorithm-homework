#include <iostream>
#include <vector>
using namespace std;
int findInsertPos(vector<int>& arr, int k, int l, int r) {
    if (l > r) return l;
    int mid = l + (r - l) / 2;
    if (arr[mid] == k) return mid;
    else if (arr[mid] < k) return findInsertPos(arr, k, mid + 1, r);
    else return findInsertPos(arr, k, l, mid - 1);
}
int main() {
    vector<int> arr = { 1,3,5,6,8,10,12 };
    int k = 2;
    int pos = findInsertPos(arr, k, 0, arr.size() - 1);
    cout << "插入点下标：" << pos << endl;
    return 0;
}