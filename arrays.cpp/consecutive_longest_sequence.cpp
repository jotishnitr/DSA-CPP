/*
    Program: Longest Consecutive Sequence

    Problem:
    Given an unsorted array of integers, find the length
    of the longest sequence of consecutive integers.

    Example:
    Input: 100 4 200 1 3 2
    Output: 4
    Explanation: The sequence 1,2,3,4 has length 4.


    1. Brute Force Approach

    Idea:
    For every element, keep checking whether the next
    consecutive number exists using linear search.

    Time Complexity: O(n^2)
    Space Complexity: O(1)


    2. Better Approach

    Idea:
    Sort the array and count consecutive numbers.

    Time Complexity: O(n log n)
    Space Complexity: O(1)


    3. Optimal Approach

    Idea:
    Use an unordered_set for O(1) lookup.

    Key Insight:
    Only start counting when the number is the
    start of a sequence (num-1 does not exist).

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

bool linearsearch(vector<int>& nums, int target){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            return true;
        }
    }
    return false;
}

int bruteforce(vector<int>& nums){
    int n = nums.size();
    int longest = 1;

    for(int i=0;i<n;i++){
        int x = nums[i];
        int count = 1;

        while(linearsearch(nums,x+1)){
            x = x + 1;
            count++;
        }

        longest = max(longest,count);
    }

    return longest;
}

int better(vector<int> nums){
    int n = nums.size();
    int longest = 1;
    int count = 0;
    int lastsmaller = INT_MIN;

    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(nums[i]-1==lastsmaller){
            count++;
            lastsmaller=nums[i];
        }
        else if(nums[i]!=lastsmaller){
            count=1;
            lastsmaller=nums[i];
        }

        longest=max(count,longest);
    }

    return longest;
}

int optimal(vector<int>& nums){
    if(nums.size()==0) return 0;

    unordered_set<int> st;
    int longest=1;

    for(int num:nums){
        st.insert(num);
    }

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int count=1;
            int x=it;

            while(st.find(x+1)!=st.end()){
                x++;
                count++;
            }

            longest=max(longest,count);
        }
    }

    return longest;
}
int main(){
    int n;
    cout<<"Enter no.of elements in array:"<<endl;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
    }
    cout<<optimal(nums);
}