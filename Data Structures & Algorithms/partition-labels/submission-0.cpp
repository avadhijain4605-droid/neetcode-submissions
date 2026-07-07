class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>last(26,0);
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        int maxEnd=0;
        vector<int>ans;
        int start=0;
        for(int i=0;i<n;i++){
            maxEnd=max(maxEnd,last[s[i]-'a']);
            if(i==maxEnd){
                ans.push_back(i-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};
