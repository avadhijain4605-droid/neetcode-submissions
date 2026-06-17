class MedianFinder {
public:
    //mx -> first half
    //mn ->second half
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<>>mn;
    int n=0;
    MedianFinder() {}
    
    void addNum(int num) {
        mn.push(num);
        if(!mx.empty()&&!mn.empty()&&mx.top()>mn.top()){
            mx.push(mn.top());
            mn.pop();
        }
        if(mn.size()>mx.size()+1){
            mx.push(mn.top());
            mn.pop();
        }
        if(mx.size()>mn.size()+1){
            mn.push(mx.top());
            mx.pop();
        }
    }
    
    double findMedian() {
        if(mn.size()==mx.size())return (mx.top()+mn.top())/2.0;
        else if(mn.size()>mx.size()) return mn.top();
        else return mx.top();
    }
};
