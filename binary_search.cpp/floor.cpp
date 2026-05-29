/*
    Problem: Find Floor in Sorted Array

    Practice Link:
    https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

    Pattern Used:
    Last True Binary Search

    Goal:
    Find the index of the greatest element
    less than or equal to x.

    Floor Definition:
        Floor(x) = largest value <= x

    If no such element exists,
    return -1.

    ---------------------------------------------------------
    Example

    Input:
        arr = [1,2,4,6,10]
        x = 5

    Output:
        2

    Explanation:
        arr[2] = 4
        and 4 is the greatest value <= 5

    ---------------------------------------------------------
    Core Idea

    We are searching for the LAST valid position
    where:
        arr[index] <= x

    Whenever:
        arr[mid] <= x

    mid can be a possible answer,
    but there may exist a larger valid value
    on the right side.

    So:
        store answer
        search right half

    ---------------------------------------------------------
    Approach

    1. Initialize:
            low = 0
            high = n - 1
            floor = -1

    2. Find mid

    3. If arr[mid] <= x:
            store mid
            search right half

    4. Else:
            search left half

    5. Return floor index

    ---------------------------------------------------------
    Time Complexity:
        O(log n)

    Space Complexity:
        O(1)

    ---------------------------------------------------------
    Important Insight

    Floor means:
        LAST element <= x

    This is opposite of Lower Bound,
    which finds:
        FIRST element >= x
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findFloor(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;

        int floorIndex = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                floorIndex = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return floorIndex;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {1, 2, 4, 6, 10};
    int x = 5;

    int result = obj.findFloor(arr, x);

    cout << "Floor Index: " << result << endl;

    return 0;
}