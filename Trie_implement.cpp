struct node{
    node *trie[26];
    bool flag = false;
    bool contains(char x){
        return(trie[x-'a'] != NULL);
    }
    void makeNextRef(char x, node* newNode){
        trie[x-'a'] = newNode;
    }
    node * getNextRef(char x){
        return trie[x-'a'];
    }
    void setEndRef(){
        flag = true;
    }
    bool isSetEnd(){
        return flag;
    }
};

class Trie {
private:
    node *root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node * ref = root;
        for(int i = 0; i<word.length(); i++){
            if(!ref->contains(word[i])){
                ref->makeNextRef(word[i], new node());
            }
            ref = ref->getNextRef(word[i]);
        }
        ref->setEndRef();
    }
    
    bool search(string word) {
        node *itr = root;
        for(int i = 0; i<word.length(); i++){
            if(!itr->contains(word[i])){
                return false;
            }
            itr = itr->getNextRef(word[i]);
        }
        return itr->isSetEnd();
    }
    
    bool startsWith(string prefix) {
        node *itr = root;
        for(int i = 0; i<prefix.length(); i++){
            if(!itr->contains(prefix[i])){
                return false;
            }
            itr = itr->getNextRef(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
