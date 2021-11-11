#include <stdio.h>
#include <stdlib.h>
#include "set.h"

Tree *newTree(int (*comp)(void *a, void *b))
{
    Tree *n = malloc(sizeof(Tree));
    n->compare = comp;
    n->size = 0;
    n->root = NULL;
    return n;
}

Node *newNode(void *element)
{
    Node *n = malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->data = element;
    return n;
}

Stack* newStack()
{
  Stack *s = malloc(sizeof(Stack));
  s->head = NULL;
  return s;
}

void push(Stack* s, void* data)
{
  sNode* n = newNode(data);
  n->next = s->head;
  s->head = n;
}

void* pop(Stack* s)
{
  if(s->head == NULL)
    return NULL;

  sNode* toDel = s->head;
  void* toRet = s->head->data;
  s->head = s->head->next;
  free(toDel);

  return toRet;
}

void* peek(Stack* s)
{
  if(s->head == NULL)
    return NULL;
  return s->head->data;
}

void printTreeIter(Tree *b)
{
  Stack *toVisit = newStack();
  Node* current = b->root;

  while(peek(toVisit) != NULL || current )
  {
    while(current != NULL)
    {
      push(toVisit, current);
      current = current->left;
    }
    current = pop(toVisit);
    printf("[%d]", *(int*)current->data);
    current = current->right;
  }

}

int contains(Tree *b, void *element, int (*comp)(void* a, void *b))
{
    Stack *toVisit = newStack();
    Node* current = b->root;

    while(peek(toVisit) != NULL || current )
    {
        while(current != NULL)
        {
        push(toVisit, current);
        current = current->left;
        }
        current = pop(toVisit);
        if(comp(element, current->data) == 0)
            return 1;
        current = current->right;
    }
    
    return 0;
}

void add(Tree *b, void *element, int (*comp)(void* a, void *b))
{
    if(contains(b, element, comp) == 0)
    {
        if(b->root == NULL)
        {
            b->root = newNode(element);
            return;
        }
        Node* current = b->root;
        while(current->data != element)
        {
            if(comp(element, current->data) < 0)
            {
            if(current->left == NULL)
            {
                current->left = newNode(element);
                return;
            }
            current = current->left;
            }
            if(comp(element, current->data) > 0)
            {
            if(current->right == NULL)
            {
                current->right  = newNode(element);
                return;
            }
            current = current->right;
            }
        }
    }
}

void printTree(Tree *tree)
{
    printTreeRec(tree->root);
}

void printTreeRec(Node *root)
{
    if(root == NULL)
        return;

    printTreeRec(root->left);
    printf("[%d]", root->data);
    printTreeRec(root->right);
}

//contains Josean

int containsNode(Tree *b, int val)
{
    Node *focusNode = b->root;

    while(focusNode != NULL && focusNode->data)
    {
        if(focusNode->data > val)
            focusNode = focusNode->left;
        if(focusNode->data < val)
            focusNode = focusNode->right;
    }

    if(focusNode == NULL)
        return 0;
    
    return 1;
}