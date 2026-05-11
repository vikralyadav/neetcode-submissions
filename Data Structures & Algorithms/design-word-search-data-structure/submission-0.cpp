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


class WordDictionary {


       TrieNode* root;
public:
    WordDictionary() {

        root = new TrieNode();
        
    }

     void addWordUtil(TrieNode* root, string word){

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
    
    void addWord(string word) {


        addWordUtil(root, word);
        
    }


        bool searchUtil(TrieNode* node, string word, int pos){

        if(node == NULL) return false;

        if(pos == word.size()) return node->isEnd;

        char c = word[pos];

        if(c == '.'){
            for(int i=0;i<26;i++){
                if(searchUtil(node->children[i], word, pos+1)){
                    return true;
                }
            }
            return false;
        }
        else{
            int index = c - 'a';
            return searchUtil(node->children[index], word, pos+1);
        }
    }
    
    bool search(string word) {
          return searchUtil(root, word, 0);
        
    }
};
