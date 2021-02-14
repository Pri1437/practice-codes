// we have to find maximum sum of k consecutive values in an array
#include<iostream>
#include<climits>
using namespace std;

// sliding window technique does it in O(n)
// A naive approach does it in O(n*k)
// where we pick starting value and iterate from i to i+k position
int mksum(int arr[],int n, int k){
    int sum=0, maxsum=INT_MIN;
    for(int i=0; i<n; i++){
        if(i<k){
            sum+=arr[i];
            maxsum=sum;
            continue;
        }
        sum-=arr[i-k];
        sum+=arr[i];
        maxsum = max(sum, maxsum);
    }
    return maxsum;
}

int main(){
    int arr[] = {1,3,-2,3,4,5,2};
    cout<<mksum(arr, 7, 3)<<endl;
    return 0;
}