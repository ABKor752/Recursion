# Coins
A classic recursion problem is determining, given a set of coins with different denominations, what the minimum number of coins needed is to reach a certain value n. One solution to this problem is to keep taking the highest denomination coin until you cannot anymore. (This is called a greedy solution.) For instance, suppose our denominations are 2 cents, 5 cents, and 10 cents. Using this greedy strategy, to reach 24 cents, we would take the highest denomination twice (10 + 10 = 20), then since we can no longer take 5 or 10, we take the 2-cent coin twice (10 + 10 + 2 + 2 = 24), making 4 the minimum number of coins needed to reach 24 cents.

However, the greedy solution does not always work. If, for instance, we added an 8-cent coin to the possible denominations, we would need only 3 coins to reach 24 cents (by taking three 8-cent coints). This mandates that we come up with a different strategy for finding the minimum number of coins needed.

Suppose you have an array of possible coin denominations, as well as a target value n. Implement the `minCoins` function in `Coins_workspace.cpp` to determine the minimum number of coins (of denominations consisting of those available in the array) needed to reach a total of n cents. You may assume that you have an infinite number of coins for each denomination. If it is not possible to reach **exactly** n cents, return -1.

*Challenge:* Can you do this in O(mn) time, where m is the size of the array?
