#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int maxSubSum(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int mid = l + (r - l) / 2;
    int left_max = maxSubSum(nums, l, mid);
    int right_max = maxSubSum(nums, mid + 1, r);
    int tmp = 0;
    int l_max = INT_MIN;
    for (int i = mid; i >= l; i--) {
        tmp += nums[i];
        l_max = max(l_max, tmp);
    }
    tmp = 0;
    int r_max = INT_MIN;
    for (int i = mid + 1; i <= r; i++) {
        tmp += nums[i];
        r_max = max(r_max, tmp);
    }
    int cross_max = l_max + r_max;
    return max(max(left_max, right_max), cross_max);
}
int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << "最大连续子数组和：" << maxSubSum(nums, 0, nums.size() - 1) << endl;
    return 0;
}