/*
====================================================
Copy List with Random Pointer
====================================================

Problem Statement
-----------------
Given a linked list where every node has:

1. next   -> Points to the next node.
2. random -> Points to any node in the list (or NULL).

Create a deep copy of the entire linked list.

A deep copy means:
- Every node in the new list is newly created.
- next pointers are preserved.
- random pointers point to the corresponding copied nodes.
- No node from the original list is reused.


Example

Original List

7 ------> 13 ------> 11 ------> 10 ------> 1
|          |           |           |         |
NULL       7           1           11        7

↓

Copied List

7 ------> 13 ------> 11 ------> 10 ------> 1
|          |           |           |         |
NULL       7           1           11        7


====================================================
Brute Force Approach (HashMap)
====================================================

Idea
----
Create a copy of every node and store the mapping

Original Node  ->  Copied Node

using a hash map.

Then use this mapping to correctly assign
both next and random pointers.

Algorithm
---------
1. Traverse the original list.
2. Create a copy of every node.
3. Store

   original node -> copied node

   inside a hash map.

4. Traverse again.
5. Assign

   copy->next = map[original->next]

   copy->random = map[original->random]

6. Return the copied head.

Time Complexity
---------------
O(n)

Space Complexity
----------------
O(n)


====================================================
Optimal Approach (Interweaving Nodes)
====================================================

Observation
-----------
Instead of using extra memory,
insert every copied node immediately after
its original node.

Original

A -> B -> C

↓

A -> A' -> B -> B' -> C -> C'

Now every copied node is adjacent to
its original node.

This allows us to assign random pointers
without using a hash map.


====================================================
Step 1 : Insert Copied Nodes
====================================================

Original

A -> B -> C

↓

A -> A' -> B -> B' -> C -> C'

Each copied node is inserted
right after its original node.


====================================================
Step 2 : Assign Random Pointers
====================================================

Suppose

A.random = C

Since

A'

comes immediately after

A

and

C'

comes immediately after

C

we can write

A'->random = A->random->next

because

A->random

is C

and

C->next

is C'.

Code

copyNode->random = temp->random->next;


====================================================
Step 3 : Separate Both Lists
====================================================

Current Structure

A -> A' -> B -> B' -> C -> C'

Restore Original List

A -> B -> C

and simultaneously build

A' -> B' -> C'

Finally return the copied head.


====================================================
Dry Run
====================================================

Original

1 ----> 2 ----> 3

Random

1 -> 3

2 -> 1

3 -> 2


After Step 1

1 -> 1' -> 2 -> 2' -> 3 -> 3'


After Step 2

1'.random = 3'

2'.random = 1'

3'.random = 2'


After Step 3

Original

1 -> 2 -> 3

Copied

1' -> 2' -> 3'


====================================================
Why Does It Work?
====================================================

Every copied node is placed immediately after
its original node.

Therefore,

Original Random

temp->random

automatically gives access to

Copied Random

temp->random->next

without needing any extra storage.

Finally, separating alternating nodes restores
the original list and extracts the copied list.


====================================================
Complexity
====================================================

Brute Force

Time  : O(n)

Space : O(n)

(Hash map stores every node.)

Optimal

Time  : O(n)

Space : O(1)

(No extra data structures are used.
Only the copied nodes themselves are created.)


====================================================
Interview Points
====================================================

1. Brute force uses a hash map to map original nodes to copied nodes.
2. Optimal solution avoids extra memory by interweaving copied nodes.
3. Random pointers are assigned using

   original->random->next

   because the copied node is always placed immediately after
   the original node.

4. Finally, separate the interwoven list into:
   - Original list
   - Deep copied list

5. The original list remains unchanged after separation.

*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    // Brute Force: O(n) time, O(n) extra space
    Node* copyRandomListBrute(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mpp;

        Node* temp = head;

        // Create all copied nodes.
        while (temp != nullptr) {
            mpp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Link next and random pointers.
        temp = head;
        while (temp != nullptr) {
            Node* copyNode = mpp[temp];

            copyNode->next = (temp->next != nullptr) ? mpp[temp->next] : nullptr;
            copyNode->random =
                (temp->random != nullptr) ? mpp[temp->random] : nullptr;

            temp = temp->next;
        }

        return mpp[head];
    }

    // Optimal: O(n) time, O(1) auxiliary space
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Insert a copied node after every original node.
        Node* temp = head;

        while (temp != nullptr) {
            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;
        }

        // Step 2: Connect random pointers in copied nodes.
        temp = head;

        while (temp != nullptr) {
            Node* copyNode = temp->next;

            if (temp->random != nullptr) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }

            temp = copyNode->next;
        }

        // Step 3: Restore original list and extract copied list.
        Node* copyHead = head->next;
        temp = head;

        while (temp != nullptr) {
            Node* copyNode = temp->next;

            temp->next = copyNode->next;

            if (copyNode->next != nullptr) {
                copyNode->next = copyNode->next->next;
            }

            temp = temp->next;
        }

        return copyHead;
    }
};

// Builds a list from values and random indices.
// Use -1 for a null random pointer.
Node* buildList(const vector<int>& values, const vector<int>& randomIndex) {
    if (values.empty()) return nullptr;

    vector<Node*> nodes;

    for (int value : values) {
        nodes.push_back(new Node(value));
    }

    for (int i = 0; i < static_cast<int>(nodes.size()) - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    for (int i = 0; i < static_cast<int>(nodes.size()); i++) {
        if (randomIndex[i] != -1) {
            nodes[i]->random = nodes[randomIndex[i]];
        }
    }

    return nodes[0];
}

// Prints list in LeetCode-style form: [[value, randomIndex], ...]
void printList(Node* head) {
    unordered_map<Node*, int> index;
    Node* temp = head;
    int i = 0;

    while (temp != nullptr) {
        index[temp] = i++;
        temp = temp->next;
    }

    cout << "[";

    temp = head;
    while (temp != nullptr) {
        cout << "[" << temp->val << ",";

        if (temp->random == nullptr) {
            cout << "null";
        } else {
            cout << index[temp->random];
        }

        cout << "]";

        if (temp->next != nullptr) {
            cout << ",";
        }

        temp = temp->next;
    }

    cout << "]\n";
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int main() {
    // LeetCode example:
    // [[7,null], [13,0], [11,4], [10,2], [1,0]]
    vector<int> values = {7, 13, 11, 10, 1};
    vector<int> randomIndex = {-1, 0, 4, 2, 0};

    Node* originalHead = buildList(values, randomIndex);

    Solution solution;
    Node* copiedHead = solution.copyRandomList(originalHead);

    cout << "Original list: ";
    printList(originalHead);

    cout << "Copied list:   ";
    printList(copiedHead);

    deleteList(originalHead);
    deleteList(copiedHead);

    return 0;
}