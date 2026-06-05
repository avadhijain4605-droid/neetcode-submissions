class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        unordered_map<char, int> mpp;
        for (char c : t) {
            mpp[c]++;
        }
        int start = 0;
        int end = 0;
        int ans = INT_MAX;
        int missing = m;
        string res = "";
        while (end < n) {
            if (mpp[s[end]] > 0) missing--;
            mpp[s[end]]--;
            // if (mpp[s[end]] == 0) mpp.erase(s[end]);
            while (missing == 0) {
                int len = end - start + 1;
                if (len < ans) {
                    res = s.substr(start, len);
                    ans = len;
                }
                mpp[s[start]]++;
                if (mpp[s[start]] > 0) missing++;
                start++;
            }
            end++;
        }
        return res;
    }
};
