/* SYSC 2006 Lab 10
   A module that implements a singly-linked list of integers. 
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

/*************************************************************
 * Functions presented in lectures.
 *************************************************************/

/* Parameter head points to the first node in a linked list, or is NULL
   if the linked list is empty. Insert a node containing the specified 
   integer value at the front of the linked list, and return a pointer to 
   the first node in the modified list.

   Terminate (via assert) if memory for the node cannot be allocated.
 */

/* Function to count occurrences of `target` in the list */

intnode_t *push(intnode_t *head, int value)
{
        intnode_t *p = malloc(sizeof(intnode_t));
    assert (p != NULL);
    p->value = value;
    p->next = head;
    return p;
}

/* Parameter head points to the first node in the list.
   Return the length of a linked list (0 if the linked list is empty). 
 */
int length(intnode_t *head)
{
    int count = 0;
    for (intnode_t *curr = head; curr != NULL; curr = curr->next) {
        count += 1;
    }
    return count;
}

/* Parameter head points to the first node in a linked list.
   Print the linked list, using the format:
       value1 -> value2 -> value3 -> ... -> last_value
 */
void print_list(intnode_t *head)
{
    if (head == NULL) {
        printf("empty list");
        return; 
    }

    intnode_t *curr;

    /* The loop prints a every node in the linked list except the last one,
       using the format "value -> ", where "->" represents the link from each node
       to the following node.

       Notice that the loop condition is:
           curr->next != NULL
       and not:
           curr != NULL

       During the last iteration, the value in the second-last node is
       printed, then curr is updated to point to the last node. The
       condition curr->next != NULL now evaluates to false, so the 
       loop exits, with curr pointing to the last node (which has  
       not yet been printed.) 
     */

    for (curr = head; curr->next != NULL; curr = curr->next) {
        printf("%d -> ", curr->value);
    }

    /* Print the last node. */
    printf("%d", curr->value);
}



/*****************************************************************
 * Solutions to New Exercises
 *****************************************************************/

// Exercise 1

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Count the number of nodes in the linked list that contain an integer
 * equal to target, and return that count.
 * 
 * Return 0 if the linked list is empty.
 */ 

int count(intnode_t *head, int target) {
    int count = 0;
    intnode_t *current = head;

    // Traverse the list and count occurrences of `target`
    while (current != NULL) {
        if (current->value == target) {
            count++;
        }
        current = current->next;
    }

    return count;
}

// Exercise 2

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the largest integer in the linked list.
 *
 * The function terminates (via assert) if the linked list is empty.
 */
int max_value(intnode_t *head) {
    // Assert that the list is not empty
    assert(head != NULL);

    // Initialize max with the value of the first node
    int max = head->value;

    // Traverse the linked list
    for (intnode_t *curr = head; curr != NULL; curr = curr->next) {
        if (curr->value > max) {
            max = curr->value; // Update max if current node's value is larger
        }
    }

    return max; // Return the maximum value found
}


// Exercise 3

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the index (position) of the first node that contains an 
 * integer equal to target. The first node is at index 0, the second node
 * is at index 1, etc.
 *
 * Return -1 if target is not in the linked list, or if the linked list
 * is empty.
 */
int value_index(intnode_t *head, int target)
{
    int index = 0; // Start with the first node's index

    // Traverse the linked list
    for (intnode_t *curr = head; curr != NULL; curr = curr->next) {
        if (curr->value == target) {
            return index; // Target found, return its index
        }
        index++; // Increment index for the next node
    }

    return -1; // Target not found or the list is empty
}


// Exercise 4

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Parameter other points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Extend the linked list pointed to by head so that it contains
 * copies of the values stored in the linked list pointed to by other.
 *
 * The function terminates (via assert) if the the linked list 
 * pointed to by head is empty.
 */
void extend(intnode_t *head, intnode_t *other)
{
    // Ensure the 'head' list is not empty
    assert(head != NULL);

    // Traverse to the end of the 'head' list
    intnode_t *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    // Traverse 'other' and copy its values to 'head'
    for (intnode_t *other_curr = other; other_curr != NULL; other_curr = other_curr->next) {
        intnode_t *new_node = malloc(sizeof(intnode_t));
        assert(new_node != NULL); // Ensure memory allocation succeeded
        new_node->value = other_curr->value;
        new_node->next = NULL;

        // Append the new node to the end of the 'head' list
        curr->next = new_node;
        curr = new_node;
    }
}

// Exercise 5

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * The function terminates (via assert) if the linked list is empty.
 *
 * Copy the value in the head node to the location pointed to by
 * parameter popped_value, delete the head node, and return a pointer
 * to the first node in the modified list.
 */
intnode_t *pop(intnode_t *head, int *popped_value)
{
    // Ensure the linked list is not empty
    assert(head != NULL);

    // Copy the value from the head node
    *popped_value = head->value;

    // Save the pointer to the next node
    intnode_t *next_node = head->next;

    // Free the memory for the head node
    free(head);

    // Return the pointer to the next node
    return next_node;
}

