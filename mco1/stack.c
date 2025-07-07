#include "stack.h"

/* Create: initializes the stack by setting its top variable to -1
    @param stack: the stack to be initizalized
*/
void Create(Stack *stack)
{
    stack->top = -1;
}

/* Push: pushes an element in the stack only if the stack is not full
    @param stack: variable name of the stack
    @param elem: the element to be pushed into the stack
*/
void Push(Stack *stack, Point elem)
{
    if (isFull(stack) == 1)
    {
        printf("Stack overflow error! Cannot push.\n");
    }
    else
    {
        stack->top = stack->top + 1;
        stack->data[stack->top].x = elem.x;
        stack->data[stack->top].y = elem.y;
    }
}

/* Pop: removes the top element in the stack if and only if the stack is not empty
    @param stack: the stack where the element is to be popped from
*/
Point Pop(Stack *stack)
{
    Point returnValue;
    returnValue.x = -99999999.0;
    returnValue.y = -99999999.0;

    if (isEmpty(stack) == 1)
        printf("Stack underflow error! Cannot pop.\n");
    else
    {
        returnValue = stack->data[stack->top];
        stack->top = stack->top - 1;
    }

    return returnValue;
}

/* Top: returns the top in the stack if and only if the stack is not empty
    @param stack: the stack where the element is from
    @return int:  returns the rightmost element from the stack
*/
Point Top(Stack *stack)
{
    Point returnVal = {-1, -1};
    if (isEmpty(stack) == 1)
    {
        printf("Stack is empty! No top element.\n");
    }
    else
    {
        returnVal = stack->data[stack->top];
    }
    return returnVal;
}

/* nextToTop: returns the second top element if and only if the stack has more than 2 elements
    @param stack:  the stack where the element is from
    @return Point: returns the second rightmost element form the stack
*/
Point nextToTop(Stack *stack)
{
    Point returnVal = {-1, -1};
    if (stack->top < 1)
    {
        printf("Stack does not have a next to top element.\n!");
    }
    else
    {
        returnVal = stack->data[stack->top - 1];
    }
    return returnVal;
}

/* isFull: checks if the stack is full
    @param stack: the stack to be checked
    @reutrn int:  1 if full and 0 if false
*/
int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

/* isEmpty: checks if the stack is empty
    @param stack: the stack to be checked
    @return int:  1 if empty and 0 if false
*/
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}