// here multiple queries will be given asking to find range of sum between two indices
// naive approach is to use a loop to calculate sum between the two indices
// which is O(n) for every query
// we can optimize this using prefix sum array so on an avg the time will be O(1) at the end of all queries

#include<iostream>
using namespace std;

void initPrefixarr(int arr[], int n, int prefix[]){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        prefix[i] = sum;
    }
}

int main(){
    int n,q, i, j;
    cin>>n;
    int arr[n], prefix[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    initPrefixarr(arr, n, prefix);
    
    cin>>q;
    while(q--){
        cin>>i>>j;
        if(i==0)
        {
            cout<<prefix[j]<<endl;
            continue;
        }
        cout<<prefix[j]-prefix[i-1]<<endl;
    }
    return 0;
}