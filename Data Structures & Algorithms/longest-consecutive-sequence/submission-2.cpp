class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        set<int> s(nums.begin(), nums.end());


        int maxi=0;



        for(auto i: s){

            if(s.find(i-1)==s.end()){
                int len =1;
                int curr=i;

                while(s.find(curr+1)!=s.end()){
                    len++;
                    curr++;
                }

                maxi=max(maxi, len);
            }
        }


        return maxi;


    
    }
};
