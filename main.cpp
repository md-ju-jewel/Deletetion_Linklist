/// ** In the name of ALLAH ** ///

#include <stdlib.h>
#include <stdio.h>

// Define the structure for a Node
struct Node
{
    int data;
    struct Node* next;
};

// Global pointers
struct Node *Head = NULL, *newnode, *temp, *prevnode;

// Function to create nodes
struct Node* createNode(int n)
{
    while (n--)
    {
        // Allocate memory for a new node
        newnode = (struct Node*)malloc(sizeof(struct Node));

        // Read the data for the new node
        scanf("%d", &newnode->data);

        // Set the next pointer of the new node to NULL
        newnode->next = NULL;

        if (Head == NULL)
        {
            // If the list is empty, initialize head and temp to the new node
            Head = temp = newnode;
        }
        else
        {
            // Append the new node to the end of the list
            temp->next = newnode;
            temp = newnode;
        }
    }

    return Head; // Return the head of the linked list
}

// Function to display the linked list
void display(struct Node* Head)
{
    struct Node* temp = Head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the beginning of the list
struct Node* delete_From_Beg(struct Node* Head)
{
    if (Head == NULL)
    {
        printf("The list is empty. Cannot delete from the beginning.\n");
        return NULL;
    }

    temp = Head;
    Head = Head->next;
    free(temp);
    return Head;
}

// Function to delete a node from the end of the list
struct Node* delete_From_End(struct Node* Head)
{
    if (Head == NULL)
    {
        printf("The list is empty. Cannot delete from the end.\n");
        return NULL;
    }

    temp = Head;

    // If the list has only one node
    if (temp->next == NULL)
    {
        free(temp);
        return NULL;
    }

    // Traverse to the second last node
    while (temp->next != NULL)
    {
        prevnode = temp;
        temp = temp->next;
    }

    // Remove the last node
    prevnode->next = NULL;
    free(temp);
    return Head;
}

// Function to delete a node from a specific position in the list
struct Node* delete_From_Position(struct Node* Head)
{
    if (Head == NULL)
    {
        printf("The list is empty. Cannot delete from the position.\n");
        return NULL;
    }

    temp = Head;

    // If the list has only one node
    if (temp->next == NULL)
    {
        free(temp);
        return NULL;
    }

    struct Node* nextnode;
    int position, i = 1;
    printf("Enter Position: ");
    scanf("%d", &position);

    // Traverse to the node before the specified position
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);

    return Head;
}

int main()
{
    struct Node* Head;
    Head = NULL; // Initialize the head pointer to NULL

    printf("How many nodes do you want to create? ");
    int n;
    scanf("%d", &n);

    // Create the linked list
    Head = createNode(n);

    // Display the linked list before deletion
    printf("Before Delete : ");
    display(Head);

    // Delete a node from the beginning
    Head = delete_From_Beg(Head);
    printf("After Deleting From Beginning: ");
    display(Head);

    // Delete a node from the end
    Head = delete_From_End(Head);
    printf("After Deleting From End: ");
    display(Head);

    // Delete a node from a specific position
    Head = delete_From_Position(Head);
    printf("After Deleting From Position: ");
    display(Head);

    return 0;
}
