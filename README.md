# Sort-and-Insert
Sorting and inserting in doubly linked list of strings in C.

I separated the code into four source files: 
* `linked_list.c` contains the main function
* `merge_sort.c` contains the functions for sorting the linked list
* `inserts.c` contains the functions that inserts/deletes elements and measures the time of inserting elements and the last source file
* `helpers.c` contains functions that are used in multiple source files

The program makes a doubly linked list of 500 random strings, after which it merge sorts it on alphabetic order. After it is sorted, a node is added in the middle, the end, and at position 498 of the list. To measure the time of inserting an element at a random place, I averaged over 2000 times (each time inserting an element and deleting it again after the time measurement). The program does this for 6 different list sizes.

![Alt text](./TimeComplexity.png?raw=true "Optional Title")
