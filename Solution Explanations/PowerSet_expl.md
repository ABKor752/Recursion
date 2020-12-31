# Power Set (Solution)
To understand how recursion applies to this problem, consider the power sets of
{1, 2, 3} and {1, 2}. The former has power set:

<img src="https://render.githubusercontent.com/render/math?math=\{ \varnothing, 
\{1\}, \{2\}, \{3\}, \{1, 2\}, \{1, 3\}, \{2, 3\}, \{1, 2, 3\} \}">

while the latter has power set:

<img src="https://render.githubusercontent.com/render/math?math=\{ \varnothing, 
\{1\}, \{2\}, \{1, 2\} \}">

Notice that since {1, 2} is a subset of {1, 2, 3}, any subset of {1, 2} will be a subset 
of {1, 2, 3}, meaning that **the power set of {1, 2} is a subset of the power set
of {1, 2, 3}.**

For a generic set A of n elements, suppose P is the power set of the first n - 1 elements.
Following the logic above, this power set composes a portion of the power set we
wish to return. More importantly, **this power set comprises all subsets A which do
not include the nth element**. Thus, we must add all subsets of A which include the
nth element, which will be every subset in P with the nth element added.

For instance, applying this to the above example, the power set of {1, 2, 3} would be:

<img src="https://render.githubusercontent.com/render/math?math=\{ \varnothing, 
\{1\}, \{2\}, \{1, 2\} \} \cup \{ \varnothing \cup \{3\}, \{1\} \cup \{3\}, \{2\} \cup 
\{3\}, \{1, 2\} \cup \{3\} \}">

The base case involves determining the power set of the empty set. Since the only
subset of an empty set is the empty set itself, we return {{}} if A is empty. Thus,
the final algorithm is as follows:
```
powerset(A[1...n]):
   if n == 0 then return { {} }
   B1 = powerset(A[1...n-1])
   B2 = B1
   for each S in B2 do:
      S = S U {A[n]}
   return B1 U B2
```