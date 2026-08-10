/*
------------------------------------------------------------
Problem: Rotate List

LeetCode:
https://leetcode.com/problems/rotate-list/

Pattern Used:
Linked List + Circular Linked List + Pointer Manipulation

============================================================

Problem Idea:

Rotate the linked list to the right by k places.

Example:

Input:

1 -> 2 -> 3 -> 4 -> 5

k = 2

Output:

4 -> 5 -> 1 -> 2 -> 3

------------------------------------------------------------

Key Observation:

Rotating right by k positions means moving the
last k nodes to the front.

For:

1 -> 2 -> 3 -> 4 -> 5

k = 2

Last 2 nodes:

4 -> 5

Move them to the front:

4 -> 5 -> 1 -> 2 -> 3

------------------------------------------------------------

Approach:

1. Find the length of the linked list.
2. Find the tail.
3. Reduce k using:

   k = k % length

4. If k is 0, no rotation is required.
5. Connect the tail to the head to make the
   linked list circular.
6. Find the new tail at position:

   length - k

7. The node after the new tail becomes the
   new head.
8. Break the circular connection.

------------------------------------------------------------

Step 1: Find Length and Tail

For:

1 -> 2 -> 3 -> 4 -> 5

We get:

length = 5

tail = 5

------------------------------------------------------------

Step 2: Reduce k

If:

k = 7

and:

length = 5

then:

k % length

= 7 % 5

= 2

Therefore, rotating 7 positions is equivalent
to rotating 2 positions.

This also handles cases where k is larger
than the list length.

------------------------------------------------------------

Step 3: Handle No Rotation

If:

k % length == 0

return head.

Example:

length = 5
k = 10

10 % 5 = 0

The list remains unchanged.

------------------------------------------------------------

Step 4: Make the List Circular

Initially:

1 -> 2 -> 3 -> 4 -> 5 -> NULL

Connect:

tail->next = head

Now:

1 -> 2 -> 3 -> 4 -> 5
     ^                   |
     |___________________|

The list is circular.

------------------------------------------------------------

Step 5: Find the New Tail

The new tail is at position:

length - k

For:

length = 5
k = 2

new tail position:

5 - 2 = 3

So:

new tail = 3

The list becomes conceptually:

1 -> 2 -> 3 -> 4 -> 5 -> 1 -> ...

------------------------------------------------------------

Step 6: Find New Head

The node after the new tail is the new head.

new tail:

3

Therefore:

new head:

4

So:

4 -> 5 -> 1 -> 2 -> 3 -> ...

------------------------------------------------------------

Step 7: Break the Circular Link

Set:

kthNode->next = nullptr

where:

kthNode = 3

Final:

4 -> 5 -> 1 -> 2 -> 3 -> NULL

------------------------------------------------------------

Dry Run

Input:

1 -> 2 -> 3 -> 4 -> 5

k = 2

------------------------------------------------------------

Length:

5

Tail:

5

------------------------------------------------------------

k:

2 % 5 = 2

------------------------------------------------------------

Make circular:

1 -> 2 -> 3 -> 4 -> 5
^                   |
|___________________|

------------------------------------------------------------

Find new tail:

length - k

= 5 - 2

= 3

New tail:

3

------------------------------------------------------------

New head:

3->next

= 4

------------------------------------------------------------

Break:

3->next = nullptr

------------------------------------------------------------

Final:

4 -> 5 -> 1 -> 2 -> 3

------------------------------------------------------------

Why Use a Circular List?

Without making the list circular, we would
have to manually reconnect the last k nodes.

By doing:

tail->next = head

the list becomes circular.

Then we only need to find the correct
breaking point.

This makes the rotation simple and efficient.

------------------------------------------------------------

Role of findKthNode()

The function:

findKthNode(head, length - k)

finds the node that will become the
new tail.

For:

1 -> 2 -> 3 -> 4 -> 5

and:

length - k = 3

it returns:

3

Then:

head = kthNode->next

gives:

4

------------------------------------------------------------

Important Edge Cases

1. Empty List

head == nullptr

Return head.

------------------------------------------------------------

2. One Node

1

Rotating it produces the same list.

------------------------------------------------------------

3. k = 0

No rotation is needed.

------------------------------------------------------------

4. k > length

Use:

k = k % length

Example:

k = 12
length = 5

12 % 5 = 2

So rotate by 2.

------------------------------------------------------------

5. k is a Multiple of Length

Example:

length = 5
k = 10

10 % 5 = 0

Return the original head.

------------------------------------------------------------

Time Complexity

Finding the length and tail:

O(n)

Finding the new tail:

O(n)

Overall:

O(n)

------------------------------------------------------------

Space Complexity

O(1)

Only a constant number of pointers are used.

------------------------------------------------------------

Key Observation

For a list of length n,

rotating right by k positions is equivalent to
rotating by:

k % n

The new tail is at:

n - k

and the node immediately after it becomes
the new head.

------------------------------------------------------------

Example

Input:

1 -> 2 -> 3 -> 4 -> 5

k = 2

Output:

4 -> 5 -> 1 -> 2 -> 3

------------------------------------------------------------

Similar Problems

1. Rotate List
2. Reverse Linked List
3. Reverse Nodes in K-Group
4. Rotate Array
5. Swap Nodes in Pairs
6. Reverse Linked List II
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

    // Find the kth node
    ListNode* findKthNode(ListNode* temp, int count) {

        while (temp != nullptr && count > 1) {
            temp = temp->next;
            count--;
        }

        return temp;
    }

    // Rotate List to the Right
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* tail = head;
        int length = 1;

        // Find length and tail
        while (tail->next != nullptr) {
            length++;
            tail = tail->next;
        }

        // No rotation needed
        if (k % length == 0) {
            return head;
        }

        k = k % length;

        // Make the list circular
        tail->next = head;

        // Find the new tail
        ListNode* kthNode = findKthNode(head, length - k);

        // New head is after new tail
        head = kthNode->next;

        // Break the circular link
        kthNode->next = nullptr;

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
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    int k = 2;

    cout << "Original List : ";
    printList(head);

    Solution obj;

    head = obj.rotateRight(head, k);

    cout << "Rotated List  : ";
    printList(head);

    return 0;
}