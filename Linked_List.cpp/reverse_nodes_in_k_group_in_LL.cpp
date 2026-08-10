/*
------------------------------------------------------------
Problem: Reverse Nodes in K-Group

LeetCode:
https://leetcode.com/problems/reverse-nodes-in-k-group/

Pattern Used:
Linked List + Group Reversal + Pointer Manipulation

============================================================

Problem Idea:

Given a linked list, reverse the nodes in groups
of size k.

Example:

Input:

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

k = 3

Output:

3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8

The last group is not reversed if it contains
fewer than k nodes.

------------------------------------------------------------

Approach:

The solution processes one group at a time.

For every group:

1. Find the kth node.
2. Check whether at least k nodes are available.
3. Disconnect the group from the remaining list.
4. Reverse the group.
5. Connect the reversed group to the previous group.
6. Move to the next group.

------------------------------------------------------------

Function 1: findKthNode()

Purpose:

Find the kth node starting from `temp`.

Initially:

k -= 1

because `temp` itself is considered
the first node.

Example:

1 -> 2 -> 3 -> 4

k = 3

Starting from 1:

1st node = 1
2nd node = 2
3rd node = 3

So the function returns node 3.

------------------------------------------------------------

Function 2: reverse()

Purpose:

Reverse the linked list segment passed to it.

It uses three pointers:

prevNode
temp
nextNode

At every step:

nextNode = temp->next

temp->next = prevNode

prevNode = temp

temp = nextNode

Since the group was disconnected before
calling this function, only that group is reversed.

------------------------------------------------------------

Function 3: reverseKGroup()

This is the main function.

Initialize:

temp = head
prevNode = nullptr

`temp` points to the beginning of the
current group.

`prevNode` points to the last node of the
previous reversed group.

------------------------------------------------------------

Step 1: Find kth Node

kthNode = findKthNode(temp, k)

If kthNode is NULL:

There are fewer than k nodes remaining.

Do not reverse them.

If a previous group exists:

prevNode->next = temp

Then stop.

------------------------------------------------------------

Step 2: Save the Next Group

Before disconnecting the current group:

nextNode = kthNode->next

This stores the beginning of the next group.

------------------------------------------------------------

Step 3: Disconnect the Group

Set:

kthNode->next = nullptr

Now the current group is separated.

Example:

1 -> 2 -> 3 -> 4 -> 5

For k = 3:

1 -> 2 -> 3 -> NULL

4 -> 5

------------------------------------------------------------

Step 4: Reverse the Group

Call:

reverse(temp)

Before:

1 -> 2 -> 3

After:

3 -> 2 -> 1

The variable `temp` still points to node 1.

Therefore, after reversal, `temp` becomes
the last node of the reversed group.

------------------------------------------------------------

Step 5: Connect the Reversed Group

For the first group:

if (temp == head)

update:

head = kthNode

Example:

Before:

1 -> 2 -> 3

After reversal:

3 -> 2 -> 1

So:

head = 3

------------------------------------------------------------

For subsequent groups:

prevNode->next = kthNode

This connects the previous reversed group
to the new reversed group.

------------------------------------------------------------

Step 6: Update prevNode

After reversing:

temp

is the last node of the current reversed group.

Therefore:

prevNode = temp

------------------------------------------------------------

Step 7: Move to Next Group

Use the previously saved pointer:

temp = nextNode

------------------------------------------------------------

Dry Run

Input:

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

k = 3

------------------------------------------------------------

Group 1:

1 -> 2 -> 3

kthNode = 3

Save:

nextNode = 4

Reverse:

3 -> 2 -> 1

Update head:

head = 3

prevNode = 1

Move:

temp = 4

Current list:

3 -> 2 -> 1

4 -> 5 -> 6 -> 7 -> 8

------------------------------------------------------------

Group 2:

4 -> 5 -> 6

kthNode = 6

Save:

nextNode = 7

Reverse:

6 -> 5 -> 4

Connect:

prevNode->next = kthNode

So:

3 -> 2 -> 1 -> 6 -> 5 -> 4

Update:

prevNode = 4

temp = 7

------------------------------------------------------------

Group 3:

7 -> 8

Only 2 nodes remain.

But:

k = 3

Therefore, fewer than k nodes remain.

Do NOT reverse them.

Connect:

prevNode->next = temp

So:

4 -> 7 -> 8

------------------------------------------------------------

Final Answer:

3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8

------------------------------------------------------------

Important Pointer Relationship

After reversing a group:

kthNode

becomes the first node of the reversed group.

`temp`

becomes the last node of the reversed group.

This is why:

prevNode = temp

is correct.

------------------------------------------------------------

Why Save nextNode Before Reversing?

This line is important:

ListNode* nextNode = kthNode->next;

The next group must be remembered before:

kthNode->next = nullptr;

and before reversing the current group.

Otherwise, the connection to the remaining
list would be lost.

------------------------------------------------------------

Why Are Fewer Than K Nodes Not Reversed?

The problem requires reversing complete
groups of k nodes.

For example:

1 -> 2 -> 3 -> 4 -> 5

k = 3

First group:

1 -> 2 -> 3

is reversed.

Remaining:

4 -> 5

contains only 2 nodes.

Therefore it remains unchanged.

Final:

3 -> 2 -> 1 -> 4 -> 5

------------------------------------------------------------

Time Complexity

Finding each kth node takes traversal.

Across all groups, the total traversal is:

O(n)

Reversing all groups also takes:

O(n)

Therefore:

Overall Time Complexity = O(n)

------------------------------------------------------------

Space Complexity

O(1)

Only a constant number of pointers are used.

The reversal is iterative, so there is no
recursive call stack.

------------------------------------------------------------

Key Observation

The main idea is not simply reversing a linked
list.

The important part is maintaining the connections
between three parts:

Previous reversed groups

Current group

Remaining groups

The important pointers are:

prevNode
temp
kthNode
nextNode

------------------------------------------------------------

Example

Input:

1 -> 2 -> 3 -> 4 -> 5 -> 6

k = 2

Output:

2 -> 1 -> 4 -> 3 -> 6 -> 5

------------------------------------------------------------

Similar Problems

1. Reverse Linked List
2. Reverse Linked List II
3. Rotate List
4. Swap Nodes in Pairs
5. Reverse Nodes in Even Length Groups
6. Reverse a Doubly Linked List
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

    // Find the kth node from temp
    ListNode* findKthNode(ListNode* temp, int k) {

        k -= 1;

        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    // Reverse the linked list
    void reverse(ListNode* temp) {

        ListNode* prevNode = nullptr;

        while (temp != nullptr) {

            ListNode* nextNode = temp->next;

            temp->next = prevNode;

            prevNode = temp;
            temp = nextNode;
        }
    }

    // Reverse nodes in groups of k
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp != nullptr) {

            ListNode* kthNode = findKthNode(temp, k);

            // Less than k nodes remain
            if (kthNode == nullptr) {

                if (prevNode != nullptr) {
                    prevNode->next = temp;
                }

                break;
            }

            ListNode* nextNode = kthNode->next;

            // Disconnect current group
            kthNode->next = nullptr;

            // Reverse current group
            reverse(temp);

            // First group
            if (temp == head) {
                head = kthNode;
            }
            else {
                prevNode->next = kthNode;
            }

            // temp is now the last node of the reversed group
            prevNode = temp;

            // Move to next group
            temp = nextNode;
        }

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

int main() {

    ListNode* head = nullptr;

    for (int i = 1; i <= 8; i++) {
        head = insertAtEnd(head, i);
    }

    int k = 3;

    cout << "Original List : ";
    printList(head);

    Solution obj;

    head = obj.reverseKGroup(head, k);

    cout << "After Reverse  : ";
    printList(head);

    return 0;
}