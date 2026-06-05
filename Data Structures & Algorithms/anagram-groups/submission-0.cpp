class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<int,int>,vector<int>>mpp;
        int m=strs.size();
        vector<vector<string>>ans;
        for(int i=0;i<m;i++){
            map<int,int>temp;
            for(auto it:strs[i]){
                temp[it-'a']++;
            }
            mpp[temp].push_back(i);
        }
        for(auto it:mpp){
            vector<string>temp;
            for(int i:it.second){
                temp.push_back(strs[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
