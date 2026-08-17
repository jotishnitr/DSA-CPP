/*
====================================================
Flattening a Linked List
====================================================

Practile Link : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/0?utm_source=chatgpt.com

Problem Statement
-----------------
Given a linked list where each node has two pointers:

1. next   -> Points to the next linked list.
2. bottom -> Points to another sorted linked list.

Each bottom list is already sorted.

Flatten the entire structure into a single sorted linked list
using only the bottom pointer.

Example

5 -> 10 -> 19 -> 28
|     |      |      |
7     20     22     35
|            |      |
8            50     40
|                   |
30                  45

Output

5
|
7
|
8
|
10
|
19
|
20
|
22
|
28
|
30
|
35
|
40
|
45
|
50


====================================================
Brute Force Approach (Store + Sort)
====================================================

Idea
----
1. Traverse every node using both next and bottom pointers.
2. Store every value inside a vector.
3. Sort the vector.
4. Create a new bottom linked list using the sorted values.

Algorithm
---------
1. Traverse each vertical list.
2. Store all node values in an array.
3. Sort the array.
4. Create a new bottom linked list.
5. Return the new head.

Time Complexity
---------------
Traversal : O(N*M)
Sorting   : O((N*M) log(N*M))

Overall   : O((N*M) log(N*M))

Space Complexity
----------------
O(N*M)


====================================================
Optimal Approach (Recursive Merge)
====================================================

Observation
-----------
Each bottom list is already sorted.

Instead of sorting everything again,
we recursively flatten the remaining lists
and merge two sorted lists at a time.

This is similar to Merge K Sorted Lists.


Recursive Idea
--------------

flatten(5)

↓

flatten(10)

↓

flatten(19)

↓

flatten(28)

Now merge while recursion returns.

merge(19,28)

↓

merge(10, merged)

↓

merge(5, merged)

Final answer is a single sorted bottom list.


====================================================
Merge Function
====================================================

Node* merge(Node* a, Node* b)

Base Cases

if(a == NULL) return b;

if(b == NULL) return a;

Compare both current nodes.

If

a->data < b->data

choose a

Else

choose b

Recursively merge the remaining nodes.

Important

result->next = NULL;

Reason:
After flattening we only use bottom pointers.
The next pointers are removed.


====================================================
Flatten Function
====================================================

Base Case

if(root == NULL || root->next == NULL)
    return root;

Recursive Step

1. Flatten the remaining lists.

root->next = flatten(root->next);

2. Merge current list with the flattened list.

return merge(root, root->next);


====================================================
Dry Run
====================================================

Input

5 -> 10 -> 19

Step 1

Flatten(19)

returns

19

↓

Merge

10-list

with

19-list

↓

10
|
19
|
20
|
22
|
50

↓

Merge

5-list

with merged list

↓

5
|
7
|
8
|
10
|
19
|
20
|
22
|
30
|
50


====================================================
Why It Works
====================================================

Every recursive call completely flattens
all the lists to the right.

Now only two sorted lists remain:

1. Current list
2. Already flattened list

Merging two sorted linked lists is straightforward.

Repeating this recursively eventually produces
one fully flattened sorted linked list.


====================================================
Complexity
====================================================

Brute Force

Time  : O((N*M) log(N*M))
Space : O(N*M)

Optimal

Time  : O(N*M)
Space : O(N)   // Recursion stack


====================================================
Interview Points
====================================================

1. Every bottom list is already sorted.
2. The problem is an application of Merge K Sorted Lists.
3. Flatten recursively from right to left.
4. Merge two sorted bottom lists at every step.
5. Set result->next = NULL because the final list should use
   only bottom pointers.
6. Brute force uses extra space and sorting.
7. Optimal solution performs in-place merging without extra arrays.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution {
public:

    //====================================================
    // Brute Force Approach (Array + Sort)
    // Time: O(NM log(NM))
    // Space: O(NM)
    //====================================================

    Node* flattenBrute(Node* head) {

        vector<int> arr;

        Node* temp = head;

        while (temp != nullptr) {

            Node* t2 = temp;

            while (t2 != nullptr) {
                arr.push_back(t2->data);
                t2 = t2->bottom;
            }

            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        if (arr.empty())
            return nullptr;

        Node* newHead = new Node(arr[0]);
        temp = newHead;

        for (int i = 1; i < arr.size(); i++) {
            temp->bottom = new Node(arr[i]);
            temp = temp->bottom;
        }

        return newHead;
    }

    //====================================================
    // Optimal Approach (Recursive Merge)
    // Time: O(NM)
    // Space: O(N) (Recursion Stack)
    //====================================================

    Node* merge(Node* a, Node* b) {

        if (a == nullptr) return b;
        if (b == nullptr) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        }
        else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = nullptr;

        return result;
    }

    Node* flatten(Node* root) {

        if (root == nullptr || root->next == nullptr)
            return root;

        root->next = flatten(root->next);

        return merge(root, root->next);
    }
};

// Insert a bottom node
void insertBottom(Node* head, int data) {

    while (head->bottom != nullptr)
        head = head->bottom;

    head->bottom = new Node(data);
}

// Print bottom list
void printBottom(Node* head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->bottom;
    }

    cout << endl;
}

int main() {

    /*
        5 -> 10 -> 19 -> 28
        |     |      |      |
        7     20     22     35
        |            |      |
        8            50     40
        |                   |
        30                  45
    */

    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    insertBottom(head, 7);
    insertBottom(head, 8);
    insertBottom(head, 30);

    insertBottom(head->next, 20);

    insertBottom(head->next->next, 22);
    insertBottom(head->next->next, 50);

    insertBottom(head->next->next->next, 35);
    insertBottom(head->next->next->next, 40);
    insertBottom(head->next->next->next, 45);

    Solution obj;

    cout << "Brute Force Flatten:\n";
    Node* brute = obj.flattenBrute(head);
    printBottom(brute);

    // Rebuild the original list for the optimal approach
    head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    insertBottom(head, 7);
    insertBottom(head, 8);
    insertBottom(head, 30);

    insertBottom(head->next, 20);

    insertBottom(head->next->next, 22);
    insertBottom(head->next->next, 50);

    insertBottom(head->next->next->next, 35);
    insertBottom(head->next->next->next, 40);
    insertBottom(head->next->next->next, 45);

    cout << "Optimal Flatten:\n";
    Node* optimal = obj.flatten(head);
    printBottom(optimal);

    return 0;
}