class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
         int n = intervals.size();
    int q = queries.size();


    sort(intervals.begin(), intervals.end());


    vector<pair<int,int>> qidx;
    for(int i = 0; i < q; i++){
        qidx.push_back({queries[i], i});
    }
    sort(qidx.begin(), qidx.end());


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    vector<int> ans(q, -1);
    int i = 0;

    for(auto &it : qidx){
        int query = it.first;
        int idx = it.second;

    
        while(i < n && intervals[i][0] <= query){
            int l = intervals[i][0];
            int r = intervals[i][1];
            pq.push({r - l + 1, r});
            i++;
        }

    
        while(!pq.empty() && pq.top().second < query){
            pq.pop();
        }

       
        if(!pq.empty()){
            ans[idx] = pq.top().first;
        }
    }

    return ans;
    }
};
