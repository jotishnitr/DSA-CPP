/*
------------------------------------------------------------
Problem: Add 1 to a Number Represented as Linked List

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

Pattern Used:
1. Reverse Linked List
2. Recursion (Backtracking)

============================================================

Approach 1: Brute Force (Reverse → Add → Reverse)

Idea:
Addition starts from the least significant
digit, but a linked list stores the most
significant digit first.

So,

1. Reverse the linked list.
2. Add 1 starting from the first node.
3. Propagate carry if needed.
4. Reverse the list back.
5. If carry still remains,
   insert a new node at the front.

------------------------------------------------------------
Algorithm

1. Reverse the linked list.

2. Initialize

carry = 1

3. Traverse the reversed list.

Add carry to current node.

If value < 10

carry becomes 0.

Stop.

Otherwise,

store 0

carry = 1

Continue.

4. Reverse the linked list again.

5. If carry remains,

insert a new node containing 1
at the front.

------------------------------------------------------------
Dry Run

Original Number

9 -> 9 -> 9

Reverse

9 -> 9 -> 9

(Addition starts here)

-----------------------

Node 1

9 + 1 = 10

Store 0

Carry = 1

-----------------------

Node 2

9 + 1 = 10

Store 0

Carry = 1

-----------------------

Node 3

9 + 1 = 10

Store 0

Carry = 1

-----------------------

Reverse Again

0 -> 0 -> 0

Carry still exists

Insert

1

Final Answer

1 -> 0 -> 0 -> 0

------------------------------------------------------------
Time Complexity

Reverse

O(n)

Addition

O(n)

Reverse

O(n)

Overall

O(n)

------------------------------------------------------------
Space Complexity

O(1)

============================================================

Approach 2: Recursion (Optimal)

Idea:
Recursion naturally reaches the last node.

The last node represents the least
significant digit.

During backtracking,

carry is propagated towards the head,
exactly like manual addition.

------------------------------------------------------------
Algorithm

Base Case

If

node == NULL

Return carry = 1

(This represents adding one.)

----------------------------

Backtracking

Receive carry from the next node.

Add carry to current node.

If value < 10

Return carry = 0

Otherwise

Store 0

Return carry = 1

----------------------------

After recursion finishes,

If carry still exists,

insert a new node containing 1
at the beginning.

------------------------------------------------------------
Dry Run

Original Number

9 -> 9 -> 9

Recursive Calls

helper(9)

↓

helper(9)

↓

helper(9)

↓

helper(NULL)

Returns

1

-----------------------

Backtracking

Last Node

9 + 1 = 10

Store 0

Carry = 1

-----------------------

Second Node

9 + 1 = 10

Store 0

Carry = 1

-----------------------

First Node

9 + 1 = 10

Store 0

Carry = 1

-----------------------

Carry still exists

Insert

1

Final Answer

1 -> 0 -> 0 -> 0

------------------------------------------------------------
Key Observation

The recursive approach avoids reversing
the linked list.

Backtracking naturally processes nodes
from right to left, making it ideal for
carry propagation.

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

O(n)

(Recursive call stack)

------------------------------------------------------------
Similar Problems

1. Add Two Numbers
2. Add Two Numbers II
3. Reverse Linked List
4. Plus One
5. Multiply Two Linked Lists
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

    // ---------------- Reverse Linked List ----------------

    Node* reverse(Node* head) {

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {

            Node* front = curr->next;

            curr->next = prev;
            prev = curr;

            curr = front;
        }

        return prev;
    }

    // ---------------- Brute Force (Reverse -> Add -> Reverse) ----------------

    Node* addOneBrute(Node* head) {

        head = reverse(head);

        Node* temp = head;
        int carry = 1;

        while (temp != nullptr) {

            temp->data += carry;

            if (temp->data < 10) {
                carry = 0;
                break;
            }

            temp->data = 0;
            carry = 1;

            if (temp->next == nullptr)
                break;

            temp = temp->next;
        }

        head = reverse(head);

        // If carry is still left, add a new node at the front
        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }

    // ---------------- Recursive Helper ----------------

    int helper(Node* temp) {

        if (temp == nullptr)
            return 1;

        int carry = helper(temp->next);

        temp->data += carry;

        if (temp->data < 10)
            return 0;

        temp->data = 0;

        return 1;
    }

    // ---------------- Optimal (Recursion) ----------------

    Node* addOne(Node* head) {

        int carry = helper(head);

        if (carry == 1) {

            Node* newNode = new Node(1);
            newNode->next = head;

            return newNode;
        }

        return head;
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
        cout << head->data;
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

    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 9);

    cout << "Original Number : ";
    printList(head);

    Solution obj;

    Node* head1 = copyList(head);
    head1 = obj.addOneBrute(head1);

    cout << "Brute Force     : ";
    printList(head1);

    Node* head2 = copyList(head);
    head2 = obj.addOne(head2);

    cout << "Optimal         : ";
    printList(head2);

    return 0;
}