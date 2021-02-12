#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count=0;
        unordered_map<int, int> pfq;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                // if key is not present it will initialize its value to zero
                // depends on the compiler
                pfq[nums[i]*nums[j]]+=1;
            }
        }
        for(const pair<int,int> p:pfq){
            int val = p.second;
            // as val*(val-1)/2 is valC_2 giving unique pairs of 2 numbers that
            // satisfied the condition after that there are 8 permutations of the pairs.
            // val*(val-1)/2 *8 = val*(val-1)*4
            count+= val*(val-1)*4;
        }

        return count;
    }
};

