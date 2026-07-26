/*
------------------------------------------------------------
Problem: Reverse Linked List

LeetCode:
https://leetcode.com/problems/reverse-linked-list/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

Pattern Used:
1. Stack (Brute Force)
2. Pointer Manipulation (Iterative)
3. Recursion

============================================================

Approach 1: Stack (Brute Force)

Idea:
Store all node values in a stack.

Since a stack follows the LIFO principle,
the values come out in reverse order.

Traverse the linked list again and replace
each node's value with the stack's top.

Note:
Only the values are reversed.
The links between nodes remain unchanged.

------------------------------------------------------------
Algorithm

1. Traverse the linked list.
2. Push every node's value into the stack.
3. Traverse the list again.
4. Replace each node's value with the
   stack's top.
5. Pop the stack.
6. Return head.

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(n)

============================================================

Approach 2: Iterative (Optimal)

Idea:
Reverse the links one by one.

Maintain three pointers

prev
current
front

For every node,

store the next node,
reverse the current link,
move all pointers forward.

------------------------------------------------------------
Algorithm

Initialize

prev = NULL
current = head

While current != NULL

1. Store

front = current->next

2. Reverse the link

current->next = prev

3. Move pointers

prev = current

current = front

Return prev as the new head.

------------------------------------------------------------
Dry Run

Original List

1 -> 2 -> 3 -> 4 -> 5 -> NULL

-----------------------

Iteration 1

front = 2

1 -> NULL

prev = 1

current = 2

-----------------------

Iteration 2

front = 3

2 -> 1 -> NULL

prev = 2

current = 3

-----------------------

Iteration 3

3 -> 2 -> 1

-----------------------

Iteration 4

4 -> 3 -> 2 -> 1

-----------------------

Iteration 5

5 -> 4 -> 3 -> 2 -> 1

current = NULL

Return

5

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(1)

============================================================

Approach 3: Recursive

Idea:
Recursively reverse the remaining linked list.

After recursion returns,

attach the current node at the end of the
reversed list.

------------------------------------------------------------
Algorithm

Base Case

If

head == NULL

or

head->next == NULL

return head.

Recursively reverse

head->next

Store the returned head.

Reverse the link

head->next->next = head

Break the old connection

head->next = NULL

Return the new head.

------------------------------------------------------------
Dry Run

Original List

1 -> 2 -> 3

Recursive Calls

reverse(1)

↓

reverse(2)

↓

reverse(3)

↓

Return 3

-----------------------

Backtracking

3 -> 2

2 -> NULL

-----------------------

Backtracking

3 -> 2 -> 1

1 -> NULL

Return 3

------------------------------------------------------------
Key Observation

The iterative solution reverses links in a
single traversal using three pointers.

The recursive solution reaches the last node
first and reverses the links while returning
(backtracking).

The stack solution is simple but uses extra
memory and only reverses node values instead
of the actual node connections.

------------------------------------------------------------
Time Complexity

Stack

O(n)

Iterative

O(n)

Recursive

O(n)

------------------------------------------------------------
Space Complexity

Stack

O(n)

Iterative

O(1)

Recursive

O(n)

(Recursive call stack)

------------------------------------------------------------
Similar Problems

1. Reverse Linked List II
2. Reverse Nodes in k-Group
3. Reverse a Doubly Linked List
4. Palindrome Linked List
5. Reorder List
------------------------------------------------------------
*/

#include <iostream>
#include <stack>
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

    // ---------------- Brute Force (Using Stack) ----------------

    ListNode* reverseListStack(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        stack<int> st;

        ListNode* temp = head;

        // Store node values in stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        // Rewrite values in reverse order
        while (temp != nullptr) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }

    // ---------------- Optimal Iterative ----------------

    ListNode* reverseList(ListNode* head) {

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {

            ListNode* front = temp->next;

            temp->next = prev;

            prev = temp;
            temp = front;
        }

        return prev;
    }

    // ---------------- Optimal Recursive ----------------

    ListNode* reverseListRecursive(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverseListRecursive(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
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

// Create a copy of a linked list
ListNode* copyList(ListNode* head) {

    if (head == nullptr)
        return nullptr;

    ListNode* newHead = new ListNode(head->val);
    ListNode* currNew = newHead;
    ListNode* currOld = head->next;

    while (currOld != nullptr) {
        currNew->next = new ListNode(currOld->val);
        currNew = currNew->next;
        currOld = currOld->next;
    }

    return newHead;
}

int main() {

    ListNode* head = nullptr;

    for (int i = 1; i <= 5; i++)
        head = insertAtEnd(head, i);

    cout << "Original List          : ";
    printList(head);

    Solution obj;

    // Stack Method
    ListNode* head1 = copyList(head);
    head1 = obj.reverseListStack(head1);
    cout << "Stack Method           : ";
    printList(head1);

    // Iterative Method
    ListNode* head2 = copyList(head);
    head2 = obj.reverseList(head2);
    cout << "Iterative Method       : ";
    printList(head2);

    // Recursive Method
    ListNode* head3 = copyList(head);
    head3 = obj.reverseListRecursive(head3);
    cout << "Recursive Method       : ";
    printList(head3);

    return 0;
}