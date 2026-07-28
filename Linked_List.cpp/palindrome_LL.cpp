/*
------------------------------------------------------------
Problem: Palindrome Linked List

LeetCode:
https://leetcode.com/problems/palindrome-linked-list/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

Pattern Used:
1. Stack
2. Slow & Fast Pointer + Reverse Linked List

============================================================

Approach 1: Stack (Brute Force)

Idea:
Store all node values in a stack.

Since a stack follows the LIFO principle,
the values are retrieved in reverse order.

Traverse the linked list again and compare
each node's value with the stack's top.

If every value matches, the linked list is
a palindrome.

------------------------------------------------------------
Algorithm

1. Create an empty stack.
2. Traverse the linked list and push every
   node's value into the stack.
3. Traverse the list again.
4. Compare the current node's value with
   the stack's top.
5. If any value differs,
   return false.
6. Otherwise continue until the end.
7. Return true.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 2 -> 1

Stack

1
2
2
1

Compare

1 == 1 ✔

2 == 2 ✔

2 == 2 ✔

1 == 1 ✔

Return true

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(n)

============================================================

Approach 2: Reverse Second Half (Optimal)

Idea:
A palindrome reads the same from both ends.

1. Find the middle of the linked list using
   Slow and Fast pointers.
2. Reverse the second half.
3. Compare the first half with the reversed
   second half.
4. Restore the original linked list.
5. Return the result.

------------------------------------------------------------
Algorithm

1. Find the middle node using Slow and Fast
   pointers.

2. Reverse the second half starting from

slow->next

3. Compare

first half

with

reversed second half.

4. If any value differs,

restore the list and return false.

5. Restore the reversed half.

6. Return true.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 2 -> 1

-----------------------

Find Middle

Slow = 2

Second Half

2 -> 1

-----------------------

Reverse Second Half

1 -> 2

Now

First Half

1 -> 2

Second Half

1 -> 2

-----------------------

Compare

1 == 1 ✔

2 == 2 ✔

All matched.

Restore

2 -> 1

Original list becomes

1 -> 2 -> 2 -> 1

Return true

------------------------------------------------------------
Key Observation

Only the second half of the linked list
needs to be reversed.

Comparing the first half with the reversed
second half determines whether the list is
a palindrome.

Restoring the reversed half preserves the
original linked list structure.

------------------------------------------------------------
Time Complexity

Stack Method

O(n)

Optimal Method

O(n)

------------------------------------------------------------
Space Complexity

Stack Method

O(n)

Optimal Method

O(1)

(Excluding the recursive call stack used in
the reverse() function.)

------------------------------------------------------------
Similar Problems

1. Reverse Linked List
2. Middle of the Linked List
3. Reorder List
4. Reverse Linked List II
5. Twin Sum of a Linked List
------------------------------------------------------------
*/

#include <iostream>
#include <stack>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:

    // ---------------- Brute Force (Using Stack) ----------------

    bool isPalindromeStack(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return true;

        stack<int> st;

        ListNode* temp = head;

        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while (temp != nullptr) {

            if (temp->val != st.top())
                return false;

            st.pop();
            temp = temp->next;
        }

        return true;
    }

    // Reverse a Linked List
    ListNode* reverse(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverse(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    // ---------------- Optimal (Reverse Second Half) ----------------

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while (second != nullptr) {

            if (first->val != second->val) {
                slow->next = reverse(newHead);   // Restore the list
                return false;
            }

            first = first->next;
            second = second->next;
        }

        slow->next = reverse(newHead);           // Restore the list

        return true;
    }
};

// Insert at End
ListNode* insertAtEnd(ListNode* head, int val) {

    ListNode* newNode = new ListNode(val);

    if (head == nullptr)
        return newNode;

    ListNode* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Print List
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

// Create a copy of a linked list
ListNode* copyList(ListNode* head) {

    if (head == nullptr)
        return nullptr;

    ListNode* newHead = new ListNode(head->val);

    ListNode* currNew = newHead;
    ListNode* currOld = head->next;

    while (currOld != nullptr) {
        currNew->next = new ListNode(currOld->val);
        currNew = currNew->next;
        currOld = currOld->next;
    }

    return newHead;
}

int main() {

    ListNode* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);

    cout << "Linked List : ";
    printList(head);

    Solution obj;

    ListNode* head1 = copyList(head);

    cout << "Stack Method          : ";

    if (obj.isPalindromeStack(head1))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    ListNode* head2 = copyList(head);

    cout << "Optimal Method        : ";

    if (obj.isPalindrome(head2))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}