/*
 * Filename: helpers.h
 * Author: Christoffel Doorman (10580557)
 * Language: C (version C11)
 * Purpose: This file contains the function declarations of the
 *  functions that are used throughout the program and contains
 *  the data structure of a node. It also decleares the LinkedList.
 */

#ifndef ASSIGNMENT3_HELPERS_H
#define ASSIGNMENT3_HELPERS_H

#include <stdlib.h>
#include <stdio.h>

/* Data structure of the node */
struct Node
{
    char name[256];    // the name of the node
    struct Node *Prev; // pointer to the previous node
    struct Node *Next; // pointer to the next node
};

extern struct Node *LinkedList; // make a global linked list

/* Function that prints the doubly linked list */
void PrintList(struct Node* temp);

/* Function that creates a random string. The argument of
 *  the function denotes the length of the random string. */
char* RandomString(unsigned length);

/* Function that takes the node to the linked list and
 *  returns the size of the linked list. */
int FindSize(struct Node *node);

#endif //ASSIGNMENT3_HELPERS_H
