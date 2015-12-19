#define type TrieNode* 
#include <stdlib.h>
#include <string.h>
#include "SuffixTrie.h"
#include "stack.h"
#include "queue.h"

TrieNode* createNode()
{
    int i;
    TrieNode* node=malloc(sizeof(TrieNode));
    node->end=false;
    node->parent=0;
    for (i=0;i<26;i++)
        node->children[i]=0;
    return node;
}

Trie* createTrie()
{
    Trie* trie=malloc(sizeof(Trie));
    trie->root=createNode();
    return trie;
}

void insert(Trie* trie, char* s)
{
    if (!trie || !s || !s[0])
        return;
    int i,j,l;
    TrieNode* node;
    l=strlen(s);
    char sub[l-1];
    node=trie->root;
    for (i=0;i<l-1;i++)
    {
        j=letterToInt(s[i]);
        node=insertChar(node,j,false);
    }
    j=letterToInt(s[i]);
    insertChar(node,j,true);
    for (i=0;i<l;i++)
        sub[i]=s[i+1];
    insert(trie,sub);
}

int letterToInt(char c)
{
    if (c<97 || c>122)
        return -1;
    return c-97;
}

TrieNode* insertChar(TrieNode* node, int i, bool end)
{
    if (!node || i==-1)
        return 0;
    TrieNode* child;
    if (!node->children[i])
    {
        child=createNode();
        node->children[i]=child;
        child->parent=node;
    }
    else child=node->children[i];
    if (end)
        child->end=true;
    return child;
}

bool isSubstring(Trie* trie, char* s)
{
    if (!trie || !s || !s[0])
        return false;
    int i,j,l;
    TrieNode* node;
    l=strlen(s);
    node=trie->root;
    for (i=0;i<l;i++)
    {
        j=letterToInt(s[i]);
        if (j==-1)
            return false;
        if (!node->children[j])
            return false;
        node=node->children[j];
    }
    return true;
}

int numberOfOccurrence(Trie* trie, char* s)
{
    if (!trie || !s)
        return -1;
    if (!s[0])
        return 0;
    int i,j,l,n;
    stack* nodeStack;
    TrieNode* node;
    l=strlen(s);
    n=0;
    nodeStack=createStack();
    node=trie->root;
    for (i=0;i<l;i++)
    {
        j=letterToInt(s[i]);
        if (j==-1)
            return 0;
        if (!node->children[j])
            return 0;
        node=node->children[j];
    }
    push_s(nodeStack,node);
    while (size_v(nodeStack->v))
    {
        node=top_s(nodeStack);
        pop_s(nodeStack);
        if (node->end)
            n++;
        for (i=0;i<26;i++)
            if (node->children[i])
                push_s(nodeStack,node->children[i]);
    }
    return n;
}

char* longestRepeated(Trie* trie)
{
    if (!trie)
        return 0;
    int i;
    char *s,*result;
    queue* q;
    TrieNode* node;
    s=0; result=0;
    q=createQueue();
    push_q(q,trie->root);
    while (size_ls(q->ls))
    {
        node=top_q(q);
        pop_q(q);
        for (i=0;i<26;i++)
            if (node->children[i])
            {
                s=nodeToString(node->children[i]);
                if (numberOfOccurrence(trie,s)>1)
                {
                    push_q(q,node->children[i]);
                    result=s;
                }
            }
    }
    return result;
}

char* nodeToString(TrieNode* node)
{
    if (!node)
        return 0;
    int i,l;
    char backtrack[100000];
    char* result;
    i=0; l=0;
    while (node->parent)
    {
        for (i=0;i<26;i++)
            if (node==node->parent->children[i])
            {
                backtrack[l]=i+97;
                l++;
                break;
            }
        node=node->parent;
    }
    result=malloc(l+1);
    for (i=0;i<l;i++)
        result[i]=backtrack[l-i-1];
    result[l]=0;
    return result;
}
