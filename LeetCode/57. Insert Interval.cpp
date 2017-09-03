/*
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 */

/**
 * Source: https://leetcode.com/problems/insert-interval/
 * Description: notice the boundary and the merged and unmerged case
 * Author: guozheng
 * Data: 20170902
 */

#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int n = intervals.size();
        //notice boundary                
        bool merged = false;
        bool label = false;
        
        for(int i = 0; i < n; i++){
            if( newInterval.start <= intervals[i].end && newInterval.end >= intervals[i].start) {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
                merged = true;
            }
            else {
                if(merged) {
                    result.push_back(newInterval);
                    merged = false;
                    label = true;
                }
                if (intervals[i].start > newInterval.end && label == false) {
                    result.push_back(newInterval);
                    label = true;
                }
                result.push_back(intervals[i]);
            }
        }
        if( merged == true || label == false) {
            result.push_back(newInterval);
        }
        return result;
    }
};
