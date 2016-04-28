#include <stdio.h>
#include <stdlib.h>

typedef struct node_s node_t;
struct node_s {
 int data; 
 node_t* prev;
 node_t* next;
};

typedef struct list_s list_t;
struct list_s {
  int size;
  node_t *head;
  node_t *tail;
};

list_t* list() {
  list_t *list = NULL;

  list = (list_t *) malloc (sizeof(list_t));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;

  return list;
}

int append(list_t *list, int data) {
  node_t *node = NULL;
  node_t *temp = NULL;

  node = (node_t *) malloc (sizeof(node_t));
  node->data = data;

  if (list->size == 0) {
    list->head = node;
    list->tail = node;

    node->next = node;
    node->prev = node;
  } else {
    temp = list->tail;
    temp->next = node;
    node->prev = temp;

    list->tail = node;
    node->next = list->head;
    list->head->prev = list->tail;

  }

  list->size++;
  return 0;
}

node_t* head(list_t *list) {
  if (list == NULL)
    return NULL;
    
  return list->head;
}

node_t* next(node_t *node) {
  node_t *temp;
  if (list == NULL)
    return NULL;

  return node->next;
}

node_t* delete(list_t *list, node_t *node) {
  node_t *prev;
  node_t *next;

  if (list == NULL)
    return NULL;

  prev = node->prev;
  next = node->next;

  prev->next = next;
  next->prev = prev;

  if (node == list->head)
    list->head = node->next;
  if (node == list->tail)
    list->tail = node->prev;

  free(node);
  list->size--;

  return next;
}

int size(list_t *list) {
  if (list == NULL)
    return 0;
  else 
    return list->size;
}

int main() {
#if 0
  list_t *l;
  node_t *n, *h, *d;

  l = list();

  append(l, 1);
  append(l, 2);
  append(l, 3);
  append(l, 4);

  h = head(l);
  printf("(%d)\n", h->data);
  n = next(h); 
  printf("(%d)\n", n->data);
  n = next(n); 
  printf("(%d)\n", n->data);

  printf("delete\n");
  d = delete(l, n);
  printf("(%d), size(%d)\n", n->data, l->size);
  printf("delete\n");
  d = delete(l, d);
  printf("delete\n");
  d = delete(l, d);
  printf("delete\n");
  d = delete(l, d);
  n = next(d); 
  printf("(%d), size(%d)\n", n->data, l->size);
  n = next(n); 
  printf("(%d)\n", n->data);
  n = next(n); 
  printf("(%d)\n", n->data);
  n = next(n); 
  printf("(%d)\n", n->data);
  n = next(n); 
  printf("(%d)\n", n->data);
#endif
#if 1
  int tc, n, k = 0;
  int i, j, m, o = 0;
  int a, b = 0;
  list_t *l;
  node_t *t;
  scanf("%d", &tc);
  for (i = 0; i < tc ; i++ ) {
    scanf("%d %d", &n, &k);
    l = list();
    m = 0;
    for (j = 1; j < n+1; j++) {
      append(l, j);
    }
    t = head(l);
    
    while (size(l) != 2) {
      t = delete(l, t);
      for (o = 1; o < k; o++)
        t = next(t);
    }
#if 0
    if (k == 1) {
      while (size(l) != 2) {
        t = delete(l, t);
      }
    } else if (k == 2) {
      while (size(l) != 2) {
        t = delete(l, t);
        t = next(t);
        t = next(t);
      }

    } else {
      while (size(l) != 2) {
        //printf("size(%d)\n", size(l));
        if (m % (k-1))
          t = delete(l, t); 
        t = next(t);
        m++;
      }
    }
#endif
    a = t->data;
    t = delete(l, t);
    b = t->data;
    t = delete(l, t);
    if (a > b)
      printf("%d %d\n", b, a);
    else
      printf("%d %d\n", a, b);
  }
  
#endif
  return 0;
}
