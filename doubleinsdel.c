#include <stdio.h>
#include <stdlib.h>


/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;


/*
 * Function used in this program
 */
void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int position);

int main()
{
    int n, data, choice=1;

    head = NULL;
    last = NULL;

    /*
     * Run forever until user chooses 0
     */
    while(choice != 0)
    {
        /*
         * Menu creation to use the program
         */
        printf("============================================\n");
        printf("DOUBLY LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Insert node - at beginning\n");
        printf("3. Insert node - at end\n");
        printf("4. Insert node - at N\n");
        printf("5. Delete node - at N\n");
        printf("6. Display list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        /*
         * Choose from different menu operation
         */
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);

                createList(n);
                break;
            case 2:
                printf("Enter data of first node : ");
                scanf("%d", &data);

                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data of last node : ");
                scanf("%d", &data);

                insertAtEnd(data);
                break;
            case 4:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &data);

                insertAtN(data, n);
                break;
            case 5:
                printf("Enter the node position which you want to delete: ");
                scanf("%d", &n);
                deleteFromN(n);
                break;
            case 6:
                displayList();
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-6");
        }

        printf("\n\n\n\n\n");
    }

    return 0;
}


void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        /*
         * Create and link the head node
         */
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        /*
         * Create and link rest of the n-1 nodes
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode;          // Make new node as last/previous node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/**
 * Display content of the list from beginning to end
 */
void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}


void insertAtBeginning(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head; // Point to next node which is currently head
        newNode->prev = NULL; // Previous node of first node is NULL

        /* Link previous address field of head with newnode */
        head->prev = newNode;

        /* Make the new node as head node */
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}


void insertAtEnd(int data)
{
    struct node * newNode;

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}



void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;

    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next; // Connect new node with n+1th node
            newNode->prev = temp;          // Connect new node with n-1th node

            if(temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->prev = newNode;
            }
            /* Connect n-1th node with new node */
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
    void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; // Move head pointer to 2 node
        
        if (head != NULL)
            head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
}


/**
 * Delete or remove the last node of the doubly linked list
 */
void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;

        last = last->prev; // Move last pointer to 2nd last node
        
        if (last != NULL)
            last->next = NULL; // Remove link to of 2nd last node with last node

        free(toDelete);       // Delete the last node
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}


/**
 * Delete node from any position in the doubly linked list
 */
void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); // Delete the n node

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}
}
