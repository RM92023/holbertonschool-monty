#include "monty.h"

/**
 * read_lines - reads each line of a file
 *
 * @file: Pointer to the file to be read
 * @stack: Pointer to the stack structure
 *
 * Return: 0 if successful, -1 otherwise
 */
int read_lines(FILE *file, stack_t **stack)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
unsigned int line_number = 1;
while ((read = getline(&line, &len, file)) != -1)
{
/* Verificar si la línea está en blanco o solo tiene espacios*/
if (strspn(line, " \t\n") == (size_t)read)
{
line_number++;
continue;
}
int status = interpret_line(line, stack, line_number);
if (status == -1)
{
free(line);
return (-1);
}
line_number++;
}
free(line);
return (0);
}

/**
 * interpret_line - interprets a single line of the file
 *
 * @line: The line to be interpreted
 * @stack: Pointer to the stack structure
 * @line_number: The line number being interpreted
 *
 * Return: 0 if successful, -1 otherwise
 */
int interpret_line(char *line, stack_t **stack, unsigned int line_number)
{
char *token = strtok(line, " \n\t");
if (token != NULL && strcmp(token, "push") == 0)
{
token = strtok(NULL, " \n\t");
if (token != NULL &&
((isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) &&
strspn(token, "-0123456789") == strlen(token))
)
push(stack, atoi(token));
else
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
return (-1);
}
}
else if (token != NULL && strcmp(token, "pall") == 0)
pall(*stack);
else if (token != NULL && strcmp(token, "pint") == 0)
pint(*stack);
else if (token != NULL && strcmp(token, "pop") == 0)
pop(stack, line_number);
else if (token != NULL && strcmp(token, "swap") == 0)
swap(stack, line_number);
else if (token != NULL && strcmp(token, "add") == 0)
add(stack, line_number);
else if (token != NULL && strcmp(token, "nop") == 0)
;/* Do nothing */
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
return (-1);
}
return (0);
}



/**
 * monty_interpreter - Interpreter for themonty functions
 *
 * @filename: The name of the file to be modified
 *
 * Return: The modified file name for the function
 */
int monty_interpreter(char *filename)
{
/* Declare a FILE pointer and a stack */
FILE *file;
stack_t *stack = NULL;
/* Open the file in read mode */
file = fopen(filename, "r");
if (file == NULL)
{
/* Print an error message and return -1 if the file can't be opened */
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (-1);
}
/* Read the lines in the file and execute the corresponding instruction */
if (read_lines(file, &stack) == -1)
{
/* If an error occurs during the reading of the file, close the file,*/
/*free the stack and return -1 */
fclose(file);
free_stack(&stack);
return (-1);
}
/* Close the file, free the stack and return 0 */
fclose(file);
free_stack(&stack);
return (0);
}
