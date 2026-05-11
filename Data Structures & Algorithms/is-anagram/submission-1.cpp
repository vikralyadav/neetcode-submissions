class Solution {
public:
    bool isAnagram(string s, string t) {


        map<char, int> mp1;
        map<char, int> mp2;


        for(char i: s){
            mp1[i]++;
        }
        for(char j : t){
            mp2[j]++;
        }


        return mp1==mp2;

       
    }
};
