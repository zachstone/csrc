#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node node;
node* appendlist(node **root, int val);
void _freelist(node **curr);
void freelist(node **root);
node* insertlist(node **curr, int val);
node* findlist(node *root, int val);
void printlist(node *root);

#endif