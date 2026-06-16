class KthLargest {
public:
    priority_queue<int>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
       for(int i:nums){
        pq.push(i);
       }
       this->k=k;
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> temp=pq;
        int n=k-1;
       while(n--){
        temp.pop();
       }
       return temp.top();
    }
};
