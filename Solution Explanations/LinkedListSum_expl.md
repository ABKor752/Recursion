# Linked List Sum (Solution)
This problem is very, very tricky. Notice that in `LinkedListSum_workspace.cpp`,
the Requires clause mandates that at least one of the two linked lists must not
be a null pointer. However, it is possible for one of them to be. To understand how
recursion comes into play, we consider the following cases:
* If l1 is a null pointer but l2 is not, we consider this to be adding by 0 and simply
return l2
* Likewise, if l2 is a null pointer but l1 is not, do the same as above with l1
* Otherwise, if neither are a null pointer, we have two digits which we must add,
append to the list which we create and eventually return, and continue adding the
remaining digits by recursing upon l1->next and l2->next.

The first two points above give us our base cases. Since the lists represent numbers
in reverse, we can think of this as adding integers from right to left, just as we
were taught in school.

Consider 351 + 64. When represented as linked lists, we start with the digits 1 and
4. We add those together and get 5, so we create a new node with value 5, append it
to our list, and move onto the next pair of integers. Now we add 5 and 6, but we have
a problem. 5 + 6 is 11, meaning **we must carry the 1**. But how can we do this with recursion?
Notice that the Requires clause of the function in `LinkedListSum_workspace.cpp` states
that each node can have an integer value of 10. Thus, to carry a 1, **we choose one of the
next two digits to add 1 to before we recurse, even if we are adding digit 9 to 1.**
We have the following cases:
* If one of l1->next and l2->next is a null pointer, add 1 to the other and recurse
* If neither l1->next nor l2->next are null pointers, choose one to add 1 to arbitrarily.
* If both l1->next and l2->next are null pointers, **do not recurse!** Simply create a new
node with value 1, append it to the list, and return the final list. We cannot recurse
on two null pointers.

With that all in mind, our final implementation is as below:
```
linkedListSum(l1, l2):
   if l1 is NULL then return l2
   if l2 is NULL then return l1
   root = new Node(last digit of l1->val + l2->val)
   if l1->val + l2->val > 9 then carry 1:
	if l1->next and l2->next are both NULL then:
	   root->next = new Node(1)
	   return root
	else if l1->next is not NULL but l2->next is NULL
	   increment l1->next->val
	else if l2->next is not NULL but l1->next is NULL
	   increment l2->next->val
   root->next = linkedListSum(l1->next, l2->next)
   return root
```