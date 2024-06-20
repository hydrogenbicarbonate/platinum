
---

# Stack-Based Virtual Machine Interpreter

This project implements a simple stack-based virtual machine interpreter in C. The interpreter executes a predefined set of instructions stored in bytecode format and manipulates a stack to perform arithmetic operations and control flow.

## Features

- **Arithmetic Operations**: Addition, subtraction, multiplication, and division operations are supported.
- **Comparison Operations**: Comparison operations (`CMPE`, `CMPNE`, `CMPG`, `CMPL`) for equality, inequality, greater than, and less than comparisons.
- **Control Flow**: Conditional (`CJMP`) and unconditional (`JMP`) jumps enable branching within the program.
- **Input/Output**: Basic input and output operations (`PRINT`) to interact with the user.

## Instructions Set

The virtual machine supports the following instructions:

- **INST_PUSH**: Pushes a value onto the stack.
- **INST_POP**: Pops a value from the stack.
- **INST_DUP**: Duplicates the top value on the stack.
- **INST_SWAP**: Swaps the top two values on the stack.
- **INST_ADD, INST_SUB, INST_MUL, INST_DIV**: Performs addition, subtraction, multiplication, and division respectively.
- **INST_CMPE, INST_CMPNE, INST_CMPG, INST_CMPL**: Performs comparisons for equality, inequality, greater than, and less than respectively.
- **INST_CJMP**: Conditional jump based on the top value of the stack.
- **INST_JMP**: Unconditional jump to a specified instruction.
- **INST_PRINT**: Prints the top value of the stack.

## Usage

### Building the Interpreter

Compile the interpreter using any C compiler:

```bash
gcc src/ptvm.c -o build/ptvm -Wall -Wextra
```

### Running Programs

1. Define your program in bytecode format using the `program` array.
2. Modify the `main` function to execute your program or load it from a file.
3. Execute the interpreter:

```bash
./build/ptvm
```

### Example Program

An example program is provided in the `program` array within `main.c`. It calculates the sum of 1 and 2, then prints the result:

```c
Inst program[] = {
    DEF_INST_PUSH(1),
    DEF_INST_PUSH(1),
    DEF_INST_CMPE(),
    DEF_INST_CJMP(7),
    DEF_INST_PUSH(2),
    DEF_INST_ADD(),
    DEF_INST_PUSH(4),
    DEF_INST_PRINT(),
};
```

## Files

- **ptvm.c**: Contains the main logic for the virtual machine interpreter.
- **Makefile**: Simplifies the build process for the interpreter.
- **README.md**: This file, providing an overview and usage instructions.

## Error Handling

The interpreter includes basic error handling for stack underflow, stack overflow, division by zero, and out-of-bounds jumps.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments

- Inspired by stack-based virtual machines in programming languages.
- Developed as an educational project to understand virtual machines and interpreters.

---

