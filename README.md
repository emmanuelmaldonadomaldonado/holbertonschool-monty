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

| opcode | description |
|----------|----------|
| push   | pushes an element onto the stack |
| pall   | Prints all values on the stack, starting from the top |
| pint   | Prints the value at the top of of the stack |
