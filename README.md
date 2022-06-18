# Welcome to 42cursus-push_swap!
This repository contains a project of the [42 school]. The task of this
exercise is to sort a list of random numbers using two stacks and some given
instructions described below. The challenge is not only about sorting numbers
in general, but also to do so in an efficient way.

The possible instructions to do so are:
 - ``sa``: exchange the two elements on the top of the stack *A*.
 - ``sb``: exchange the two elements on the top of the stack *B*.
 - ``ss``: perform a swap on both stacks at the same time.
 - ``pa``: push the topmost element of the stack *A* to the top of stack *B*.
 - ``pb``: push the topmost element of the stack *B* to the top of stack *A*.
 - ``ra``: rotate the stack *A* in ascending order.
 - ``rra``: rotate the stack *A* in descending order.
 - ``rb``: rotate the stack *B* in ascending order.
 - ``rrb``: rotate the stack *B* in descending order.
 - ``rr``: rotate both stacks in ascending order.
 - ``rrr``: rotate both stacks in descending order.

## Approach
The sorting algorithm is kept quite simple: at the beginning, the numbers are
indiced, the smallest number will get the biggest index. After that, the
indices are sorted using a reverse radix sorting algorithm.

### Radix sort
The radix sorting algorithm is quite simple: if the last binary digit is a
zero, the number is pushed to the stack *B*, otherwise, the stack *A* is
rotated. After going through the whole stack *A*, the numbers in the other
stack are pushed back to the stack *A*. Then the process is repeated with the
second last binary digit, after that with the third last binary digit and so
on, until the stack is sorted, which is checked after each cycle.

## Usage
Using the application is quite simple: after using the makefile, a list of
valid integers can be passed as argument(s) to the executable, no number must
be duplicated. The application will the show the operations that are needed to
sort these numbers.

### Final notes
This repository showcases my proper solution to the exercise and it will not be
developed any further.

> As all other C projects at the [42 school], the code has to written in accordance
> with the [norm]:
> - Only 25 lines per function,
> - only 5 functions per file,
> - usage of only the allowed external functions.

© 2021 [mhahnFr](https://www.github.com/mhahnFr)

[42 school]: https://www.42heilbronn.de/learncoderepeat
[norm]: https://www.github.com/42School/norminette
