class Solution {
public:
    int evalRPN(vector<string>& tokens) {
 stack<int> s;

    for(string i : tokens) {
        if(i == "+" || i == "-" || i == "*" || i == "/") {
            int r = s.top(); s.pop();
            int l = s.top(); s.pop();

            if (i == "+") s.push(l + r);
            else if (i == "-") s.push(l - r);
            else if (i == "*") s.push((long)l * r); 
            else if (i == "/") s.push(l / r);
        } 
        else {
           
            s.push(stoi(i));
        }
    }

    return s.top();
        
    }
};
