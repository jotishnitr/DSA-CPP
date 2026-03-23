/*
    Program: Merge Intervals

    Problem:
    Given a collection of intervals, merge all overlapping intervals.

    Example:
    Input:  [1,3], [2,6], [8,10], [15,18]
    Output: [1,6], [8,10], [15,18]

    Explanation:
    [1,3] and [2,6] overlap → merged into [1,6]

    1. Brute Force Approach

    Idea:
    - Sort intervals
    - For each interval, try to merge with all following intervals

    Steps:
    1. Fix interval i
    2. Extend its end as long as next intervals overlap
    3. Skip already covered intervals

    Time Complexity: O(n^2)
    Space Complexity: O(n)

    2. Optimal Approach

    Key Idea:
    Once sorted, overlapping intervals are adjacent.

    Steps:
    1. Sort intervals based on start time
    2. Traverse intervals:
        - If no overlap → add new interval
        - If overlap → merge with last interval

    Condition:
        overlap if current.start <= last.end

    Time Complexity: O(n log n)  (due to sorting)
    Space Complexity: O(n)

    Concepts Used:
    - Sorting
    - Greedy merging
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteforce(vector<vector<int>> intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (!result.empty() && end <= result.back()[1]) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            } else {
                break;
            }
        }

        result.push_back({start, end});
    }

    return result;
}

vector<vector<int>> optimal(vector<vector<int>> intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());

    for (auto& interval : intervals) {
        if (result.empty() || result.back()[1] < interval[0]) {
            result.push_back(interval);
        } else {
            result.back()[1] = max(result.back()[1], interval[1]);
        }
    }

    return result;
}

void printIntervals(vector<vector<int>> intervals) {
    for (auto& it : intervals) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    cout << "Optimal Result:\n";
    vector<vector<int>> res2 = optimal(intervals);
    printIntervals(res2);

    return 0;
}