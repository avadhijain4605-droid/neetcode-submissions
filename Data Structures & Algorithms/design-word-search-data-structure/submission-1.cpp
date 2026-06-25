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
class WordDictionary {
public:
     Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
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
    bool dfs(Node* node,int ind,string& s){
        if(!node) return false;
        if(ind==s.size()){
            return node->flag;
        }
        char c=s[ind];
        if(c=='.'){
            for(int i=0;i<26;i++){
                if(node->links[i]!=nullptr){
                    if(dfs(node->links[i],ind+1,s)) return true;
                }
            }
            return false;
        }
        else if(!node->contains(c)) return false;
        return dfs(node->get(c),ind+1,s);
    }
    bool search(string word) {
        Node* temp=root;
        return dfs(temp,0,word);
    }
};
