//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//[
//  ["aa","b"],
//  ["a","a","b"]
//]
//Subscribe to see which companies asked this question.
//
//

class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        while(start < end)  {
            if(s[start] != s[end]) {
                return false;
            }
            start++; end--;
        }
        return true;
    }

    void partitionHelper(string &s, int start, vector<string> &output, vector<vector<string> > &result) {
        if( start == s.size()) {
            result.push_back(output);
            return;
        }
        for(int i=start; i<s.size(); i++) {
            if( isPalindrome(s, start, i) == true ){
                output.push_back(s.substr(start, i-start+1) );
                partitionHelper(s, i+1, output, result);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> >result;
        vector<string> output;

        partitionHelper(s, 0, output, result);
        return result;
    }
};
