class Solution {
public:
    bool checkInclusion(string s1, string s2) {


      if(s1.size() > s2.size()) return false;

    map<char,int> mp1, mp2;
    int n = s1.size();

    for(char c : s1)
        mp1[c]++;

    for(int i = 0; i < n; i++)
        mp2[s2[i]]++;

    if(mp1 == mp2) return true;

    for(int i = n; i < s2.size(); i++) {

      
        mp2[s2[i]]++;

    
        mp2[s2[i-n]]--;
        if(mp2[s2[i-n]] == 0)
            mp2.erase(s2[i-n]);

        if(mp1 == mp2)
            return true;
    }

    return false;
        
    }
};
