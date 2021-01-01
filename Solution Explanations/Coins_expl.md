# Coins (Solution)
It's best to understand this problem with an example. 
Suppose, like in our problem statement, we have coin denominations of 2, 5, 8, and
10 cents, and we wish to reach 24 cents. Let's consider all the possible combinations
of coins with these denominations that add up to 24. The first coin in any combination
must either be worth 2, 5, 8 or 10 cents. Therefore, we can split up all combinations
of coins adding to 24 cents into the following four categories:
* one 2-cent coin, followed by all combinations of 24 - 2 = 22 cents
* one 5-cent coin, followed by all combinations of 24 - 5 = 19 cents
* one 8-cent coin, followed by all combinations of 24 - 8 = 16 cents
* one 10-cent coin, followed by all combinations of 24 - 10 = 14 cents.

Assume that we already know the minimum number of coins to make 22, 19, 16, and 14 cents
with the available denominations, and call these amounts w, x, y, and z respectively.
Then, the minimum number of coins needed to reach 24 cents must be:

<img src="https://render.githubusercontent.com/render/math?math=\min\{1%2Bw, 1%2Bx, 1%2By, 1%2Bz\}">

The 1 comes from accounting for the 2-cent, 5-cent, 8-cent, or 10-cent beginning coin
in each case.

But what happens when we start approaching 0 cents in our recursive calls? Our base
cases for this problem might look a tad abnormal, so let's work them out logically.
* Suppose we need coins to add to 0 cents. Then we simply need 0 coins; we are already at the required total.
* What if we reach negative cents? Well, that's impossible, so don't let it get to that point!
* If we know ahead of time that we'll reach negative cents, we know that such a coin
combination is impossible, and thus we should return -1. For instance, if we want
to add to 1 cent, the lowest denomination coin is 2 cents, meaning we would recurse
upon -1 cents. We know that this is impossible, so instead we return -1.
* Similar to above, we might have to recurse on a coin amount which is in between existing
denominations. Say we want to recurse upon 6 cents. We can do that with denominations of
2 and 5 just fine, but not with 8 and 10, since 6 - 8 = -2 and 6 - 10 = -4 are both
negative. **Therefore, we recurse if and only if the target total is at least equal to
the coin denomination we wish to recurse with.**
* When looking for the minimum number of coins across multiple possibilities, we must
be careful not to include -1. Thus, when calculating the minimum, temporarily make -1
a very large integer so that it cannot be considered.

With all this laid out, we write the pseudocode for the final solution:

```
minCoins(arr[1...m], n):
   if n == 0 then return 0
   current_min = INT_MAX (maximum possible integer)
   for each denomination in arr do:
      if n < denomination then break (exit loop, cannot recurse on negative cents)
      value = 1 + minCoins(arr, n - denomination)
      if value == 0 then value = INT_MAX (recursive call returned -1, so do not consider it)
      current_min = min{current_min, x}
   if current_min == INT_MAX then return -1 (no proper minimum number of coins found)
   return current_min
```

*Bonus (Runtime)*: How can we make this algorithm more efficient? If we run the above
algorithm on n = 24 and arr = [2, 5, 8, 10], then for instance, we will recurse on n = 14
once when calling `minCoins(arr, 24 - 10)`, and another time when we recurse on n = 24
with denomination 8, then recurse upon that with 2 (i.e. `minCoins(arr, 24 - 8 - 2)`).
Currently, the runtime is exponential because of these multiple recursive calls. However,
we can improve the efficiency by storing the results to subproblems in a memo table.

Define an array `memo[1...n]`, which when called initially,
is filled with the value -2. Any time we figure out the result to `minCoins(arr[1...m], i)`,
we set `memo[i]` to that result. Then, if we ever call `minCoins(arr[1...m], i)` again,
we simply return that result. The revised algorithm looks like this:

```
minCoins(arr[1...m], n, memo[]):
   if memo[n] is not -2 then return memo[n]
   if n == 0 then return 0
   current_min = INT_MAX (maximum possible integer)
   for each denomination in arr do:
      if n < denomination then break (exit loop, cannot recurse on negative cents)
      value = 1 + minCoins(arr, n - denomination)
      if value == 0 then value = INT_MAX (recursive call returned -1, so do not consider it)
      current_min = min{current_min, x}
   if current_min == INT_MAX then memo[n] = -1 (no proper minimum number of coins found)
   else memo[n] = current_min
   return memo[n]
```

For any given n, `minCoins` will have its main implementation (everything after the first line)
executed *at most once*, and for each call, we have a loop over the m possible denominations.
Therefore, the new runtime is O(mn).

