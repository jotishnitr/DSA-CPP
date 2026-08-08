/*
------------------------------------------------------------
Problem: Add Two Numbers

LeetCode:
https://leetcode.com/problems/add-two-numbers/

Pattern Used:
Simulation + Carry Handling + Dummy Node

============================================================

Idea:
The linked lists store digits in reverse order.

Example

342

is stored as

2 -> 4 -> 3

Since the least significant digit comes first,
we can simply traverse both linked lists
simultaneously while maintaining a carry.

Whenever the sum becomes greater than or
equal to 10,

store

sum % 10

and carry

sum / 10

Continue until

both linked lists are exhausted
and no carry remains.

------------------------------------------------------------
Algorithm

1. Create a dummy node.

2. Keep a pointer

current

pointing to the dummy node.

3. Initialize

carry = 0

4. While

l1 != NULL

or

l2 != NULL

or

carry != 0

a) sum = carry

b) If l1 exists

add l1->val

move l1

c) If l2 exists

add l2->val

move l2

d) Create a new node containing

sum % 10

e) Update

carry = sum / 10

f) Move current forward.

5. Return

dummy->next

------------------------------------------------------------
Dry Run

l1

2 -> 4 -> 3

(Number = 342)

l2

5 -> 6 -> 4

(Number = 465)

----------------------------

Iteration 1

sum = 2 + 5 + 0

= 7

Digit = 7

Carry = 0

Answer

7

----------------------------

Iteration 2

sum = 4 + 6 + 0

= 10

Digit = 0

Carry = 1

Answer

7 -> 0

----------------------------

Iteration 3

sum = 3 + 4 + 1

= 8

Digit = 8

Carry = 0

Answer

7 -> 0 -> 8

Represents

807

which is

342 + 465

------------------------------------------------------------
Example 2

l1

9 -> 9 -> 9

l2

1

----------------------------

Iteration 1

9 + 1 = 10

Digit = 0

Carry = 1

----------------------------

Iteration 2

9 + Carry

= 10

Digit = 0

Carry = 1

----------------------------

Iteration 3

9 + Carry

= 10

Digit = 0

Carry = 1

----------------------------

Iteration 4

Carry = 1

Digit = 1

Carry = 0

Final Answer

0 -> 0 -> 0 -> 1

Represents

1000

------------------------------------------------------------
Why Dummy Node?

Without a dummy node,

the first node has to be handled separately.

Using a dummy node,

every newly created node is attached in
exactly the same way.

Finally,

return

dummy->next

which points to the actual answer.

------------------------------------------------------------
Key Observation

The linked lists already store digits from
least significant to most significant.

Therefore,

no reversing is required.

Simply simulate elementary school addition
while maintaining the carry.

------------------------------------------------------------
Time Complexity

O(max(n, m))

where

n = length of l1

m = length of l2

------------------------------------------------------------
Space Complexity

O(max(n, m))

(New linked list created for the answer.)

------------------------------------------------------------
Similar Problems

1. Add Two Numbers II
2. Add 1 to a Number Represented as Linked List
3. Reverse Linked List
4. Multiply Two Numbers Represented as Linked List
5. Sum of Two Integers
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

    // ---------------- Optimal ----------------

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {

            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
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

    // Number 342 -> 2 -> 4 -> 3
    ListNode* l1 = nullptr;
    l1 = insertAtEnd(l1, 2);
    l1 = insertAtEnd(l1, 4);
    l1 = insertAtEnd(l1, 3);

    // Number 465 -> 5 -> 6 -> 4
    ListNode* l2 = nullptr;
    l2 = insertAtEnd(l2, 5);
    l2 = insertAtEnd(l2, 6);
    l2 = insertAtEnd(l2, 4);

    cout << "List 1 : ";
    printList(l1);

    cout << "List 2 : ";
    printList(l2);

    Solution obj;

    ListNode* ans = obj.addTwoNumbers(l1, l2);

    cout << "Sum    : ";
    printList(ans);

    return 0;
}