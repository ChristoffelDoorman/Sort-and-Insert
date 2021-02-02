/*
 * Filename: merge_sort.h
 * Author: Christoffel Doorman (10580557)
 * Language: C (version C11)
 * Purpose: This file contains the function declarations to merge sort a doubly linked list.
 */

#ifndef ASSIGNMENT3_MERGE_SORT_H
#define ASSIGNMENT3_MERGE_SORT_H

/* Function splits a doubly linked list into 2 of half sizes. Takes
 *  the head node of the list and returns the node of the new list. */
struct Node *Split(struct Node *head);

/* Function to merges two linked lists. Takes pointers to nodes of two
 *  lists, and returns a single pointer to node of the merged list. */
struct Node *Merge(struct Node *first, struct Node *second);


/* Function to do merge sort the doubly linked list. Uses split and
 *  merge functions and returns the sorted list. */
struct Node *MergeSort(struct Node *head);

#endif //ASSIGNMENT3_MERGE_SORT_H
