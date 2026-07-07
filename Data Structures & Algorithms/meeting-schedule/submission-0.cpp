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
    bool canAttendMeetings(vector<Interval>& in) {
        sort(in.begin(),in.end(),[](Interval& a,Interval& b){
            return a.end<b.end;
        });
        int n=in.size();
        int start=in[0].start;
        int end=in[0].end;
        for(int i=1;i<n;i++){
            if(in[i].start<end) return false;
            start=in[i].start;
            end=in[i].end;
        }
        return true;
    }
};
