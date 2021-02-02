/*
 * Filename: merge_sort.c
 * Author: Christoffel Doorman (10580557)
 * Language: C (version C11)
 * Purpose: This file contains the functions to merge sort a doubly linked list.
 */

#include "merge_sort.h"
#include "helpers.h"


// function to merge two linked lists
struct Node *Merge(struct Node *first, struct Node *second) {
    // if first linked list is empty
    if (!first)
        return second;

    // if second linked list is empty
    if (!second)
        return first;

    // if letters are the same, check next letter
    int letter = 0;
    while (first->name[letter] == second->name[letter])
        letter += 1;

    // check which list should come first
    if (first->name[letter] < second->name[letter]) {
        first->Next = Merge(first->Next,second);
        first->Next->Prev = first;
        first->Prev = NULL;
        return first;
    }
    else {
        second->Next = Merge(first,second->Next);
        second->Next->Prev = second;
        second->Prev = NULL;
        return second;
    }
}

// function to do merge sort
struct Node *MergeSort(struct Node *head) {
    if (!head || !head->Next)
        return head;
    struct Node *second = Split(head);

    // recur for left and right halves
    head = MergeSort(head);
    second = MergeSort(second);

    // merge the two sorted halves
    return Merge(head,second);
}


// split a doubly linked list into 2 of half sizes
struct Node *Split(struct Node *head) {
    struct Node *fast = head,*slow = head;
    while (fast->Next && fast->Next->Next) {
        fast = fast->Next->Next;
        slow = slow->Next;
    }
    struct Node *temp = slow->Next;
    slow->Next = NULL;
    return temp;
}