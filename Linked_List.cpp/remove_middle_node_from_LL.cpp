/*
------------------------------------------------------------
Problem: Delete the Middle Node of a Linked List

LeetCode:
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

Pattern Used:
1. Two Pass Traversal
2. Slow & Fast Pointer

============================================================

Approach 1: Brute Force (Count Length)

Idea:
First count the total number of nodes.

The middle node is at index

Length / 2

Traverse to the node just before the
middle node and remove it.

------------------------------------------------------------
Algorithm

1. If the list has zero or one node,
   delete it and return NULL.

2. Traverse the linked list and count
   the total number of nodes.

3. Compute

middle = count / 2

4. Traverse to the node just before
   the middle node.

5. Change pointers

temp->next = temp->next->next

6. Delete the middle node.

7. Return head.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

Length = 7

Middle Index

7 / 2 = 3

Middle Node = 4

Delete 4

Result

1 -> 2 -> 3 -> 5 -> 6 -> 7

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
Use Slow and Fast pointers.

Fast moves two nodes at a time.

Slow moves one node at a time.

Start

fast = head->next->next

so that when fast reaches the end,

slow stops at the node just before the
middle node.

Delete

slow->next

------------------------------------------------------------
Algorithm

1. If the list has zero or one node,
   delete it and return NULL.

2. Initialize

slow = head

fast = head->next->next

3. While

fast != NULL

and

fast->next != NULL

Move

slow = slow->next

fast = fast->next->next

4. Delete

slow->next

5. Return head.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

Initially

Slow = 1

Fast = 3

-----------------------

Iteration 1

Slow = 2

Fast = 5

-----------------------

Iteration 2

Slow = 3

Fast = 7

-----------------------

Next Move

Fast reaches NULL

Slow stops at 3

Delete

slow->next = 4

Final List

1 -> 2 -> 3 -> 5 -> 6 -> 7

------------------------------------------------------------
Key Observation

By starting the fast pointer two nodes
ahead,

the slow pointer stops exactly one node
before the middle node.

This allows deleting the middle node
without needing a second traversal.

------------------------------------------------------------
Time Complexity

Brute Force

O(n)

Optimal

O(n)

------------------------------------------------------------
Space Complexity

Brute Force

O(1)

Optimal

O(1)

------------------------------------------------------------
Similar Problems

1. Middle of the Linked List
2. Remove Nth Node From End of List
3. Delete Node in a Linked List
4. Reverse Linked List
5. Linked List Cycle
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

    // ---------------- Brute Force (Count Length) ----------------

    ListNode* deleteMiddleBrute(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        int count = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int middle = count / 2;

        temp = head;

        for (int i = 1; i < middle; i++) {
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;

        delete delNode;

        return head;
    }

    // ---------------- Optimal (Slow & Fast Pointer) ----------------

    ListNode* deleteMiddle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;

        delete delNode;

        return head;
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

// Copy List
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

    for (int i = 1; i <= 7; i++) {
        head = insertAtEnd(head, i);
    }

    cout << "Original List : ";
    printList(head);

    Solution obj;

    ListNode* head1 = copyList(head);
    head1 = obj.deleteMiddleBrute(head1);

    cout << "Brute Force   : ";
    printList(head1);

    ListNode* head2 = copyList(head);
    head2 = obj.deleteMiddle(head2);

    cout << "Optimal       : ";
    printList(head2);

    return 0;
}