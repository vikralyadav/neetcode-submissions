class Solution {
public:
    int maxArea(vector<int>& heights) {


        int ans = 0;


        for(int i=0;i<heights.size()-1;i++){


            for(int j=i+1;j<heights.size();j++){


                int temp = 1;
                temp=min(heights[i], heights[j])*(j-i);

                ans = max(temp, ans);

            }
        }



    return ans;





        
    }
};
