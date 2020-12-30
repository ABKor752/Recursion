/**
 * Requires: n > 0
 * Modifies: Nothing
 * Effects:  Returns n! using recursion.
 */
int factorial(int n) {
    // Base case
    if (n == 1) return 1;
    // Recursive call
    return n * factorial(n - 1);
}
