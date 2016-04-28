#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s node_t;
typedef struct list_s list_t;
typedef struct stack_s stack_t;

struct node_s {
  int depth;
  int datalen;
  int* data;
  node_t* next;
  list_t *list;;
};

struct list_s {
  int size;
  node_t* head;
  node_t* tail;
};

list_t* list() {
  list_t* l;
  l = (list_t *) malloc (sizeof(list_t));
  l->size = 0;
  l->head = NULL;
  l->tail = NULL;
  return l;
}

int append(list_t* l, node_t* n) {
  if (l == NULL)
    return -1;

  if (l->size == 0) {
    n->list = NULL;
    n->next = NULL;
    l->head = n;
    l->tail = n;
    l->size++;
  } else {
    n->list = NULL;
    n->next = NULL;
    l->tail->next = n;
    l->tail = n;
    l->size++;
  }
  return 0;
}
// return 0 if data find, else return 0;
// l : list, i : index, d = find data
node_t* search1(list_t *l, int i, int d) {
  node_t* r; // runner
  r = l->head;

  while (r) {
    if (r->data[i] == d) return r;
    r = r->next;
  }
  return NULL; 
}

node_t* search2(list_t *l, int n, int *d) {
  node_t* r; // runner
  int i, flag = 0;
  r = l->head;
  while (r) {
    flag = 0;
    for (i = 0; i < n; i++)
      if (r->data[i] != d[i]) flag = -1;
    if (flag == 0) return r;
    else return NULL;
    r = r->next;
  }
  return NULL;
}

struct stack_s {
  int size;
  node_t* top;
};

stack_t* stack() {
  stack_t* s;
  s = (stack_t *) malloc (sizeof(stack_t));
  s->size = 0;
  s->top = 0;
  return s;
}

int push(stack_t* s, node_t* n) {
  if (s == NULL)
    return -1;

  if (s->size == 0) {
    s->top = n;
    s->size++;
  } else {
    n->next = s->top;
    s->top = n;
    s->size++;
  }
  return 0;
}

node_t* pop(stack_t* s) {
  node_t* temp;
  if (s == NULL)
    return NULL;

  if (s->size == 0) {
    return  NULL;
  } else {
   temp = s->top;
   s->top = temp->next;
   return temp;
  }
}

int copy_node(node_t* src, node_t* dest, int n) {
  int i = 0;
  dest->depth = src->depth;
  dest->datalen = src->datalen;
  for (i = 0; i < n; i++) {
    dest->data[i] = src->data[i];
  }
  return 0;
}

int malloc_node(node_t* node, int size) {
  node = (node_t *) malloc (sizeof(node_t));
  memset(node, 0x00, sizeof(node_t));

  node->datalen = size;
  node->data = (int *) malloc (sizeof(int) * node->datalen);
  return 0;
}

int free_node(node_t* node) {
  if (node->data)
    free(node->data);
  if (node)
    free(node);
  return 0;
}

int free_list(list_t *l) {
  node_t *next, *prev;
  prev = l->head;
  next = l->head;
  while (prev) {
    next = next->next;
    free_node(prev);
    prev = next;
  }
  return 0;
}


