class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k,int v){
        key=k;
        val=v;
    }
};
class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void insertBeginning(Node* node){
        Node* nxt=head->next;
        head->next=node;
        node->prev=head;
        nxt->prev=node;
        node->next=nxt;
    }
    void remove(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
       // node->prev=prevNode;
        nextNode->prev=prevNode;
        //->next=nextNode;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        remove(node);
        insertBeginning(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            remove(mpp[key]);
            mpp[key]->val=value;
            insertBeginning(mpp[key]);
            return;
        }
        else{
            Node* node=new Node(key,value);
            if(mpp.size()<cap){
                insertBeginning(node);
                mpp[key]=node;
            }
            else{
                mpp.erase(tail->prev->key);
                remove(tail->prev);
                insertBeginning(node);
                mpp[key]=node;
            }
        }
    }
};
