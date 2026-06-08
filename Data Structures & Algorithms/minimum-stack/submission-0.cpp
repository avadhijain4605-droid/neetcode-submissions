class MinStack {
public:
    stack<int>st;
    multiset<int>ms;
    MinStack() {
    }
    void push(int val) {
        st.push(val);
        ms.insert(val);
    }
    
    void pop() {
        int ele=st.top();
       st.pop(); 
       auto it=ms.find(ele);
       ms.erase(it);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *ms.begin();
    }
};
