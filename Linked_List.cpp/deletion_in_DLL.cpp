/*
------------------------------------------------------------
Problem: Delete Head, Tail and Given Element in a Doubly Linked List

Practice Link (GeeksforGeeks):
https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

Pattern Used:
Doubly Linked List + Pointer Manipulation

Idea:
In a Doubly Linked List, every node has both
previous and next pointers.

Deletion becomes easier because the previous
node is directly accessible.

Cases:

1. Delete Head
   Move head to the next node, update
   its prev pointer to NULL, and delete
   the old head.

2. Delete Tail
   Traverse to the last node, update the
   previous node's next pointer to NULL,
   and delete the last node.

3. Delete Given Element
   Find the target node, connect its
   previous and next nodes together,
   then delete the target node.

------------------------------------------------------------
Algorithm

Delete Head

1. If list is empty, return NULL.
2. If only one node exists,
   delete it and return NULL.
3. Move head to head->next.
4. Set head->prev = NULL.
5. Delete the old head.
6. Return new head.

----------------------------

Delete Tail

1. If list is empty, return NULL.
2. If only one node exists,
   delete it and return NULL.
3. Traverse to the last node.
4. Set last->prev->next = NULL.
5. Delete the last node.
6. Return head.

----------------------------

Delete Given Element

1. If list is empty, return NULL.
2. If key is at head,
   delete the head.
3. Traverse to the target node.
4. If target is not found,
   return head.
5. If target is the last node,
   delete the tail.
6. Connect

prev->next = next

next->prev = prev

7. Delete the target node.
8. Return head.

------------------------------------------------------------
Dry Run

Original List

NULL <- 1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL

----------------------------

Delete Head

Delete 1

NULL <- 2 <-> 3 <-> 4 <-> 5 -> NULL

----------------------------

Delete Tail

Delete 5

NULL <- 2 <-> 3 <-> 4 -> NULL

----------------------------

Delete Element (3)

Previous = 2
Next = 4

Connect

2 <-> 4

Final List

NULL <- 2 <-> 4 -> NULL

------------------------------------------------------------
Key Observation

Unlike a Singly Linked List, a Doubly Linked
List provides direct access to both previous
and next nodes.

This allows deletion of a node without first
finding its previous node separately.

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

1. Delete Node in a Doubly Linked List
2. Reverse a Doubly Linked List
3. Insert in a Doubly Linked List
4. Remove Duplicates from Sorted Doubly Linked List
5. LRU Cache (Uses Doubly Linked List)
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

// Insert at End
Node* insertAtEnd(Node* head, int val) {

    Node* newNode = new Node(val);

    if (head == nullptr)
        return newNode;

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Delete Head
Node* deleteHead(Node* head) {

    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    head = head->next;
    head->prev = nullptr;

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

    while (temp->next != nullptr)
        temp = temp->next;

    temp->prev->next = nullptr;

    delete temp;

    return head;
}

// Delete Element
Node* deleteElement(Node* head, int key) {

    if (head == nullptr)
        return nullptr;

    if (head->data == key)
        return deleteHead(head);

    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr)
        return head;

    if (temp->next == nullptr)
        return deleteTail(head);

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

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