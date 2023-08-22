#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"  /* Include the correct header file */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
   while (getline(&line, &len, file) != -1)
   {
    line_number++;

        char *opcode = strtok(line, " \t\n");
        if (opcode == NULL)
            continue;

        char *arg = strtok(NULL, " \t\n");

        if (strcmp(opcode, "push") == 0) {
            if (arg == NULL || !is_numeric(arg)) {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free_stack(&stack);
                fclose(file);
                free(line);
                exit(EXIT_FAILURE);
            }
            push(&stack, line_number, arg);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack, line_number);
        } /* Add more cases for other opcodes */

        free(line);
        line = NULL;
        len = 0;
    }

    free_stack(&stack);
    fclose(file);
    free(line);

    return 0;
}
