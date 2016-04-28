#include <stdio.h>
#include <stdlib.h>

typedef struct node_s node_t;
typedef struct list_s list_t;

struct node_s {
  int depth;
  int dlen;
  int *dp;
  node_t *next;
};

struct list_s {
  int size;
  node_t *head;
  node_t *tail;
};

node_t* node(int datalen, int *data) {
  int i = 0;
  node_t* n; 
  n = (node_t *) malloc (sizeof(node_t));
  n->dlen = datalen;
#if 1
  n->dp = (int *) malloc (sizeof(int) * datalen);
  for(i = 0; i < datalen; i++) {
    n->dp[i] = data[i];
  }
#endif
  return n;
}

int node_free(node_t *n) {
  if (n == NULL)
    return -1;
  if (n->dp) {
    free(n->dp);
    n->dp = NULL;
  }
  return 0;
}

list_t* list() { 
  list_t *l;
  l = (list_t *) malloc (sizeof(list_t));
  l->size = 0;
  l->head = NULL;
  l->tail = NULL;
  return l;
}

int list_free(list_t *l) {
  free(l);
  l = NULL;
}

node_t* list_head(list_t *l) {
  if (l == NULL)
    return NULL;
  return l->head;
}

node_t* list_tail(list_t *l) {
  if (l == NULL)
    return NULL;
  return l->tail;
}

node_t* list_next(node_t *n) {
  if (n == NULL)
    return NULL;

  if (n->next == NULL)
    return NULL;
  else
    return n->next;
}

int list_insert_tail(list_t *l, node_t *n) {
  if (l == NULL)
    return -1;

  if (l->size == 0) {
    l->head = n;
    l->tail = n;
  } else {
    l->tail->next = n;
    l->tail = n;
  }

  l->size++;
  return 0;
}

int list_insert_head(list_t *l, node_t *n) {
  return 0;
}

int list_remove_head(list_t *l) {
  node_t *dn;  // delete node
  if (l == NULL)
    return -1;

  if (l->size == 0) {
    return 0;
  } else if (l->size == 1) {
    free(l->head);
    l->head = NULL; 
    l->tail = NULL;
    l->size = 0;
  } else {
    dn = l->head;
    l->head = dn->next;
    free(dn);
    l->size--;
  }
  return 0;
}

int list_remove_tail(list_t *l) {
  int i = 0;
  node_t *tail; //  
  if (l == NULL)
    return -1;
  
  if (l->size == 0) {
    return 0;
  } else if (l->size == 1) {
    free(l->tail);
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
  } else {
    free(l->tail);
    tail = l->head;
    for (i = 0; i < l->size-1; i++)
      tail = tail->next;
    l->tail = tail;
    l->tail->next = NULL; 
    l->size--;
  }
}

int list_size(list_t *l) {
  if (l == NULL)
    return -1;
  return l->size;
}

int list_print(list_t *l, int n) {
  int i = 0;
  node_t* r; // runner;
  r = l->head;
  while (r) {
    for (i = 0; i < n; i++) 
      printf("(%d) ", r->dp[i]); 
    printf("\n");
    r = r->next;
  }
}

int get_numberofcase(int m, int c, int *cp) {
  int i, j = 0;
#if 0
  printf("money(%d), case(%d)\n", m, c);
  for (i = 0; i < c; i++) {
    printf("(%d) ", cp[i]);
  }
  printf("\n");
#endif
  int num = 0;
  int *cpn, *data;
  list_t *l1;
  node_t *n1;

  cpn = (int *) malloc (sizeof(int) * c);
# if 1
  for (i = 0; i < c; i++) {
    cpn[i] = cp[c-1] / cp[i];
    printf("cpn(%d) ", cpn[i]);
  }
  printf("\n");
#endif 

  l1 = list();
  data = (int *) malloc (sizeof(int) * (c+1));
  j = 0;
  for (i = 0; i < cpn[j]+1; i++) {
    data[j] = i;
    n1 = node(c+1, data);
    list_insert_tail(l1, n1);
  }
  j++;
  free(data);
  data = NULL;

  printf("size(%d)\n", l1->size);
  list_print(l1, c);


  free(cpn); 
  cpn = NULL;
  return num;
}

int main() {
  int rc = 0;
  int t, m, c = 0; // testcase, money, case
  int *cp = NULL; // case pointer
  int i, j = 0;

  scanf("%d", &t);
  for (i = 0; i < t ; i++ ) {
    scanf("%d %d", &m, &c);
    cp = (int *) malloc (sizeof(int) * c);
    for (j = 0; j < c; j++) {
      scanf("%d", &cp[j]);
    }
    rc = get_numberofcase(m, c, cp);
    free(cp);
  }

  return 0;
}
