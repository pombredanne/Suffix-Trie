struct listNode
{
    type data;
    struct listNode* next;
    struct listNode* prev;
};

struct list
{
    struct listNode* begin;
    struct listNode* end;
    int size;
};

typedef struct listNode listNode;
typedef struct list list;

list* createList();
void deleteList(list* ls);
void clear(listNode* node);
int size_ls(list* ls);
type front(list* ls);
type back(list* ls);
void push_front(list* ls,type val);
void pop_front(list* ls);
void push_back_ls(list* ls,type val);
void pop_back_ls(list* ls);
void insert_ls(list* ls,int pos,type val);
void erase_ls(list* ls,int pos);
