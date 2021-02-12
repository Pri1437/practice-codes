#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        long maxlen=INT_MIN, count=0;
        for(int i=0; i<rectangles.size();i++){
            long currlen = min(rectangles[i][0], rectangles[i][1]);
            if(maxlen == currlen)
            {
                count++;
            }
            else if(maxlen < currlen){
                maxlen=currlen;
                count=1;
            }
        }
        return count;
    }
};