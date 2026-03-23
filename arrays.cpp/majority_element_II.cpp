/*
    Program: Majority Element II (Elements appearing more than n/3 times)

    Problem:
    Given an integer array of size n, return all elements that appear
    more than ⌊n/3⌋ times.

    Key Observation:
    At most TWO elements can appear more than n/3 times.

    Proof intuition:
    If three different elements each appeared more than n/3 times,
    total occurrences would exceed n.

    1. Brute Force Approach

    Idea:
    For every element, count its occurrences by scanning
    the entire array.

    Steps:
    1. For each index i
    2. Count frequency of nums[i]
    3. If frequency > n/3 and not already added → store it

    Time Complexity: O(n²)
    Space Complexity: O(1)

    2. Better Approach (Hash Map)

    Idea:
    Use a hash map to store frequency of each element.

    Steps:
    1. Traverse array and update frequency map
    2. Traverse map and collect elements with freq > n/3

    Time Complexity: O(n)
    Space Complexity: O(n)

    3. Optimal Approach (Extended Boyer–Moore Voting)

    Key Insight:
    Since at most two elements can appear more than n/3 times,
    we track two candidates and their counts.

    Phase 1: Candidate Selection
        Maintain:
            element1, element2
            count1, count2

        Adjust counts while scanning the array.

    Phase 2: Verification
        Count occurrences of both candidates
        to confirm they appear more than n/3 times.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Concepts Used:
    - Frequency counting
    - Hash maps
    - Boyer–Moore majority voting algorithm
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }

        if (count > n / 3)
        {
            if (find(ans.begin(), ans.end(), nums[i]) == ans.end())
                ans.push_back(nums[i]);
        }
    }

    return ans;
}

vector<int> better(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> freq;
    vector<int> ans;

    for (int num : nums)
        freq[num]++;

    for (auto it : freq)
    {
        if (it.second > n / 3)
            ans.push_back(it.first);
    }

    return ans;
}

vector<int> optimal(vector<int> &nums)
{
    int n = nums.size();

    int count1 = 0, count2 = 0;
    int element1 = INT_MIN, element2 = INT_MIN;

    for (int num : nums)
    {
        if (count1 == 0 && num != element2)
        {
            element1 = num;
            count1 = 1;
        }
        else if (count2 == 0 && num != element1)
        {
            element2 = num;
            count2 = 1;
        }
        else if (num == element1)
            count1++;
        else if (num == element2)
            count2++;
        else
        {
            count1--;
            count2--;
        }
    }

    int cnt1 = 0, cnt2 = 0;

    for (int num : nums)
    {
        if (num == element1)
            cnt1++;
        else if (num == element2)
            cnt2++;
    }

    vector<int> ans;

    if (cnt1 > n / 3)
        ans.push_back(element1);

    if (cnt2 > n / 3)
        ans.push_back(element2);

    return ans;
}

void printResult(vector<int> result)
{
    if (result.empty())
    {
        cout << "No majority elements\n";
        return;
    }

    for (int num : result)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};

    cout << "Input Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n\n";

    cout << "Brute Force Result: ";
    printResult(bruteForce(nums));

    cout << "Better Solution Result: ";
    printResult(better(nums));

    cout << "Optimal Solution Result: ";
    printResult(optimal(nums));

    return 0;
}