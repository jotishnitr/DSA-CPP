/*
    Problem: Koko Eating Bananas

    Practice Link:
    https://leetcode.com/problems/koko-eating-bananas/

    Pattern Used:
    Binary Search on Answer

    Goal:
    Koko has several banana piles.

    She can eat at a speed of:

        k bananas/hour

    In one hour:
        - She chooses one pile
        - Eats up to k bananas
        - If pile has fewer than k bananas,
          she finishes the pile

    Find the minimum integer speed k
    such that all bananas are eaten within h hours.

    =========================================================
    Example

    Input:
        piles = [3,6,7,11]
        h = 8

    Output:
        4

    Explanation:

        Speed = 4

        3 -> 1 hour
        6 -> 2 hours
        7 -> 2 hours
        11 -> 3 hours

        Total = 8 hours

    =========================================================
    Observation

    If eating speed increases:

        Required hours decrease.

    Example:

        Speed = 2 -> 15 hours
        Speed = 3 -> 10 hours
        Speed = 4 -> 8 hours
        Speed = 5 -> 8 hours
        Speed = 6 -> 6 hours

    This creates a monotonic pattern:

        F F F T T T T

    Therefore:

        Binary Search on Answer

    can be applied.

    =========================================================
    Helper Functions

    ---------------------------------------------------------
    maxEl()

    Purpose:

        Find maximum pile size.

    Why?

        Maximum possible eating speed
        is the largest pile.

    Search Space:

        [1 ... maxPile]

    ---------------------------------------------------------
    hoursNeeded()

    Purpose:

        Calculate total hours required
        at a given eating speed.

    Formula:

        hours =
            ceil(pile / speed)

    Example:

        pile = 11
        speed = 4

        hours = ceil(11/4)
              = 3

    Sum hours for all piles.

    =========================================================
    1. Brute Force Approach

    Idea:

    Try every speed from:

        1 to maxPile

    Steps:

    1. Calculate required hours
    2. First speed satisfying:

            hours <= h

       is the answer

    ---------------------------------------------------------
    Time Complexity:

        O(maxPile * n)

    where:

        n = number of piles

    Space Complexity:

        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    Search for the minimum speed
    that satisfies:

        hoursNeeded(speed) <= h

    ---------------------------------------------------------
    Binary Search Condition

    If:

        hoursNeeded(mid) <= h

    Then:

        mid is a valid speed.

        Store answer and search left
        for a smaller valid speed.

            high = mid - 1

    ---------------------------------------------------------

    If:

        hoursNeeded(mid) > h

    Then:

        speed is too slow.

        Search right.

            low = mid + 1

    =========================================================
    Algorithm

    1. Search space:

            [1 ... maxPile]

    2. Compute mid speed

    3. Calculate required hours

    4. Check feasibility

    5. Move search space

    6. Return minimum valid speed

    =========================================================
    Time Complexity

    Binary Search:
        O(log(maxPile))

    Hours Calculation:
        O(n)

    Total:

        O(n * log(maxPile))

    =========================================================
    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We are not searching for a pile.

    We are searching for the minimum speed
    that satisfies a condition.

    Condition:

        hoursNeeded(speed) <= h

    This is a classic:

        Binary Search on Answer

    problem.

    =========================================================
    Optimization

    Instead of:

        ceil((double)pile / speed)

    You can use integer arithmetic:

        (pile + speed - 1) / speed

    Example:

        (11 + 4 - 1) / 4
        = 14 / 4
        = 3

    Avoids floating-point operations.

    ---------------------------------------------------------
    STL Shortcut:
        No direct STL solution exists.

    Custom binary search is required.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:

    int maxEl(vector<int>& arr) {
        int largest = INT_MIN;

        for(int i = 0; i < arr.size(); i++) {
            largest = max(largest, arr[i]);
        }

        return largest;
    }

    long long hoursNeeded(vector<int>& arr, int speed) {

        long long totalHours = 0;

        for(int i = 0; i < arr.size(); i++) {
            totalHours += ceil((double)arr[i] / (double)speed);
        }

        return totalHours;
    }

    // Brute Force Approach
    int minEatingSpeedBrute(vector<int>& piles, int h) {

        int maxPile = maxEl(piles);

        for(int speed = 1; speed <= maxPile; speed++) {

            if(hoursNeeded(piles, speed) <= h) {
                return speed;
            }
        }

        return -1;
    }

    // Optimal Binary Search Approach
    int minEatingSpeedOptimal(vector<int>& piles, int h) {

        int low = 1;
        int high = maxEl(piles);

        int ans = INT_MAX;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(hoursNeeded(piles, mid) <= h) {
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

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Brute Force Answer : "
         << obj.minEatingSpeedBrute(piles, h)
         << endl;

    cout << "Binary Search Answer : "
         << obj.minEatingSpeedOptimal(piles, h)
         << endl;

    return 0;
}