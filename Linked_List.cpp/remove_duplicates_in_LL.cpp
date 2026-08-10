/*
------------------------------------------------------------
Problem: Remove Duplicates from a Sorted Linked List

LeetCode:
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-linked-list/1

Pattern Used:
Linked List Traversal + Pointer Manipulation

============================================================

Important Note:

This solution assumes that the linked list is SORTED.

Example:

1 -> 1 -> 2 -> 3 -> 3

Because duplicate values are adjacent, we only need
to compare the current node with the following nodes.

------------------------------------------------------------

Idea:

Use a pointer `temp` to represent the current
unique value.

For every `temp`:

1. Start `nextNode` from `temp->next`.
2. While `nextNode` has the same value as `temp`,
   delete the duplicate node.
3. Connect `temp->next` to the first different node.
4. Move `temp` forward.

------------------------------------------------------------

Algorithm

Initialize:

temp = head

While:

temp != NULL

and

temp->next != NULL

1. Store:

nextNode = temp->next

2. While:

nextNode != NULL

and

nextNode->val == temp->val

delete the duplicate node.

3. After all duplicates are removed:

temp->next = nextNode

4. Move:

temp = temp->next

5. Return head.

------------------------------------------------------------

Dry Run

Original List:

1 -> 1 -> 2 -> 3 -> 3

------------------------------------------------------------

temp = 1

nextNode = 1

Values are equal.

Delete duplicate 1.

List:

1 -> 2 -> 3 -> 3

Now:

temp->next = 2

Move:

temp = 2

------------------------------------------------------------

temp = 2

nextNode = 3

2 != 3

No deletion.

Move:

temp = 3

------------------------------------------------------------

temp = 3

nextNode = 3

Values are equal.

Delete duplicate 3.

List:

1 -> 2 -> 3

No more duplicate.

------------------------------------------------------------

Final List:

1 -> 2 -> 3

------------------------------------------------------------

Why Can We Stop at the First Different Node?

Because the list is sorted.

If:

temp->val != nextNode->val

then all later nodes will also have values
greater than or equal to the current value.

Therefore, there cannot be another duplicate
of `temp->val` later in the list.

------------------------------------------------------------

Important Pointer Detail

Before deleting a node:

nextNode = nextNode->next;

must be saved first.

Then:

delete duplicate;

Otherwise, after deleting the node, accessing
its `next` pointer would be invalid.

The code correctly does:

ListNode* duplicate = nextNode;

nextNode = nextNode->next;

delete duplicate;

------------------------------------------------------------

Time Complexity

O(n)

Each node is visited and processed at most once.

------------------------------------------------------------

Space Complexity

O(1)

Only a few pointers are used.

------------------------------------------------------------

Key Observation

Because the linked list is sorted,

duplicates are always adjacent.

Therefore, instead of using a hash map,
we can remove duplicates directly by
changing the `next` pointers.

------------------------------------------------------------

Example

Input:

1 -> 1 -> 2 -> 3 -> 3

Output:

1 -> 2 -> 3

------------------------------------------------------------

Similar Problems

1. Remove Duplicates from Sorted List II
2. Remove Duplicates from an Unsorted Linked List
3. Merge Two Sorted Lists
4. Sort List
5. Delete All Occurrences of a Given Value
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

    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {

            ListNode* nextNode = temp->next;

            while (nextNode != nullptr) {

                if (nextNode->val == temp->val) {

                    ListNode* duplicate = nextNode;

                    nextNode = nextNode->next;

                    delete duplicate;
                }
                else {
                    break;
                }
            }

            temp->next = nextNode;
            temp = temp->next;
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

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 3);

    cout << "Original List : ";
    printList(head);

    Solution obj;

    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates : ";
    printList(head);

    return 0;
}