#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, unsigned int line_number, char *arg)
{
    /* Check if the argument is an integer */
    char *endptr;
    int value = strtol(arg, &endptr, 10);

    if (*endptr != '\0' && *endptr != '\n')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

