/**
 * Requires: Nothing
 * Modifies: Nothing
 * Effects:  Returns whether n contains duplicate digits or not.
 *           See DuplicateDigits.md for the definition of duplicate
 *           digits.
 */
bool duplicateDigits(int n) {
    // Base case
    if (!n) return false;
    // Check last two digits
    if (n % 10 == (n / 10) % 10) return true;
    // Recurse upon all digits except last one
    return duplicateDigits(n / 10);
}