#include "stdlib.h"
#include "listInterface.h"

list* createList()
{
    list* ls=malloc(sizeof(list));
    ls->begin=0;
    ls->end=0;
    ls->size=0;
    return ls;
}

void deleteList(list* ls)
{
    clear(ls->begin);
    ls->size=0;
    free(ls);
}

void clear(listNode* node)
{
    if (!node)
        return;
    clear(node->next);
    free(node);
}

int size_ls(list* ls)
{
    return ls->size;
}

type front(list* ls)
{
    if (!ls || !(ls->begin))
        return 0;
    return ls->begin->data;
}

type back(list* ls)
{
    if (!ls || !(ls->end))
        return 0;
    return ls->end->data;
}

void push_front(list* ls,type val)
{
    if (!ls)
        return;
    listNode* node=malloc(sizeof(listNode));
    node->data=val;
    node->next=ls->begin;
    node->prev=0;
    if (ls->size)
        ls->begin->prev=node;
    ls->begin=node;
    if (!ls->size)
        ls->end=node;
    ls->size++;
}

void pop_front(list* ls)
{
    if (!ls)
        return;
    if (ls->size==0)
        return;
    if (ls->size==1)
    {
        free(ls->begin);
        ls->begin=0;
        ls->end=0;
    }
    else
    {
        listNode* node=ls->begin->next;
        free(ls->begin);
        ls->begin=node;
        ls->begin->prev=0;
    }
    ls->size--;
}

void push_back_ls(list* ls,type val)
{
    if (!ls)
        return;
    listNode* node=malloc(sizeof(listNode));
    node->data=val;
    node->next=0;
    node->prev=ls->end;
    if (ls->size)
        ls->end->next=node;
    ls->end=node;
    if (!ls->size)
        ls->begin=node;
    ls->size++;
}

void pop_back_ls(list* ls)
{
    if (!ls)
        return;
    if (ls->size==0)
        return;
    if (ls->size==1)
    {
        free(ls->begin);
        ls->begin=0;
        ls->end=0;
    }
    else
    {
        listNode* node=ls->end->prev;
        free(ls->end);
        ls->end=node;
        ls->end->next=0;
    }
    ls->size--;
}

void insert_ls(list* ls,int pos,type val)
{
    if (!ls)
        return;
    if (pos<0 || pos>ls->size)
        return;
    if (pos==0)
        push_front(ls,val);
    else if (pos==ls->size)
        push_back_ls(ls,val);
    else
    {
        int i,mid;
        listNode *node,*prevNode,*nextNode;
        node=malloc(sizeof(listNode));
        node->data=val;
        mid=ls->size/2;
        if (pos<mid)
        {
            prevNode=ls->begin;
            for (i=0;i<pos-1;i++)
                prevNode=prevNode->next;
            nextNode=prevNode->next;
        }
        else
        {
            nextNode=ls->end;
            for (i=ls->size;i>pos+1;i--)
                nextNode=nextNode->prev;
            prevNode=nextNode->prev;
        }
        prevNode->next=node;
        nextNode->prev=node;
        node->prev=prevNode;
        node->next=nextNode;
        ls->size++;
    }
}

void erase_ls(list* ls,int pos)
{
    if (!ls)
        return;
    if (pos<0 || pos>=ls->size)
        return;
    if (pos==0)
        pop_front(ls);
    else if (pos==ls->size-1)
        pop_back_ls(ls);
    else
    {
        int i,mid;
        listNode *node,*prevNode,*nextNode;
        mid=ls->size/2;
        if (pos<mid)
        {
            node=ls->begin;
            for (i=0;i<pos;i++)
                node=node->next;
        }
        else
        {
            node=ls->end;
            for (i=ls->size-1;i>pos;i++)
                node=node->prev;
        }
        prevNode=node->prev;
        nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        free(node);
        ls->size--;
    }
}
