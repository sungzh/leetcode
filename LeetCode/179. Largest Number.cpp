//Given a list of non negative integers, arrange them such that they form the largest number.
//
//For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.
//
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.
//
//Subscribe to see which companies asked this question.
//
//Show Tags

class Solution {
public:
    static bool cmp(string& s1, string& s2) { return s1+s2 > s2+s1; }
    string largestNumber(vector<int>& nums) {

        vector<string> v;
        for(int i=0; i < nums.size(); i++) {
            v.push_back(to_string(nums[i]));
        }

        sort(v.begin(), v.end(), cmp);
        
        string result;
        for(int i=0; i<v.size(); i++) {
            result += v[i];
        }
        if( result[0] == '0') return "0";
        return result;
    }
};
