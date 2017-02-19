//Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
//
//Note:
//You may assume the interval's end point is always bigger than its start point.
//Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
//Example 1:
//Input: [ [1,2], [2,3], [3,4], [1,3] ]
//
//Output: 1
//
//Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
//Example 2:
//Input: [ [1,2], [1,2], [1,2] ]
//
//Output: 2
//
//Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
//Example 3:
//Input: [ [1,2], [2,3] ]
//
//Output: 0
//
//Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
//Subscribe to see which companies asked this question.

/**
 ** Definition for an interval.
 **/

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool compare(const Interval &lhs, const Interval &rhs) {
        return (lhs.start == rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        vector<Interval> result;
        int overlap = 0;
        if(intervals.size() == 0 ) return overlap;
        sort(intervals.begin(), intervals.end(), compare);

        for(int i=0; i < intervals.size(); i++){
            int size = result.size();
            if( size>0 && intervals[i].start < result[size-1].end) {
                overlap++;
                result[size-1].end = min(result[size-1].end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return overlap;
    }
};
