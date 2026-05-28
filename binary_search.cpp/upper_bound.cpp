/*
    Problem: Upper Bound

    Practice Link:
    https://www.geeksforgeeks.org/problems/implement-upper-bound/1

    Goal:
    Find the first index such that:
        arr[index] > target

    If no such index exists,
    return arr.size().

    ---------------------------------------------------------
    Example

    Input:
        arr = [1,2,4,4,5,6]
        target = 4

    Output:
        4

    Explanation:
    arr[4] = 5
    and it is the first element > 4.

    ---------------------------------------------------------
    Core Idea

    We are searching for the FIRST element
    strictly greater than target.

    Whenever:
        arr[mid] > target

    mid may be a possible answer,
    but there could still be a smaller valid index
    on the left side.

    So:
        store answer
        continue searching left half

    ---------------------------------------------------------
    Approach

    1. Initialize:
            low = 0
            high = n - 1
            ans = n

    2. Find mid

    3. If arr[mid] > target:
            ans = mid
            search left half

    4. Else:
            search right half

    5. Return ans

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    Upper Bound means:
        FIRST element > target

    Difference from Lower Bound:

        Lower Bound:
            FIRST element >= target

        Upper Bound:
            FIRST element > target
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& arr, int target) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] > target) {
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

    vector<int> arr = {1, 3, 3, 5, 7, 9};
    int target = 3;

    int result = obj.upperBound(arr, target);

    cout << "Upper Bound Index: " << result << endl;

    return 0;
}