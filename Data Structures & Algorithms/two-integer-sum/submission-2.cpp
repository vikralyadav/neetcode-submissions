class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

     map<int, int> mp;

     int n = nums.size();
     vector<int> ans;

       for(int i=0;i<n;i++){


        int temp = target-nums[i];

        if(mp.find(temp)!=mp.end()){
            return {mp[temp], i};
        }

    
        else{
            mp.insert({nums[i], i});

        }
       }


       return {};

        
    }
};
