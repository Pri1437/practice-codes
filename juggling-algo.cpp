// this program implements juggling algo for rotation of array.
// time complexity O(n) and aux mem O(1)
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// we need to use gcd algo in juggling algo.
// std::__gcd()

void juggling(vector<int> &arr, int lrotations){
    int size = arr.size(), nsets = __gcd(size, lrotations);
    int j, d, temp;
    // outer loop iterates over sets
    for(int i=0; i<nsets; i++){
        j=i;
        temp = arr[i];
        while(1){
            d=(j+lrotations)%size;
            if(d == i)
            {
                // completed going through the set
                arr[j]=temp;
                break;
            }
            arr[j] = arr[d];
            j=d;
        }
    }
}

int main()
{
    vector<int> values;
    for(int i=0;i<10;i++){
        cout<<i<<" ";
        values.push_back(i);
    }
    // three left rotations
    juggling(values, 2);
    cout<<"\nafter 2 left rotations"<<endl;
    for(int i=0; i<10; i++){
        cout<<values[i]<< " ";
    }
    return 0;
}