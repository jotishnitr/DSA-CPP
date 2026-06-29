/*
    Problem: Minimum Number of Days to Make m Bouquets

    Practice Link:
    https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

    Pattern Used:
    Binary Search on Answer

    Goal:
    Given:

        bloomDay[i] = day on which flower i blooms

        m = number of bouquets required

        k = flowers needed per bouquet

    Find the minimum day on which it is possible
    to make exactly m bouquets.

    Rule:

        A bouquet requires k ADJACENT bloomed flowers.

    If impossible,
    return -1.

    =========================================================
    Example

    Input:

        bloomDay = [1,10,3,10,2]
        m = 3
        k = 1

    Output:

        3

    Explanation:

        Day 1:
            [1]
            Only 1 bouquet possible

        Day 2:
            [1,2]
            2 bouquets possible

        Day 3:
            [1,3,2]
            3 bouquets possible

        Minimum day = 3

    =========================================================
    Important Observation

    If bouquets can be made on day X,

    then bouquets can also be made on:

        X+1
        X+2
        X+3
        ...

    Because more flowers bloom as days increase.

    This creates a monotonic pattern:

        F F F F T T T T

    Therefore:

        Binary Search on Answer

    can be applied.

    =========================================================
    Feasibility Function

        possible(arr, day, m, k)

    Purpose:

        Determine whether m bouquets
        can be formed by day.

    ---------------------------------------------------------
    Logic

    Traverse array:

        arr[i] <= day

            flower is bloomed

            count++

        otherwise

            bouquetCount += count / k

            reset count

    After traversal:

        bouquetCount += count / k

    Return:

        bouquetCount >= m

    ---------------------------------------------------------
    Why count / k ?

    Example:

        count = 7
        k = 3

    Possible bouquets:

        7 / 3 = 2

    =========================================================
    Helper Function

        minMax()

    Purpose:

        Find minimum and maximum bloom day.

    Search Space:

        [minimum bloom day ... maximum bloom day]

    =========================================================
    1. Brute Force Approach

    Idea:

    Check every day from:

        minDay to maxDay

    First day satisfying:

        possible(day) == true

    is the answer.

    ---------------------------------------------------------
    Time Complexity:

        O((maxDay - minDay) * n)

    Space Complexity:

        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    Search for the minimum day
    that satisfies:

        possible(day) == true

    ---------------------------------------------------------
    Binary Search Condition

    If:

        possible(mid) == true

    Then:

        mid is a valid answer.

        Store answer and search left.

            high = mid - 1

    ---------------------------------------------------------

    If:

        possible(mid) == false

    Then:

        Need more days.

            low = mid + 1

    =========================================================
    Edge Case

    Before starting:

        if(m * k > total flowers)

    Then:

        Impossible to make m bouquets.

        Return -1.

    ---------------------------------------------------------

    Example:

        n = 5
        m = 3
        k = 2

        Need:
            3 * 2 = 6 flowers

        Available:
            5 flowers

        Impossible.

    =========================================================
    Time Complexity

    Binary Search:
        O(log(maxDay - minDay))

    Feasibility Check:
        O(n)

    Total:

        O(n * log(maxDay - minDay))

    =========================================================
    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We are not searching for a flower.

    We are searching for the minimum day
    that satisfies a condition.

    Condition:

        Can we make m bouquets by this day?

    This is a classic:

        Binary Search on Answer

    problem.

    ---------------------------------------------------------
    STL Shortcut:
        No direct STL solution exists.

    Custom binary search is required.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    bool possible(vector<int>& arr, int day, int m, int k) {

        int count = 0;
        int bouquetCount = 0;

        for(int i = 0; i < arr.size(); i++) {

            if(arr[i] <= day) {
                count++;
            }
            else {
                bouquetCount += count / k;
                count = 0;
            }
        }

        bouquetCount += count / k;

        return bouquetCount >= m;
    }

    vector<int> minMax(vector<int>& arr) {

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int x : arr) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        return {mini, maxi};
    }

    // Brute Force
    int minDaysBrute(vector<int>& bloomDay, int m, int k) {

        if((long long)m * k > bloomDay.size()) {
            return -1;
        }

        vector<int> mm = minMax(bloomDay);

        for(int day = mm[0]; day <= mm[1]; day++) {

            if(possible(bloomDay, day, m, k)) {
                return day;
            }
        }

        return -1;
    }

    // Optimal
    int minDaysOptimal(vector<int>& bloomDay, int m, int k) {

        if((long long)m * k > bloomDay.size()) {
            return -1;
        }

        vector<int> mm = minMax(bloomDay);

        int low = mm[0];
        int high = mm[1];
        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    cout << "Brute Force Answer : "
         << obj.minDaysBrute(bloomDay, m, k)
         << endl;

    cout << "Binary Search Answer : "
         << obj.minDaysOptimal(bloomDay, m, k)
         << endl;

    return 0;
}