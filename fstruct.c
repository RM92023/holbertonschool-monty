#include "monty.h"
/**
 * monty_interpreter - Interpreter for themonty functions
 *
 * @filename: The name of the file to be modified
 *
 * Return: The modified file name for the function
 */

int monty_interpreter(char *filename)
{
FILE *file;
char *line = NULL;
size_t len = 0;
ssize_t read;
stack_t *stack = NULL;
unsigned int line_number = 1;

file = fopen(filename, "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (-1);
}

while ((read = getline(&line, &len, file)) != -1)
{
/* Verificar si la línea está en blanco o solo tiene espacios*/
if (strspn(line, " \t\n") == (size_t)read)
{
line_number++;
continue;
}
char *token = strtok(line, " \n\t");
if (token != NULL && strcmp(token, "push") == 0)
{
token = strtok(NULL, " \n\t");
if (token != NULL &&
((isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) &&
strspn(token, "-0123456789") == strlen(token))
)
push(&stack, atoi(token));
else
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free(line);
fclose(file);
free_stack(&stack);
return (-1);
}
}
else if (token != NULL && strcmp(token, "pall") == 0)
pall(stack);
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
free(line);
fclose(file);
free_stack(&stack);
return (-1);
}
line_number++;
}
free(line);
fclose(file);
free_stack(&stack);
return (0);
}
