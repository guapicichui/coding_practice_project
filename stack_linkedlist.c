#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_linkedlist.h"
#include <string.h>

#define ERROR_CHECK(ret, error_flag, msg) \
    do { \
        if ((ret) == (error_flag)) { \
            printf("error: %s\n", msg); \
            exit(1); \
        } \
    } while(0)

static Stack* clear_stack(Stack* stack)
{
	StackFrame* temp;
	while (stack->top != NULL)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	return stack;
}
static StackFrame* create_stack_frame(DataType val)
{
	StackFrame* stack_frame = (StackFrame*)malloc(sizeof(StackFrame));
	stack_frame->next = NULL;
	stack_frame->data = val;
	return stack_frame;
}

Stack* create_stack()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	ERROR_CHECK(stack, NULL, "failed");
	stack->top == NULL;
	return stack;

}
void destroy_stack(Stack* stack)
{
	if (stack == NULL)
		return;
	StackFrame* temp;
	while (stack->top != NULL)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
	return;
}

void push_stack(Stack* stack, DataType val)
{
	StackFrame* stack_frame = create_stack_frame(val);
	stack_frame->next = stack->top;
	stack->top = stack_frame;
	return;
}
DataType pop_stack(Stack* stack)
{
	if (stack == NULL)
		exit(1);
	StackFrame* temp = stack->top;
	stack->top = stack->top->next;
	DataType val = temp->data;
	free(temp);
	return val;

}

bool is_parentheses_matched(Stack* stack, const char* str)
{
	if (stack != NULL)
		clear_stack(stack);
	while (*str)
	{
		switch (*str) {
		case '(':
			push_stack(stack,')');
			break;
		case '{':
			push_stack(stack, '}');
			break;
		case '[':
			push_stack(stack, ']');
			break;
		case ')':
			if (')' != pop_stack(stack))
				return false;
			break;
		case ']':
			if (']' != pop_stack(stack))
				return false;
			break;
		case '}':
			if ('}' != pop_stack(stack))
				return false;
			break;
		}
	}
	return true;
}