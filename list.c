#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node *nodoLocal = (Node *) malloc(sizeof(Node));
    nodoLocal->next = NULL;
    nodoLocal->prev = NULL;
    nodoLocal->data = data;
    return nodoLocal;
  }

List * createList() {
  List *listaLocal = (List *) malloc(sizeof(List));
  listaLocal->head = NULL;
  listaLocal->tail = NULL;
  listaLocal->current = NULL;
  return listaLocal;
}

void * firstList(List * list) {
  if (!list->head)
    return NULL;

  list->current = list->head;
  return (list->head->data);
}

void * nextList(List * list) {
  if (!list->current)
    return NULL;

  if (!list->current->next)
    return NULL;

  list->current = list->current->next;
  return (list->current->data);
}

void * lastList(List * list) {
  if (!list->tail)
    return NULL;
  
  list->current = list->tail;
  return (list->tail->data);
}

void * prevList(List * list) {
  if (!list->current)
    return NULL;
  
  if (!list->current->prev)
    return NULL;

  list->current = list->current->prev;
  return (list->current->data);
}

void pushFront(List * list, void * data) {
  Node* nodoLocal = createNode(data);
  if (!list->tail)
    return NULL;
  nodoLocal->next = list->head;
  if (list->head != NULL)
    list->head->prev = nodoLocal;
  list->head = nodoLocal;
  nodoLocal->prev = NULL;

}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
