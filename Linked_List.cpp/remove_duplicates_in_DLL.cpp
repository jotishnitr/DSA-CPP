/*
------------------------------------------------------------
Problem: Remove Duplicates from a Sorted Doubly Linked List

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

Pattern Used:
Doubly Linked List + Pointer Manipulation

============================================================

Important Note:

This solution assumes that the doubly linked list
is SORTED.

Example:

1 <-> 1 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4

Since duplicate values are adjacent, we can
remove them by traversing the list and
changing the next and prev pointers.

------------------------------------------------------------

Idea:

Use `temp` to represent the current unique node.

For every `temp`:

1. Start `nextNode` from `temp->next`.
2. While `nextNode` contains the same value
   as `temp`, delete that duplicate node.
3. Connect `temp` with the first different node.
4. Update the `prev` pointer of that node.
5. Move `temp` forward.

------------------------------------------------------------

Algorithm

Initialize:

temp = headRef

While:

temp != NULL

and

temp->next != NULL

1. Set:

nextNode = temp->next

2. While:

nextNode != NULL

and

nextNode->data == temp->data

Delete the duplicate node.

3. After removing all consecutive duplicates:

temp->next = nextNode

4. If nextNode exists:

nextNode->prev = temp

5. Move:

temp = temp->next

6. Return headRef.

------------------------------------------------------------

Dry Run

Original List:

1 <-> 1 <-> 2 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4

------------------------------------------------------------

Step 1

temp = 1

nextNode = 1

Values are equal.

Delete duplicate 1.

Now:

1 <-> 2 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4

Connect:

1 <-> 2

------------------------------------------------------------

Step 2

temp = 2

nextNode = 2

Values are equal.

Delete duplicate 2.

Again:

nextNode = 2

Values are equal.

Delete duplicate 2.

Now:

1 <-> 2 <-> 3 <-> 4 <-> 4

Connect:

2 <-> 3

------------------------------------------------------------

Step 3

temp = 3

nextNode = 4

Values are different.

Move:

temp = 4

------------------------------------------------------------

Step 4

temp = 4

nextNode = 4

Values are equal.

Delete duplicate 4.

Final List:

1 <-> 2 <-> 3 <-> 4

------------------------------------------------------------

Backward Traversal:

4 <-> 3 <-> 2 <-> 1

Output:

4 3 2 1

------------------------------------------------------------

Why Update Both Pointers?

Because this is a Doubly Linked List.

After deleting duplicate nodes, we need:

temp->next = nextNode

and

nextNode->prev = temp

The first statement fixes the forward
connection.

The second statement fixes the backward
connection.

Without updating `nextNode->prev`, the
backward traversal would still point to a
deleted node.

------------------------------------------------------------

Important Pointer Detail

Before deleting a duplicate:

ListNode* duplicate = nextNode;

nextNode = nextNode->next;

delete duplicate;

We first save the next node before deleting
the current node.

After deletion, `nextNode` safely points to
the next node that needs to be checked.

------------------------------------------------------------

Why No Special Head Case?

Unlike deletion of a specific value from a
doubly linked list, this algorithm always
keeps the first occurrence of every value.

Therefore, the head itself is never deleted.

For example:

1 <-> 1 <-> 2

The first `1` remains the head.

Only the duplicate `1` is deleted.

------------------------------------------------------------

Why Can We Stop at the First Different Node?

Because the list is sorted.

If:

temp->data != nextNode->data

then there cannot be another occurrence of
`temp->data` later in the list.

Therefore, we can safely move `temp` forward.

------------------------------------------------------------

Time Complexity

O(n)

Every node is processed at most once.

------------------------------------------------------------

Space Complexity

O(1)

Only temporary pointers are used.

------------------------------------------------------------

Key Observation

For a sorted doubly linked list:

Duplicates are always consecutive.

Therefore, we do not need a hash map.

We can remove duplicates directly by
reconnecting:

previous <-> next

while maintaining both:

next

and

prev

pointers.

------------------------------------------------------------

Example

Input:

1 <-> 1 <-> 2 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4

Output:

1 <-> 2 <-> 3 <-> 4

------------------------------------------------------------

Similar Problems

1. Remove Duplicates from Sorted List
2. Remove Duplicates from Sorted List II
3. Remove Duplicates from an Unsorted Linked List
4. Delete All Occurrences of a Given Value
5. Sort a Doubly Linked List
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
public:

    Node* removeDuplicates(Node* headRef) {

        Node* temp = headRef;

        while (temp != nullptr && temp->next != nullptr) {

            Node* nextNode = temp->next;

            while (nextNode != nullptr &&
                   nextNode->data == temp->data) {

                Node* duplicate = nextNode;

                nextNode = nextNode->next;

                delete duplicate;
            }

            temp->next = nextNode;

            if (nextNode != nullptr) {
                nextNode->prev = temp;
            }

            temp = temp->next;
        }

        return headRef;
    }
};

// Insert at End
Node* insertAtEnd(Node* head, int value) {

    Node* newNode = new Node(value);

    if (head == nullptr)
        return newNode;

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Print Forward
void printForward(Node* head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Print Backward
void printBackward(Node* head) {

    if (head == nullptr)
        return;

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

int main() {

    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 4);

    cout << "Original List : ";
    printForward(head);

    Solution obj;

    head = obj.removeDuplicates(head);

    cout << "After Removing Duplicates : ";
    printForward(head);

    cout << "Backward List : ";
    printBackward(head);

    return 0;
}