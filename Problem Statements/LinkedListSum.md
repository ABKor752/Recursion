# Linked List Sum
(Note: this problem requires previous knowledge of linked lists)

Define a singly-linked list to be comprised of nodes containing an integer value and a 
`next` pointer. In C++, this is defined as:
```
struct Node {
   int val;
   Node* next;
   Node(int val) : val(val) { next = nullptr; }
}
```
You are given two linked lists which represent **positive integers in reverse order**, where each
node represents a single digit. For instance, the list 1->5->2->NULL represents the
integer 251. The number represented by the linked list might be too large for the compiler
to handle, so they cannot simply be converted to regular integers.

Determine the **sum** of the two numbers represented by the linked lists, and return
a linked list representing the final sum in reverse order. **You must use recursion.**

Example:

1->5->2->NULL

4->6->NULL

This is equivalent to adding 251 and 64, which is 315. Thus, 
return 5->1->3->NULL.