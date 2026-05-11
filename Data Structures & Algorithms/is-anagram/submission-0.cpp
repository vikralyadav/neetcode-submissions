class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char, int> mp1, mp2;




        if(s.length()!= t.length()){
            return false;
        }



        for (char c : s) {
        mp1[c]++;
    }

    for (char c : t) {
        mp2[c]++;
    }


        if(mp1==mp2){
            return true;
        }
   


   return false;






        
    }
};
