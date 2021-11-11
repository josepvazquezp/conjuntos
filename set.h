#ifndef SET_SET_H
#define SET_SET_H

struct StrNode
{
    void *data;
    struct StrNode *left, *right;
};

typedef struct StrNode Node;

struct sTree
{
    struct StrNode *root;
    int (*compare)(void *a, void *b);
    int size;
};


typedef struct sTree Tree;

struct node
{
  void* data;
  struct node* next;
};

typedef struct node sNode;

struct stack
{
  sNode* head;
};

typedef struct stack Stack;

Tree *newTree(int (*comp)(void* a, void *b));
Node *newNode();

int contains(Tree *b, void *element, int (*comp)(void* a, void *b));
void add(Tree *b, void *element, int (*comp)(void* a, void *b));

void printTreeIter(Tree *b);
void printTree(Tree *tree);
void printTreeRec(Node *node);

Stack* newStack();
void push(Stack* s, void* data);
void* pop(Stack* s);
void* peek(Stack* s);

void printTreeIter(Tree *b);

int containsNode(Tree *b, int val);

#endif