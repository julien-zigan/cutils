#include "treeutils.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


TNODE *newtnode(int value)
{
    TNODE *n = (TNODE *)malloc(sizeof(TNODE));
    if (n) {
        n->value = value;
        n->left = n->right = NULL;
    }
    return n;
}

TNODE *tinsert(TNODE *tree, TNODE *node)
{
    if (tree == NULL)
        return node;
    if (node->value < tree->value)
        tree->left = tinsert(tree->left, node);
    else 
        tree->right = tinsert(tree->right, node);
    return tree;
}

void inordertrav(TNODE *t)
{
    if (t->left) inordertrav(t->left);
    printf("%d\t", t->value);
    if (t->right) inordertrav(t->right);
}

int enque(QE **queue, TNODE *n) 
{
    QE *r = (QE *)malloc(sizeof(QE));
    if (r == NULL) {
        printf("malloc failed\n");
        return 0;
    }
    r->node = n;
    r->next = NULL;
    QE *p = *queue;
    if (p == NULL) {
        *queue = r;
    }
    else {
        while (p->next) p = p->next;
        p->next = r;
    }
    return 1;
}

QE *inorderenqueue(TNODE *t, QE **queue)
{
    if (t->left) inorderenqueue(t->left, queue);
    enque(queue, t);
    if (t->right) inorderenqueue(t->right, queue);
}

QE *deque4freeing(QE **queue) 
{
    QE *p = *queue;
    if (p != NULL) 
        *queue = p->next;
    return p;
}

int queuelength(QE *queue)
{
    int len = 0;
    while(queue) {
        len++;
        queue = queue->next;
    }
    return len;
}

TNODE *delete_leaf4freeing(TNODE **t, int value)
{
    TNODE *q = *t;
    if (q == NULL) return q;
    if (q->value == value && !q->left && !q->right) {
        *t = NULL;
        return q;
    }
    if (q->value == value && (q->left || q->right)) {
        printf("cannot delete: not empty\n");
        return NULL;
    }
    if (q->left) delete_leaf4freeing(&q->left, value);
    if (q->right) delete_leaf4freeing(&q->right, value);
}

void printlevel(TNODE *tree)
{
    int nodeCount;
    if (tree == NULL) return;
    QE *ptr = NULL;
    enque(&ptr, tree);
    nodeCount = queuelength(ptr);
    while (1) {
        nodeCount = queuelength(ptr);
        if (nodeCount == 0) break;
        while(nodeCount > 0) {
            QE *q = deque4freeing(&ptr);
            printf("%i ", q->node->value);
            if(q->node->left) enque(&ptr, q->node->left);
            if(q->node->right) enque(&ptr, q->node->right);
            nodeCount--;
        }
        puts("");
    }
}

/* FOR QUICK TESTING */
int main(void) 
{
    int vals[] = {6, 3, 7, 9, 1, 4, 2, 8, 0};
    TNODE *root = newtnode(5);
    QE *queue = NULL;
    int i;
    for (i = 0; i < 9; i++) {
        TNODE *n = newtnode(vals[i]);
        /*enque(&queue, n);*/
        /*printf("queuelength = %d\n", queuelength(queue));*/
        tinsert(root, n);
    }

    printlevel(root);

    /*i = 0;*/
    /**/
    /*QE *qptr = queue;*/
    /*while(qptr) {*/
    /*    printf("%d. node: %i -> ", ++i, qptr->node->value);*/
    /*    qptr = qptr->next;*/
    /*}*/
    /*puts("");*/
    /**/
    /**/
    /*QE *forFreeing = deque4freeing(&queue);*/
    /*printf("forFreeing->node->value: %i\n", forFreeing->node->value);*/
    /*free(forFreeing);    */
    /*forFreeing = deque4freeing(&queue);*/
    /*printf("forFreeing->node->value: %i\n", forFreeing->node->value);*/
    /*free(forFreeing);    */
    /*printf("Queue: %d\n", queue->node->value);*/
    /*inordertrav(root);*/
    /*puts("");*/
    /**/
    /*for (i = 0; i < 10; i++) {*/
    /*    printf("trying to delete %i...\n", i);*/
    /*    TNODE *del = delete_leaf4freeing(&root, i);*/
    /*    if (del) free(del);*/
    /*    inordertrav(root),*/
    /*    puts("");*/
    /* }*/
    return EXIT_SUCCESS;
}
