//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
//Return:
//
//[
//  ["ate", "eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//Note: All inputs will be in lower-case.
//
//Subscribe to see which companies asked this question.

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        map<string, int> m;
        for(int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            if( m.find(word) == m.end() ) {
                vector<string> v;
                v.push_back(strs[i]);
                result.push_back(v);
                m[word] = result.size() - 1;
            } else {
                result[m[word]].push_back(strs[i]);
            }
        }

        return result;               
    }
};
