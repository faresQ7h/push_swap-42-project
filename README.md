This project is about sorting a stack of integers with a limited set of stack operations, in the least possible number of moves.  
It was developed as part of the 42 curriculum.
The program prints a list of operations that will sort the numbers.
these operations are well explained in the subject pdf (Push_swap.pdf), so please go read it first :)
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
-The logic depends on target node, so each node in stack a or b will have its targrt node in the other stack (a target b / b target a) wich will be set using some calculations after then:

**logic steps(briefly):

1- Setup: push from A -> B
Push most elements from A to B (keep a tiny base in A, so loop stop if a size <= 3).

2- Target selection (core idea)
For each node x in B, find its target in A =
the node with the smallest index greater than x.
If none exists, the target is the minimum in A.
After we place x just above its target, A stays sorted.

3- Cost calculation:
For every x in B compute:

cost_a: rotations to bring target in A to the top (ra vs rra)
cost_b: rotations to bring x in B to the top (rb vs rrb)

Pick the cheapest plan among:

both up -> use rr as much as possible, then finish ra/rb
both down -> use rrr as much as possible, then finish rra/rrb
mixed -> do ra + rrb or rra + rb
Execute that plan, then pa.

4- Repeat best move.

5- Recompute targets and costs after each pa. Always choose the lowest total cost node in B next.

6 -Finish, when B is empty, rotate A so the minimum is on top (sorted ascending).

*****Notes******

-Input must contain only valid integers, otherwise, The program will return an error message if the input is invalid (non-numeric, duplicates, out of int range).
