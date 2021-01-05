// Feel free to include any libraries you'd like
#include <algorithm> // for std::min
/**
 * Requires: n > 0, K >= 0
 * Modifies: Nothing
 * Effects:  Returns the number of ways to roll an n-sided die to reach a
 *           total sum of K
 */
int waysToRollK(int n, int K) {
    if (!K) {
        return 1;
    }
    int numWays = 0;
    for (int i = 1; i <= std::min(n, K); ++i) {
        numWays += waysToRollK(n, K - i);
    }
    return numWays;
}