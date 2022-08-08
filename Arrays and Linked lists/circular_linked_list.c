#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertHead(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }
    
    // now the p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

void linkedListTraversal(struct node *head);

int main()
{
    // Creating nodes
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate memory in for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first node to second
    head->data = 7;
    head->next = second;

    // Link second node to third
    second->data = 11;
    second->next = third;

    // Link third node to fourth
    third->data = 66;
    third->next = fourth;

    // Link fourth node to the head
    fourth->data = 77;
    fourth->next = head;

    printf("\n Circular linked list before insertion\n");
    printf("************************************************\n");
    linkedListTraversal(head);
    
    head = insertHead(head,69);

    printf("\n Circular linked list after insertion\n");
    printf("************************************************\n");
    linkedListTraversal(head);

    return 0;
}

void linkedListTraversal(struct node *head)
{
    struct node *ptr = head;

    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    

    // printf("Element is %i\n", ptr->data);
    // ptr = ptr->next;

    // while (ptr != head)
    // {
        // printf("Element is %i\n", ptr->data);
        // ptr = ptr->next;
    // }
}
