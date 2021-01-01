# Duplicate Digits (Solution)
We know immediately that if n has a single digit, then it is impossible for it to have
duplicate digits, since duplicate digits requires two consecutive digits.

Now, suppose we look at the final two digits of n and they are the same. If this is
so, then we are done and simply return true. Otherwise, we must check the remaining
pairs of digits. If n contains duplicate digits in this case, then they cannot include
the final digit of n, thus we recurse upon n excluding its final digit. The implemenation
is thus:
```
duplicateDigits(n):
   if |n| < 10 then return false (we can change this to if n == 0 if we'd like; it would return false either way)
   if (n mod 10 == floor(n / 10) mod 10) return true (mathematical way to access last two digits)
   return duplicateDigits(floor(n / 10))
```