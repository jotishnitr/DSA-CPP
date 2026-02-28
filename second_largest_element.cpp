/*
Problem:Second Largest element
category:Arrays
Difficulty:easy

Problem Statement:
Given an array of integers, find the second largest
distinct element.

Approach : Optimal (Single Pass)
 Maintain two variables:
  largest
  secondLargest
 Traverse once:
   If element > largest:
      secondLargest = largest
      largest = element
   Else if element < largest and element > secondLargest:
      update secondLargest

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- All elements equal
- Array size < 2
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter no.of values u provide"<<endl;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int largest = vec[0];
    int slargest= 0;
    for(int i=1;i<n;i++){
        if(vec[i]>largest){
            slargest=largest;
            largest=vec[i];
        }
        else if(vec[i]>slargest && slargest<largest){
            slargest=vec[i];
        }
    }
    cout<<slargest<<endl;
    return 0;
}
