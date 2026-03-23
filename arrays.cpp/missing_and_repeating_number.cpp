/*
    Program: Find Missing and Repeating Number

    Problem:
    Given an array of size n containing numbers from 1 to n,
    one number is missing and one number is repeating.
    Find both numbers.

    Example:
    Input:  [4, 3, 6, 2, 1, 1]
    Output: Repeating = 1, Missing = 5

    
    1. Brute Force Approach

    Idea:
    For each number from 1 to n, count its occurrences.

    Steps:
    - For each number i from 1 to n:
        count occurrences in array
        if count == 2 → repeating
        if count == 0 → missing

    Time Complexity: O(n^2)
    Space Complexity: O(1)

    
    2. Better Approach (Hashing)

    Idea:
    Use a frequency array to count occurrences.

    Steps:
    - Create hash array of size n+1
    - Count frequency of each element
    - Traverse hash:
        freq == 2 → repeating
        freq == 0 → missing

    Time Complexity: O(n)
    Space Complexity: O(n)

    
    3. Optimal Approach (Mathematics)

    Idea:
    Use sum and sum of squares formulas.

    Let:
        x = missing number
        y = repeating number

    We know:
        S  = sum of array
        SN = n(n+1)/2

        S2  = sum of squares of array
        SN2 = n(n+1)(2n+1)/6

    Then:
        x - y = SN - S
        x^2 - y^2 = SN2 - S2

    ⇒ (x - y)(x + y) = SN2 - S2

    Solve:
        x + y = (SN2 - S2) / (SN - S)

    Finally:
        x = ( (x - y) + (x + y) ) / 2
        y = x - (x - y)

    Time Complexity: O(n)
    Space Complexity: O(1)

    Important:
    Use long long to avoid overflow when dealing with sums.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force
vector<int> brute(vector<int> arr){
    int n = arr.size();
    int repeating = -1, missing = -1;

    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i) count++;
        }
        if(count == 2) repeating = i;
        else if(count == 0) missing = i;
    }
    return {repeating, missing};
}

// Better (hashing)
vector<int> better(vector<int> arr){
    int n = arr.size();
    vector<int> hash(n+1, 0);

    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++){
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;
    }
    return {repeating, missing};
}

// Optimal
vector<int> optimal(vector<int> arr){
    int n = arr.size();
    long long S = 0, S2 = 0;

    for(int i = 0; i < n; i++){
        S += arr[i];
        S2 += (long long)arr[i] * arr[i];
    }

    long long SN = (long long)n * (n + 1) / 2;
    long long SN2 = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long val1 = SN - S;
    long long val2 = SN2 - S2;

    val2 = val2 / val1;

    long long x = (val1 + val2) / 2; // missing
    long long y = x - val1;          // repeating

    return {(int)y, (int)x};
}

int main(){
    vector<int> arr = {4, 3, 6, 2, 1, 1};

    vector<int> ans = optimal(arr);

    cout << "Optimal: Repeating = " << ans[0] << ", Missing = " << ans[1] << endl;

    return 0;
}