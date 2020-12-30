# Collatz
The Collatz Conjecture is a current open problem in mathematics stating the following: starting with a positive integer n, multiply by 3 and add 1 if n is odd, and divide by 2 otherwise. No matter your starting choice of n, you will eventually reach 1.

Let's suppose that this conjecture is indeed true. Now, we want to know how many *cycles* it would take to reach 1 for a given n. For instance, given n = 6, we would do the following:

6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

This process takes 8 cycles, since 8 iterations of the Collatz algorithm are needed to reach 1.

Using recursion, implement the `collatzCycles` function in `Collatz_workspace.cpp`, which returns the number of Collatz cycles produced for a given positive integer n. 
