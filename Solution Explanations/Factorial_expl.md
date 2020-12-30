# Factorial (Solution)
The key to this problem is understanding how `factorial(n)` relates to `factorial(n - 1)`. To do this, we examine the expansions of both n!:

<img src="https://render.githubusercontent.com/render/math?math=n! = n \cdot (n - 1) \cdot (n - 2) \cdot \ldots \cdot 2 \cdot 1">

and (n - 1)!:

<img src="https://render.githubusercontent.com/render/math?math=(n - 1)! = (n - 1) \cdot (n - 2) \cdot \ldots \cdot 2 \cdot 1">

Notice that the expansion for n! includes the expansion for (n - 1)! in such a way that we can write:

<img src="https://render.githubusercontent.com/render/math?math=n! = n \cdot (n - 1)!">

Therefore, to calculate the factorial of n using recursion, we must find the factorial of n - 1 and multiply it with n.

And don't forget about the base case! The requires clause for the function specifies that n > 0, so we infer that our base case is reached when n is 1, namely n! = 1! = 1. The implementation is therefore as follows:
```
factorial(n):
   if n == 1 then return 1
   return n * factorial(n - 1)
```

