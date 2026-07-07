class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gasSum=0;
        int costSum=0;
        for(int i=0;i<n;i++){
            gasSum+=gas[i];
            costSum+=cost[i];
        }
        if(costSum>gasSum) return -1;
        int tank=0;
        int start=0;
        for(int i=0;i<n;i++){
            tank+=gas[i]-cost[i];
            if(tank<0){
                tank=0;
                start=i+1;
            }
        }   
        if(tank<0) return -1;
        return start; 
    }
};
