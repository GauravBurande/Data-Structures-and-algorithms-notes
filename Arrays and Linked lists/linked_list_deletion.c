#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// case 1: Deleting the first element of the linked list
struct node *deleteHead(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
};

// case 2: Deleting an element at an Index of the linked list
struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;

    // if (index = 0)
    // {
    // head = head->next;
    // free(p);
    // }
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    struct node *q = p->next;
    p->next = q->next;
    free(q);

    return head;
}

// case 3: Deleting an element after a node of the linked list
void deleteAfterNode(struct node *prevNode)
{
    struct node *p = prevNode->next;
    prevNode->next = p->next;
    free(p);
}

// case 4: Deleting the last element of the linked list
void deleteEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}

// case 5: Deleting the first found element of the linked list by it's value
struct node *deleteValue(struct node *head, int value)
{
    struct node *p = head;

    // if (head->data == value)
    // {
    // head = head->next;
    // free(p);
    // }

    struct node *q = p->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

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

    printf("\n Linked list before deletion\n");
    printf("************************************************\n");
    linkedListTraversal(head);

    // head = deleteHead(head);
    // head = deleteAtIndex(head, 2);
    // deleteAfterNode(second);
    // deleteEnd(head);
    head = deleteValue(head, 77);

    printf("\n Linked list after deletion\n");
    printf("************************************************\n");
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
