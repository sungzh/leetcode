/*
 * Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
 *
 * For example, with A = "abcd" and B = "cdabcdab".
 *
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
 *
 * Note:
 * The length of A and B will be between 1 and 10000.
 */

/*
 * Source: https://leetcode.com/problems/repeated-string-match/
 * Description: start matching at A[i]=B[0] them repeat
 * Author: guozheng
 * Data: 20180111
 */

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for(int i=0,j=0; i<A.size(); i++) {
            for(j=0; j<B.size()&&A[(i+j)%A.size()]==B[j]; j++);
            if(j==B.size()) return (i+j)/A.size() + ((i+j)%A.size() !=0 ? 1:0);
        }
        return -1;
    }
};
