class Trie {
private:
    vector<Trie*> children;
    bool is_end;
    Trie* searchNode(string word)
    {
        Trie* node = this;
        for(auto i : word)
        {
            i -= 'a';
            if (node->children[i] == nullptr)return nullptr;
            node = node->children[i];
        }
        return node;
    }
public:
    /** Initialize your data structure here. */
    Trie():children(26), is_end(false) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* begin = this;
        for(auto i : word)
        {
            i -= 'a';
            if (begin->children[i] == nullptr)begin->children[i] = new Trie();
            begin = begin->children[i];
        }
        begin->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = searchNode(word);
        return node!=nullptr&&node->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = searchNode(prefix);
        return node!=nullptr;
    }
};
