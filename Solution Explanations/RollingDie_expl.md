# Rolling N-sided Die (Solution)
On our first roll, we can roll either 1, 2, ..., or n, meaning we would need to roll
a remaining sum of K - 1, K - 2, ..., K - n, respectively in each case. Once the "remaining 
sum" which we want to reach becomes 0, we have added to exactly K and can stop. However,
if this "remaining sum" becomes negative, then we have exceeded the total of K. Hence,
We recurse upon a sum of K - i if and only if i does not exceed K, for 1 <= i <= n.

As noted above, our base case is reached when K is 0. There is exactly one way to roll
a sum of 0, which is to not roll at all.

The overall logic is shown in the algorithm below:

```
waysToRollK(n, K):
   if K is 0 then return 1
   numWays = 0
   for i = 1 to min(n, K):
      numWays = numWays + waysToRollK(n, K - i)
   return numWays
```

*Bonus (Runtime)*: What is the runtime of the above algorithm? Let T(n, K) be the worst-case total
number of operations that this algorithm performs. Then T(n, 0) = 1 for all n, and otherwise,

<img src="https://render.githubusercontent.com/render/math?math=T(n, K) = \sum_{i = 1}^K T(n, K - i) = T(n, K - 1) + \sum_{i = 2}^K T(n, K - 2)
= T(n, K - 1) + T(n, K - 1) = 2T(n, K - 1)">

When solved, the recurrence relation above gives:

<img src="https://render.githubusercontent.com/render/math?math=T(n, K) = 2^KT(n, 0) = 2^K(1) = O(2^K)">

Hence, the current trivial recursive algorithm runs in exponential time with respect to K. To make this more efficient, we will use **dynamic programming**.
Suppose we have an array arr[1...K] which is initially filled with -1's. If we find the result to `waysToRoll(n, M)`, then we set arr[M] to that value and
reuse it whenever we call `waysToRoll(n, M)` again. This way, we can ensure that we run the body of `waysToRollK` **at most K times**. The new algorithm is as follows:

```
waysToRollKHelper(n, K, arr[]):
   if arr[K] is not -1 then return arr[K]
   if K is 0 then return 1
   numWays = 0
   for i = 1 to min(n, K):
      numWays = numWays + waysToRollK(n, K - i)
   arr[K] = numWays
   return numWays

waysToRollK(n, K):
   arr[1...K] = [-1, ..., -1]
   return waysToRollKHelper(n, K, arr)
```

There will be at most K recursive calls which execute the **for** loop in `waysToRollKHelper`, a loop which executes K times in the worst case scenario. 
The runtime is therefore O(K^2).