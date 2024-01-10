#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

int isEmpty(struct node *tail)
{
    if (tail == NULL)
        return 1;
    else
        return 0;
}

// struct node *addToEmpty(int data)
// {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->info = data;
//     temp->link = temp;
//     return temp;
// }

struct node *createSingly(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = temp;
    return temp;
}

struct node *insert_at_beg(struct node *tail, int data)
{
    struct node *temp;
    temp = createSingly(data);
    if (tail == NULL)
        tail = temp;
    else
    {
        temp->link = tail->link;
        tail->link = temp;
    }
    return tail;
}

struct node *insert_at_end(struct node *tail, int data)
{
    struct node *temp;
    temp = createSingly(data);
    if (tail == NULL)
        tail = temp;
    else
    {
        temp->link = tail->link;
        tail->link = temp;
        tail = temp;
    }
    return tail;
}

struct node *insert_at_any_pos(struct node *tail, int pos, int data)
{
    struct node *p = tail->link;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = NULL;

    while (pos > 1)
    {
        p = p->link;
        pos--;
    }
    temp->link = p->link;
    p->link = temp;
    if (p == tail)
        tail = tail->link;
    return tail;
}

void display(struct node *tail)
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        struct node *p;
        p = tail->link;
        do
        {
            printf("%d->", p->info);
            p = p->link;
        } while (p != tail->link);
    }
}

void count(struct node *tail)
{
    int count = 0;
    if (tail != NULL)
    {
        struct node *p = tail->link;
        while (p->link != tail->link)
        {
            p = p->link;
            count++;
        }
    }
    printf("There are %d no. of nodes inside the list", count);
}

void search(struct node *tail, int data)
{
    struct node *p;
    p = tail->link;

    int flag = 0;

    do
    {
        if (data == p->info)
        {
            flag = 1;
            break;
        }
    } while (p->link != tail->link);

    if (flag == 1)
    {
        printf("Elemnent found in the list\n");
    }
    else
    {
        printf("Element not found in the list\n");
    }
}

struct node *del(struct node *tail, int data)
{
    struct node *p = tail->link;
    int deleteHandler = 0;

    if (p->info == data)
    {
        tail->link = p->link;
        free(p);
        deleteHandler = 1;
    }

    else
    {
        do
        {
            struct node *temp;
            if (p->link->info == data)
            {
                temp = p->link;
                p->link = temp->link;
                free(temp);
                deleteHandler = 1;
            }
        } while (p->link != tail->link);
    }

    if (deleteHandler)
    {
        printf("Successfully deleted %d from the list", data);
        return tail;
    }
    else
    {
        printf("Element not found in the list\n");
        return tail;
    }
}

int main()
{
    struct node *tail = NULL;
    int data, choice, pos, item;

    while (1)
    {
        printf("1.Display the list\n");
        printf("2.Count nodes in list\n");
        printf("3.Search element in list\n");
        printf("4.Insert new node at the begining\n");
        printf("5.Insert new node at the end\n");
        printf("6.Insert new node after the given node\n");
        printf("7.Insert new node at any position\n");
        printf("8.Delete node\n");
        printf("9.Quit\n\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(tail);
            break;
        case 2:
            count(tail);
            break;
        case 3:
            printf("Enter the item to be searched:");
            scanf("%d", &item);
            search(tail, item);
            break;
        case 4:
            printf("Enter data to be inserted:");
            scanf("%d", &data);
            tail = insert_at_beg(tail, data);
            break;
        case 5:
            printf("Enter data to be inserted:");
            scanf("%d", &data);
            tail = insert_at_end(tail, data);
            break;
        // case 6:
        //     printf("Enter data to be inserted:");
        //     scanf("%d", &data);
        //     printf("Enter the node after which you want to insert:");
        //     scanf("%d", &item);
        //     tail = insert_after_given_node(tail, data, item);
        //     break;
        case 7:
            printf("Enter data to be inserted:");
            scanf("%d", &data);
            printf("Enter the position at which you want to insert:");
            scanf("%d", &pos);
            tail = insert_at_any_pos(tail, data, pos);
            break;
        case 8:
            printf("Enter data you want to delete:");
            scanf("%d", &data);
            tail = del(tail, data);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Wrong choice!!!\n");
        }
        fflush(stdin);
        printf("\n\n PRESS any key to Continue...\n");
        getc(stdin);
    }
    return 0;
}