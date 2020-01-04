#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <assert.h>

int isStackEmpty(Stack* stack)
{
    if(stack->topIndex==-1)
        return 1;
    else
        return 0;
}

Stack* initStack()
{
    Stack* stack = ((Stack*) malloc(sizeof(Stack)));
    if(stack==NULL)
        return NULL;
    stack->content = ((Element*)malloc(sizeof(Element)));
    if (stack->content==NULL)
        return NULL;
    stack->size = 1;
    stack->content->c = '1';
    stack->topIndex = -1;
    return stack;
}

void push(Stack* stack, Element element)
{
    Element * backupElement = stack->content;
    if((stack->content) - (stack->topIndex +1) == 0)
    {
        size_t newSize = 2*stack->size*(sizeof(Element));
        backupElement = realloc(stack->content,newSize);
        if(backupElement == NULL)
        {
            printf("realloc() has failed\n");
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


void destroyStack(Stack* stack)
{
    if(stack->content == NULL)
        return;
    else
    {
        free(stack->content);
        free(stack);
    }

}
Element pop(Stack* stack)
{
    if((stack->topIndex*2) < stack->size)
    {
        Element *backup = (Element *) realloc(stack->content, sizeof(Element) * 1/2 * (stack->size));
        if (backup != NULL)
        {
            stack->content = backup;
            stack->size*=1/2;
        }
    }
    Element temp = stack->content[stack->topIndex];
    stack->topIndex--;
    return temp;
}

Element top(Stack* stack)
{
    return stack->content[stack->topIndex];
}

void printStack(Stack* stack)
{
//    while(stack->topIndex != -1)
//    {
//        printf("%c",stack->content);
//        stack->topIndex--;
//    }
}