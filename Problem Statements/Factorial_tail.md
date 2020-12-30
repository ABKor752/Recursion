# Factorial (Tail Recursive)
(Note: It's suggested that you try out the Factorial problem before attempting this problem.)

We defined the factorial of a positive integer n in the Factorial problem and computed it using recursion. In `Factorial_tail_workspace.cpp`, implement the `factorial` function (along with its helper function `factorialHelper`) using **tail recursion**. A recursive function is tail recursive if the final executed statement of the function is the recursive call. The solution in `Factorial_solution.cpp` is *not* tail recursive since a multiplication must be performed after the recursive call, making the recursion not the last executed statement.

*Hint*: You will need to store the running factorial in a variable. Look at the helper function. What variables might you be able to store the running total in?

