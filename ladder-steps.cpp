// your given a ladder of 11 steps with values as how many places you can move some steps at max in one hop
// find out the min number of hops needed to get to the top of the ladder.
// greedy doesn't work for case like 1 5 2 1 1 1 1 6 3 4 1
// we have to use DP

/*
the idea is to find min steps to a particular step and calculate min steps to j (j>i) where min steps of j = min steps from i + 1
*/
#include<bits/stdc++.h>
using namespace std;

int min_hops(){
    int size;
    cin>>size;
    vector<int> ladder(size), min_steps(size);
    for(int i=0; i<size; i++)
    {
        cin>>ladder[i];
        min_steps[i] = INT_MAX;
    }
    // we are already there for the first step
    min_steps[0]=0;

    // we try to find min steps to other places
    int max_jump;
    for(int i=0; i<size; i++){
        max_jump = ladder[i];
        for(int j=1; j<=max_jump; j++)
        {
            if(i+j < size){
                min_steps[i+j] = min(min_steps[i]+1, min_steps[i+j]);
            }
        }
    }
    return min_steps[size-1];
}

int main(){
    int t;
    t=1;
    while(t--){
        cout<<min_hops()<<endl;
    }
    return 0;
}