#include <stdlib.h>
#include <stdio.h>
#include "strings.h"
#include <assert.h>
#include "stack.h"


int isLegalString(char str[])
{
    //create new stack which contains all the opening brackets.
    Stack* openStack = initStack();
    int i=0;
    while(str[i] != '\0')
    {
        char c = str[i];
        if(c == '<' || c=='{' || c=='(' || c=='[')
        {
            Element element;
            element.c = c;
            push(openStack,element);
        }
        else if(c == '>' || c=='}' || c==')' || c==']')
        {
            //if we found a closing bracket but the stack of the opening brackets is empty it means the match
            //opening bracket was not there ----> invalid.
            if(isStackEmpty(openStack))
                return 0;
            Element popElement = pop(openStack);
            switch(c)
            {
                case '}':
                    if(popElement.c != '{')
                        return 0;
                    break;
                case ']':
                    if(popElement.c != '[')
                        return 0;
                    break;
                case ')':
                    if(popElement.c != '(')
                        return 0;
                    break;
                case '>':
                    if(popElement.c != '<')
                        return 0;
                    break;
                default:
                    break;
            }
        }
        i++;
    }
    if(!isStackEmpty(openStack))
        return 0;
    return 1;
}