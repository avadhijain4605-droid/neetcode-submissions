class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> in;
        //unordered_set<char> ele;
        for (const string& w : words) {
            for (char c : w) {
                in[c]=0;
            }
        }
        for (int k = 0; k < n - 1; k++) {
            string s = words[k];
            string t = words[k + 1];
            if (s.size() > t.size() && s.substr(0, t.size()) == t) return "";
            int len = min(s.size(), t.size());
            for (int i = 0; i < len; i++) {
                if (s[i] != t[i]) {
                    adj[s[i]].push_back(t[i]);
                    in[t[i]]++;
                    break;
                }
            }
        }
        string ans = "";
        stack<char> st;
        for (auto it : in) {
            if (it.second == 0) {
                st.push(it.first);
                ans += it.first;
            }
        }
        while (!st.empty()) {
            char node = st.top();
            st.pop();
            for (char i : adj[node]) {
                in[i]--;
                if (in[i] == 0) {
                    st.push(i);
                    ans += i;
                }
            }
        }
        if (ans.size() != in.size()) return "";
        return ans;
    }
};
