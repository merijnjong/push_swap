# push_swap
In this project I have to write a program which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.
Function name | push_swap |
|:--- |:---
Turn in files | [Makefile](https://github.com/merijnjong/push_swap/blob/main/Makefile), [push_swap.h](https://github.com/merijnjong/push_swap/blob/main/push_swap.h), [push_swap.c](https://github.com/merijnjong/push_swap/blob/main/push_swap.c) |
Arguments | Stack a: A list of integers |
External functions | read, write, malloc, free, exit, ft_printf and any equivalent I coded |
Libft authorized | Yes |
Description | Sort stacks |

### The rules
* You have 2 stacks named a and b.<br />
* At the beginning:<br />
  * The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.<br />
  * The stack b is empty.<br />
* The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:<br />
  *  sa (swap a): Swap the first 2 elements at the top of stack a.<br />
  &emsp; Do nothing if there is only one or no elements.<br />
  *  sb (swap b): Swap the first 2 elements at the top of stack b.<br />
  &emsp; Do nothing if there is only one or no elements.<br />
  *  ss : sa and sb at the same time.<br />
  *  pa (push a): Take the first element at the top of b and put it at the top of a.<br />
  &emsp; Do nothing if b is empty.<br />
  *  pb (push b): Take the first element at the top of a and put it at the top of b.<br />
  &emsp; Do nothing if a is empty.<br />
  *  ra (rotate a): Shift up all elements of stack a by 1.<br />
  &emsp; The first element becomes the last one.<br />
  *  rb (rotate b): Shift up all elements of stack b by 1.<br />
  &emsp; The first element becomes the last one.<br />
  *  rr : ra and rb at the same time.<br />
  *  rra (reverse rotate a): Shift down all elements of stack a by 1.<br />
  &emsp; The last element becomes the first one.<br />
  *  rrb (reverse rotate b): Shift down all elements of stack b by 1.<br />
  &emsp; The last element becomes the first one.<br />
  *  rrr : rra and rrb at the same time.<br />
