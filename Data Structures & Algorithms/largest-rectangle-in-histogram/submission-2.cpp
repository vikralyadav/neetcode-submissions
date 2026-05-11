class Solution {
public:


  void getPrevSmall(vector<int>& heights, int n, vector<int>& prev) {

    stack<int> s;
    s.push(-1);

    for(int i = 0; i < n; i++) {

        while(s.top() != -1 && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        prev[i] = s.top();   
        s.push(i);
    }
}


   void getNextSmall(vector<int>& heights,int n, vector<int>& next){


    stack<int> s;
    s.push(-1);

    for(int i = n - 1; i >= 0; i--) {

        while(s.top() != -1 && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        next[i] = (s.top() == -1) ? n : s.top();
        s.push(i);

    }
   }
 int largestRectangleArea(vector<int>& heights) {


        int n = heights.size();
        vector<int> prev(n);
        vector<int> next(n);


        getPrevSmall(heights, n, prev);

        getNextSmall(heights, n, next);




        int ans = 0;



        for(int i=0;i<n;i++){


            int b =next[i]-prev[i]-1;


            int area = b*heights[i];


        ans = max(area , ans);


        }



        return ans;







        
    }
};
