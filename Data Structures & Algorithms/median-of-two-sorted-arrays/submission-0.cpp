class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {


        vector<int> temp;

        for(auto i :nums1){
            temp.push_back(i);
        }


        for(auto j:nums2){
            temp.push_back(j);
        }

        sort(temp.begin(), temp.end());

        int n = temp.size();

         if(n % 2 != 0){
        return temp[n/2];
    } 
    else{
        return (temp[n/2 - 1] + temp[n/2]) / 2.0;
    }
        
    }
};
