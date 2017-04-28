//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].
//
//Subscribe to see which companies asked this question.

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if(matrix.size() <= 0 ) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = n, u = 0, d = m;
        int step = 0;
        int i = 0, j = 0;

        while(step != m*n) {
            while( j < r && i >= u && i < d ){
                res.push_back(matrix[i][j++]);
                step++;
            }
            u = u + 1;
            j--; i++;
            cout<< i << " " << j << " " << l << " " << r << " " << u << " " << d<< endl;
            cout<<step<<endl;
            while( i < d && j >= l && j < r ) {
                res.push_back(matrix[i++][j]);
                step++;
            }
            r = r - 1;
            i--; j--;
            cout<< i << " " << j << " " << l << " " << r << " " << u << " " << d<< endl;
            cout<<step<<endl;
            while( j >= l && i >= u && i < d ) {
                res.push_back(matrix[i][j--]);
                step++;
            }
            d = d - 1;
            
            cout<< i << " " << j << " " << l << " " << r << " " << u << " " << d<< endl;
            cout<<step<<endl;
            while( i > u && j >= l && j < r ) {
                res.push_back(matrix[i--][j]);
                step++;
            }
            cout<< i << " " << j << " " << l << " " << r << " " << u << " " << d<< endl;
            cout<<step<<endl;
            l = l + 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > matrix;
    vector<int> v;
    v.push_back(1);v.push_back(2);v.push_back(3);matrix.push_back(v);v.clear();
    v.push_back(4);v.push_back(5);v.push_back(6);matrix.push_back(v);v.clear();
    v.push_back(7);v.push_back(8);v.push_back(9);matrix.push_back(v);v.clear();
    //v.push_back(6);v.push_back(9);v.push_back(7);matrix.push_back(v);v.clear();
    //v.push_back(4);v.push_back(0);v.push_back(-1);matrix.push_back(v);v.clear();
    vector<int> res = s.spiralOrder(matrix);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<endl;
    }
}
