/*
====================================================
README - Sort a Stack
====================================================

Problem:
Given a stack of integers, sort the stack such that the
largest element remains at the top and the smallest
element is at the bottom.

----------------------------------------------------
Approach 1: Brute Force (Vector + Sort)
----------------------------------------------------
Idea:
1. Pop all elements from the stack into a vector.
2. Sort the vector in ascending order.
3. Push all elements back into the stack.

Since elements are pushed from smallest to largest,
the largest element ends up at the top of the stack.

Time Complexity : O(n log n)
Space Complexity: O(n)

----------------------------------------------------
Approach 2: Optimal (Recursion)
----------------------------------------------------
Idea:
Sort the stack recursively without using any extra
data structure.

Steps:
1. Pop the top element.
2. Recursively sort the remaining stack.
3. Insert the popped element back into its correct
   position using another recursive function.

The insert() function:
- If the stack is empty or the top element is less
  than or equal to the current element, push it.
- Otherwise:
    • Pop the top element.
    • Recursively insert the current element.
    • Push the removed element back.

Time Complexity : O(n²)
Space Complexity: O(n) (Recursion Stack)

----------------------------------------------------
Example
----------------------------------------------------

Input Stack (Top -> Bottom):
4
2
5
1

After Sorting (Top -> Bottom):
5
4
2
1

----------------------------------------------------
Key Learning
----------------------------------------------------
1. Recursion can simulate the auxiliary stack.
2. insert() places an element in its correct sorted
   position.
3. A recursive solution avoids using any explicit
   extra data structure, though recursion consumes
   O(n) stack space.
4. This is one of the most common recursion problems
   asked in coding interviews.
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //====================================================
    // Brute Force (Using Vector + Sort)
    // Time: O(n log n)
    // Space: O(n)
    //====================================================

    void sortStackBrute(stack<int>& st) {

        vector<int> arr;

        while (!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }

        sort(arr.begin(), arr.end());

        for (int x : arr) {
            st.push(x);
        }
    }

    //====================================================
    // Optimal (Recursion)
    // Time: O(n²)
    // Space: O(n)
    //====================================================

    void insert(stack<int>& st, int temp) {

        if (st.empty() || st.top() <= temp) {
            st.push(temp);
            return;
        }

        int val = st.top();
        st.pop();

        insert(st, temp);

        st.push(val);
    }

    void sortStack(stack<int>& st) {

        if (!st.empty()) {

            int temp = st.top();
            st.pop();

            sortStack(st);

            insert(st, temp);
        }
    }
};

void printStack(stack<int> st) {

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {

    Solution obj;

    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);

    cout << "Original Stack: ";
    printStack(st);

    // ---------- Brute Force ----------
    stack<int> brute = st;
    obj.sortStackBrute(brute);

    cout << "After Brute Force Sorting: ";
    printStack(brute);

    // ---------- Optimal ----------
    stack<int> optimal = st;
    obj.sortStack(optimal);

    cout << "After Recursive Sorting: ";
    printStack(optimal);

    return 0;
}