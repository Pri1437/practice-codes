// we are given a string and we have to generate subsets or subsequences of this string
// assuming all elements are distinct
// for a string of n elements there are 2^n subsequences

// idea
// if we know the subsets of string of len n-1 then we can find subsets of len n string

// Recursive solution
// we start from empty string i=0;
// we add elements in two ways considering string[i] and not considering with given set of subsequence
// we go the next level and repeat the same
// we repeat this until i=n;
#include<bits/stdc++.h>
using namespace std;

// i=0 initially
void subsequence(string seq, string &A, int i){
    if(i==A.size()){
        cout<<seq<<endl;
        return;
    }
    // leave the current seq with adding the new element
    subsequence(seq, A, i+1);

    // seq created by adding the current element
    subsequence(seq+A[i], A, i+1);
}