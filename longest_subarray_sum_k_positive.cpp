/*

Problem: Longest Subarray with Sum = K (Positive Integers Only)
Category: Arrays / Sliding Window
Difficulty: Medium

Problem Statement:
Given an array of positive integers and an integer K,
find the length of the longest contiguous subarray
whose sum equals K.

Approach 1: Brute Force
- Generate all subarrays using two loops.
- Compute sum for each.
- Track maximum length where sum == K.

Time Complexity: O(n^2)
Space Complexity: O(1)

Approach 2: Better (Prefix Sum + Hashing)
- Maintain running prefix sum.
- Store prefix sum frequencies in map.
- If (currentSum - K) exists, update max length.

Time Complexity: O(n)
Space Complexity: O(n)

Approach 3: Optimal (Sliding Window)
Why it works:
Since all elements are positive:
- Expanding window increases sum
- Shrinking window decreases sum

Algorithm:
- Maintain two pointers (left, right).
- Expand right to increase sum.
- If sum > K, shrink from left.
- Update max length when sum == K.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int bruteforce(int n,int k,int array[]){
    int longest=0;
    for(int i=0;i<n;i++){
        
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=array[j];
            if(sum==k){
                longest=max(longest,j-i+1);
            }
        }
    }
    return longest;
}

int better(int n,int k,int array[]){
    map<long long ,int>presummap;
    long long sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        int rem=sum-k;
        if(presummap.find(rem)!=presummap.end()){
            int len=i-presummap[rem];
            maxlen=max(maxlen,len);
        }
        if(presummap.find(sum)==presummap.end()){
            presummap[sum]=i;
        }
    }
    return maxlen;

}

int optimal(int n,int k,int array[]){
    int sum=array[0];
    int maxlen=0;
    int right=0;
    int left=0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=array[left];
            left++;
        }
        if(sum==k){
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n){
            sum+=array[right];
        }
    }
    return maxlen;
}
int main(){
    int n,k;
    cin>>n>>k;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<optimal(n,k,array);

}


