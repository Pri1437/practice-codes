// equilibrium index is the one where sum of elements left and sum of elements in the right are equal
// optimized approaches use prefix sum array and other is cummulative sum
#include<iostream>
using namespace std;

int get_eq_index(int arr[], int n)
{
    int sum=0, leftsum=0;
    for(int i=0; i<n;i++){
        sum+=arr[i];
    }

    for(int i=0;i<n;i++){
        sum-=arr[i];
        if(leftsum == sum)
            return i;
        leftsum+=arr[i];
    }
    return -1;
}

int main(){
    int arr[]={-7, 1, 5, 2, -4, 3, 0};
    int index = get_eq_index(arr, 7);
    cout<<"eq index: "<<index<<endl;
    return 0;
}