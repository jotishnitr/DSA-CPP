/*
    Program: Union of Two Sorted Arrays

    Description:
    This program computes the union of two arrays.
    The union contains all distinct elements present in either array.

    Two approaches are implemented:

    1. Brute Force Approach (union1):
       - Uses a set to store unique elements.
       - Automatically removes duplicates.
       - Order is sorted because set stores elements in ascending order.

    2. Optimal Approach (union2):
       - Uses two-pointer technique.
       - Works only if both input arrays are already sorted.
       - Avoids extra space like set.
       - Maintains sorted order and removes duplicates manually.

    --------------------------------------------------

    Brute Force Approach (union1):
    - Insert all elements of both arrays into a set.
    - Copy elements from set to a vector.

    Time Complexity: O((n1 + n2) log(n1 + n2))
    Space Complexity: O(n1 + n2)

    --------------------------------------------------

    Optimal Approach (union2):
    - Use two pointers i and j for arr1 and arr2.
    - Compare elements and push the smaller one.
    - Skip duplicates using back() comparison.
    - After one array finishes, append remaining elements of the other.

    Time Complexity: O(n1 + n2)
    Space Complexity: O(1) extra (output vector excluded)

    --------------------------------------------------

    Assumptions:
    - Both arrays are sorted in non-decreasing order.
    - Arrays may contain duplicate values.
*/

#include <bits/stdc++.h>
using namespace std;
// bruce force solution
vector<int > union1(int n1,int n2,int arr1[],int arr2[]){
    set <int>st;
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    }
    vector<int>un(st.size());
    int i=0;
    for(auto it:st){
        un[i++]=it;
    }
    return un;
}
//optimal solution
vector<int> union2(int n1,int n2,int arr1[],int arr2[]){
    vector<int>un;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(un.size()==0 || arr1[i]!=un.back()){
            un.push_back(arr1[i]);
            }
        i++;
        }
        else{
            if(un.size()==0 || arr2[j]!=un.back()){
            un.push_back(arr2[j]);
            }
        j++;
        }
    }

    while(i<n1){
        if(un.size()==0 || arr1[i]!=un.back()){
            un.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(un.size()==0 || arr2[j]!=un.back()){
            un.push_back(arr2[j]);
        }
        j++;
    }
    return un;

}

int main(){
    int n1,n2;
    cin>>n1;
    cin>>n2;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    vector<int>un=union2(n1,n2,arr1,arr2);
    for(int i=0;i<un.size();i++){
        cout<<un[i];
    }
}