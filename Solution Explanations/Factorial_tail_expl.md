# Factorial (Tail Recursive) (Solution)
The key to this problem is to store the running factorial in the variable k. This way, the recursive multiplication is done immediately *before* the recursive call takes place, making the recursive call the final executed statement of `factorialHelper` and hence making the function tail recursive.

```
factorialHelper(n, k):
   if n == 1 then return k
   return factorialHelper(n - 1, k * n)

factorial(n):
   return factorialHelper(n, 1)
```