int get_numberofcase(int m, int c, int *mc) {
  node_t* n = NULL; // new stack node
  stack_t* s = NULL;
  node_t* sn = NULL; // stack node
  list_t* l1 = NULL; // list1
  list_t* l2 = NULL; // list2
  node_t* l1n = NULL; // list1 node
  node_t* l2n = NULL; // list2 node
  node_t* nl1n = NULL;  // new list1 node
  node_t* nl2n = NULL;  // new list2 node
  int num = 0;
  int *mcn;
  int i, j, k = 0;
  int rc, diff = 0;

  mcn = (int *) malloc (sizeof(int) * c);
  for (i = 0; i < c; i++) 
    mcn[i] = m / mc[i];

  s = stack();
  j = 0;
  for (i = 0; i < mcn[j] + 1; i++) {
    if (c % mc[j] == 0) {
      malloc_node(sn, c + 2); // (15, 0, 0, 0), (left money), depth
      sn->depth = 0;
      sn->data[sn->depth] = i;
      sn->data[c] = m - (mc[j] * i); 
      push(s, sn);
      sn = NULL;
    }
  }

  while (s->size != 0) {
    sn = pop(s); 
    
    if (sn->depth == c-1) {
      // find case : last leaf, sn->depth is c-1
      if (l1 == NULL) {
        l1 = list();
        malloc_node(l1n, 2); // (left money, number of case)
      } else {
        l1n = search1(l1, 0, sn->data[0]);  
        if (l1n == NULL) {
          // not found
          malloc_node(l1n, 2);
        } else {
          // found
        }
      }
      l2 = l1n->list; 
      if (l2 == NULL) {
        l2 = list();
        malloc_node(l2n, c);  // ex : (15, 0, 0, 0)

        l2n->data[sn->depth] = sn->data[sn->depth];    
        append(l2, l2n);

        l1n->data[0] = sn->data[c]; // money
        l1n->data[1] = 1;
      } else {
        l2n = search2(l2, c, sn->data);
        if (l2n == NULL) {
          // not found
          malloc_node(l2n, c);

          l2n->data[sn->depth] = sn->data[sn->depth];    
          append(l2, l2n);

          l1n->data[0] = sn->data[c]; // money
          l1n->data[1] = 1;
        } else {
          // found
        }
      }
      num++;
      free_node(sn);

    } else {
      if (sn->data[0] % mc[sn->depth] == 0) {
        for (i = 0; i < mcn[sn->depth] + 1; i++) {
          diff = sn->data[0] - (mc[sn->depth] * i);
          
          l1n = search1(l1, 0, diff);  
          if (l1n == NULL) {
            // not found
            malloc_node(l1n, 2);
          } else {
            // found
            l1n = search1(l1, 0, diff);     
            if (l1n == NULL) {
              // not found
              malloc_node(l1n, 2);
            } else {
              // found
            }
            l2 = l1n->list;
            if (l2 == NULL) {
              // not found
              malloc_node(n, c+2);
              copy_node(sn, n, c+2); 
              n->data[n->depth] = i;
              n->data[c] = diff;  
              n->depth++;
              push(s, n);
              n = NULL;
            } else {
              l2n = search2(l2, c, sn->data);
              if (l2n == NULL) {
                // not found
                malloc_node(n, c+2);
                copy_node(sn, n, c+2); 
                n->data[n->depth] = i;
                n->data[c] = diff;  
                n->depth++;
                push(s, n);
                n = NULL;
              } else {
                // found
                
                malloc_node(nl2n, c); 
                for(k = 0; k < c; k++) {
                  if (k < sn->depth)  
                    nl2n->data[k] = sn->data[k];
                  else if (k == sn->depth)
                    nl2n->data[sn->depth] = i;
                  else 
                    nl2n->data[k] = l1n->data[1];
                }

                malloc_node(nl1n, 2);
                nl1n->data[0] = sn->data[0];
                nl1n->data[1] = 1;
                
                nl1n = NULL;
                nl2n = NULL;
              }
            }
          }
        }
        free_node(sn);
      } else {
        free_node(sn);
      }
    }
  }

  n = l1->head;
  while(n) {
    free_list(n->list);
    n = n->next;
  }
  free_list(l1);

  free(s);
  free(mcn);
  return num;
}

int main() {
  int tc = 0; /* test case */
  int i, j = 0;
  int m, c = 0;
  int *mc;
  int rc = 0;

  scanf("%d", &tc);

  for (i = 0; i < tc ; i++ ) {
    scanf("%d %d", &m, &c);

    mc = (int *) malloc (sizeof(int) * m);
    for (j = 0; j < m; j++) {
      scanf("%d", &mc[j]);
    }
    rc = get_numberofcase(m, c, mc);

    free(mc);

  }

  return 0;
}
