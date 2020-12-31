#include <vector>

/**
 * Requires: Nothing
 * Modifies: Nothing
 * Effects:  Returns the power set of "set"
 */
std::vector<std::vector<int>> powerset(std::vector<int>& set) {
    // Power set of an empty set consists only of the empty set
    if (set.empty()) return { {} };
    // Determine power set of "set" without last element
    std::vector<int> without_last(set.begin(), set.begin() + set.size() - 1);
    std::vector<std::vector<int>> current = powerset(without_last);
    // Add each element of "current" to the back of "current" with the final value of "set"
    // included
    int size = int(current.size());
    for (int i = 0; i < size; ++i) {
        current.push_back(current[i]);
        current.back().push_back(set.back());
    }
    return current;
}