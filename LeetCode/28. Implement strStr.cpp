/*
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Example 1:
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 */

/*
 * Source: https://leetcode.com/problems/implement-strstr
 * Description: using two index
 * Author: guozheng
 * Data: 20171118
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; ; i++)
            for(int j=0; ; j++) {
                if (j == needle.size()) return i;
                if (haystack.size() == (i+j)) return -1;
                if (needle[j] != haystack[i+j]) break;
            }
        return -1;
    }
};
