/*
 Daniel Cancelmo
 CSC 173 - Computation & Formal Systems
 Prof. Ferguson
 I attest that all work herein is my own and I did not collaborate with anyone.
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//Creates a new list with the head having the given val
struct node* newList(int val) {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->value = val;
    head->next = NULL;
    return head;
}

//Creates a new list with the head having NO VALUE
struct node* newListE() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->value = NULL;
    head->next = NULL;
    return head;
}

//Frees the list and all its content from memory
void destoryList(struct node* headNode) {
    if (headNode->next != NULL) {
        destoryList(headNode->next);
    }
    free(headNode->value);
    free(headNode);
}

//Inserts to the end of the list
void insert(int val, struct node* headNode) {
    //Recurses through looking for end of list, when found inserts it
    if (headNode->next == NULL) {
        headNode->next = (struct node*)malloc(sizeof(struct node));
        headNode->next->value = val;
        headNode->next->next = NULL;
    } else {
        insert(val, headNode->next);
    }
}

//Inserts item to start of list
void prepend(int val, struct node* headNode) {
    if (headNode->value == NULL) {
        headNode->value = val;
        return;
    } else {
        struct node* newList = newListE();
        insert(val, newList);
        for (; headNode != NULL; headNode = headNode->next) {
            insert(headNode->symbols, newList);
        }
        headNode = newList;
    }
}

//Searches for and deltes the node with the given val
struct node* deleteNode(int val, struct node* headNode) {
    //If list empty or val not in list, do nothing
    if (headNode == NULL || headNode->next == NULL) return NULL;
    //If head of list is to be deleted
    if (val == headNode->value) {
        struct node* temp = headNode;
        headNode = headNode->next;
        free(temp);
        return headNode;
    }
    //Recurses through looking for node with right val, when found deletes it
    if (val == headNode->next->value) {
        struct node* temp = headNode->next;
        headNode->next = headNode->next->next;
        free(temp);
    } else {
        deleteNode(val, headNode->next);
    }
    return headNode;
}

//Searches for val in the list. Returnes true if in list
Boolean lookup(int val, struct node* headNode) {
    while (headNode != NULL) {
        if (headNode->value == val) {
            return true;
        }
        headNode = headNode->next;
    }
    return false;
}

//Prints the values of the list
void printList(struct node* headNode) {
    while (headNode != NULL) {
        printf("%d\t", headNode->value);
        headNode = headNode->next;
    }
    printf("\n");
}
