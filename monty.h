#ifndef MONTY_H
#define MONTY_H

/* Definition of the stack_t struct */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number, char *arg);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
int is_numeric(const char *str);

#endif /* MONTY_H */

