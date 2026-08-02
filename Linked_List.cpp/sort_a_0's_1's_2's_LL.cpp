/*
------------------------------------------------------------
Problem: Sort a Linked List of 0s, 1s and 2s

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Pattern Used:
1. Counting
2. Three Separate Linked Lists

============================================================

Approach 1: Brute Force (Counting)

Idea:
Since the linked list contains only
0, 1 and 2,

count the frequency of each value.

Traverse the linked list again and
overwrite the node values in sorted order.

The node connections remain unchanged.

------------------------------------------------------------
Algorithm

1. Traverse the linked list.
2. Count the number of

0s
1s
2s

3. Traverse the list again.
4. Fill

0s first

then

1s

then

2s

5. Return head.

------------------------------------------------------------
Dry Run

Original List

1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1

Count

0 = 2

1 = 3

2 = 2

Rewrite

0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(1)

============================================================

Approach 2: Three Separate Lists (Optimal)

Idea:
Instead of changing node values,

create three separate linked lists

One for

0s

One for

1s

One for

2s

Finally connect the three lists together.

This preserves the original nodes and only
changes the links.

------------------------------------------------------------
Algorithm

1. Create three dummy nodes

zeroHead

oneHead

twoHead

2. Traverse the original list.

If value is

0

attach to zero list.

If value is

1

attach to one list.

Otherwise

attach to two list.

3. Connect

Zero List

↓

One List (if present)

↓

Two List

4. Set

two->next = NULL

5. Return

zeroHead->next

------------------------------------------------------------
Dry Run

Original List

1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1

----------------------------

Zero List

0 -> 0

----------------------------

One List

1 -> 1 -> 1

----------------------------

Two List

2 -> 2

----------------------------

Connect

0 -> 0

↓

1 -> 1 -> 1

↓

2 -> 2

Final List

0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

------------------------------------------------------------
Key Observation

The counting approach modifies only the
values stored in the nodes.

The optimal approach does not modify any
node values.

Instead, it rearranges the existing nodes
by changing their next pointers, making it
a true linked list solution.

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

(Only three dummy nodes are created.)

------------------------------------------------------------
Similar Problems

1. Sort Colors
2. Partition List
3. Merge Two Sorted Lists
4. Odd Even Linked List
5. Rearrange Linked List
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:

    // ---------------- Brute Force (Count 0s, 1s and 2s) ----------------

    Node* segregateBrute(Node* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->data == 0)
                count0++;
            else if (temp->data == 1)
                count1++;
            else
                count2++;

            temp = temp->next;
        }

        temp = head;

        while (count0--) {
            temp->data = 0;
            temp = temp->next;
        }

        while (count1--) {
            temp->data = 1;
            temp = temp->next;
        }

        while (count2--) {
            temp->data = 2;
            temp = temp->next;
        }

        return head;
    }

    // ---------------- Optimal (Three Separate Lists) ----------------

    Node* segregate(Node* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->data == 0) {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = temp;
            }
            else {
                two->next = temp;
                two = temp;
            }

            temp = temp->next;
        }

        zero->next = (oneHead->next != nullptr) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;

        Node* newHead = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
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

// Print List
void printList(Node* head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Copy List
Node* copyList(Node* head) {

    if (head == nullptr)
        return nullptr;

    Node* newHead = new Node(head->data);
    Node* currNew = newHead;
    Node* currOld = head->next;

    while (currOld != nullptr) {
        currNew->next = new Node(currOld->data);
        currNew = currNew->next;
        currOld = currOld->next;
    }

    return newHead;
}

int main() {

    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 0);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 0);
    head = insertAtEnd(head, 1);

    cout << "Original List : ";
    printList(head);

    Solution obj;

    Node* head1 = copyList(head);
    head1 = obj.segregateBrute(head1);

    cout << "Brute Force   : ";
    printList(head1);

    Node* head2 = copyList(head);
    head2 = obj.segregate(head2);

    cout << "Optimal       : ";
    printList(head2);

    return 0;
}