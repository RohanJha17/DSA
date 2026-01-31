struct Node{
    struct Node* child[26];
    bool isEOW;

    Node(){
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
        isEOW = false;
    }
};


class Trie {
    Node* root = NULL;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int i = 0;
        Node* temp = root;
        while(i < word.length()){
            int idx = word[i] - 'a';

            if(temp->child[idx] == NULL){
                temp->child[idx] = new Node();
            }
            temp = temp->child[idx];
            i++;
        }
        temp->isEOW = true;
    }
    
    bool search(string word) {
        int i = 0;
        Node* temp = root;
        while(i < word.length()){
            int idx = word[i] - 'a';
            if(temp->child[idx] == NULL)
                return false;

            temp = temp->child[idx];
            i++;
        }

        return temp->isEOW; 
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char c : prefix){
            int idx = c - 'a';
            if(temp->child[idx] == NULL)
                return false;
             temp = temp->child[idx];
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