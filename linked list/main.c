#include "stdio.h"
#include "linkedlist.h"

int main()
{
    node *root;
    root = NULL;
    node *curr = root;
    
    int i;
    for(i = 0; i < 50; ++i) {
        curr = appendlist(&root, i);
    }
    
    curr = findlist(root, 30);
    insertlist(&curr, 72);
    printlist(root);
    
    freelist(&root);
    
    return 0;
}