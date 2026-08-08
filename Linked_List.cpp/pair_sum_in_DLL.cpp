/*
------------------------------------------------------------
Problem: Find Pairs with Given Sum in a Doubly Linked List

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

Pattern Used:
1. Brute Force - Nested Traversal
2. Two Pointer - Left and Right Pointers

============================================================

Idea:

The doubly linked list is sorted.

To find all pairs whose sum is equal to
the target, use two pointers:

left  -> starts at the head
right -> starts at the tail

Because a Doubly Linked List has both
next and prev pointers, both pointers can
move toward each other efficiently.

------------------------------------------------------------

Approach 1: Brute Force

Check every possible pair of nodes.

For every node temp1,

start temp2 from temp1->next and check
all nodes after temp1.

If

temp1->data + temp2->data == target

store the pair.

------------------------------------------------------------

Algorithm

1. Set

temp1 = head

2. For every temp1,

set

temp2 = temp1->next

3. Traverse temp2 until NULL.

4. If

temp1->data + temp2->data == target

store the pair.

5. Move temp1 forward.

------------------------------------------------------------

Dry Run

List:

1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6

Target = 7

Check pairs:

1 + 2 = 3
1 + 3 = 4
1 + 4 = 5
1 + 5 = 6
1 + 6 = 7  ✓

2 + 3 = 5
2 + 4 = 6
2 + 5 = 7  ✓

3 + 4 = 7  ✓

4 + 5 = 9
...

Pairs:

(1, 6)
(2, 5)
(3, 4)

------------------------------------------------------------

Time Complexity

O(n²)

------------------------------------------------------------

Space Complexity

O(1)

excluding the result vector.

============================================================

Approach 2: Two Pointer (Optimal)

Idea:

Use two pointers.

left starts at the head.

right starts at the tail.

Since the list is sorted:

If

left->data + right->data < target

we need a larger sum.

Move left forward:

left = left->next

If

left->data + right->data > target

we need a smaller sum.

Move right backward:

right = right->prev

If the sum equals target,

store the pair and move both pointers.

------------------------------------------------------------

Algorithm

1. Initialize

left = head

2. Move right to the last node.

3. Continue while the two pointers
   have not crossed.

4. Calculate

sum = left->data + right->data

5. If

sum == target

store the pair.

Move:

left = left->next
right = right->prev

6. If

sum < target

move:

left = left->next

7. If

sum > target

move:

right = right->prev

8. Return the result.

------------------------------------------------------------

Dry Run

List:

1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6

Target = 7

Initially:

left = 1
right = 6

----------------------------

1 + 6 = 7

Pair found:

(1, 6)

Move both:

left = 2
right = 5

----------------------------

2 + 5 = 7

Pair found:

(2, 5)

Move both:

left = 3
right = 4

----------------------------

3 + 4 = 7

Pair found:

(3, 4)

Move both.

Pointers have crossed.

Stop.

Final Result:

(1, 6)
(2, 5)
(3, 4)

------------------------------------------------------------

Why Does Moving the Pointers Work?

The list is sorted.

Suppose:

left + right < target

Since right is already the largest
available value, keeping left fixed
cannot produce the required larger sum
by moving right backward.

Therefore, move left forward to increase
the sum.

Similarly,

if

left + right > target

move right backward to decrease the sum.

------------------------------------------------------------

Why Use a Doubly Linked List?

In a Singly Linked List, moving backward
from the tail is not directly possible.

In a Doubly Linked List,

right->prev

allows the right pointer to move backward
in O(1).

This makes the two-pointer approach
possible without extra data structures.

------------------------------------------------------------

Pointer Crossing Condition

The loop uses:

left != right

and

left->prev != right

The second condition handles the case where
the two pointers have crossed each other.

Example:

1 <-> 2 <-> 3 <-> 4

If:

left = 3
right = 2

then

left->prev == right

so the pointers have crossed and the
search must stop.

------------------------------------------------------------

Time Complexity

Finding the tail:

O(n)

Two Pointer Traversal:

O(n)

Overall:

O(n)

------------------------------------------------------------

Space Complexity

O(1)

excluding the result vector.

------------------------------------------------------------

Comparison

Brute Force:

Time  = O(n²)
Space = O(1)

Two Pointer:

Time  = O(n)
Space = O(1)

The two-pointer approach is therefore
the optimal solution.

------------------------------------------------------------

Similar Problems

1. Two Sum
2. Two Sum II - Input Array Is Sorted
3. 3Sum
4. Pair Sum in a Sorted Linked List
5. Find Pairs with Given Difference
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
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

class Solution {
public:

    // ---------------- Brute Force ----------------
    // Check every possible pair

    vector<vector<int>> givenSumPairsBrute(Node* head, int target) {

        vector<vector<int>> result;

        Node* temp1 = head;

        while (temp1 != nullptr) {

            Node* temp2 = temp1->next;

            while (temp2 != nullptr) {

                if (temp1->data + temp2->data == target) {
                    result.push_back({
                        temp1->data,
                        temp2->data
                    });
                }

                temp2 = temp2->next;
            }

            temp1 = temp1->next;
        }

        return result;
    }

    // ---------------- Optimal ----------------
    // Two Pointer Approach

    vector<vector<int>> givenSumPairs(Node* head, int target) {

        vector<vector<int>> result;

        if (head == nullptr)
            return result;

        Node* left = head;
        Node* right = head;

        // Move right to the tail
        while (right->next != nullptr) {
            right = right->next;
        }

        while (left != nullptr &&
               right != nullptr &&
               left != right &&
               left->prev != right) {

            int sum = left->data + right->data;

            if (sum == target) {

                result.push_back({
                    left->data,
                    right->data
                });

                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return result;
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

// Print pairs
void printPairs(vector<vector<int>> result) {

    for (auto pair : result) {
        cout << "(" << pair[0] << ", " << pair[1] << ") ";
    }

    cout << endl;
}

int main() {

    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 6);

    int target = 7;

    Solution obj;

    vector<vector<int>> brute =
        obj.givenSumPairsBrute(head, target);

    vector<vector<int>> optimal =
        obj.givenSumPairs(head, target);

    cout << "Brute Force : ";
    printPairs(brute);

    cout << "Optimal      : ";
    printPairs(optimal);

    return 0;
}