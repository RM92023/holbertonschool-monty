#include "monty.h"
/**
 * main - main function
 * 
 * Return: none
 */
int main(void)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        line_number++;

        /* Dividir la línea en comandos */
        char *opcode, *arg;
        opcode = strtok(line, " \n\t\r");
        arg = strtok(NULL, " \n\t\r");

        /* Ejecutar la operación */
        if (opcode != NULL)
        {
            if (strcmp(opcode, "push") == 0)
            {
                if (arg == NULL || !isdigit(*arg))
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
                push(&stack, atoi(arg));
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(stack);
            }
            else
            {
                /* Comando no reconocido */
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
    }

    /* Liberar memoria y salir */
    free(line);
    while (stack != NULL)
    {
        stack_t *tmp = stack;
        stack = stack->next;
        free(tmp);
    }
    exit(EXIT_SUCCESS);
}
