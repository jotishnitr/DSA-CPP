/*
------------------------------------------------------------
Problem: Delete Head, Tail and Given Element in a Singly Linked List

Practice Link (GeeksforGeeks):
https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

Pattern Used:
Linked List Traversal + Pointer Manipulation

Idea:
Deletion in a Singly Linked List depends on
which node is being removed.

1. Delete Head
   Move the head to the next node and
   delete the old head.

2. Delete Tail
   Traverse to the second last node,
   delete the last node and set its
   next pointer to NULL.

3. Delete Given Element
   Traverse until the previous node of
   the target is found.
   Change its next pointer to skip the
   target node and delete it.

------------------------------------------------------------
Algorithm

Delete Head

1. If list is empty, return NULL.
2. Store head in a temporary pointer.
3. Move head to head->next.
4. Delete the old head.
5. Return new head.

----------------------------

Delete Tail

1. If list is empty, return NULL.
2. If only one node exists,
   delete it and return NULL.
3. Traverse to the second last node.
4. Delete the last node.
5. Set second last node's next to NULL.

----------------------------

Delete Given Element

1. If list is empty, return NULL.
2. If key is present at head,
   delete the head.
3. Traverse until previous node of
   the key is found.
4. Skip the target node.
5. Delete the target node.
6. Return head.

------------------------------------------------------------
Dry Run

Original List

1 -> 2 -> 3 -> 4 -> 5

----------------------------

Delete Head

Delete 1

2 -> 3 -> 4 -> 5

----------------------------

Delete Tail

Delete 5

2 -> 3 -> 4

----------------------------

Delete Element (3)

Previous node = 2

2 -> 4

------------------------------------------------------------
Key Observation

Deletion in a Singly Linked List requires
access to the previous node because links
can only be updated in the forward direction.

Deleting the head is the only case where
the previous node is not required.

------------------------------------------------------------
Time Complexity

Delete Head

O(1)

Delete Tail

O(n)

Delete Element

O(n)

------------------------------------------------------------
Space Complexity

O(1)

------------------------------------------------------------
Similar Problems

1. Delete Node in a Linked List
2. Remove Linked List Elements
3. Delete without Head Pointer
4. Remove Nth Node From End of List
5. Delete Middle Node of Linked List
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert at End
Node* insertAtEnd(Node* head, int val) {

    Node* newNode = new Node(val);

    if (head == nullptr)
        return newNode;

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Delete Head
Node* deleteHead(Node* head) {

    if (head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;

    delete temp;

    return head;
}

// Delete Tail
Node* deleteTail(Node* head) {

    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;

    return head;
}

// Delete Element
Node* deleteElement(Node* head, int key) {

    if (head == nullptr)
        return nullptr;

    if (head->data == key)
        return deleteHead(head);

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != key)
        temp = temp->next;

    if (temp->next != nullptr) {

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    return head;
}

// Print
void print(Node* head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    Node* head = nullptr;

    for (int i = 1; i <= 5; i++)
        head = insertAtEnd(head, i);

    cout << "Original : ";
    print(head);

    head = deleteHead(head);
    cout << "After Delete Head : ";
    print(head);

    head = deleteTail(head);
    cout << "After Delete Tail : ";
    print(head);

    head = deleteElement(head, 3);
    cout << "After Delete 3 : ";
    print(head);
}
