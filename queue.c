/*****************************************
 * Name: Dvir Asaf
 * ID: 313531113
 * Group: 01
 * Assignment: ass5
 ****************************************/

#include <stdlib.h>
#include "queue.h"

/*****************************************
 * Function Name: initQueue.
 * Input: the function does not get any input..
 * Output: Queue*(pointer to arr Stack).
 * Function Operation: the function send to Stack* initStack to make 2 stacks and return pointer to the start
 * address of the queue.
 *****************************************/

Queue* initQueue()
{
    Queue * queue = ((Queue*) malloc(sizeof(Queue)));
    if(queue==NULL)
        return NULL;
    queue->s1 = initStack();
    if(queue->s1 == NULL)
    {
        return NULL;
    }
    queue->s2 = initStack();
    if(queue->s2 == NULL)
    {
        return NULL;
    }
    return queue;
}

/*****************************************
 * Function Name: destroyQueue.
 * Input: Stack* stack(pointer to arr stack).
 * Output: the function returns nothing.
 * Function Operation: the function destroy the stack s1 and s2 and free all the address that the stacks use.
 *****************************************/

void destroyQueue(Queue* queue)
{
    if(queue == NULL)
        return;
    destroyStack(queue->s1);
    destroyStack(queue->s2);
    free(queue);
}

/*****************************************
 * Function Name:
 * Input: Stack* stack(pointer to arr stack).
 * Output: int 1 or 0( int boolean 1 mean the stack is empty and 0 mean it is not).
 * Function Operation: the function send both stacks to isStackEmpty and if both of them are empty return 1.
 * else return 0.
 *****************************************/

int isQueueEmpty(Queue* queue)
{
    if(queue == NULL)
        return 1;
    if(isStackEmpty(queue->s2) && isStackEmpty(queue->s1))
        return 1;
    else
        return 0;
}

/*****************************************
 * Function Name: lenOfQueue.
 * Input: Stack* stack(pointer to arr stack).
 * Output:  int(all numbers that are greater or equal to zero).
 * Function Operation: the function send both stack(s1 and s2) to lenOfStack and return the sum both of them.
 *****************************************/

int lenOfQueue(Queue* queue)
{
    if(queue == NULL)
        return 0;

    return lenOfStack(queue->s1) + lenOfStack(queue->s2);
}

/*****************************************
 * Function Name: capacityOfQueue.
 * Input: Stack* stack(pointer to arr stack).
 * Output: int(all numbers that are greater or equal to zero).
 * Function Operation: the function send both stack(s1 and s2) to capacityOfStack and return the sum both of them.
 *****************************************/

int capacityOfQueue(Queue* queue)
{
    if(queue == NULL)
        return 0;
    return capacityOfStack(queue->s1) + capacityOfStack(queue->s2);

}

/*****************************************
 * Function Name: enqueue.
 * Input: Stack* stack(pointer to arr stack) and Element element(get 1 type from the user).
 * Output: the function returns nothing.
 * Function Operation: the function check that have a queue and stack s1 and send s1 to push that put in s1 the
 * the elements the user enter.
 *****************************************/

void enqueue(Queue* queue, Element element)
{
    if(queue == NULL)
        return;
    if(queue->s1 == NULL)
        return;
    push(queue->s1,element);
}

/*****************************************
 * Function Name: dequeue.
 * Input: Stack* stack(pointer to arr stack).
 * Output: Element(the type from stack).
 * Function Operation: the function check is s2 is not empty. if s2 have elements in the function send to pop
 * the stack s2 and return the element. else the function take all the elements from s1 and put them in s2 and clean
 * all the elements from s1, after this in s2 have elements in it and then send s2 to pop and return the element.
 * the function return the elements in the same order the user enter them.(FIFO)
 *****************************************/

Element dequeue(Queue* queue)
{
    if(!isStackEmpty(queue->s2))
    {
        return pop(queue->s2);
    }
    //move all s1's elements to s2.
    for (int i = queue->s1->topIndex ; i >=0  ; i--)
    {
        Element popedElement = pop(queue->s1);
        push(queue->s2,popedElement);
    }
    //pop last (LIFO) element from s2 which is the same as the first element that was pushed to s1 (FIFO)
    return pop(queue->s2);
}

/*****************************************
 * Function Name: peek.
 * Input: Stack* stack(pointer to arr stack).
 * Output: Element(the type from stack).
 * Function Operation: the function check if is stack s2 have elements. if in stack s2 have elements the function
 * send s2 to top and return the element. else the function take all the elements from
 * s1 and put them is s2 and clean all the elements drom s1,after this is s2 have elements in it and then send s2
 * to top and return the element.the function return the elements in the same order the user enter them.(FIFO)
 *****************************************/

Element peek(Queue* queue)
{
    if(!isStackEmpty(queue->s2))
    {
        return top(queue->s2);
    }
    //move all s1's elements to s2.
    for (int i = queue->s1->topIndex ; i >=0  ; i--)
    {
        Element popedElement = pop(queue->s1);
        push(queue->s2,popedElement);
    }
    //pop last (LIFO) element from s2 which is the same as the first element that was pushed to s1 (FIFO)
    return top(queue->s2);

}
