/**
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 *
 * Subscribe to see which companies asked this question.
 */
#include<vector>
#include<iostream>
using namespace std;

class Solution {

public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        vector<vector<int> > match(s1.size()+1, vector<int>(s2.size()+1, false));
        match[0][0] = true;
        for(int i = 0; i < s1.size() + 1; i++)
            for(int j = 0; j < s2.size() + 1; j++) {
                if(i==0 && j==0) 
                    match[i][j] = true;
                else if (i == 0)
                    match[i][j] = ( match[i][j-1] && s2[j-1] == s3[i+j-1] );
                else if (j == 0)
                    match[i][j] = ( match[i-1][j] && s1[i-1] == s3[i+j-1] );
                else
                    match[i][j] = ( match[i-1][j] && s1[i-1] == s3[i+j-1]) || ( match[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
        return match[s1.size()][s2.size()];
    }

    int aa = 0;
    bool isInterleave1(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        const char *p1 = s1.c_str(), *p2 = s2.c_str(), *p3 = s3.c_str();
        for (; *p3 != '\0'; p3++){
            cout<<s1 << " " << s2 << " " << s3<<endl;
            aa++;
            if (*p3 == *p1 && *p3!=*p2) {
                p1++;
            }else if ( *p3 == *p2 && *p3 != *p1) {
                p2++;
            }else if (*p3==*p1 && *p3 ==*p2) {
                if (isInterleave1(p1, p2+1, p3+1) == false) {
                    return isInterleave1(p1+1, p2, p3+1);
                }
                return true;
            }else{
                return false;
            }
        }
    return ( *p1 =='\0' && *p2 =='\0' && *p3 =='\0' );
    }
};

int main() {
    Solution s; 
    cout<<s.isInterleave("aabcc", "dbbca", "aadbbcbcac")<<endl;
    cout<<s.isInterleave("aabcc", "dbbca", "aadbbbaccc")<<endl;
    cout<<s.isInterleave1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
    cout<<s.aa<<endl;

    return 0;
}

