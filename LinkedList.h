/*
 Daniel Cancelmo
 CSC 173 - Computation & Formal Systems
 Prof. Ferguson
 I attest that all work herein is my own and I did not collaborate with anyone.
 */

#ifndef LinkedList_h
#define LinkedList_h

struct employee {
    char* name;
    int* numID;
};

struct node {
    int value;
    struct node* next;
};

typedef int Boolean;
#define true 1;
#define false 0;

struct node* newList(int val);
void insert(int val, struct node* headNode);
struct node* deleteNode(int val, struct node* headNode);
Boolean lookup(int val, struct node* headNode);
void printList(struct node* headNode);

#endif /* LinkedList_h */
