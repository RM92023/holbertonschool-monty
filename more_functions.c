#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    /* validate that there are at least two elements in the stack */
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = *stack;
    temp->next = *stack;
    temp->prev = NULL;
    (*stack)->prev = temp;
    *stack = temp;
}

