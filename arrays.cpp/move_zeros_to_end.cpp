/*
    Program: Move All Zeros to the End of the Array

    Description:
    This program rearranges the array so that all zero values
    are moved to the end while maintaining the relative order
    of non-zero elements.

    Working:
    1. Read the number of elements (n).
    2. Store n integers in an array.
    3. Find the index of the first zero and store it in j.
    4. Traverse the array from index j+1.
    5. Whenever a non-zero element is found, swap it with
       the element at index j and increment j.
    6. After completion, all zeros will be shifted to the end.
    7. Print the modified array.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Assumptions:
    - Input size n > 0.
*/


#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int j=-1;
    for(int i=0;i<n;i++){
        if(array[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(array[i]!=0){
            swap(array[i],array[j]);
            j++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}