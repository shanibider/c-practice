#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *getTail(struct node *head)
{
    struct node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail;
}

struct node *addToEmpty(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct node *addToBeg(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    head->prev = temp;
    return temp;
}

struct node *addToEnd(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    struct node *tp = head;
    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}

struct node *addAfterPos(struct node *head, int data, int position)
{

    struct node *tp = head;

    for (int i = 1; i < position; i++)
    {
        tp = tp->next;
        if (tp->next == NULL)
        {
            return addToEnd(head, data);
        }
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    struct node *tp2 = tp->next;

    tp->next = temp;
    tp2->prev = temp;
    temp->next = tp2;
    temp->prev = tp;

    return head;
}

struct node *deleteFirst(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    temp = NULL;
    return head;
}

struct node *deleteLast(struct node *head)
{
    struct node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    struct node *tail = temp->prev;

    tail->next = NULL;
    temp = NULL;
    free(temp);
    return head;
}

struct node *deleteAt(struct node *head, int pos)
{
    struct node *temp = head;

    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            return deleteLast(head);
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp = NULL;
    free(temp);
    return head;
}

struct node *createList(struct node *head)
{
    int numOfNodes;
    printf("How many nodes would you like to create? ");
    scanf("%d", &numOfNodes);
    if (numOfNodes == 0)
        return head;

    int nodeData;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Please enter data for node 1: ");
    scanf("%d", &nodeData);
    head = addToEmpty(head, nodeData);

    for (int i = 1; i < numOfNodes; i++)
    {
        printf("please enter data for node %d: ", (i + 1));
        scanf("%d", &nodeData);
        head = addToEnd(head, nodeData);
    }

    return head;
}

struct node *reverse(struct node *head)
{
    {
        struct node *ptr1 = head;
        struct node *ptr2 = ptr1->next;

        ptr1->next = NULL;
        ptr1->prev = ptr2;

        while (ptr2 != NULL)
        {
            ptr2->prev = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->prev;
        }

        return ptr1;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *ptr;
    // head = createList(head);
    head = addToEmpty(head, 45);
    head = addToBeg(head, 42);
    head = addToEnd(head, 69);
    head = addAfterPos(head, 1337, 2);
    head = addAfterPos(head, 60, 2);
    head = addAfterPos(head, 40, 5);
    head = addAfterPos(head, 20, 1);
    ptr = head;
    while (ptr != NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
    // head = deleteFirst(head);
    // head = deleteFirst(head);
    // head = deleteFirst(head);
    // head = deleteFirst(head);
    // head = deleteLast(head);
    // head = deleteLast(head);
    // head = deleteAt(head, 3);
    head = reverse(head);
    tail = getTail(head);
    ptr = head;
    printf("After: \n");
    while (ptr != NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("Tail: %d", tail->data);
    return 0;
}