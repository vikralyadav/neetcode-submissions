class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {



        stack<double> s;


        vector<pair<int, double>> v;




        for(int i=0;i<position.size();i++){
            v.push_back({position[i], (target-position[i])/speed[i]});
        }


        sort(v.rbegin(), v.rend());




        for(auto i: v){


            if(s.empty()){
                s.push(i.second);
            }
        
            else{if(s.top()<i.second){
                s.push(i.second);
            }}
            
        

        }


        return s.size();



        
    }
};
