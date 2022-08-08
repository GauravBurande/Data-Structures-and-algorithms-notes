#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr);

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

    // Terminate the list at the fourth node
    fourth->data = 77;
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;
}

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elemenet: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
