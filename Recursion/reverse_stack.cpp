/*
====================================================
README - Reverse a Stack
====================================================

Problem:
Given a stack, reverse its order so that the top element
becomes the bottom and the bottom element becomes the top.

----------------------------------------------------
Brute Force Approach (Using Extra Stack)
----------------------------------------------------
Idea:
1. Create another stack.
2. Pop every element from the original stack.
3. Push each element into the new stack.
4. Assign the new stack back.

Time Complexity : O(n)
Space Complexity: O(n)

----------------------------------------------------
Optimal Approach (Recursion)
----------------------------------------------------
Idea:
1. Pop the top element recursively until the stack becomes empty.
2. While recursion returns, insert each removed element
   at the bottom of the stack.
3. This naturally reverses the stack without using any
   extra data structure.

Helper Function:
insertBottom(stack<int>& st, int val)
- Inserts an element at the bottom of the stack using recursion.

Time Complexity : O(n²)
Space Complexity: O(n)   // Recursion stack

----------------------------------------------------
Key Concept:
- Brute Force uses an additional stack.
- Optimal uses recursion to simulate the extra storage.
- Although called "optimal" in interview practice because it
  avoids an explicit auxiliary stack, it still uses O(n)
  recursive call stack and has O(n²) time due to repeated
  bottom insertions.

Related Problems:
- LeetCode: Not available as an official problem.
- GeeksforGeeks: Reverse a Stack
- Coding Ninjas: Reverse Stack Using Recursion
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //====================================================
    // Brute Force (Using Extra Stack)
    // Time: O(n)
    // Space: O(n)
    //====================================================

    void reverseStackBrute(stack<int>& st) {

        stack<int> temp;

        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        st = temp;
    }

    //====================================================
    // Optimal (Recursion)
    // Time: O(n²)
    // Space: O(n) (Recursion Stack)
    //====================================================

    void insertBottom(stack<int>& st, int val) {

        if (st.empty()) {
            st.push(val);
            return;
        }

        int topVal = st.top();
        st.pop();

        insertBottom(st, val);

        st.push(topVal);
    }

    void reverseStack(stack<int>& st) {

        if (st.empty()) {
            return;
        }

        int topVal = st.top();
        st.pop();

        reverseStack(st);

        insertBottom(st, topVal);
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

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    Solution obj;

    cout << "Original Stack: ";
    printStack(st);

    // Recreate stack since printStack() takes a copy
    st = stack<int>();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // ---------- Brute Force ----------
    obj.reverseStackBrute(st);

    cout << "After Brute Force Reverse: ";
    printStack(st);

    // Recreate stack
    st = stack<int>();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // ---------- Optimal ----------
    obj.reverseStack(st);

    cout << "After Recursive Reverse: ";
    printStack(st);

    return 0;
}