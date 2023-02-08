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
### [Time complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms)

Time complexity in coding refers to the amount of time an algorithm takes to solve a problem as a function of the size of the input data. It is used to analyze and compare the efficiency of different algorithms. The time complexity is expressed using big O notation, which provides an upper bound on the growth rate of the running time as the size of the input increases. Common time complexities include O(1) for constant time, O(log n) for logarithmic time, O(n) for linear time, and O(n^2) for quadratic time. Lower time complexities are preferred as they indicate faster algorithms.

### **O(n^2) Quadratic Time** 
A common example of an algorithm that takes quadratic time is the nested loop algorithm. Here's a simple example in C:
```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // do some operation
    }
}
```
In this example, the inner loop runs n times for each iteration of the outer loop, so the total number of operations is n * n = n^2. This means that the running time of the algorithm grows in proportion to the square of the size of the input n, making it a quadratic time algorithm.

### **O(log n) Logarithmic Time** 
A common example of an algorithm that takes O(log n) time is binary search. Here's a simple example in C:
```c
int binary_search(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x) 
            return mid;
 
        if (arr[mid] > x) 
            return binary_search(arr, l, mid - 1, x);
 
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}
```
In this example, the input array arr is divided into two halves in each iteration of the binary search algorithm, so the size of the input is reduced by half in each step. This means that the number of steps required to find the target element is proportional to the logarithm of the size of the input, making the algorithm a logarithmic time algorithm with a time complexity of O(log n).

### **O(n) Linear Time** 
A common example of an algorithm that takes O(n) linear time is the simple loop algorithm. Here's a simple example in C:
```c
for (int i = 0; i < n; i++) {
    // do some operation
}
```
In this example, the loop runs n times, once for each element in the input. The running time of the algorithm grows in proportion to the size of the input n, making it a linear time algorithm with a time complexity of O(n). This means that the number of operations required to run the algorithm grows linearly with the size of the input.


### [Space complexity](https://www.geeksforgeeks.org/g-fact-86/)

Space complexity in coding refers to the amount of memory used by an algorithm to solve a problem. It measures how the memory usage of an algorithm increases with the size of the input data.

In other words, space complexity is the amount of additional memory needed by an algorithm in terms of the size of the input. It takes into account not only the memory used to store the data, but also the memory used by any data structures and variables needed to solve the problem.

Space complexity is important to consider in algorithms because memory usage can affect the performance of an algorithm, especially for large input sizes. For example, an algorithm with a high space complexity may run out of memory and crash, or it may be slow because it has to constantly swap data in and out of the memory.

Space complexity is usually expressed using big O notation, just like time complexity. For example, an algorithm with a space complexity of O(n) uses memory proportional to the size of the input, while an algorithm with a space complexity of O(1) uses a constant amount of memory, independent of the size of the input.

When analyzing an algorithm, it's important to consider both time and space complexity to determine the overall performance of the algorithm. A highly efficient algorithm in terms of time complexity may not be a good choice if it requires a lot of memory, and vice versa.

## Types of sorting algorithms
[Bubble sort:](https://www.geeksforgeeks.org/bubble-sort/) 
> - Time complexity - O(n^2)
> - Space complexity - O(1)
---
Insertion Sort: 
> - Time complexity - O(n^2)
> - Space complexity - O(1)
---
Selection Sort: 
> - Time complexity - O(n^2)
> - Space complexity - O(1)
---
[Quick sort:](https://en.wikipedia.org/wiki/Quicksort) 
> - Time complexity - O(n log n) on average, O(n^2) in worst case
> - Space complexity - O(log n)
---
[Merge sort:](https://en.wikipedia.org/wiki/Merge_sort)
> - Time complexity - O(n log n)
> - Space complexity - O(n)
---
Heap Sort: 
> - Time complexity - O(n log n)
> - Space complexity - O(1)
---
Counting Sort:
> - Time complexity - O(n)
> - Space complexity - O(k), where k is the range of input values
---
Radix Sort:
> - Time complexity - O(nk), where k is the number of digits in the largest number
> - Space complexity - O(n + k)
---
Bucket Sort:
> - Time complexity - O(n + k), where k is the range of input values
> - Space complexity - O(n + k)
---

##Todo
- get checker working
- submit

## Links
> 🌟[Efficient Push_Swap](https://web.archive.org/web/20220802162832/https://www.codequoi.com/en/push_swap-efficient-positional-sorting-algorithm/)

> [Push Rotate](https://kipplesunderscore.github.io/posts/push-swap/)

> [Push Swap tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)

> [Least steps Push Swap](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

> [AdrianW](https://github.com/AdrianWR/push_swap)

# Result
100/100
