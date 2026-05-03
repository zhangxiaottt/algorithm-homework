#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        if (nums[l] < nums[r]) return nums[l];
        int mid = l + (r - l) / 2;
        if (nums[mid] >= nums[l]) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return nums[l];
}
int main() {
    vector<int> nums = { 3,5,8,1,2 };
    cout << "旋转数组最小值：" << findMin(nums) << endl;
    vector<int> test = { 4,5,6,7,0,1,2 };
    cout << "示例数组最小值：" << findMin(test) << endl;
    return 0;
}