/*
------------------------------------------------------------
Problem: Remove Nth Node From End of List

LeetCode:
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/delete-nth-node-from-end-of-linked-list/1

Pattern Used:
1. Two Pass Traversal
2. Two Pointers (Fast & Slow)

============================================================

Approach 1: Brute Force (Count Length)

Idea:
First count the total number of nodes.

The node to delete from the beginning is at

Position = Length - N

Traverse to the previous node of that
position and remove the target node.

------------------------------------------------------------
Algorithm

1. Traverse the linked list and count the
   total number of nodes.

2. If

count == n

delete the head node.

3. Otherwise,

position = count - n

4. Traverse to the node just before the
   target node.

5. Change pointers

temp->next = temp->next->next

6. Delete the removed node.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 3 -> 4 -> 5

n = 2

Length = 5

Position from beginning

5 - 2 = 3

Previous node = 3

Delete

4

Result

1 -> 2 -> 3 -> 5

------------------------------------------------------------
Time Complexity

O(n) + O(n)

=

O(n)

------------------------------------------------------------
Space Complexity

O(1)

============================================================

Approach 2: Two Pointers (Optimal)

Idea:
Maintain a gap of n nodes between
the fast and slow pointers.

First move the fast pointer n steps ahead.

Then move both pointers together until
fast reaches the last node.

At that moment,

slow points to the node just before
the node that must be deleted.

------------------------------------------------------------
Algorithm

1. Initialize

fast = head

2. Move fast ahead by n nodes.

3. If fast becomes NULL,

delete the head node.

4. Otherwise,

initialize

slow = head

5. Move both pointers until

fast->next == NULL

6. Delete

slow->next

7. Return head.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 3 -> 4 -> 5

n = 2

-----------------------

Move fast two steps

Slow = 1

Fast = 3

-----------------------

Move together

Slow = 2

Fast = 4

-----------------------

Move together

Slow = 3

Fast = 5

Fast reaches the last node.

Delete

slow->next

Delete 4

Final List

1 -> 2 -> 3 -> 5

------------------------------------------------------------
Key Observation

Keeping a gap of n nodes between the
fast and slow pointers ensures that
when fast reaches the last node,

slow automatically reaches the node
just before the target node.

Thus, the linked list is traversed only
once after creating the initial gap.

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
2. Remove Linked List Elements
3. Delete Middle Node of a Linked List
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

    ListNode* removeNthFromEndBrute(ListNode* head, int n) {

        ListNode* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        if (count == n) {

            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int pos = count - n;

        temp = head;

        while (--pos) {
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;

        delete delNode;

        return head;
    }

    // ---------------- Optimal (Two Pointers) ----------------

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (fast == nullptr) {

            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* slow = head;

        while (fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next;
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

    for (int i = 1; i <= 5; i++)
        head = insertAtEnd(head, i);

    int n = 2;

    cout << "Original List : ";
    printList(head);

    Solution obj;

    ListNode* head1 = copyList(head);
    head1 = obj.removeNthFromEndBrute(head1, n);

    cout << "Brute Force   : ";
    printList(head1);

    ListNode* head2 = copyList(head);
    head2 = obj.removeNthFromEnd(head2, n);

    cout << "Optimal       : ";
    printList(head2);

    return 0;
}