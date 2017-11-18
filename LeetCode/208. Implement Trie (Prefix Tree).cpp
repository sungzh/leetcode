/*
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 */

/*
 * Source: https://leetcode.com/problems/implement-trie-prefix-tree
 * Description: 26 char
 * Author: guozheng
 * Data: 20171118
 */

class TrieNode {
public:
    TrieNode *next[26];
    bool is_word;

    TrieNode(bool b=false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
                
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p=root;
        for(char ch:word) {
            if(p->next[ch-'a'] == NULL) p->next[ch-'a'] = new TrieNode();
            p = p->next[ch-'a'];
        }
        p->is_word = true;
    }
                    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p!= NULL && p->is_word;
    }
                        
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
private: 
    TrieNode* find(string word) {
        TrieNode *p = root;
        for(char w : word) {
            p = p->next[w-'a'];
            if(p ==NULL) break;
        }
        return p;
    }
};

/**
 ** Your Trie object will be instantiated and called as such:
 ** Trie obj = new Trie();
 ** obj.insert(word);
 ** bool param_2 = obj.search(word);
 ** bool param_3 = obj.startsWith(prefix);
 **/
