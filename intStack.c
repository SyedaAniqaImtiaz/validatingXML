/**
 *  The functions in this module implement a Stack data structure
 *  of integers.  (Note that chars are also integers so this
 *  integer Stack can be used for chars as well.)
 *
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 integers can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!
#include <stdio.h>
static int top = 0, empty_count = 0, value;
static int stack[100];
//static int stack[100][2];


/**
 * pop() removes the top integer on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value -1 (minus one) is returned.
 */

int pop(int ch)
{
    if(isEmpty() == 1){
        //printf("Error because of stack underflow.\n");
        return (-1);
    }
    
    else{
        top--;
        if(stack[top] == ch){
        value = stack[top];
        stack[top] = '\0';
        //stack[top][1]--;
        //printf("%c popped from the stack\n", value);
        return value;
        }
    }
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(int thing2push)
{
    if(top >= 100){
        printf("Error because of stack overflow.\n");
    }
    
    else if(top < 100){
        stack[top] = thing2push;
        //stack[top][1]++;
        //printf("%c pushed on the stack\n", stack[top][0]);
        top++;
    }
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()
{
    for(int i = 0; i < 100; i++){
        if(stack[i] == '\0'){
            empty_count++;
            //printf("%d", empty_count);
        }
    }
    
    if(empty_count == 100){
        empty_count = 0;
        return 1;
    }
    
    else{
        empty_count = 0;
        return 0;
    }
}
