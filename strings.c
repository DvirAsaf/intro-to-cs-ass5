/*****************************************
 * Name: Dvir Asaf
 * ID: 313531113
 * Group: 01
 * Assignment: ass5
 ****************************************/
#include "string.h"
#include "stack.h"

/*****************************************
 * Function Name: isLegalString.
 * Input: char str[](arr of chars from the main).
 * Output: int 1 or 0(int boolean 1 mean that the function is correct and 0 mean that is not).
 * Function Operation: the function get from the main arr (char str[]) the function check if to all opening
 * brackets have closing brackets in the same char and the same order.
 * for example the main give [1234]. the function take the opening brackets('[') and check if
 * the closing brackets is ']'. the char between the function ignored.
 *****************************************/

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
            {
                destroyStack(openStack);
                return 0;
            }
            Element popElement = pop(openStack);
            switch(c)
            {
                case '}':
                    if(popElement.c != '{')
                    {
                        destroyStack(openStack);
                        return 0;
                    }
                    break;
                case ']':
                    if(popElement.c != '[')
                    {
                        destroyStack(openStack);
                        return 0;
                    }
                    break;
                case ')':
                    if(popElement.c != '(')
                    {
                        destroyStack(openStack);
                        return 0;
                    }
                    break;
                case '>':
                    if(popElement.c != '<')
                    {
                        destroyStack(openStack);
                        return 0;
                    }
                    break;
                //all other characters that are not above make the program continue to the next char.
                default:
                    break;
            }
        }
        i++;
    }
    if(!isStackEmpty(openStack))
    {
        destroyStack(openStack);
        return 0;
    }
    destroyStack(openStack);
    return 1;
}
