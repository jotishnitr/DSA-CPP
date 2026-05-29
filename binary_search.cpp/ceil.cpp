/*
    Problem: Find Ceil in Sorted Array

    Practice Link:
    https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1

    Pattern Used:
    First True Binary Search

    Goal:
    Find the index of the smallest element
    greater than or equal to x.

    Ceil Definition:
        Ceil(x) = smallest value >= x

    If no such element exists,
    return -1.

    ---------------------------------------------------------
    Example

    Input:
        arr = [1,2,4,6,10]
        x = 5

    Output:
        3

    Explanation:
        arr[3] = 6
        and 6 is the smallest value >= 5

    ---------------------------------------------------------
    Core Idea

    We are searching for the FIRST valid position
    where:
        arr[index] >= x

    Whenever:
        arr[mid] >= x

    mid can be a possible answer,
    but there may exist a smaller valid value
    on the left side.

    So:
        store answer
        search left half

    ---------------------------------------------------------
    Approach

    1. Initialize:
            low = 0
            high = n - 1
            ceil = -1

    2. Find mid

    3. If arr[mid] >= x:
            store mid
            search left half

    4. Else:
            search right half

    5. Return ceil index

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    Ceil means:
        FIRST element >= x

    This is similar to Lower Bound.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCeil(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;

        int ceilIndex = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] >= x) {
                ceilIndex = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ceilIndex;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {1, 2, 4, 6, 10};
    int x = 5;

    int result = obj.findCeil(arr, x);

    cout << "Ceil Index: " << result << endl;

    return 0;
}