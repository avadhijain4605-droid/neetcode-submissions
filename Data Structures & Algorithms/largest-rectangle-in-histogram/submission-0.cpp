class Solution {
public:
    vector<int>nextSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
        //for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        //cout<<endl;
        return ans;
    }
    vector<int>prevSmaller(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
       // for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse=nextSmaller(heights);
        vector<int>pse=prevSmaller(heights);
        int maxA=INT_MIN;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int a=(nse[i]-pse[i]-1)*heights[i];
            maxA=max(maxA,a);
        }
        return maxA;
    }
};
