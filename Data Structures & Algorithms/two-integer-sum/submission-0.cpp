class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {



        map<int,int> mp;   // number -> index

    for(int i = 0; i < nums.size(); i++) {

        int temp = target - nums[i];

        // if complement already exists
        if(mp.find(temp) != mp.end()) {
            return {mp[temp], i};
        }

        // store current number
        mp[nums[i]] = i;
    }

    return {};  // if no solution
}

};
