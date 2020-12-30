# Collatz (Solution)
We first note what happens if n is 1. In this case, no work needs to be done, thus 0 cycles are required. This is our base case.

Otherwise, the number of cycles required to reach 1 equals **the number of cycles to reach 1 from the next value in the Collatz sequence**, plus one. This is because we account for one cycle by dividing n by 2 if n is even, or multiplying by 3 and adding 1 if n is odd, then account for the rest of the moves by calling the Collatz algorithm on this new value. The recursive function is therefore as follows:

```
collatzCycles(n):
   if n == 1 then return 0
   else if n is even then
      return 1 + collatzCycles(n / 2)
   else
      return 1 + collatzCycles(3 * n + 1)
