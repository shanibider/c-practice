#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree
{
    struct tree *left;
    struct tree *right;
    int value;
} tree;

void printtabs(int t)
{
    for (int i = t; i < t * 2; i++)
        printf("\t");
}

tree *createNode(int val)
{
    tree *t = malloc(sizeof(struct tree));
    t->value = val;
    t->left = NULL;
    t->right = NULL;
}

void printTreeRec(tree *t, int level)
{
    if (t == NULL)
    {
        printtabs(level);
        printf("{EMPTY}\n");
        return;
    }
    printtabs(level);
    printf("Value: %d\n", t->value);
    printtabs(level);
    printf("Left:");
    printTreeRec(t->left, level + 1);
    printtabs(level);
    printf("Right:");
    printTreeRec(t->right, level + 1);
    printtabs(level);
    printf("Done\n");
}

void printTree(tree *t)
{
    printTreeRec(t, 0);
}

void insertNumber(tree **t, int value)
{
    tree *tptr = *t;
    if (tptr == NULL)
    {
        *t = createNode(value);
        return;
    }

    if (value == tptr->value)
        return;

    if (value < tptr->value)
    {
        insertNumber(&tptr->left, value);
    }
    else
    {
        insertNumber(&tptr->right, value);
    }
}

bool findNumber(tree **t, int val)
{
    tree *tptr = *t;

    if (tptr == NULL)
    {
        return false;
    }

    if (val == tptr->value)
        return true;

    else if (val < tptr->value)
    {
        return findNumber(&tptr->left, val);
    }
    else
        return findNumber(&tptr->right, val);
}

int main()
{
    tree *root = NULL;
    insertNumber(&root, 5);
    insertNumber(&root, 5);
    insertNumber(&root, 2);
    insertNumber(&root, 15);
    insertNumber(&root, 12);

    printTree(root);

    printf("The number 5 exists: %d\n", findNumber(&root, 5));
    printf("The number 7 exists: %d\n", findNumber(&root, 7));
    // tree *node1 = createNode(1);
    // tree *node2 = createNode(2);
    // tree *node3 = createNode(3);
    // tree *node4 = createNode(4);

    // root->left = node1;
    // root->right = node2;
    // node2->left = node3;
    // node2->right = node4;
}