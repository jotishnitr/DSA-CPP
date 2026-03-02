/*
    Program: Check if Array is Sorted

    Description:
    This program checks whether a given list of integers
    is sorted in non-decreasing (ascending) order.

    Working:
    1. The user enters the number of elements (n).
    2. The program reads n integers into a vector.
    3. A boolean variable 'isSorted' is initialized as true.
    4. The program iterates from index 1 to n-1.
    5. Each element is compared with its previous element.
       If vec[i] < vec[i-1], the array is not sorted.
    6. If such a case is found, the loop breaks early.
    7. The final result is printed.

    Time Complexity: O(n)
    Space Complexity: O(n)

    Assumptions:
    - Duplicate values are allowed.
    - Sorting means ascending order only.
*/


#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter no.of values u provide"<<endl;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    bool sort=true;
    for(int i=1;i<n;i++){
        if(vec[i]<vec[i-1]){
            sort=false;
        }
    }
    if(sort==true){
        cout<<"it is sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
}