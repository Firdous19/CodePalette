#include<stdio.h>
#include<stdlib.h>

/*Code for Node of Doubly Linked List*/
struct DLLNode
{
    struct DLLNode *prev;
    int info;
    struct DLLNode *next;
};

typedef struct DLLNode Node;

/*Insert new node at the beginning*/
Node *insert_at_beg(Node *head ,int data)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->info = data;
    temp->prev = NULL;
    temp->next = head;
    if(head)
        head->prev = temp;
    head = temp;
    return head;
}

/*Insert new node at the end*/
Node *insert_at_end(Node *head, int data)
{
    Node *p, *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->info = data;
    p = head;
    if(p)
    {
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
        temp->next = NULL;
        temp->prev = p;
    }
    else
        head = temp;
    return head;
}

/*Deleting node from the list*/
Node *del(Node *head, int data)
{
    Node *temp, *p;
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    /*only one node in the list*/
    if(head->next == NULL)
    {
        if(head->info == data)
        {
            temp = head;
            head = NULL;
            free(temp);
            return head;
        }
        else{
            printf("Element %d not found\n", data);
            return head;
        }
    }
    /*Deletion of first node*/
    if(head->info == data)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    /*Deletion in between*/
    temp = head->next;
    while(temp->next != NULL)
    {
        if(temp->info == data)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return head;
        }
        temp = temp->next;
    }

    /*Deletion of last node */
    if(temp->info == data)
    {
        temp->prev->next = NULL;
        free(temp);
        return head;
    }
    printf("Element %d not found\n", data);
    return head;
}

/*Reversing the elements in a linked list*/
Node *reversal(Node *head)
{
    Node *p1, *p2;
    p1 = head;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;

    while(p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    head = p1;
    return head;
}

/*Insert new node at the given position*/
Node *insert_at_any_pos(Node *head, int data, int pos)
{
    Node *temp, *p;
    int i;
    temp = (Node*)malloc(sizeof(Node));
    temp->info = data;
    if(pos == 1)
    {
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        temp->next->prev = head;
        return head;
    }
    p = head;
    for(i=1; i < pos - 1 && p != NULL; i++)
        p = p->next;
    if(p == NULL)
        printf("There are less than %d elements\n", pos);
    else
    {
        temp->next = p->next;
        temp->prev = p;
        temp->next->prev = temp;
        p->next = temp;
    }
    return head;
}

/*Insert new node after the given node in the list*/
Node *insert_after_given_node(Node *head, int data, int item)
{
    Node *temp, *p;
    temp = (Node*)malloc(sizeof(Node));
    temp->info = data;
    p = head;
    while(p != NULL)
    {
        if(p->info == item)
        {
            temp->prev = p;
            temp->next = p->next;
            if(p->next != NULL)
                p->next->prev = temp;
            p->next = temp;
            return head;
        }
        p = p->next;
    }
    printf("%d not present in the list\n\n", item);
    return head;
}

/*Traversal through the list*/
void display(Node *head)
{
    Node *p;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = head;
    printf("List is:\n");
    while(p != NULL)
    {
        printf("%d->", p->info);
        p = p->next;
    }
    printf("\n\n");
}

/*Count no. of nodes in the list*/
void count(Node *head)
{
    Node *p;
    int c = 0;
    p = head;
    while(p != NULL)
    {
        p = p->next;
        c++;
    }
    printf("Number of elements are: %d\n", c);
}

void search(Node *head, int item)
{
    Node *p = head;
    int pos = 1;
    while(p != NULL)
    {
        if(p->info == item)
        {
            printf("Item %d found at position %d\n", item, pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("Item %d not found in list\n", item);
}

int main()
{
    struct node *head = NULL;
    int choice, data, item,pos;

    while(1)
    {
        printf("1.Display the list\n");
        printf("2.Count nodes in list\n");
        printf("3.Search element in list\n");
        printf("4.Insert new node at the begining\n");
        printf("5.Insert new node at the end\n");
        printf("6.Insert new node after the given node\n");
        printf("7.Insert new node at any position\n");
        printf("8.Delete node\n");
        printf("9.Reverse the list\n");
        printf("10.Quit\n\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            count(head);
            break;
        case 3:
            printf("Enter the item to be searched:");
            scanf("%d", &item);
            search(head, item);
            break;
        case 4:
            printf("Enter data to be inserted:");
            scanf("%d", &data);
            head = insert_at_beg(head, data);
            break;
        case 5:
            printf("Enter data to be inserted:");
            scanf("%d", &data);
            head = insert_at_end(head, data);
            break;
        case 6:
            printf("Enter data to be inserted:");
            scanf("%d", &data);
            printf("Enter the node after which you want to insert:");
            scanf("%d", &item);
            head = insert_after_given_node(head, data, item);
            break;
        case 7:
            printf("Enter data to be inserted:");
            scanf("%d", &data);
            printf("Enter the position at which you want to insert:");
            scanf("%d", &pos);
            head = insert_at_any_pos(head, data, pos);
            break;
        case 8:
            printf("Enter the data you want to delete:");
            scanf("%d", &data);
            head = del(head, data);
            break;
        case 9:
            head = reversal(head);
            display(head);
            break;
        case 10:
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
