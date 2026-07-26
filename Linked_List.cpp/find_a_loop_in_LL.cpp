/*
------------------------------------------------------------
Problem: Linked List Cycle

LeetCode:
https://leetcode.com/problems/linked-list-cycle/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

Pattern Used:
1. Hashing
2. Slow & Fast Pointer (Floyd's Cycle Detection)

============================================================

Approach 1: Hash Map (Brute Force)

Idea:
Traverse the linked list while storing the
address of every visited node in a hash map.

If a node is encountered again, it means
the node has already been visited and a
cycle exists.

------------------------------------------------------------
Algorithm

1. Create an empty hash map.
2. Traverse the linked list.
3. If the current node already exists in
   the hash map, return true.
4. Otherwise, store the current node.
5. Move to the next node.
6. If traversal reaches NULL,
   return false.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

Visit

1

Store

Visit

2

Store

Visit

3

Store

Visit

4

Store

Visit

5

Store

Next = 3

3 already exists in map

Return true

------------------------------------------------------------
Time Complexity

O(n)

------------------------------------------------------------
Space Complexity

O(n)

============================================================

Approach 2: Floyd's Cycle Detection (Optimal)

Idea:
Use two pointers.

Slow moves one step at a time.

Fast moves two steps at a time.

If a cycle exists,

the fast pointer will eventually catch
the slow pointer inside the loop.

If there is no cycle,

fast reaches NULL.

------------------------------------------------------------
Algorithm

Initialize

slow = head
fast = head

While

fast != NULL

and

fast->next != NULL

Move

slow = slow->next

fast = fast->next->next

If

slow == fast

Return true.

If loop finishes,

Return false.

------------------------------------------------------------
Dry Run

Linked List

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

Initially

Slow = 1

Fast = 1

-----------------------

Iteration 1

Slow = 2

Fast = 3

-----------------------

Iteration 2

Slow = 3

Fast = 5

-----------------------

Iteration 3

Slow = 4

Fast = 4

Slow == Fast

Return true

------------------------------------------------------------
Key Observation

If no cycle exists,

the fast pointer reaches NULL because it
moves twice as fast.

If a cycle exists,

the distance between slow and fast keeps
decreasing inside the loop, so they must
eventually meet.

This makes Floyd's Algorithm the most
efficient solution with constant space.

------------------------------------------------------------
Time Complexity

Hash Map

O(n)

Floyd's Algorithm

O(n)

------------------------------------------------------------
Space Complexity

Hash Map

O(n)

Floyd's Algorithm

O(1)

------------------------------------------------------------
Similar Problems

1. Linked List Cycle II
2. Find the Duplicate Number
3. Happy Number
4. Middle of the Linked List
5. Remove Loop in Linked List
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

    bool hasCycleHash(ListNode* head) {

        unordered_map<ListNode*, int> mpp;

        ListNode* temp = head;

        while (temp != nullptr) {

            if (mpp.find(temp) != mpp.end()) {
                return true;
            }

            mpp[temp] = 1;
            temp = temp->next;
        }

        return false;
    }

    // ---------------- Optimal (Floyd's Cycle Detection) ----------------

    bool hasCycle(ListNode* head) {

        if (head == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
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

int main() {

    ListNode* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Create a cycle:
    // 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution obj;

    cout << "Hash Map Approach : ";

    if (obj.hasCycleHash(head))
        cout << "Cycle Found\n";
    else
        cout << "No Cycle\n";

    cout << "Floyd's Algorithm : ";

    if (obj.hasCycle(head))
        cout << "Cycle Found\n";
    else
        cout << "No Cycle\n";

    return 0;
}