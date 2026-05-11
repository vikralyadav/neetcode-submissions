class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {



        map<int,int> mp;

    for(auto n : nums)
        mp[n]++;

    vector<pair<int,int>> freq;

    for(auto it : mp)
        freq.push_back({it.second, it.first});  // {frequency, number}

    sort(freq.rbegin(), freq.rend()); // descending

    vector<int> ans;

    for(int i = 0; i < k; i++)
        ans.push_back(freq[i].second);

    return ans;
        
    }
};
