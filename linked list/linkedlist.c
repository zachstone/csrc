#include "linkedlist.h"

#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int val;
    struct node *link;
} node;

node* appendlist(node **root, int val)
{
    node *new = malloc(sizeof(node));
    new->val = val;
    new->link = NULL;
    if(*root) {
        node *temp;
        temp = *root;
        while(temp->link) temp = temp->link;
        temp->link = new;
    } else *root = new;
    return new;
}

void _freelist(node **curr)
{
    if((*curr)->link) {
        _freelist(&((*curr)->link));
    }
    free(*curr);
}

void freelist(node **root)
{
    if(root) {
        _freelist(root);
    }
}

node* insertlist(node **curr, int val)
{
    node *new = malloc(sizeof(node));
    new->val = val;
    new->link = (*curr)->link;
    (*curr)->link = new;
    return *curr;
}

node* findlist(node *root, int val)
{
    if(root) {
        node *temp;
        temp = root;
        while(temp) {
            if(temp->val == val) return temp;
            temp = temp->link;
        }
    } else return NULL;
}

void printlist(node *root)
{
    if(root) {
        node *temp;
        temp = root;
        while(temp) {
            printf("%d\n", temp->val);
            temp = temp->link;
        }
    } else printf("list is empty\n");
}