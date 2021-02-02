/*
 * Filename: inserts.h
 * Author: Christoffel Doorman (10580557)
 * Language: C (version C11)
 * Purpose: This file contains the function declarations that do operations on the
 *  doubly linked list such as inserting and deleting elements, and measure
 *  the time it takes to insert an element at a random place.
 */

#ifndef ASSIGNMENT3_INSERTS_H
#define ASSIGNMENT3_INSERTS_H

#include <string.h>
#include <stdlib.h>
#include <time.h>

extern struct Node** head_ref;

/* Function inserts a new node at the end of the doubly linked list */
void InsertNodeEnd(struct Node** head_ref, char *name);

/* Function inserts a new node at the middle of the doubly linked list */
void InsertAtMid(struct Node** head_ref, char *name);

/* Function inserts a new node at a given position of the doubly linked list.
 *  In addition to the usual arguments, this function takes the position and
 *  the length of the list as an argument. */
void InsertAtPosition(struct Node** head_ref, int position, char *name, int list_length);

/* Function that deletes a node at a given position */
void DeleteNode(struct Node** head_ref, int position);

/* Function that measures the time average time of the InsertAtPosition function
 *  for a given list of list length list_length. */
void InsertTime(struct Node** head, int list_length, int strlen);

#endif //ASSIGNMENT3_INSERTS_H
