#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *top)
{
    if(top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow \n");
    }
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = top;
    top = n;
    return top;
}

int pop(struct node **top)
{
    if(isEmpty((*top)))
    {
        printf("Stack Underflow! The stack is empty.\n");
    }
    struct node *n  = (*top);
    (*top) = (*top)->next;
    int x = n->data;
    free(n);
    return x;   
}


void linkedListTraversal(struct node *ptr);

int main()
{
    struct node *top = NULL;
    top = push(top, 23);
    top = push(top, 72);
    top = push(top, 64);
    linkedListTraversal(top);

    int element = pop(&top);
    printf("popped element is %d\n", element);
    linkedListTraversal(top);

    return 0;
}

void linkedListTraversal(struct node *ptr)
{
    int index = 0;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", index, ptr->data);
        index++;
        ptr = ptr->next;
    }
}












