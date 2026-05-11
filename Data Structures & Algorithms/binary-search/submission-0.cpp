class Solution {
public:
  int solve(vector<int>& nums, int target, int s, int e) {
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (nums[mid] == target)
        return mid;

    if (nums[mid] > target)
        return solve(nums, target, s, mid - 1);

    return solve(nums, target, mid + 1, e);
}

int search(vector<int>& nums, int target) {

    return solve(nums, target, 0, nums.size() - 1);
        
    }
};
