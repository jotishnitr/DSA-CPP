/*
------------------------------------------------------------
Problem: Sort List

LeetCode:
https://leetcode.com/problems/sort-list/

GeeksforGeeks:
https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

Pattern Used:
1. Store Values + Sort
2. Merge Sort on Linked List

============================================================

Approach 1: Brute Force (Store Values in Array)

Idea:
Traverse the linked list and store all node
values in an array.

Sort the array.

Traverse the linked list again and replace
each node's value with the sorted values.

The links remain unchanged;
only node values are modified.

------------------------------------------------------------
Algorithm

1. Traverse the linked list.
2. Store every node's value in a vector.
3. Sort the vector.
4. Traverse the linked list again.
5. Replace each node's value using the
   sorted vector.
6. Return head.

------------------------------------------------------------
Dry Run

Original List

4 -> 2 -> 1 -> 3

Store

[4, 2, 1, 3]

Sort

[1, 2, 3, 4]

Rewrite List

1 -> 2 -> 3 -> 4

------------------------------------------------------------
Time Complexity

Traversing List

O(n)

Sorting

O(n log n)

Updating List

O(n)

Overall

O(n log n)

------------------------------------------------------------
Space Complexity

O(n)

============================================================

Approach 2: Merge Sort (Optimal)

Idea:
Merge Sort works efficiently on linked lists
because splitting and merging can be done
using pointer manipulation.

Steps

1. Find the middle node.
2. Split the list into two halves.
3. Recursively sort both halves.
4. Merge the two sorted lists.

------------------------------------------------------------
Algorithm

Base Case

If

head == NULL

or

head->next == NULL

Return head.

----------------------------

Split

Find the middle node.

Break the list into

Left Half

Right Half

----------------------------

Recursive Calls

Sort left half.

Sort right half.

----------------------------

Merge

Merge the two sorted linked lists.

Return merged head.

------------------------------------------------------------
Dry Run

Original List

4 -> 2 -> 1 -> 3

----------------------------

Split

Left

4 -> 2

Right

1 -> 3

----------------------------

Split Left

4

2

Merge

2 -> 4

----------------------------

Split Right

1

3

Merge

1 -> 3

----------------------------

Final Merge

2 -> 4

1 -> 3

↓

1 -> 2 -> 3 -> 4

------------------------------------------------------------
Key Observation

Merge Sort is the preferred sorting algorithm
for linked lists because:

• Finding the middle is O(n).
• Splitting requires only changing one pointer.
• Merging two sorted linked lists is O(n).
• No random access is required unlike arrays.

------------------------------------------------------------
Time Complexity

Finding Middle

O(n)

Merge

O(n)

Total

O(n log n)

------------------------------------------------------------
Space Complexity

Recursive Stack

O(log n)

(No extra array is used.)

------------------------------------------------------------
Similar Problems

1. Merge Two Sorted Lists
2. Merge K Sorted Lists
3. Insertion Sort List
4. Convert Sorted List to BST
5. Sort an Array
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
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

    // ---------------- Brute Force (Store Values in Array + Sort) ----------------

    ListNode* sortListBrute(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> arr;

        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;
        int i = 0;

        while (temp != nullptr) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }

    // ---------------- Merge Two Sorted Lists ----------------

    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1 != nullptr)
            temp->next = list1;
        else
            temp->next = list2;

        ListNode* newHead = dummyNode->next;
        delete dummyNode;

        return newHead;
    }

    // ---------------- Find Middle ----------------

    ListNode* findMiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // ---------------- Optimal (Merge Sort) ----------------

    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        middle->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge(leftHead, rightHead);
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

// Copy List
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

    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 3);

    cout << "Original List : ";
    printList(head);

    Solution obj;

    ListNode* head1 = copyList(head);
    head1 = obj.sortListBrute(head1);

    cout << "Brute Force   : ";
    printList(head1);

    ListNode* head2 = copyList(head);
    head2 = obj.sortList(head2);

    cout << "Optimal       : ";
    printList(head2);

    return 0;
}