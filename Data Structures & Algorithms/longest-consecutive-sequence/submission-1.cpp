class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


       set<int> s(nums.begin(), nums.end());



      int maxlen=0;

        for(auto i: s){
            if(s.find(i-1)==s.end()){
                int currentNum = i;
                int currlen=1;

                while(s.find(currentNum+1)!=s.end()){
                    currentNum++;
                    currlen++;
                }

                maxlen = max(maxlen, currlen);
            }
        }


        return maxlen;

        
    }
};
