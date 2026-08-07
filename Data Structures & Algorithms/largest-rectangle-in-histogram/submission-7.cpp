class Solution {
public:



   void getNext(vector<int> &heights, vector<int> &next){


    stack<int> s;
    int n = heights.size();



    for(int i=n-1;i>=0;i--){
        while(!s.empty() && heights[s.top()]>=heights[i]){
            s.pop();

        }


        next[i]= s.empty() ? n : s.top();
        s.push(i);
    }
  }


  void getPrev(vector<int> &heights, vector<int> &prev){


    stack<int> s;
    int n = heights.size();



    for(int i=0;i<n;i++){
        while(!s.empty() && heights[s.top()]>=heights[i]){
            s.pop();

        }

        prev[i]= s.empty() ? 0 : s.top();
        s.push(i);
    }
  }




    int largestRectangleArea(vector<int>& heights) {


        int n = heights.size();



        vector<int> prev(n);

        vector<int> next(n);

        int ans =0;
        if(n==1){
            return heights[0];
        }



        getPrev(heights, prev);
        getNext(heights, next);

        for(int i=0;i<n;i++){
            ans = max(ans, (next[i]-prev[i]-1)*heights[i]);
        }





        return ans;





        
    }
};
