#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef enum {
  INST_PUSH,
  INST_POP, 
  INST_ADD,
  INST_SUB,
  INST_MUL,
  INST_DIV,
  INST_PRINT,
} Inst_Set;

typedef struct {
  Inst_Set type;
  int value;
} Inst;

Inst program[] = {
  {.type = INST_PUSH, .value = 15},
  {.type = INST_PUSH, .value = 20},
  {.type = INST_PUSH, .value = 25},
  {.type = INST_PUSH, .value = 30},
};

#define PROGRAM_SIZE (sizeof(program)/sizeof(program[0]))
#define MAX_STACK_SIZE 1024
int stack[MAX_STACK_SIZE];
int stack_size = 0;

void push(int value) {

  if(stack_size >= MAX_STACK_SIZE) {
    fprintf(stderr, "ERROR: stack overflow\n");
    exit(1);
  }

  stack[stack_size] = value;
  stack_size++;
}

int pop() {

  if(stack_size <= 0) {
    fprintf(stderr, "ERROR: stack underflow\n");
    exit(1);
  }

  return stack[stack_size--];
}

void print_stack() {
  for(int i = stack_size - 1; i >= 0; i--) {
    printf("%d\n",stack[i]);
  }
}

int main(int argc, char** argv) {

int a,b;
  for(size_t i = 0; i < PROGRAM_SIZE; i++) {
    switch(program[i].type) {
      case INST_PUSH:
        push(program[i].value);
        break;
      case INST_POP:
        pop();
        break;
      case INST_ADD:
        a = pop();
        b = pop();
        push(a+b);
        break;
      case INST_SUB:
        a = pop();
        b = pop();
        push(b-a);
        break;
      case INST_MUL:
        a = pop();
        b = pop();
        push(a*b);
        break;
      case INST_DIV:
        a = pop();
        b = pop();
        push(b/a);
        break;
      case INST_PRINT:
        printf("%d\n",pop());      
        break;
    }
  }
  print_stack();

  // if(argc < 2) {
  //   printf("Usage: ./build/ptvm <filename> \n");
  //   exit(1);
  // }
  printf("Build: %s\n",argv[0]); 
  printf("File: %s\n", argv[1]);
  return 0;
}
