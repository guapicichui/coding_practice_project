#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H


typedef char DataType;
typedef struct node StackFrame;

typedef struct node{
	DataType data;
	StackFrame* next;
}StackFrame;

typedef struct {
	StackFrame* top;

}Stack;

Stack* create_stack();
void destroy_stack(Stack* stack);
void push_stack(Stack* stack, DataType val);
DataType pop_stack(Stack* stack);


#endif // !STACK_LINKEDLIST_H

