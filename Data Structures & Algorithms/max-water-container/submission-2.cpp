class Solution {
public:
    int maxArea(vector<int>& heights) {


        int ans = 0;


        int left=0;
        int right=heights.size()-1;


        while(left<right){

            int h = min(heights[left], heights[right]);

            int b = right-left;

            int water = h*b;

            ans = max(water, ans);


            if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }




        }




    return ans;





        
    }
};
