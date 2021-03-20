// we have three towers 'A','B','C' and n number of disks and we need to print the moves, on how we are moving the disks
// the idea
// if we have n disks we move n-1 disks to aux tower (considering it as intermediate destination)
// then move the nth disk to the correct destination
// then repeat the process on those n-1 disks.

#include<iostream>
using namespace std;

// A represents start, B aux, C destination
void TOH(int n, char A, char B, char C){
    if(n==1)
    {
        cout<<"Move "<<n<<"from "<<A<<"To "<<C;
        return;
    }

    // we try to push the n-1 disks to the aux tower so we can easily access nth disk
    TOH(n-1, A, C, B);
    // n-1 disks are moved so nth disk is moved to the destination
    cout<<"Move "<<n<<"from "<<A<<"To "<<C;

    // call TOH on n-1 disks and move them to correct destination
    TOH(n-1, B, A, C);
}