//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1,1,2] have the following unique permutations:
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//]
//Subscribe to see which companies asked this question.
//

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > vv;
        vv.push_back(nums);

        if(nums.size() <2){
            return vv;
        }
            
        int pos=0;
        while(pos<nums.size()-1) {
            int size = vv.size();
            for(int i=0; i<size; i++) {
                sort(vv[i].begin() + pos, vv[i].end());
                for(int j=pos+1; j<vv[i].size(); j++) {
                    vector<int> v = vv[i];
                    if(j>0 && v[j] == v[j-1])
                        continue;
                    int t = v[j];
                    v[j] = v[pos];
                    v[pos] = t;
                    vv.push_back(v);
                }
            }
            pos++;
        }
        return vv;
    }
};
