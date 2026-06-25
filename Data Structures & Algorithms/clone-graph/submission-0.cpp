/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr; 
        unordered_map<Node*,Node*>mpp;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(!mpp.count(curr))mpp[curr]=new Node(curr->val);
            for(int i=0;i<curr->neighbors.size();i++){
                Node* temp=curr->neighbors[i];
                if(!mpp.count(temp)) {
                    mpp[temp]=new Node(temp->val);
                q.push(temp);
                }
                mpp[curr]->neighbors.push_back(mpp[temp]);
            }
        }
        return mpp[node];
    }
};
