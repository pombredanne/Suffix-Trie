struct vector
{
    type* a;
    int size;
    int max;
};

typedef struct vector vector;

vector* creatVector();
void deleteVector(vector* v);
int size_v(vector* v);
int max_size(vector* v);
void resize(vector* v, int n);
type at(vector* v, int i);
type* data(vector* v);
void push_back_v(vector* v, type val);
void pop_back_v(vector* v);
void insert_v(vector* v, int pos, type val);
void erase_v(vector* v, int pos);
