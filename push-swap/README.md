# Push Swap
*Because swap push isn't as natural*


### Summary
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

### The Rules
You have 2 stacks named `a` and `b`. The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. The stack `b` is empty. The goal is to sort in ascending order numbers into stack `a`. To do so you have the following operations at your disposal
-  sa(swap `a`): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
-  sb(swap `b`): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
-  ss:sa and sb at the same time.
-  pa(push `a`): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if b is empty.
-  pb(push `b`): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if a is empty.
-  ra(rotate `a`): Shift up all elements of stack `a` by 1. The first element becomes the last one.
-  rb(rotate `b`): Shift up all elements of stack `b` by 1. The first element becomes the last one.
-  rr:ra and rb at the same time.
-  rra(reverse rotate `a`): Shift down all elements of stack a by 1. The last element becomes the first one.
-  rrb(reverse rotate `b`): Shift down all elements of stack b by 1. The last element becomes the first one.
-  rrr:rra and rrb at the same time.

## Read
[Time complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms)

[Space complexity](https://www.geeksforgeeks.org/g-fact-86/)

## Types of sorting algorithms
 [Bubblesort](https://www.geeksforgeeks.org/bubble-sort/)
> - Worst complexity: n^2
> - Average complexity: n^2
> - Best complexity: n
> - Space complexity: 1
> - Method: Exchanging
> - Stable: Yes
> - Class: Comparison sort
---
 [Quicksort](https://en.wikipedia.org/wiki/Quicksort)
> - Worst complexity: n^2
> - Average complexity: n*log(n)
> - Best complexity: n*log(n)
> - Space complexity: 1
> - Method: Partitioning
> - Stable: No
> - Class: Comparison sort
---
 [Mergesort](https://en.wikipedia.org/wiki/Merge_sort)
> - Worst complexity: n*log(n)
> - Average complexity: n*log(n)
> - Best complexity: n*log(n)
> - Space complexity: n
> - Method: Merging
> - Stable: Yes
> ---

## Links
> 🌟[Efficient Push_Swap](https://www.codequoi.com/en/push_swap-efficient-positional-sorting-algorithm/#sorting_algorithm_for_over_3_numbers)

> [Push Rotate](https://kipplesunderscore.github.io/posts/push-swap/)

> [Push Swap tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)

> [Least steps Push Swap](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
