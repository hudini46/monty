#include<stdlib.h>
#include "monty.h"
#include <stdio.h>

/**
 * pall - Print all elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; /* Unused parameter */

    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * free_stack - Free the stack memory.
 * @stack: A pointer to the stack.
 */
void free_stack(stack_t **stack)
{
    while (*stack != NULL)
    {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

