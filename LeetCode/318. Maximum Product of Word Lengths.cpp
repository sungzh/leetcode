//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
//
//Example 1:
//Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//Return 16
//The two words can be "abcw", "xtfn".
//
//Example 2:
//Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//Return 4
//The two words can be "ab", "cd".
//
//Example 3:
//Given ["a", "aa", "aaa", "aaaa"]
//Return 0
//No such pair of words.
//
//Credits:
//Special thanks to @dietpepsi for adding this problem and creating all test cases.
//
//Subscribe to see which companies asked this question.

#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> maxLens;
        for(auto& w: words) {
            int mask = 0;
            for(auto& c: w) {
                mask = mask | (1 << (c-'a'));
            }
            //using bit to store difference letters and map to distinguish
            if( maxLens.find(mask) == maxLens.end() || maxLens[mask] < w.size() ) {
                maxLens[mask] = w.size();
            }
        }                
        int result = 0;
        for(auto a: maxLens) {
            for(auto b: maxLens) {
                if(a.first & b.first) continue;
                result = max(result, a.second * b.second);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> words;
    words.push_back("a");
    words.push_back("ab");
    words.push_back("abc");
    words.push_back("d");
    words.push_back("cd");
    words.push_back("bcd");
    words.push_back("abcd");
    cout<<s.maxProduct(words)<<endl;
}
