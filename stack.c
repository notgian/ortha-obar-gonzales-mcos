#include "stack.h"

/*function initializes the stack by setting its top variable to -1
@param convexHull: the stack to be initizalized
*/
void Create(Stack *convexHull)
{
  convexHull->top = -1;
}

/*function pushes an element in the stack only if the stack is not full
@param convexHull: variable name of the stack
@param elem: the element to be pushed into the stack
*/
void Push(Stack *convexHull, Point elem)
{
  if (isFull(convexHull) == 1)
  {
    printf("Stack is overflowing! Cannot push (%lf,%lf)\n!", elem.x, elem.y);
  }
  else
  {
    convexHull->top = convexHull->top + 1;
    convexHull->data[convexHull->top].x = elem.x;
    convexHull->data[convexHull->top].y = elem.y;
  }
}

/*function pops an element in the stack only if the stack is not empty
@param convexHull: the stack where the element is to be popped from
*/
void Pop(Stack *convexHull)
{
  if (isEmpty(convexHull) == 1)
  {
    printf("Stack is underflowing! Cannot pop!\n");
  }
  else
  {
    convexHull->top = convexHull->top - 1;
  }
}

/*function returns the top element only if the stack is not empty
@param convexHull: the stack where the element is from
return value: returns the rightmost element from the stack
*/
Point Top(Stack *convexHull)
{
  Point returnVal = {-1, -1};
  if (isEmpty(convexHull) == 1)
  {
    printf("Stack is empty! No top element\n!");
  }
  else
  {
    returnVal = convexHull->data[convexHull->top];
  }
  return returnVal;
}

/*function returns the second top element only if the stack has more than 2 elements
@param convexHull: the stack where the element is from
return value: returns the second rightmost element form the stack
*/
Point nextToTop(Stack *convexHull)
{
  Point returnVal = {-1, -1};
  if (convexHull->top < 1)
  {
    printf("Stack does not have a next to top element\n!");
  }
  else
  {
    returnVal = convexHull->data[convexHull->top - 1];
  }
  return returnVal;
}

/*function checks if the stack is full
@param convexHull: the stack to be checked
reutrn value: 1 if full and 0 if false
*/
int isFull(Stack *convexHull)
{
  return convexHull->top == MAX - 1;
}

/*function checks if the elements is empty
@param convexHull: the stack to be checked
return value: 1 if empty and 0 if false
*/
int isEmpty(Stack *convexHull)
{
  return convexHull->top == -1;
}