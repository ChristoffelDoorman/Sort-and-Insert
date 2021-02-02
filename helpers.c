/*
 * Filename: helpers.c
 * Author: Christoffel Doorman (10580557)
 * Language: C (version C11)
 * Purpose: This file contains the functions that are used throughout the program.
 */

#include "helpers.h"

// returns a string of random alphabets of length
char* RandomString(unsigned length) {

    char* string;
    string = (char *)malloc(sizeof(char)*length);

    // create random string
    for (int i = 0; i < length; i++)
        string[i] = rand() % 26 + 'a';

    // terminate string
    string[length] = '\0';

    return string;
}

// this function returns size of linked list
int FindSize(struct Node *node) {
    int len = 0;
    while (node != NULL) {
        len++;
        node = node->Next;
    }
    return len;
}

// this function prints the linked list
void PrintList(struct Node* temp) {
    int nr=0; // node number
    while(temp) { // while pointer points to next node
        printf("Node number: %d. Name: %s\n",nr++,temp->name);
        temp=temp->Next;
    }
}


