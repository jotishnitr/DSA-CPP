/*
    Problem: Magnetic Force Between Two Balls
    (Aggressive Cows)

    Practice Links:
    LeetCode:
    https://leetcode.com/problems/magnetic-force-between-two-balls/

    GFG:
    https://www.geeksforgeeks.org/problems/aggressive-cows/1

    Pattern Used:
    Binary Search on Answer

    Goal:
    Given positions of baskets and m balls,
    place all balls such that the minimum
    distance between any two balls is maximized.

    Return the largest possible minimum distance.

    =========================================================
    Example

    Input:

        position = [1,2,3,4,7]
        m = 3

    Output:

        3

    Explanation:

        Place balls at:

            1, 4, 7

        Distances:

            3 and 3

        Minimum distance = 3

        This is the maximum possible answer.

    =========================================================
    Observation

    Suppose:

        distance = 3

    If placing all balls is possible,

    then placing them with:

        distance = 2
        distance = 1

    is also possible.

    ---------------------------------------------------------

    Suppose:

        distance = 4

    If placing all balls is NOT possible,

    then:

        distance = 5
        distance = 6

    will also be impossible.

    ---------------------------------------------------------

    Pattern:

        T T T T F F F

    Therefore:

        Binary Search on Answer

    can be applied.

    =========================================================
    Search Space

    Minimum Possible Distance:

        1

    Maximum Possible Distance:

        last_position - first_position

    Therefore:

        low = 1

        high =
            position[n-1] - position[0]

    =========================================================
    Helper Function

        canWePlace(arr, distance, balls)

    Purpose:

        Check whether all balls can be placed
        while maintaining at least 'distance'
        between consecutive balls.

    ---------------------------------------------------------
    Greedy Placement

    Place first ball at:

        arr[0]

    Then place the next ball at the first
    valid position satisfying:

        current_position - last_position
            >= distance

    Continue until all positions are checked.

    ---------------------------------------------------------

    If:

        countBalls >= balls

    Return:

        true

    Otherwise:

        false

    =========================================================
    1. Brute Force Approach

    Idea

    Try every possible distance.

    ---------------------------------------------------------

    For:

        distance = 1 to maximum distance

    Check:

        canWePlace(distance)

    First distance that becomes invalid:

        answer = distance - 1

    ---------------------------------------------------------
    Time Complexity:

        O((maxDistance) * n)

    Space Complexity:

        O(1)

    =========================================================
    2. Optimal Binary Search Approach

    Core Idea

    Search for the largest distance
    for which placement is possible.

    ---------------------------------------------------------
    Binary Search Condition

    If:

        canWePlace(mid) == true

    Then:

        distance is possible.

        Store answer.

        Try larger distance.

            low = mid + 1

    ---------------------------------------------------------

    If:

        canWePlace(mid) == false

    Then:

        distance is too large.

        Search smaller distances.

            high = mid - 1

    =========================================================
    Why Return high?

    Binary search ends when:

        low > high

    At that point:

        high = largest valid distance

        low = first invalid distance

    Therefore:

        answer = high

    In your code:

        ans stores the same value.

    Hence:

        return ans;

    or

        return high;

    both work.

    =========================================================
    Example

        position = [1,2,3,4,7]
        m = 3

    Search Space:

        low = 1
        high = 6

    ---------------------------------------------------------

        mid = 3

        Possible

        Answer = 3

        Search right

    ---------------------------------------------------------

        mid = 5

        Not possible

        Search left

    ---------------------------------------------------------

        mid = 4

        Not possible

        Search left

    ---------------------------------------------------------

    End:

        high = 3

    Answer:

        3

    =========================================================
    Time Complexity

    Sorting:
        O(n log n)

    Binary Search:
        O(log(maxDistance))

    Feasibility Check:
        O(n)

    Total:

        O(n log n +
          n * log(maxDistance))

    =========================================================
    Space Complexity:
        O(1)

    =========================================================
    Important Insight

    We are not searching for a basket.

    We are searching for the largest
    minimum distance that satisfies:

        Can all balls be placed?

    This is a classic:

        Binary Search on Answer

    problem.

    ---------------------------------------------------------
    Similar Problems

    - Aggressive Cows
    - Allocate Books
    - Split Array Largest Sum
    - Painter's Partition
    - Capacity To Ship Packages
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool canWePlace(vector<int>& arr, int distance, int balls) {

        int countBalls = 1;
        int last = 0;

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] - arr[last] >= distance) {
                countBalls++;
                last = i;
            }
        }

        return countBalls >= balls;
    }

    // Brute Force Approach
    int maxDistanceBrute(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int n = position.size();
        int limit = position[n - 1] - position[0];

        for (int dist = 1; dist <= limit; dist++) {

            if (!canWePlace(position, dist, m)) {
                return dist - 1;
            }
        }

        return limit;
    }

    // Optimal Binary Search Approach
    int maxDistanceOptimal(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int n = position.size();

        int low = 1;
        int high = position[n - 1] - position[0];

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canWePlace(position, mid, m)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;     // or return high;
    }
};

int main() {

    Solution obj;

    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;

    cout << "Brute Force Answer  : "
         << obj.maxDistanceBrute(position, m)
         << endl;

    cout << "Binary Search Answer: "
         << obj.maxDistanceOptimal(position, m)
         << endl;

    return 0;
}