#include "monty.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    if (monty_interpreter(argv[1]) == -1)
        exit(EXIT_FAILURE);

    exit(EXIT_SUCCESS);
}
