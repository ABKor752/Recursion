# Rolling N-sided Die
You are given an N-sided die with values 1, 2, ..., N, and an integer K. Determine,
using recursion the number of ways to repeatedly roll the die to reach a total sum
of exactly K.

Example: N = 3, K = 5. There are 13 ways to roll the die to reach a sum of 5.
* 3, 2
* 2, 3
* 3, 1, 1
* 1, 3, 1
* 1, 1, 3
* 2, 2, 1
* 2, 1, 2
* 1, 2, 2
* 2, 1, 1, 1
* 1, 2, 1, 1
* 1, 1, 2, 1
* 1, 1, 1, 2
* 1, 1, 1, 1, 1

*Bonus*: What is the asymptotic runtime of the trivial recursive algorithm?
Can you implement an O(K^2) algorithm?