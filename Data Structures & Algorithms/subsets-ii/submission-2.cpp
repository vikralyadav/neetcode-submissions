class Solution {
public:

  void solve(vector<int>& nums,  set<vector<int>> &temp, vector<int> res, int index){


    if(index==nums.size()){
        temp.insert(res);
        return ;
    }


    res.push_back(nums[index]);
    solve(nums, temp, res, index+1);

    res.pop_back();
     solve(nums, temp, res, index+1);


    
  }




    vector<vector<int>> subsetsWithDup(vector<int>& nums) {



      sort(nums.begin(), nums.end());

        set<vector<int>> temp;

        vector<int> res;


        vector<vector<int>> ans;


        solve(nums, temp, res, 0);


        for(auto i:temp){
            ans.push_back(i);
        }




        return ans;



        
    }
};
