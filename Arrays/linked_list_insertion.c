#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
};

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

struct node *insertAfterNode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
};

struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
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

    // Terminate the list at the third node
    fourth->data = 77;
    fourth->next = NULL;

    printf("\n Linked list before insertion\n");
    printf("************************************************\n");
    linkedListTraversal(head);

    printf("\n Linked list after insertion\n");
    printf("************************************************\n");
    // head = insertAtFirst(head, 98);
    // head = insertAtIndex(head, 98, 2);
    // head = insertAtEnd(head, 98);
    head = insertAfterNode(head, third, 32);
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
