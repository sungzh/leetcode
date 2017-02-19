//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
//For example,
//
//Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//Return:
//["AAAAACCCCC", "CCCCCAAAAA"].
//Subscribe to see which companies asked this question.
//
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    const static int MAX_LEN = 10;
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<size_t, int> stat;
        hash<string> hash_func;
        vector<string> result;
        for(int i=0; i+MAX_LEN<=s.size(); i++) {
            string word = s.substr(i, MAX_LEN);
            size_t hash_code = hash_func(word);
            stat[hash_code]++;
            if(stat[hash_code]==2) {
                result.push_back(word);
            }
        }
        return result;
    }
};
