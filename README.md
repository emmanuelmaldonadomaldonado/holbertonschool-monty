# holbertonschool-monty

# Monty

Monty 0.98 is a versatile scripting language compiled into Monty byte codes, akin to Python. It operates on a distinctive stack, employing specific instructions for manipulation. The primary objective of this project is to develop an interpreter for Monty ByteCodes files.

# Monty Byte Code Files

Files housing Monty byte codes generally carry the .m extension. While the industry often adheres to this standard, it is not mandated by the language specification. Each line typically contains a single instruction, allowing any number of spaces before or after the opcode and its argument:

# Compile all files using the following form:

	gcc -Wall -Werror -Wextra -pedantic *.c -o monty
	To execute the program:

# To execute the program:

	./monty bytecode_file

# Opcode	Description

| Opcode | Description |
|----------|----------|
| push   | pushes an element onto the stack |
| pall   | Prints all values on the stack, starting from the top |
| pint   | Prints the value at the top of of the stack |
| pop    | Removes the top element of the stack |
| swap   | Swaps the top two elements of the stack |
| add    | Adds the top two elements of the stack, storing the result in the second node |
| nop    | No-operation; does not affect the stack |
| sub    | Subtracts the top element from the second top element, storing the result in the second node |
| div    | Divides the second top element by the top element, storing the result in the second node |
| mul    | Multiplies the top two elements, storing the result in the second node |
| mod    | Computes the remainder of the second top element divided by the top element |
| #      | Comment indicator; the line is treated as a comment |
| pchar  | Prints the ASCII representation of the integer at the top of the stack |
| pstr   | Prints the ASCII representation of integers in the stack until 0 or a non-ASCII value |
| rotl   | Rotates the top of the stack to the bottom |
| rotr   | Rotates the bottom of the stack to the top |
| stack  | Default behavior; sets the format of the data into a stack (LIFO) |
| queue  | Sets the format of the data into a queue (FIFO) |
