#ifndef clox_vm_h
#define clox_vm_h

#include "object.h"
#include "table.h"
#include "value.h"

// Max function call stack depth
#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct {
    // Pointer back to the function closure this is associated with
    ObjClosure* closure;
    // Next bytecode instruction to execute in this function’s chunk
    uint8_t* ip;
    // Base pointer into the VM's value stack for this call frame
    Value* slots;
} CallFrame;

typedef struct {
    // Stack of call frames
    CallFrame frames[FRAMES_MAX];
    // Number of ongoing function calls
    int frameCount;

    // Global value stack for all stack values
    Value stack[STACK_MAX];
    // Pointer to the next empty slot on the stack
    Value* stackTop;
    // Hashtable of all global variables
    Table globals;
    // Hashtable of all "interned" strings being used
    Table strings;
    // Interned string name of the class initializer method
    ObjString* initString;
    // Head of the linked list of 'open' upvalue pointers for closing
    // Searched to ensure we don't duplicate upvalues
    ObjUpvalue* openUpvalues;

    // Track the total bytes of managed memory for the GC
    size_t bytesAllocated;
    // Byte threshold which triggers the GC
    size_t nextGC;
    // Head of linked list of all objects.
    // Used to free memory with the GC and when the VM exits.
    Obj* objects;
    // Garbage Collector vars
    // Count of gray marked objects
    int grayCount;
    // Capacity of our gray object array
    int grayCapacity;
    // Stack of gray marked objects for the GC to work through
    Obj** grayStack;
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
