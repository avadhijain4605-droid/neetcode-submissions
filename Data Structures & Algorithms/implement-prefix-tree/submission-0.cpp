class Node{
    public:
    vector<Node*>links;
    bool flag;
    Node(){
        links.assign(26,nullptr);
        flag=false;
    }
    bool contains(char ch){
        return links[ch-'a']!=nullptr;
    }
    Node* put(char ch,Node* node){
        return links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root=new Node(); 
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(temp->contains(c)){
                temp=temp->get(c);
            }
            else {
                temp=temp->put(c,new Node());
            }
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(temp->contains(c))temp=temp->get(c);
            else return false;
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++){
            char c=prefix[i];
            if(temp->contains(c))temp=temp->get(c);
            else return false;
        }
        return true;
    }
};
