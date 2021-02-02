/*
 * Filename: inserts.c
 * Author: Christoffel Doorman (10580557)
 * Language: C (version C11)
 * Purpose: This file contains the functions that do operations on the
 *  doubly linked list such as inserting and deleting elements, and measure
 *  the time it takes to insert an element at a random place.
 */

#include "inserts.h"
#include "helpers.h"


void InsertNodeEnd(struct Node** head_ref, char *name) {
    struct Node *old_head = *head_ref;

    // make a new node
    LinkedList = (struct Node *) calloc(1, sizeof(struct Node));
    strcpy(LinkedList->name, name);
    LinkedList->Next = NULL;

    // if the Linked List is empty, then make the new node as head
    if (*head_ref == NULL) {
        LinkedList->Prev = NULL;
        *head_ref = LinkedList;
        return;
    }

    // else traverse till the last node
    while (old_head->Next != NULL)
        old_head = old_head->Next;

    // change the next of last node
    old_head->Next = LinkedList;

    // make last node as previous of new node
    LinkedList->Prev = old_head;

    return;
}


// function to insert node at the middle of the linked list
void InsertAtMid(struct Node** head_ref, char *name) {

    // make a new node
    LinkedList = (struct Node *) calloc(1, sizeof(struct Node));
    strcpy(LinkedList->name, name);
    struct Node* old_head = *head_ref;

    // find length of list
    int len;
    len = FindSize(old_head);

    // 'count' the number of nodes after which the new node is to be inserted
    int count = ((len % 2) == 0) ? (len / 2) : (len + 1) / 2;

    // 'ptr' points to the node after which the new node is to be inserted
    while (count-- > 1)
        old_head = old_head->Next;

    // insert the 'newNode' and adjust the required links
    LinkedList->Next = old_head->Next;
    old_head->Next = LinkedList;

    // make old_head as previous of LinkedList
    LinkedList->Prev = old_head;

    // change previous of LinkedList's next node
    if (LinkedList->Next != NULL)
        LinkedList->Next->Prev = LinkedList;
}


// function to insert node at a certain position of the linked list
void InsertAtPosition(struct Node** head_ref, int position, char *name, int list_length) {

    // make a new node
    LinkedList = (struct Node *) calloc(1, sizeof(struct Node));
    strcpy(LinkedList->name, name);
    struct Node* ptr = *head_ref;

    // check if position fits in list length
    if (position > list_length) {
        printf("List is shorter than this position");
        return;
    }

    // 'ptr' points to the node after which the new node is to be inserted
    ptr = *head_ref;
    while (position-- > 1)
        ptr = ptr->Next;

    // insert the 'newNode' and adjust the required links
    LinkedList->Next = ptr->Next;
    ptr->Next = LinkedList;

    // make old_head as previous of LinkedList
    LinkedList->Prev = ptr;

    // change previous of LinkedList's next node
    if (LinkedList->Next != NULL)
        LinkedList->Next->Prev = LinkedList;
}


// delete node at given position
void DeleteNode(struct Node** head_ref, int position)
{
    // if list in NULL or invalid position is given
    if (*head_ref == NULL || position <= 0)
        return;

    struct Node* current = *head_ref;

    // traverse up to the node at position from the beginning
    for (int i=1; current != NULL && i < position; i++)
        current = current->Next;

    // if 'n' is greater than the number of node in the doubly linked list
    if (current == NULL)
        return;

    // delete the node pointed to by 'current'
    DeleteNode(head_ref, current);
}

// measure time to insert at random location
void InsertTime(struct Node** head, int list_length, int strlen) {

    // measure time 2000 times to take average
    double sum_time = 0;
    for (int k=0; k<2000; k++) {
        int r = rand() % list_length; // choose random position to insert

        // measure time to
        clock_t begin = clock();
        InsertAtPosition(head, r, RandomString(strlen), list_length);
        clock_t end = clock();
        double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
        sum_time += time_spent;

        // delete node
        DeleteNode(head, r);
    }
    // print average time
    printf("Average time to insert at list of length %d is: %lf\n", list_length, sum_time/2000.0);
}