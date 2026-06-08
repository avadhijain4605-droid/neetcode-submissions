class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int>st;
        int n=t.size();
        for(int i=0;i<n;i++){
            if(t[i]=="+"||t[i]=="-"||t[i]=="*"||t[i]=="/"){
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                if(t[i]=="+"){
                    st.push(op1+op2);
                    continue;
                }
                else if(t[i]=="-"){
                    st.push(op1-op2);
                    continue;
                }
                else if(t[i]=="*"){
                    st.push(op1*op2);
                    continue;
                }
                else {
                    st.push(op1/op2);
                    continue;
                }
            }
            else{
                st.push(stoi(t[i]));
            }
        }
        return st.top();
    }
};
