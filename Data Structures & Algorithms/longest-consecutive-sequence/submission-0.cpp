class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


         set<int> s(nums.begin(), nums.end());

    int maxLen = 0;

    for (int num : s) {


        if (s.find(num - 1) == s.end()) {

            int currNum = num;
            int currLen = 1;

            while (s.find(currNum + 1) != s.end()) {
                currNum++;
                currLen++;
            }

            maxLen = max(maxLen, currLen);
        }
    }

    return maxLen;



      

    }
};
