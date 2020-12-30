/**
 * Requires: n, k > 0 
 * Modifies: Nothing     
 * Effects:  Returns n! using tail recursion   
 */       
int factorialHelper(int n, int k) {
    // Base case
    if (n == 1) return k;
    // Tail recursive call
    return factorialHelper(n - 1, k * n);
}

/**
 * Requires: n > 0 
 * Modifies: Nothing           
 * Effects:  Returns n! using the factorialHelper function        
 */
int factorial(n) {
    return factorialHelper(n, 1);
}
