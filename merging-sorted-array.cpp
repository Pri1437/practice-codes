// to merge two sorted arrays of size m and n.
// only one approach cycle through elements simultaneously through these arrays
// whichever value is small add it to the third arrray
// now if one array is completely traversed and elements are present in second array then just copy them on to the final array.
#include<iostream>
using namespace std;

int* merge(int arr1[], int m, int arr2[], int n){
    // normally declared arrays are created on stack
    // we need to create arrays heap to pass those arrays.
    int *final = (int*)malloc(m*n*sizeof(int));
    int i=0,j=0, k=0;
    while(i<m && j<n){
        if(arr1[i]<=arr2[j])
        {
            final[k]=arr1[i];
            i++;
        }
        else{
            final[k]=arr2[j];
            j++;
        }
        k++;
    }
    // first array has elements left
    while(i<m){
        // same as final[k++]=arr1[i++];
        final[k]=arr1[i];
        i++;
        k++;
    }

    // if second array has elements left
    while(j<n){
        final[k]=arr2[j];
        j++;
        k++;
    }
    return final;
}

int main(){
    int arr1[]={1,1,3,5}, arr2[]={1,2,4,6};
    int* final = merge(arr1, 4, arr2, 4);
    for(int i=0;i<8;i++){
        cout<<final[i]<<" ";
    }
}