#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include <assert.h>


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

void destroyQueue(Queue* queue)
{
    if(queue == NULL)
        return;
    destroyStack(queue->s1);
    destroyStack(queue->s2);
    free(queue);
}

int isQueueEmpty(Queue* queue)
{
    //TODO: wait for instructor answer
    if(queue == NULL)
        return 1;
    if(isStackEmpty(queue->s2) && isStackEmpty(queue->s1))
        return 1;
    else
        return 0;
}

int lenOfQueue(Queue* queue)
{
    //TODO: wait for answer
    if(queue == NULL)
        return 0;
    //one of them must be empty so it is ok to return the sum of both.
    return lenOfStack(queue->s1) + lenOfStack(queue->s2);
}

int capacityOfQueue(Queue* queue)
{
    //TODO: wait for answer
    if(queue == NULL)
        return 0;
    return capacityOfStack(queue->s1) + capacityOfStack(queue->s2);

}

void enqueue(Queue* queue, Element element)
{
    //TODO: wait for answer
    if(queue == NULL)
        return;
    //TODO: wait for answer
    if(queue->s1 == NULL)
        return;
    push(queue->s1,element);
}

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