/*
    Program: Remove Duplicates from Sorted Array

    Description:
    This program removes duplicate elements from a sorted array
    and prints only the unique elements.

    Important:
    The input array MUST be sorted.
    If the array is not sorted, this logic will fail.

    Working:
    1. Read the number of elements (n).
    2. Store n integers in a vector.
    3. Use two-pointer technique:
       - Pointer i tracks position of last unique element.
       - Pointer j scans the array.
    4. If vec[j] != vec[i], it means a new unique element is found.
       Move it to position i+1 and increment i.
    5. After traversal, elements from index 0 to i are unique.
    6. Print elements from 0 to i.

    Time Complexity: O(n)
    Space Complexity: O(1) extra space (in-place modification)

    Assumptions:
    - Input array is sorted in non-decreasing order.
    - Duplicates appear consecutively.
*/


#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int i=0;
    for(int j=1;j<n;j++){
        if(vec[j]!=vec[i]){
            vec[i+1]=vec[j];
            i++;
        }
    }
    for(int m=0;m<=i;m++){
        cout<<vec[m]<<endl;
    }
    
}