// Definition of linked list node
struct Node {
    int val;
    Node* next;
    Node(int val) : val(val) { next = nullptr; }
};

/**
 * Requires: The lists l1 and l2 represent positive integers
 *           For each node, 0 <= val <= 10
 *           l1 and l2 are not both nullptr
 * Modifies: Nothing
 * Effects:  Adds the numbers represented by l1 and l2 together and returns
 *           the sum as a linked list. See LinkedListSum.md for an example.
 */
Node* linkedListSum(Node* l1, Node* l2) {
    // Base cases
    if (!l1) return l2;
    if (!l2) return l1;
    // Add next two digits together
    Node* root = new Node((l1->val + l2->val) % 10);
    // Check for carrying 1
    if (l1->val + l2->val > 9) {
        if (!l1->next && !l2->next) {
            root->next = new Node(1);
            return root;
        }
        else if (l1->next) {
            l1->next->val++;
        }
        else {
            l2->next->val++;
        }
    }
    // Recurse upon remaining digits and return list
    root->next = linkedListSum(l1->next, l2->next);
    return root;
}