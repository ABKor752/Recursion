#include <vector>
#include <algorithm> // for std::min

/**
 * Requires: denoms is filled only with positive integers in ascending 
 *           order and is nonempty
 * Modifies: Nothing
 * Effects:  Returns the minimum number of coins (whose denominations are 
 *           represented in denoms) required to reach a total of n cents,
 *           or return -1 if this is not possible.
 */
int minCoins(std::vector<int> denoms, int n) {
    // We don't need any coins to reach 0 cents
    if (!n) return 0;
    int curr_min = INT_MAX;
    // Reaching n cents by starting with a denoms[i] coin, for each i
    for (size_t i = 0; i < denoms.size(); ++i) {
        // It is not possible to reach n cents with a denomination greater than n
        if (n < denoms[i]) break;
        // If recursive call returns -1, we make it INT_MAX to ensure that curr_min
        // does not become -1
        int x = 1 + minCoins(denoms, n - denoms[i]);
        if (!x) x = INT_MAX;
        // Updating minimum number of coins used
        curr_min = std::min(curr_min, x);
    }
    // If curr_min == INT_MAX, there were no successful finds, thus we return -1
    if (curr_min == INT_MAX) return -1;
    // Return the final result
    return curr_min;
}