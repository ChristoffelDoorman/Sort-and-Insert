/*
 * Filename: linked_list.c
 * Author: Christoffel Doorman (10580557)
 * Language: C (version C11)
 * Purpose: This file contains the main function which creates a
 *  doubly linked list of random strings and sorts them alphabetically.
 *  Also, it tests three insert-functions and measures the time complexity
 *  of inserting at a random place in the doubly linked list.
 */


#include <time.h>
#include "helpers.h"
#include "merge_sort.h"
#include "inserts.h"

#define STRLEN 5 // set the length of random strings

// the start (head) of the linked list
struct Node *LinkedList=NULL;


int main(void) {

  // start with the empty list
  struct Node* head = NULL;

  // seed number for rand()
  srand((unsigned int) time(0));

  // set the length of the random list
  int list_length = 500;

  // add random strings to list
  for (int i=0; i<list_length; i++) {
    InsertNodeEnd(&head, RandomString(STRLEN));
  }

  // sort list on alphabetic order
  head = MergeSort(head);

  // insert strings at end, mid and position 498
  InsertNodeEnd(&head, "LAST NODE");
  InsertAtMid(&head, "MID OF THE LIST");
  InsertAtPosition(&head, 498, "POSITION 498", list_length);

  // print out linked list
  PrintList(head);

  // calculate time to insert string at random position for 5 list lengths
  InsertTime(&head, list_length, STRLEN);
  for (int i=0; i<5; i++) {

    // increase list with 1000 random strings
    for (int j=0; j<1000; j++)
      InsertNodeEnd(&head, RandomString(STRLEN));

    // measure time to insert and update list_length
    list_length += 1000;
    InsertTime(&head, list_length, STRLEN);
  }

  return 0;
}