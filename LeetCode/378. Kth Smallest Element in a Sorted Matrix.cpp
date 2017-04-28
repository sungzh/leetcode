//
//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//Example:
//
//matrix = [
//  [ 1,  5,  9],
//  [10, 11, 13],
//  [12, 13, 15]
//],
//k = 8,
//
//return 13.
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ n2.
//
//Subscribe to see which companies asked this question.
//
//Show Tags
//Show Similar Problems
//

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int low = matrix[0][0], high = matrix[matrix.size()-1][matrix[0].size()-1] + 1;
        while(low < high) {
            int mid = low + (high - low)/2;
            int count = 0, j = matrix[0].size() - 1;
            for(int i = 0; i < matrix.size(); i++) {
                while(j>=0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if(count < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

int main() {
    vector<vector<int> >  matrix;
    vector<int> v;
    v.push_back(1);v.push_back(2);v.push_back(3);
    matrix.push_back(v);v.clear();
    v.push_back(3);v.push_back(4);v.push_back(5);
    matrix.push_back(v);v.clear();
    v.push_back(6);v.push_back(7);v.push_back(8);
    matrix.push_back(v);v.clear();
    Solution s;
    cout<<s.kthSmallest(matrix, 1)<<endl;
    cout<<s.kthSmallest(matrix, 8)<<endl;
    matrix.clear();
    v.push_back(1);v.push_back(2);
    matrix.push_back(v);v.clear();
    v.push_back(1);v.push_back(3);
    matrix.push_back(v);v.clear();
    cout<<s.kthSmallest(matrix, 4)<<endl;
    cout<<s.kthSmallest(matrix, 2)<<endl;
    matrix.clear();
    v.push_back(1);v.push_back(4);v.push_back(7);v.push_back(11);v.push_back(15);
    matrix.push_back(v);v.clear();
    v.push_back(2);v.push_back(5);v.push_back(6);v.push_back(12);v.push_back(19);
    matrix.push_back(v);v.clear();
    v.push_back(3);v.push_back(6);v.push_back(9);v.push_back(16);v.push_back(22);
    matrix.push_back(v);v.clear();
    v.push_back(10);v.push_back(13);v.push_back(14);v.push_back(17);v.push_back(24);
    matrix.push_back(v);v.clear();
    v.push_back(18);v.push_back(21);v.push_back(23);v.push_back(26);v.push_back(30);
    matrix.push_back(v);v.clear();
    cout<<s.kthSmallest(matrix, 5)<<endl;
    
    return 0;
}


