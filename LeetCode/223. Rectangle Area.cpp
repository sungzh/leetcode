/*
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 *
 * Rectangle Area
 * Assume that the total area is never beyond the maximum possible value of int.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
 */

/*
 * Source: https://leetcode.com/problems/rectangle-area/
 * Description: using max(min) to cal the right overlapping
 * Author: guozheng
 * Data: 20121202
 */

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left=max(A,E), right=max(min(C,G),left);
        int bottom=max(B,F), top=max(min(D,H), bottom);
        return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
    }
};
