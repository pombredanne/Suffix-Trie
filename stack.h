#include "stackInterface.h"

stack* createStack()
{
    stack* s;
    s=malloc(sizeof(s));
    s->v=createVector();
    return s;
}

void deleteStack(stack* s)
{
    if (!s)
        return;
    deleteVector(s->v);
    free(s);
    s=0;
}

/*int sizeofStack(stack* s)
{
    if (!s)
        return 0;
    return size(s->v);
}*/

type top_s(stack* s)
{
    if (!s)
        return 0;
    return at(s->v,size_v(s->v)-1);
}

void push_s(stack* s, type val)
{
    if (!s)
        return;
    push_back_v(s->v,val);
}

void pop_s(stack* s)
{
    if (!s)
        return;
    pop_back_v(s->v);
}
