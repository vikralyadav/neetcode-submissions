class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> ans;

    int left = 0;

    for (int right = 0; right < nums.size(); right++) {

    
        if (right - left + 1 == k) {

            int maxi = INT_MIN;

        
            for (int i = left; i <= right; i++) {
                maxi = max(maxi, nums[i]);
            }

            ans.push_back(maxi);

          
            left++;
        }
    }

    return ans;
    }
};
