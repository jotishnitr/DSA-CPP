/*
------------------------------------------------------------
Problem: Reverse a Doubly Linked List
Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

Pattern Used:
Pointer Manipulation

Idea:
In a Doubly Linked List, every node has:

prev ← current → next

To reverse the list,

simply swap the prev and next pointers
of every node.

After processing all nodes,
the last processed node becomes the new head.

------------------------------------------------------------
Algorithm

Initialize:

current = head
last = NULL

While current is not NULL

1. Store current->prev

last = current->prev

2. Swap pointers

current->prev = current->next
current->next = last

3. Move to next node

Since pointers are swapped,

original next

=

current->prev

So,

current = current->prev

After traversal,

return

last->prev

which points to the new head.

------------------------------------------------------------
Dry Run

Original List

NULL <- 1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL

--------------------------------

Node = 1

Before

prev = NULL
next = 2

After Swap

prev = 2
next = NULL

Move

current = 2

--------------------------------

Node = 2

Before

prev = 1
next = 3

After Swap

prev = 3
next = 1

Move

current = 3

--------------------------------

Continue similarly

--------------------------------

Final List

NULL <- 5 <-> 4 <-> 3 <-> 2 <-> 1 -> NULL

------------------------------------------------------------
Why return last->prev ?

During the last iteration,

last stores the previous pointer
(before swapping) of the last processed node.

After swapping,

last->prev points to the new head.

Example

Original

1 <-> 2 <-> 3

After processing node 3

last = 2

After swapping,

2 <- 3

last->prev

↓

3

which is the new head.

------------------------------------------------------------
Key Observation

Unlike a Singly Linked List,

no separate reversal of links is required.

Simply swapping

prev

and

next

for every node automatically reverses
the entire list.

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(1)

------------------------------------------------------------
Similar Problems

1. Reverse Linked List
2. Reverse Linked List II
3. Reverse Nodes in k-Group
4. Reverse a Sublist of Linked List
5. Rotate Doubly Linked List
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
public:

    Node* reverse(Node* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* last = nullptr;
        Node* current = head;

        while (current != nullptr) {

            last = current->prev;

            current->prev = current->next;
            current->next = last;

            current = current->prev;
        }

        return last->prev;
    }
};

// Insert at end
Node* insertAtEnd(Node* head, int val) {

    Node* newNode = new Node(val);

    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Print Doubly Linked List
void printList(Node* head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    cout << "Original List : ";
    printList(head);

    Solution obj;

    head = obj.reverse(head);

    cout << "Reversed List : ";
    printList(head);

    return 0;
}