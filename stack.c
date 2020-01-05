/*****************************************
 * Name: Dvir Asaf
 * ID: 313531113
 * Group: 01
 * Assignment: ass5
 ****************************************/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <assert.h>

/*****************************************
 * Function Name: isStackEmpty.
 * Input: Stack* stack(pointer to arr stack).
 * Output: int 1 or 0( int boolean 1 mean the stack is empty and 0 mean it is not).
 * Function Operation: the function get pointer to stack and check if in the stack have elements, the pointer check
 * the the location of index in the stack if the location is -1 that mean the stack have not elements and return 0,
 * else the function have elements and return 1.
 *****************************************/

int isStackEmpty(Stack* stack)
{
    if(stack->topIndex==-1)
        return 1;
    else
        return 0;
}

/*****************************************
 * Function Name: initStack.
 * Input: the function does not get any input.
 * Output: Stack*(pointer to arr Stack).
 * Function Operation: the function create arr stack in size 1 and return pointer to the start address of the stack.
 * the function initializing the topIndex to -1 because the first char will be in index 0.
 * the function initializing the size to 1 because the function have now 1 place to put in the stack char.
 *****************************************/

Stack* initStack()
{
    Stack* stack = ((Stack*) malloc(sizeof(Stack)));
    if(stack==NULL)
        return NULL;
    stack->content = ((Element*)malloc(sizeof(Element)));
    if (stack->content==NULL)
        return NULL;
    stack->size = 1;
    stack->topIndex = -1;
    return stack;
}

/*****************************************
 * Function Name: push.
 * Input: Stack* stack(pointer to aar Stack) and Element element(get 1 type from the user).
 * Output: the function returns nothing.
 * Function Operation: the function get from the user (scanf from main) a element and check if their empty place to
 * put it in the stack. if the stack have empty place the function put it in the stack.
 * else increases the number of places by multiplying 2 by the number of places that currently exist and
 * the size of the element.(because the realloc increase in bytes and not the size of the elements).
 *****************************************/

void push(Stack* stack, Element element)
{
    Element * backupElement = stack->content;
    if((stack->content) - (stack->topIndex +1) == 0)
    {
        size_t newSize = 2*stack->size*(sizeof(Element));
        backupElement = realloc(stack->content,newSize);
        if(backupElement == NULL)
        {
            printf("realloc(push) has failed\n");
            //before exit program free allocated memory to avoid memory leaks
            destroyStack(stack);
            exit(1);
        }
        stack->content = backupElement;
        stack->size *= 2;
    }
    stack->topIndex++;
    stack->content[stack->topIndex] = element;
}

/*****************************************
 * Function Name: destroyStack.
 * Input: Stack* stack(pointer to aar Stack)
 * Output: the function returns nothing.
 * Function Operation: the function destroy the stack the free all the address that the stack use.
 *****************************************/

void destroyStack(Stack* stack)
{
    if(stack == NULL)
        return;
    free(stack->content);
    free(stack);
}

/*****************************************
 * Function Name: pop.
 * Input: Stack* stack(pointer to aar Stack).
 * Output: Element(the type from stack).
 * Function Operation: the function go to the last place that put in the stack element and
 * return it and free that place. the function check that if in the stack have element to get out.
 *****************************************/

Element pop(Stack* stack)
{
    if(((stack->topIndex+1)*2) < stack->size)
    {
        Element *backup = (Element *) realloc(stack->content, sizeof(Element) * 1/2 * (stack->size));
        if (backup != NULL)
        {
            stack->content = backup;
            stack->size*=1/2;
        }
        else{
            printf("realloc(pop) has failed\n");
            //before exit program free allocated memory to avoid memory leaks
            destroyStack(stack);
            exit(1);
        }
    }
    Element temp = stack->content[stack->topIndex];
    stack->topIndex--;
    return temp;
}

/*****************************************
 * Function Name: top.
 * Input: Stack* stack(pointer to aar Stack).
 * Output: Element(the type from stack).
 * Function Operation: the function go to the last place that put in the stack element and return it.
 * the function check if in the stack have elements to show out.
 *****************************************/

Element top(Stack* stack)
{
    return stack->content[stack->topIndex];
}

/*****************************************
 * Function Name: printStack.
 * Input: Stack* stack(pointer to aar Stack).
 * Output: the function returns nothing.
 * Function Operation: the function print all the elements that in the stack in the same order them entered.
 *****************************************/

void printStack(Stack* stack)
{
    for (int i = stack->topIndex ; i >= 0 ; i--)
    {
        printf("%d: %c\n",i+1,stack->content[i].c);

    }

}

/*****************************************
 * Function Name: ienOfStack.
 * Input: Stack* stack(pointer to aar Stack).
 * Output: int(all numbers that are greater or equal to zero).
 * Function Operation: the function check the len of elements on stack.
 * return the number of elements that have on stack.
 *****************************************/

int lenOfStack(Stack* stack)
{
    if(stack == NULL)
        return 0;
    return stack->topIndex+1;
}

/*****************************************
 * Function Name: capacityOfStack.
 * Input: Stack* stack(pointer to aar Stack).
 * Output: int(all numbers that are greater or equal to zero).
 * Function Operation: the function check the len of stack. if the stack is not exists the function return 0.
 * else return the number of places that have on stack.
 *****************************************/

int capacityOfStack(Stack* stack)
{
    if(stack == NULL)
        return 0;
    return stack->size;
}

