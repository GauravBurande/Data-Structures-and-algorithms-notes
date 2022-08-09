#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
    
struct node *top = NULL;



int isEmpty(struct node *top)
{
    if (top == NULL)
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

struct node *push(int x)
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

int pop()
{
    if (isEmpty((top)))
    {
        printf("Stack Underflow! The stack is empty.\n");
    }
    struct node *n = (top);
    (top) = (top)->next;
    int x = n->data;
    free(n);
    return x;
}

int peek( int position)
{
    struct node *ptr = top;
    for (int i = 0; (i < position-1 && ptr !=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("End of the linked list stack!\n");
        return -1;
    }
    return ptr->data;

}

void linkedListTraversal(struct node *ptr);

int main()
{
    top = push(23);
    top = push(72);
    top = push(64);
    top = push(45);

    linkedListTraversal(top);
    printf("the popped element is: %d\n", pop());
    linkedListTraversal(top);

    for (int i = 1; i <= 3; i++)
    {
        printf("the value at positon %d is: %d\n", i, peek(i));
    }
    

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
