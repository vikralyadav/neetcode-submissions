class Solution {
public:
    string longestPalindrome(string s) {


        int mid;


        string res;
        int maxLen=0;

        int n = s.size();


        for(int mid=0;mid<n;mid++){

        int i = mid;
        int j = mid;

        while (i >= 0 && j < n && s[i] == s[j]) {
            if (j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                res = s.substr(i, maxLen);
            }

            i--;
            j++;
        }
        i = mid;
        j = mid + 1;

        while (i >= 0 && j < n && s[i] == s[j]) {
            if (j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                res = s.substr(i, maxLen);
            }

            i--;
            j++;
        }
    }

    return res;


        
    }
};
