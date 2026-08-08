/*
------------------------------------------------------------
Problem: Delete All Occurrences of a Given Value in a
         Doubly Linked List

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-key-in-doubly-linked-list/1

Pattern Used:
Doubly Linked List + Pointer Manipulation

============================================================

Idea:

Traverse the entire doubly linked list.

Whenever a node contains the value x:

1. Store its previous node.
2. Store its next node.
3. If the node is the head, update head.
4. Connect the previous node to the next node.
5. Connect the next node back to the previous node.
6. Delete the current node.
7. Continue from the next node.

The important point is that after deleting
the current node, we must move to

nextNode

because the current node no longer exists.

============================================================

Algorithm

Initialize

temp = head

While temp != NULL:

If

temp->data == x

Store:

prevNode = temp->prev
nextNode = temp->next

------------------------------------------------------------

Case 1: Current node is Head

If

temp == head

update

head = nextNode

If the new head exists:

head->prev = NULL

------------------------------------------------------------

Case 2: Previous node exists

Connect

prevNode->next = nextNode

------------------------------------------------------------

Case 3: Next node exists

Connect

nextNode->prev = prevNode

------------------------------------------------------------

Delete current node

delete temp

Move to

temp = nextNode

------------------------------------------------------------

Otherwise

temp = temp->next

Finally return head.

============================================================

Dry Run

Original List

1 <-> 2 <-> 3 <-> 2 <-> 4 <-> 2 <-> 5

x = 2

------------------------------------------------------------

First 2

Delete

1 <-> 2 <-> 3

After reconnection:

1 <-> 3

List becomes

1 <-> 3 <-> 2 <-> 4 <-> 2 <-> 5

------------------------------------------------------------

Second 2

Delete

3 <-> 2 <-> 4

Reconnect:

3 <-> 4

List becomes

1 <-> 3 <-> 4 <-> 2 <-> 5

------------------------------------------------------------

Third 2

Delete

4 <-> 2 <-> 5

Reconnect:

4 <-> 5

Final List

1 <-> 3 <-> 4 <-> 5

------------------------------------------------------------

Backward Traversal

5 <-> 4 <-> 3 <-> 1

Output:

5 4 3 1

============================================================

Important Edge Cases

1. Empty List

head = NULL

Return NULL.

------------------------------------------------------------

2. Only One Node

x matches the node.

Delete it and return NULL.

------------------------------------------------------------

3. Head Contains x

Update head and set

head->prev = NULL

------------------------------------------------------------

4. Multiple Consecutive Occurrences

Example:

1 <-> 2 <-> 2 <-> 2 <-> 3

Each occurrence is deleted one by one.

------------------------------------------------------------

5. All Nodes Contain x

Example:

2 <-> 2 <-> 2

After deletion:

NULL

------------------------------------------------------------

6. x Does Not Exist

The list remains unchanged.

============================================================

Key Observation

Because this is a Doubly Linked List,

we already have access to both:

temp->prev

and

temp->next

Therefore, after finding the node to delete,
we can directly reconnect both neighboring
nodes.

The main pointer update is:

prevNode->next = nextNode

nextNode->prev = prevNode

This removes the current node from both
directions.

============================================================

Why Move to nextNode After Deletion?

After

delete temp

the pointer temp points to deleted memory
and must not be used again.

Therefore, store:

nextNode = temp->next

before deleting temp.

Then:

delete temp;

temp = nextNode;

This safely continues the traversal.

============================================================

Time Complexity

O(n)

Every node is visited at most once.

------------------------------------------------------------

Space Complexity

O(1)

Only a few temporary pointers are used.

============================================================

Similar Problems

1. Delete a Node in a Doubly Linked List
2. Delete Head of a Doubly Linked List
3. Delete Tail of a Doubly Linked List
4. Reverse a Doubly Linked List
5. Remove Duplicates from a Doubly Linked List
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
public:

    // Delete all occurrences of x
    Node* deleteAllOccurOfX(Node* head, int x) {

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->data == x) {

                Node* prevNode = temp->prev;
                Node* nextNode = temp->next;

                // If deleting head
                if (temp == head) {
                    head = nextNode;

                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                }

                // Connect previous node
                if (prevNode != nullptr) {
                    prevNode->next = nextNode;
                }

                // Connect next node
                if (nextNode != nullptr) {
                    nextNode->prev = prevNode;
                }

                delete temp;

                temp = nextNode;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};

// Insert at End
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

    if (head == nullptr) {
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

int main() {

    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 5);

    cout << "Original List : ";
    printForward(head);

    Solution obj;

    int x = 2;

    head = obj.deleteAllOccurOfX(head, x);

    cout << "After deleting " << x << " : ";
    printForward(head);

    cout << "Backward       : ";
    printBackward(head);

    return 0;
}