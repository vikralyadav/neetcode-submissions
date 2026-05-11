class Solution {
public:

   void solve(vector<int> &nums, vector<vector<int>>&ans,vector<int> output,int i){


    if(i == nums.size()){
        ans.push_back(output);
        return;
    }

    solve(nums, ans, output, i+1);


    int ele = nums[i];
    output.push_back(ele);

    solve(nums, ans, output, i+1);


   }



    vector<vector<int>> subsets(vector<int>& nums) {

       vector<vector<int>> ans;
    vector<int> output;

    solve(nums, ans, output, 0);

    return ans;
        
    }
};
