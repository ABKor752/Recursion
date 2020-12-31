# Power Set
The **power set** of a set A is **the set of all subsets of A**.
For instance, the power set of {1, 2, 3} would be:

{ {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3} }

In `PowerSet_workspace.cpp`, implement the `powerset` function which returns the
power set of `set`. Note the following:
* The resulting subsets may be in any order
* No subset may appear more than once (i.e. {1, 3} and {3, 1} cannot both appear)
* The values within the subsets can be in any order (so either {1, 3} or {3, 1} is fine)
