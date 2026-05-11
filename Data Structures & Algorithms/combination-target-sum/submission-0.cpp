class Solution {
public:
   void solve(vector<int>& nums, int target, int index, vector<int>& current, vector<vector<int>>& ans){
    
    if(target == 0){
        ans.push_back(current);
        return;
    }

    if(index >= nums.size() || target < 0){
        return;
    }


    current.push_back(nums[index]);
    solve(nums, target - nums[index], index, current, ans); 
    current.pop_back();


    solve(nums, target, index + 1, current, ans);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    
    vector<vector<int>> ans;
    vector<int> current;

    solve(nums, target, 0, current, ans);

    return ans;
        
    }
};
