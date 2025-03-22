#ifndef __TREEUTILS_H__
#define __TREEUTILS_H__

typedef struct tnode{
    int value;
    struct tnode *left, *right;
} TNODE;

typedef struct qe{
    struct qe *next;
    TNODE *node;
} QE;

extern TNODE *newtnode(int value);
extern TNODE *tinsert(TNODE *tree, TNODE *node);
extern void inordertrav(TNODE *t);
extern int enque(QE **queue, TNODE *n);
extern QE *inorderenqueue(TNODE *t, QE **queue);
extern QE *deque4freeing(QE **queue);
extern int queuelength(QE *queue);
extern TNODE *delete_leaf4freeing(TNODE **t, int value);
extern void printlevel(TNODE *tree);

#endif
