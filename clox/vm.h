#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "table.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
    // Currently loaded chunk
    Chunk* chunk;
    // Instruction pointer
    uint8_t* ip;
    // Value stack
    Value stack[STACK_MAX];
    // Pointer to the next empty slot on the stack
    Value* stackTop;
    // Hashtable of all "interned" strings being used
    Table strings;
    // Head of the linked list of objects (for freeing all memory)
    Obj* objects;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif
