/*
    Program: Leaders in an Array

    Definition:
    An element is called a leader if it is strictly greater than
    all elements to its right side in the array.

    Example:
    Input:  10 22 12 3 0 6
    Output: 22 12 6

    Explanation:
    - 22 > 12,3,0,6
    - 12 > 3,0,6
    - 6 has no element to its right


    1. Brute Force Approach

    Idea:
    For every element, check all elements to its right.
    If none of them are greater or equal, it is a leader.

    Steps:
    - For each index i
    - Compare arr[i] with all elements from i+1 to n-1
    - If no larger element is found → leader

    Time Complexity: O(n²)
    Space Complexity: O(1) extra (excluding output)


    2. Optimal Approach

    Key Observation:
    If we scan from the right, we only need to track the
    maximum element seen so far.

    Idea:
    - Traverse array from right to left
    - Maintain variable 'maxi'
    - If current element > maxi → it is a leader
    - Update maxi

    Steps:
    1. Start from last element
    2. Track maximum element so far
    3. Add element if it exceeds current maximum
    4. Reverse the result at the end

    Time Complexity: O(n)
    Space Complexity: O(1) extra (excluding output)

*/

#include<bits/stdc++.h>
using namespace std;
vector<int>bruteforce(vector<int>arr){
    int n=arr.size();
    vector<int>result;
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if(arr[i]<=arr[j]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            result.push_back(arr[i]);
        }
    }
    return result;
}

vector<int>optimal(vector<int>arr){
    int n=arr.size();
    vector<int>result;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            maxi=arr[i];
            result.push_back(arr[i]);
        }
    }
    reverse(result.begin(),result.end());
    return result;
}

int main(){
    int n;
    cout<<"Enter no. of elements:"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>leaders=optimal(arr);
    for(int i=0;i<leaders.size();i++){
        cout<<leaders[i]<<" ";
    }
    return 0;

}