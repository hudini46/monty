#include <stdbool.h>
#include <stddef.h>

/* Function to check if a string is numeric */
int is_numeric(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0; // Not numeric
    }

    for (const char *c = str; *c != '\0'; c++) {
        if (*c < '0' || *c > '9') {
            return 0; // Not numeric
        }
    }

    return 1; // Numeric
}
