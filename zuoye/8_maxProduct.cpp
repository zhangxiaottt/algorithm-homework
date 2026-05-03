#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
long long maxProduct(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int mid = l + (r - l) / 2;
    long long left_max = maxProduct(nums, l, mid);
    long long right_max = maxProduct(nums, mid + 1, r);
    long long tmp = 1;
    long long l_max = nums[mid], l_min = nums[mid];
    for (int i = mid; i >= l; i--) {
        tmp *= nums[i];
        l_max = max(l_max, tmp);
        l_min = min(l_min, tmp);
    }
    tmp = 1;
    long long r_max = nums[mid + 1], r_min = nums[mid + 1];
    for (int i = mid + 1; i <= r; i++) {
        tmp *= nums[i];
        r_max = max(r_max, tmp);
        r_min = min(r_min, tmp);
    }
    long long cross_max = max(l_max * r_max, l_min * r_min);
    return max(max(left_max, right_max), cross_max);
}
int main() {
    vector<int> nums = { 2,3,-2,4,-1 };//例子
    cout << "最大连续子数组积：" << maxProduct(nums, 0, nums.size() - 1) << endl;
    return 0;
}
//应该不能采用4.5节的那个