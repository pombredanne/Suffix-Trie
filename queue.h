#include "queueInterface.h"

queue* createQueue()
{
    queue* q=malloc(sizeof(queue));
    q->ls=createList();
    return q;
}

void deleteQueue(queue* q)
{
    if (!q)
        return;
    deleteList(q->ls);
    free(q);
}

type top_q(queue* q)
{
    if (!q)
        return 0;
    return front(q->ls);
}

void push_q(queue* q,type val)
{
    if (!q)
        return;
    push_back_ls(q->ls,val);
}

void pop_q(queue* q)
{
    if (!q)
        return;
    pop_front(q->ls);
}
