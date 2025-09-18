This project is about sorting a stack of integers with a limited set of stack operations, in the least possible number of moves.  
It was developed as part of the 42 curriculum.
The program prints a list of operations that will sort the numbers.
these operations are well explained in the subject pdf (Push_swap_subject.pdf), so please go read it first :)
*****Usage******

Clone the repository and run `make` to build the program.

```bash
make
-----------------------------
./push_swap 2 1 3 6 5 8
pb
pb
rrb
pb
sa
pa
pa
pa
------------------------------


42 provides a checker program to verify that your moves really sort the stack.
You can download it through the provided links (just ctrl+c / ctrl+v):
checker for Mac: ''''' https://cdn.intra.42.fr/document/document/37654/checker_Mac '''''''
checker for Linux: ''''' https://cdn.intra.42.fr/document/document/37655/checker_linux ''''''

Example:
----------------------------
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker_linux $ARG
ok
----------------------------

If everything works, the checker will output OK.

*********logic*************

-The logic depends on a target node: every node in one stack is assigned a target in the other stack.

**logic steps(briefly):
1- Setup (A -> B)''''''
Push most elements from A to B, keeping a small base in A (stop when size(A) <= 3).
Sort the remaining 2–3 in A directly.

2- Target selection (core idea)'''''
For each node x in **B, its target in **A** is the node with the **smallest index greater than x**. If none exists, the target is the **minimum** in **A**. Inserting x` just above its target keeps A ordered.

3- Cost calculation'''''''''''
For each x in B, compute:
cost_a: rotations to bring target(A) to top (ra vs rra)
cost_b: rotations to bring x (B) to top (rb vs rrb)

Choose the cheapest plan:
both up → use rr as much as possible, then finish with ra/rb
both down → use rrr as much as possible, then finish with rra/rrb
mixed → ra + rrb or rra + rb
Execute the plan, then pa.

4- Repeat best move'''''''''''
After each pa, recompute targets and costs, and pick the lowest total cost node in B next.

5-Finish''''''''''''
When B is empty, rotate A so the minimum is on top (ascending order).

*****Notes******

-Input must contain only valid integers, otherwise, The program will return an error message if the input is invalid (non-numeric, duplicates, out of int range).
