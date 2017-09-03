/*
 * Given a string, sort it in decreasing order based on the frequency of characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 */
/*
 * Source: https://leetcode.com/problems/sort-characters-by-frequency/
 * Description: easy question using map and list
 * Author: guozheng
 * Data: 20170902
 */

class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> freq;
        vector<string> cells(s.size()+1, "");
        for(char c:s) freq[c]++;
        for(auto &it:freq) {
            int n = it.second;
            char c = it.first;
            cells[n].append(n, c);
        }
        for(int i = s.size(); i>0; i--) {
            res = res.append(cells[i]);
        }
        return res;
    }
};
