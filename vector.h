#include <stdio.h>
#include <stdlib.h>
#include "vectorInterface.h"

vector* createVector()
{
    vector* v=malloc(sizeof(vector));
    v->size=0;
    v->max=4;
    v->a=malloc(v->max*sizeof(type));
    return v;
}

void deleteVector(vector* v)
{
    if (!v)
        return;
    free(v->a);
    v->a=0;
    free(v);
    v=0;
}

int size_v(vector* v)
{
    return v->size;
}

int max_size(vector* v)
{
    return v->max;
}

void resize(vector* v, int n)
{
    if (!v)
        return;
    v->a=realloc(v->a,n*sizeof(type));
    v->max=n;
}

type at(vector* v, int i)
{
    if (!v)
        return 0;
    if (i<0 || i>=v->size)
    {
        printf("Index out of bounds\n");
        return 0;
    }
    return v->a[i];
}

type* data(vector* v)
{
    if (!v)
        return 0;
    return v->a;
}

void push_back_v(vector* v, type val)
{
    if (!v)
        return;
    insert_v(v,v->size,val);
}

void pop_back_v(vector* v)
{
    if (!v)
        return;
    erase_v(v,v->size-1);
}

void insert_v(vector* v, int pos, type val)
{
    if (!v)
        return;
    if (pos<0 || pos>v->size)
        return;
    int i;
    if (v->size==v->max)
    {
        v->max=v->max*2;
        resize(v,v->max);
    }
    for (i=v->size;i>pos;i--)
        v->a[i]=v->a[i-1];
    v->a[pos]=val;
    v->size++;
}

void erase_v(vector* v, int pos)
{
    if (!v)
        return;
    if (pos>=v->size)
        return;
    int i;
    for (i=pos;i<v->size-1;i++)
    {
        v->a[i]=v->a[i+1];
    }
    v->a[i]=0;
    v->size--;
}
