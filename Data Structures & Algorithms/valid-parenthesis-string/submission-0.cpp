class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<char>st1;
        stack<char>st2;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='(')st1.push(i);
            else if(c=='*')st2.push(i);
            else{
                if(!st1.empty())st1.pop();
                else if(!st2.empty())st2.pop();
                else return false;
            }
        }
        while(!st1.empty()&&!st2.empty()){
            if(st1.top()<st2.top()) {
                st1.pop();
                st2.pop();
            }
            else return false;
        }
        return st1.empty();
    }
};
