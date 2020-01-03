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
    Stack* stack = ((Stack*) malloc(sizeof(stack)));
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

void push(Stack* stack, Element element){
    stack->content[++stack->topIndex] = element;
    Element * tempElement = stack->content;
    if ((stack->size) - (stack->topIndex) == 1) {
        tempElement = realloc(stack->content, 2*stack->size*(sizeof(Element)));
        if (stack->content == NULL){
            printf("error in allocating memory in push in stack.c!");
            exit(1);
        }
        stack->content = tempElement;
        stack->size *= 2;
    }
}

//void push(Stack* stack, Element element)
//{
//
////    stack->content[++stack->topIndex] = element;
//    Element* tempElement;
////    if(stack->size - stack->topIndex==1)
////    {
//    if(stack->content == NULL){
//        printf("ERROR\n");
//        destroyStack(stack);
//        exit(1);
//    }
//    tempElement = realloc(stack->content,sizeof(Element)*2*stack->size );
//    if(tempElement == NULL)
//    {
//        printf("ERROR\n");
//        destroyStack(stack);
//        exit(1);
//    }
////    free(tempElement);
////    }
////    stack->size*=2;
////    stack->content = tempElement;
////    tempElement = NULL;
//
//}
//void push(Stack* stack, Element element)
//{
//
////    stack->content[++stack->topIndex] = element;
////    if(stack->size - stack->topIndex==1)
////    {
////        int s = stack->size;
////        size_t  x = sizeof(Element);
//
//
//
//    Element* tempElement;
//    tempElement = realloc(stack->content,sizeof(Element)*2*(stack->size) );
//
//
//
//
////        tempElement = realloc(stack->content,x*20 );
//        if(tempElement == NULL)
//        {
//            printf("ERROR\n");
//            destroyStack(stack);
//            exit(1);
//        }
////        stack->size*=2;
////        stack->content = tempElement;
////        tempElement = NULL;
////    }
//}


//void push(Stack* stack, Element element)
//{
//
////    stack->content[++stack->topIndex] = element;
//    Element* tempElement;
////    if(stack->size - stack->topIndex==1)
////    {
//        tempElement = realloc(stack->content,sizeof(Element)*2*stack->size );
//        if(tempElement == NULL)
//        {
//            printf("ERROR\n");
//            destroyStack(stack);
//            exit(1);
//        }
////    }
////    stack->size*=2;
////    stack->content = tempElement;
////    tempElement = NULL;
//
//}

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