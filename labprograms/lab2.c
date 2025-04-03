#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE *insert(NODE *first, int data)
{
    NODE *newnode, *temp, *prev = NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return first;
    }
    
    newnode->info = data;
    newnode->next = NULL;

    if (first == NULL || data < first->info)
    {
        newnode->next = first;
        first = newnode;
    }
    else
    {
        temp = first;
        while (temp != NULL && data > temp->info)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL || data != temp->info)
        {
            newnode->next = temp;
            prev->next = newnode;
        }
    }
    return first;
}

NODE *insert_end(NODE *first, int data)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return first;
    }
    
    newnode->info = data;
    newnode->next = NULL;

    if (first == NULL)
    {
        return newnode;
    }

    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;

    return first;
}

NODE *merge(NODE *l1, NODE *l2)
{
    NODE *l3 = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->info < l2->info)
        {
            l3 = insert_end(l3, l1->info);
            l1 = l1->next;
        }
        else if (l1->info > l2->info)
        {
            l3 = insert_end(l3, l2->info);
            l2 = l2->next;
        }
        else
        {
            l3 = insert_end(l3, l1->info);
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    while (l1 != NULL)
    {
        l3 = insert_end(l3, l1->info);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        l3 = insert_end(l3, l2->info);
        l2 = l2->next;
    }

    return l3;
}

void display(NODE *first)
{
    NODE *temp = first;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    NODE *l1 = NULL;
    NODE *l2 = NULL;
    NODE *l3 = NULL;

    l1 = insert(l1, 1);
    l1 = insert(l1, 2);
    l1 = insert(l1, 3);
    l1 = insert(l1, 4);
    l1 = insert(l1, 5);

    l2 = insert(l2, 1);
    l2 = insert(l2, 2);
    l2 = insert(l2, 3);
    l2 = insert(l2, 4);
    l2 = insert(l2, 5);

    l3 = merge(l1, l2);

    printf("Merged List: ");
    display(l3);

    return 0;
}
