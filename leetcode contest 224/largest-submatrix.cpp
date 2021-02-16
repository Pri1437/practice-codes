// we have to find area of max submatrix that has all values one in it in a binary matrix.
// the idea is to go row wise and consider consecutive number ones as pillars
// then sort them according to height then pick max area among them and compare it with overall max till there.
#include<bits/stdc++.h>
using namespace std;

int largestSubmatrix(vector<vector<int>>& matrix) {
    int rows=matrix.size(), cols=matrix[0].size();
    int maxArea = INT_MIN;
    vector<int> cheight(cols, 0);

    for(int i=0; i<rows; i++){
        // calculating height of pillars
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 0)
                cheight[j]=0;
            else
                cheight[j]+=1;
        }
        // copy of heights
        vector<int> h=cheight;
        // sorting pillars
        sort(h.begin(), h.end());
        for(int j=0; j<cols; j++){
            maxArea=max(maxArea, h[j]*(cols-j));
        }
    }
    return maxArea;
}