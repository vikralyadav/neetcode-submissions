
class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};



class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for(char c : word){
            int index = c - 'a';

            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for(char c : word){
            int index = c - 'a';

            if(curr->children[index] == NULL){
                return false;
            }

            curr = curr->children[index];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char c : prefix){
            int index = c - 'a';

            if(curr->children[index] == NULL){
                return false;
            }

            curr = curr->children[index];
        }

        return true;
    }
};
