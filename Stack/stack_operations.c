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
    ptr->top--;
    return value;
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("stack has been created successfully!\n");

    printf("before pushing, Full: %d\n", isFull(sp));
    printf("before pushing, Empty: %d\n", isEmpty(sp));

    push(sp, 34);
    push(sp, 76);
    push(sp, 22);
    push(sp, 84);
    push(sp, 76);
    push(sp, 39);
    push(sp, 33);
    push(sp, 67);
    push(sp, 54);
    push(sp, 25);  // ----> pushed 10 values
    push(sp, 58); // ----> stack overflow since the size of the stack is 10

    printf("after pushing, Full: %d\n", isFull(sp));
    printf("after pushing, Empty: %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp)); // ----> last in first out!

    return 0;
}