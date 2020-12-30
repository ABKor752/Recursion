/**
 * Requires: n > 0
 * Modifies: Nothing
 * Effects:  Returns the number of Collatz cycles required to reach 1 from n
 */
int collatzCycles(int n) {
    // Base case
    if (n == 1) return 0;
    // If n is even
    if (n % 2 == 0) return 1 + collatzCycles(n / 2);
    // Otherwise, if n is odd
    return 1 + collatzCycles(3 * n + 1);
}