# **C - Stacks, Queues - LIFO, FIFO**

## **Monty 0.98 Interpreter**
---
 This is an interpreter for Monty ByteCode files, written in C. Monty is a scripting language that is first compiled into Monty byte codes and relies on a unique stack, with specific instructions to manipulate it.

 ### **Requirements**
 ---
 The interpreter follows the following requirements:

1. If the user does not give any file or more than one argument to the program, it will print the error message "USAGE: monty file", followed by a new line, and exit with the status EXIT_FAILURE.
   
2. If, for any reason, it’s not possible to open the file, the interpreter will print the error message "Error: Can't open file <file>", followed by a new line, and exit with the status EXIT_FAILURE, where <file> is the name of the file.

3. If the file contains an invalid instruction, the interpreter will print the error message "L<line_number>: unknown instruction", followed by a new line, and exit with the status EXIT_FAILURE, where <line_number> is the line number where the instruction appears.

4. Line numbers always start at 1.

5. The interpreter runs the bytecodes line by line and stops if either:
   * It executed properly every line of the file.
   * It finds an error in the file.
   * An error occurred.

6. If the interpreter can’t malloc anymore, it will print the error message "Error: malloc failed", followed by a new line, and exit with status EXIT_FAILURE.
   
7. The interpreter uses malloc and free and is not allowed to use any other function from man malloc (realloc, calloc, …).


### Avaliable Operations Commands
---
| **_Opcode_** 	| **_Description_**                                                                                                                                                                                  	|
|--------------	|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
|   **push**   	| Pushes an element to the stack. e.g (push 1 # pushes 1 into the stack)                                                                                                                             	|
|   **pall**   	| Prints all the values on the stack, starting from the to of the stack.                                                                                                                             	|
|   **pint**   	| Prints the value at the top of the stack.                                                                                                                                                          	|
|    **pop**   	| Removes the to element of the stack.                                                                                                                                                               	|
|   **swap**   	| Swaps the top to elements of the stack.                                                                                                                                                            	|
|    **add**   	| Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.                                                                               	|
|    **nop**   	| This opcode does not do anything.                                                                                                                                                                  	|
|    **sub**   	| Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.                                              	|
|    **div**   	| Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.                                                	|
|    **mul**   	| Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.                                             	|
|    **mod**   	| Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.                              	|
|     **#**    	| When the first non-space of a line is a # the line will be trated as a comment.                                                                                                                    	|
|   **pchar**  	| Prints the integer stored in the top of the stack as its ascii value representation.                                                                                                               	|
|   **pstr**   	| Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value. 	|
|   **rotl**   	| Rotates the top of the stack to the bottom of the stack.                                                                                                                                           	|
|   **rotr**   	| Rotates the bottom of the stack to the top of the stack.                                                                                                                                           	|
|   **stack**  	| This is the default behavior. Sets the format of the data into a stack (LIFO).                                                                                                                     	|
|   **queue**  	| Sets the format of the data into a queue (FIFO).                                                                                                                                                   	|


### **Usage**
---
To use the interpreter, run the following command:

```c
$ ./monty <file>
```
Where <file> is the path to the file containing Monty byte code.

### **File Description**
---
The project includes the following files:

1. opcodes1.c: contains functions:
   * _push: pushes an element to the stack.
   * _pall: prints ALL values on the stack, starting from the top of the stack.
   * _pint: prints SPECIFICALLY the value at the top of the stack, followed by a newline.
   * _pop: removes SPECIFICALLY the top element of the stack.
   * _swap: swaps SPECIFICALLY the top two elements of the stack.
2. opcodes2.c: contains functions:
   * _add: adds SPECIFICALLY the top two elements of the stack.
   * _nop: does nothing.
3. strtok.c: contains functions:
   * _ischar: checks if an element of a string is a char.
   * _strtok: emulates strtok and saves time.
4. monty.h: contains structures and function initialization.
5. main.c: contains functions:
   * free_vglo: frees variables inside vglo.
   * start_vglo: declares the variables inside global_t struct.
   * check_input: checks given input and determines if it exists.
   * main: monty code interpreter.
6. getopc.c: contains functions:
   * getopc: grabs the right opcode.
7. dlistfuncs.c: contains functions:
   * add_dnodeint_end: add a node at the end of the doubly link list.
   * add_dnodeint: adds a node at the beginning of a doubly link list.
   * free_dlistint: frees the doubly linked list.

### **Authors**
--- 

![GitHub Contributors Image](https://contrib.rocks/image?repo=RM92023/holbertonschool-low_level_programming)
Robinson Muñetón Jaramillo - <a href="https://github.com/RM92023" target="_blank"> @RM92023</a> ![Your Repository's Stats](https://github-readme-stats.vercel.app/api?username=RM92023&show_icons=true)
