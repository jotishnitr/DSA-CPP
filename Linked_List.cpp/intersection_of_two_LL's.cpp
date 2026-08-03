/*
------------------------------------------------------------
Problem: Intersection of Two Linked Lists

LeetCode:
https://leetcode.com/problems/intersection-of-two-linked-lists/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

Pattern Used:
1. Hashing
2. Difference in Length
3. Two Pointer Switching

============================================================

Approach 1: Hash Map (Brute Force)

Idea:
Store the address of every node in the
first linked list.

Traverse the second linked list.

The first node whose address is already
present in the hash map is the
intersection node.

------------------------------------------------------------
Algorithm

1. Traverse List A.
2. Store every node address in a hash map.
3. Traverse List B.
4. If a node already exists in the hash map,
   return that node.
5. If traversal finishes,
   return NULL.

------------------------------------------------------------
Dry Run

List A

4 -> 1 -> 8 -> 4 -> 5

List B

5 -> 6 -> 1 -> 8 -> 4 -> 5

Store all nodes of List A.

Traverse List B

5

6

1

8

Node 8 already exists.

Return 8.

------------------------------------------------------------
Time Complexity

O(n + m)

------------------------------------------------------------
Space Complexity

O(n)

============================================================

Approach 2: Difference in Length (Better)

Idea:
If one linked list is longer than the other,

move its pointer ahead by the difference
in lengths.

Now both pointers have the same number
of nodes left to travel.

Move both pointers together until they
meet.

------------------------------------------------------------
Algorithm

1. Find lengths of both linked lists.

2. Compute

difference = |lengthA - lengthB|

3. Move the pointer of the longer list
   ahead by difference nodes.

4. Move both pointers together.

5. The first common node is the
   intersection node.

6. If both reach NULL,
   there is no intersection.

------------------------------------------------------------
Dry Run

List A

4 -> 1 -> 8 -> 4 -> 5

Length = 5

List B

5 -> 6 -> 1 -> 8 -> 4 -> 5

Length = 6

Difference = 1

Move List B one step ahead

6 -> 1 -> 8 -> 4 -> 5

Now move together

4 , 6

1 , 1

8 , 8

Pointers meet.

Return 8.

------------------------------------------------------------
Time Complexity

O(n + m)

------------------------------------------------------------
Space Complexity

O(1)

============================================================

Approach 3: Two Pointer Switching (Optimal)

Idea:
Traverse both linked lists simultaneously.

When a pointer reaches the end of its list,

redirect it to the head of the other list.

Eventually,

both pointers travel exactly

LengthA + LengthB

nodes.

If an intersection exists,

they meet there.

Otherwise,

both become NULL simultaneously.

------------------------------------------------------------
Algorithm

Initialize

t1 = headA

t2 = headB

While

t1 != t2

If

t1 == NULL

move it to headB

Else

t1 = t1->next

Similarly,

If

t2 == NULL

move it to headA

Else

t2 = t2->next

Return

t1

(It is either the intersection node
or NULL.)

------------------------------------------------------------
Dry Run

List A

4 -> 1 -> 8 -> 4 -> 5

List B

5 -> 6 -> 1 -> 8 -> 4 -> 5

Pass 1

t1 traverses

A

t2 traverses

B

Neither meets.

After reaching the end,

t1 starts from List B.

t2 starts from List A.

Pass 2

Now both have travelled the same total
distance.

They meet at

8

Return 8.

------------------------------------------------------------
Key Observation

Switching the pointers removes the need
to calculate the lengths.

Both pointers traverse exactly

LengthA + LengthB

nodes.

Therefore,

if an intersection exists,

they are guaranteed to meet there.

Otherwise,

both pointers reach NULL together.

------------------------------------------------------------
Time Complexity

Hash Map

O(n + m)

Difference in Length

O(n + m)

Two Pointer Switching

O(n + m)

------------------------------------------------------------
Space Complexity

Hash Map

O(n)

Difference in Length

O(1)

Two Pointer Switching

O(1)

------------------------------------------------------------
Similar Problems

1. Linked List Cycle
2. Linked List Cycle II
3. Merge Two Sorted Lists
4. Remove Nth Node From End
5. Copy List with Random Pointer
------------------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
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

    // ---------------- Brute Force (Hash Map) ----------------

    ListNode* getIntersectionNodeHash(ListNode* headA, ListNode* headB) {

        unordered_map<ListNode*, int> mpp;

        ListNode* temp = headA;

        while (temp != nullptr) {
            mpp[temp] = 1;
            temp = temp->next;
        }

        temp = headB;

        while (temp != nullptr) {

            if (mpp.find(temp) != mpp.end())
                return temp;

            temp = temp->next;
        }

        return nullptr;
    }

    // ---------------- Better (Difference in Length) ----------------

    ListNode* collisionFound(ListNode* h1, ListNode* h2, int diff) {

        ListNode* t1 = h1;

        while (diff--) {
            t1 = t1->next;
        }

        ListNode* t2 = h2;

        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }

        return t1;
    }

    ListNode* getIntersectionNodeBetter(ListNode* headA, ListNode* headB) {

        int n1 = 0, n2 = 0;

        ListNode* temp = headA;

        while (temp != nullptr) {
            n1++;
            temp = temp->next;
        }

        temp = headB;

        while (temp != nullptr) {
            n2++;
            temp = temp->next;
        }

        if (n1 >= n2)
            return collisionFound(headA, headB, n1 - n2);

        return collisionFound(headB, headA, n2 - n1);
    }

    // ---------------- Optimal (Two Pointer Switching) ----------------

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {

            t1 = (t1 == nullptr) ? headB : t1->next;
            t2 = (t2 == nullptr) ? headA : t2->next;
        }

        return t1;
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

    // Common Part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A : 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B : 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "List A : ";
    printList(headA);

    cout << "List B : ";
    printList(headB);

    Solution obj;

    ListNode* ans1 = obj.getIntersectionNodeHash(headA, headB);
    cout << "\nHash Map       : ";
    if (ans1)
        cout << ans1->val << endl;
    else
        cout << "No Intersection\n";

    ListNode* ans2 = obj.getIntersectionNodeBetter(headA, headB);
    cout << "Length Method  : ";
    if (ans2)
        cout << ans2->val << endl;
    else
        cout << "No Intersection\n";

    ListNode* ans3 = obj.getIntersectionNode(headA, headB);
    cout << "Optimal        : ";
    if (ans3)
        cout << ans3->val << endl;
    else
        cout << "No Intersection\n";

    return 0;
}