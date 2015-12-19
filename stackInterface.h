#include "vector.h"

struct stack
{
    vector* v;
};

typedef struct stack stack;

stack* createStack();
void deleteStack(stack* s);
//int sizeofStack(stack* s);
type top_s(stack* s);
void push_s(stack* s, type val);
void pop_s(stack* s);
