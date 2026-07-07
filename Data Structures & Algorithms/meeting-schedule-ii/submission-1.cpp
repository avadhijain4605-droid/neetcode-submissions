/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& in) {
        map<int,int>mpp;
        for(auto it:in){
            mpp[it.start]++;
            mpp[it.end]--;
        }
        int a=0;
        int ans=INT_MIN;
        for(auto it:mpp){
            a+=it.second;
            ans=max(ans,a);
        }
        return ans==INT_MIN?0:ans;
    }
};
