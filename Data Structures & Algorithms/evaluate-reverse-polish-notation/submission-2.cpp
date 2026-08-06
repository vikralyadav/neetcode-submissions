class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int> s;
    
    for (const string& i : tokens) {
        if (i == "+") {
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(left + right);
        } 
        else if (i == "-") {
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(left - right); // Order matters: Left - Right
        } 
        else if (i == "*") {
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(left * right);
        } 
        else if (i == "/") {
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(left / right); // Order matters: Left / Right
        } 
        else {
            // Convert string to integer before pushing
            s.push(stoi(i)); 
        }
    }
        // for(auto i :tokens){
        //     if(i=="+" || i =="-" || i== "*" || i== "/"){
        //         int r = s.top();
        //         s.pop();
        //         int l = s.top();
        //         s.pop();


        //         if(i=="+") s.push(l+r);
        //         else if(i=="-")s.push(l-r);
        //         else if(i=="*")s.push(l*r);
        //         else if(i=="/")s.push(l/r);
        //     }
        //     else{
        //         s.push(stoi(i));
        //     }
        // }

        return s.top();   
    }
};
