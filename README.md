# push_swap.c

**Introduction**

Push_swap is a project designed to sort a set of integers using a specific set of stack-based operations. It challenges developers to create an optimized sorting algorithm with minimal operations, focusing on algorithmic complexity and efficiency. The project builds a strong foundation in sorting algorithms, stack manipulation, and algorithm optimization.

**Features - Mandatory Functionality**
The core program, push_swap, is responsible for:

Sorting integers from stack a into ascending order with the least number of operations.
Providing output as a sequence of instructions using a specific language of commands:
sa: Swap the first two elements of stack a.
sb: Swap the first two elements of stack b.
ss: Perform sa and sb simultaneously.
pa: Push the top element from stack b to stack a.
pb: Push the top element from stack a to stack b.
ra: Rotate stack a (shift all elements up; first becomes last).
rb: Rotate stack b.
rr: Perform ra and rb simultaneously.
rra: Reverse rotate stack a (shift all elements down; last becomes first).
rrb: Reverse rotate stack b.
rrr: Perform rra and rrb simultaneously.

**Implementation Details**

Input: The program receives integers as arguments. The first integer corresponds to the top of stack a.

Output: A minimal sequence of instructions, separated by \n, that sorts the integers in stack a.
Constraints:
No duplicates in input.
Errors (e.g., non-integer arguments, duplicates) are reported with "Error\n" on stderr.

**Edge Cases:**
If no arguments are passed, the program produces no output.
Sorting must meet specific operation count thresholds.
Example
Given the input:

bash
$> ./push_swap 2 1 3 6 5 8
The output might be:

sa
pb
pb
pb
sa
pa
pa
pa

**Bonus Features**

**Checker Functionality:**

Verifies the sequence of sorting instructions.
Outputs "OK" if the operations correctly sort stack a and leave stack b empty.
Outputs "KO" if the operations fail to sort correctly.
Outputs "Error" for invalid inputs or instructions.
Input:
Accepts a list of integers for stack a.
Reads instructions from stdin.
Output:
"OK", "KO", or "Error", as described above.

