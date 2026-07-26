/*
------------------------------------------------------------
Problem: Middle of the Linked List

LeetCode:
https://leetcode.com/problems/middle-of-the-linked-list/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

Pattern Used:
1. Two Pass Traversal (Brute Force)
2. Slow and Fast Pointer (Tortoise and Hare)

------------------------------------------------------------
Approach 1: Brute Force (Two Passes)

Idea:
First count the total number of nodes.

The middle node is present at index

count / 2

Traverse again until this index and
return that node.

------------------------------------------------------------
Algorithm

First Pass

1. Traverse the entire list.
2. Count the total number of nodes.

Second Pass

1. Compute

middle = count / 2

2. Start from head.
3. Move middle steps.
4. Return the current node.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 3 -> 4 -> 5 -> 6

Count = 6

Middle Index

6 / 2 = 3

Move 3 steps

1 -> 2 -> 3 -> 4

Answer = 4

------------------------------------------------------------
Time Complexity

O(n) + O(n)

=

O(n)

------------------------------------------------------------
Space Complexity

O(1)

============================================================

Approach 2: Slow & Fast Pointer (Optimal)

Idea:
Use two pointers.

Slow moves one node at a time.

Fast moves two nodes at a time.

When fast reaches the end,

slow automatically reaches the middle.

------------------------------------------------------------
Algorithm

Initialize

slow = head
fast = head

While

fast != NULL

and

fast->next != NULL

Move

slow = slow->next

fast = fast->next->next

Return slow.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 3 -> 4 -> 5 -> 6

Initially

Slow = 1
Fast = 1

-----------------------

Iteration 1

Slow = 2

Fast = 3

-----------------------

Iteration 2

Slow = 3

Fast = 5

-----------------------

Iteration 3

Slow = 4

Fast = NULL

Loop stops.

Answer = 4

------------------------------------------------------------
Key Observation

Fast moves twice as quickly as slow.

By the time fast reaches the end of the
list,

slow has covered exactly half the distance,
placing it at the middle node.

For an even number of nodes,

the second middle node is returned,
which matches the problem requirement.

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(1)

------------------------------------------------------------
Similar Problems

1. Linked List Cycle
2. Linked List Cycle II
3. Happy Number
4. Find the Duplicate Number
5. Palindrome Linked List
------------------------------------------------------------
*/

#include <iostream>
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

    // ---------------- Brute Force (Two Passes) ----------------

    ListNode* middleNodeBrute(ListNode* head) {

        int count = 0;
        ListNode* temp = head;

        // Count the number of nodes
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int middle = count / 2;

        temp = head;

        // Move to the middle node
        while (middle--) {
            temp = temp->next;
        }

        return temp;
    }

    // ---------------- Optimal (Slow & Fast Pointer) ----------------

    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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

int main() {

    ListNode* head = nullptr;

    for (int i = 1; i <= 6; i++) {
        head = insertAtEnd(head, i);
    }

    cout << "Linked List : ";
    printList(head);

    Solution obj;

    ListNode* middle1 = obj.middleNodeBrute(head);
    cout << "Brute Force Middle : " << middle1->val << endl;

    ListNode* middle2 = obj.middleNode(head);
    cout << "Optimal Middle     : " << middle2->val << endl;

    return 0;
}