class CountSquares {
public:
    map<pair<int,int>, int> mp;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for (auto &it : mp) {
            int px = it.first.first;
            int py = it.first.second;
            int freq = it.second;

            // Check diagonal condition
            if (abs(px - x) == abs(py - y) && px != x && py != y) {
                int f1 = mp[{px, y}];
                int f2 = mp[{x, py}];

                ans += freq * f1 * f2;
            }
        }

        return ans;

    }
};
