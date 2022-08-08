#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack.\n",value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack.\n");
        return -1;
    }
    int value = ptr->arr[ptr->top];
    ptr->top -= 1;

    return value;
}

int peek(struct stack *sp, int i)
{
    int index = sp->top-i+1;
    if (index<0)
    {
        printf("Invalid argument for the position of the element!\n");
        return -1;
    }
    
    return sp->arr[index];
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("stack has been created successfully!\n");

    push(sp, 34);
    push(sp, 76);
    push(sp, 22);
    push(sp, 84);
    push(sp, 76);
    push(sp, 39);
    push(sp, 33);
    push(sp, 67);
    push(sp, 54);
    push(sp, 25);
    push(sp, 58);
    push(sp, 99);
    
    // printing values inside the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
    printf("The element at position %d is %d\n", j, peek(sp,j));
    }

    // for (int i = sp->top; i >= 0; i--)
    // {
        // printf("The element at index %d is %d\n",sp->top, sp->arr[sp->top]);
        // sp->top--;
    // }
    

    return 0;
}