/*
    Program: Pascal's Triangle Generation

    Problem:
    Generate the first N rows of Pascal’s Triangle.

    Pascal’s Triangle is a triangular arrangement where:
        - The first and last elements of every row are 1.
        - Every other element is the sum of the two numbers
          directly above it in the previous row.

    Example (N = 5):

        1
        1 1
        1 2 1
        1 3 3 1
        1 4 6 4 1

    Approach Used: Binomial Coefficient Formula

    The element at position (row r, column c) is:

        C(r-1, c-1)

    where
        C(n, k) = n! / (k! * (n-k)!)

    Instead of computing factorials, we use the recurrence:

        next_value = current_value * (n - i) / i

    This lets us compute each element in O(1) time.


    Steps:

    1. Generate each row individually using the formula.
    2. Start every row with 1.
    3. Iteratively compute the next value using the relation
       derived from binomial coefficients.
    4. Store each row in a 2D vector.


    Time Complexity:
        O(N^2)
        Because the triangle contains N(N+1)/2 elements.

    Space Complexity:
        O(N^2)
        For storing the triangle.

        
    Advantages of This Method:
    - Avoids factorial computations
    - Prevents large intermediate numbers
    - More efficient than computing each element separately
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> row(int n) {
    vector<int> r;
    r.push_back(1);

    long long ans = 1;

    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        r.push_back(ans);
    }

    return r;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    for (int i = 1; i <= numRows; i++) {
        result.push_back(row(i));
    }

    return result;
}

int main() {

    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> triangle = generate(numRows);

    for (auto r : triangle) {
        for (auto val : r) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}