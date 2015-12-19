#include "list.h"

struct queue
{
    list* ls;
};

typedef struct queue queue;

queue* createQueue();
void deleteQueue(queue* q);
type top_q(queue* q);
void push_q(queue* q,type val);
void pop_q(queue* q);
