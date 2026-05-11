class Solution {
public:
    int trap(vector<int>& height) {

 int n = height.size();
    int water = 0;

    for (int i = 1; i < n - 1; i++) {

        int leftMax = 0, rightMax = 0;

       
        for (int l = 0; l <= i; l++)
            leftMax = max(leftMax, height[l]);

       
        for (int r = i; r < n; r++)
            rightMax = max(rightMax, height[r]);

        water += min(leftMax, rightMax) - height[i];
    }

    return water;
    }
};
