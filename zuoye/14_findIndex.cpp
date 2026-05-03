#include <iostream>
#include <vector>
using namespace std;
int findIndex(vector<int>& arr, int l, int r) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == mid) return mid;
    else if (arr[mid] > mid) return findIndex(arr, l, mid - 1);
    else return findIndex(arr, mid + 1, r);
}
int main() {
    vector<int> arr = { -1,0,2,4,5,7,9 };
    int res = findIndex(arr, 0, arr.size() - 1);
    if (res != -1) {
        cout << "符合条件的下标：" << res << endl;
    }
    else {
        cout << "无符合条件的下标" << endl;
    }
    return 0;
}