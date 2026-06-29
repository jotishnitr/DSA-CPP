/*
    Problem: Capacity To Ship Packages Within D Days

    Practice Link:
    https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

    Pattern Used:
    Binary Search on Answer

    Goal:
    Given an array weights where weights[i]
    represents the weight of a package.

    Find the minimum ship capacity required
    to deliver all packages within exactly
    'days' days.

    Packages must be shipped in the given order.

    ---------------------------------------------------------
    Example

    Input:

        weights = [1,2,3,4,5,6,7,8,9,10]
        days = 5

    Output:

        15

    ---------------------------------------------------------
    Observation

    If ship capacity increases:

        Required days decrease.

    Example:

        Capacity = 10 -> 7 days
        Capacity = 12 -> 6 days
        Capacity = 15 -> 5 days
        Capacity = 20 -> 4 days

    Pattern:

        F F F F T T T T

    Therefore:

        Binary Search on Answer

    can be applied.

    =========================================================
    Search Space

    Minimum Capacity:

        largest element in array

    Why?

        Every package must fit inside ship.

    Therefore:

        low = max(weights)

    ---------------------------------------------------------

    Maximum Capacity:

        sum of all elements

    Why?

        Ship can carry everything
        in one day.

    Therefore:

        high = sum(weights)

    =========================================================
    Helper Function

        sumAndMaxi()

    Purpose:

        Find:

            total sum
            largest element

    Used to initialize:

            low
            high

    =========================================================
    Helper Function

        dayNumber(weights, capacity)

    Purpose:

        Calculate number of days needed
        if ship capacity is fixed.

    Logic:

        Keep adding packages.

        If next package exceeds capacity:

            start new day

            days++

    ---------------------------------------------------------
    Example

        weights = [1,2,3,4,5]
        capacity = 5

        Day 1:
            1 + 2 = 3

        Next package 3

            3 + 3 > 5

        Start Day 2

        Continue similarly...

    =========================================================
    1. Brute Force Approach

    Idea:

    Try every capacity from:

        maxElement → totalSum

    First capacity satisfying:

        requiredDays <= givenDays

    is the answer.

    ---------------------------------------------------------
    Time Complexity:

        O((sum - maxElement) * n)

    Space Complexity:

        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    Search for the minimum capacity
    that can ship all packages
    within given days.

    ---------------------------------------------------------
    Binary Search Condition

    If:

        requiredDays <= days

    Then:

        current capacity works.

        Store answer.

        Try smaller capacity.

            high = mid - 1

    ---------------------------------------------------------

    If:

        requiredDays > days

    Then:

        capacity is too small.

        Need larger capacity.

            low = mid + 1

    =========================================================
    Algorithm

    1. Find:
            largest element
            total sum

    2. Set:

            low = largest element
            high = total sum

    3. Compute capacity = mid

    4. Calculate required days

    5. Check feasibility

    6. Shrink search space

    7. Return minimum valid capacity

    =========================================================
    Time Complexity

    Binary Search:
        O(log(sum))

    Day Calculation:
        O(n)

    Total:

        O(n * log(sum))

    =========================================================
    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We are NOT searching for a package.

    We are searching for the minimum
    ship capacity that satisfies:

        requiredDays <= givenDays

    This is a classic:

        Binary Search on Answer

    problem.

    ---------------------------------------------------------
    Similar Problems

    - Koko Eating Bananas
    - Smallest Divisor Given Threshold
    - Minimum Days to Make Bouquets
    - Allocate Books
    - Split Array Largest Sum
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    vector<long long> sumAndMaxi(vector<int>& arr) {

        long long sum = 0;
        long long largest = INT_MIN;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            largest = max(largest, (long long)arr[i]);
        }

        return {sum, largest};
    }

    long long dayNumber(vector<int>& arr, long long capacity) {

        long long days = 1;
        long long load = 0;

        for(int i = 0; i < arr.size(); i++) {

            if(load + arr[i] > capacity) {
                days++;
                load = arr[i];
            }
            else {
                load += arr[i];
            }
        }

        return days;
    }

    // Brute Force Approach
    int shipWithinDaysBrute(vector<int>& weights, int days) {

        vector<long long> info = sumAndMaxi(weights);

        long long totalSum = info[0];
        long long maxWeight = info[1];

        for(long long capacity = maxWeight;
            capacity <= totalSum;
            capacity++) {

            if(dayNumber(weights, capacity) <= days) {
                return capacity;
            }
        }

        return -1;
    }

    // Optimal Binary Search Approach
    int shipWithinDaysOptimal(vector<int>& weights, int days) {

        vector<long long> info = sumAndMaxi(weights);

        long long low = info[1];   // max element
        long long high = info[0];  // total sum

        long long ans = 0;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            long long requiredDays =
                dayNumber(weights, mid);

            if(requiredDays <= days) {
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

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << "Brute Force Answer : "
         << obj.shipWithinDaysBrute(weights, days)
         << endl;

    cout << "Binary Search Answer : "
         << obj.shipWithinDaysOptimal(weights, days)
         << endl;

    return 0;
}