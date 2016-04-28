#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node_s node_t;
typedef struct node_s {
  char *array;
  int nqueen;
  node_t *next;
} node_t;

typedef struct queue_s queue_t;
typedef struct queue_s {
  int size;
  node_t *front;
  node_t *rear;
} queue_t;

queue_t* queue() {
  queue_t *q = (queue_t *)malloc(sizeof(queue_t));

  q->size = 0;
  q->front = NULL;
  q->rear = NULL;

  return q;
}

int enqueue(queue_t *q, char *data, int size, int queen) {
  int i = 0;
  node_t* temp;
  node_t* node = (node_t *)malloc(sizeof(node_t));
  node->next = NULL;

  node->array = (char *)malloc(sizeof(char)*size);
  for(i = 0; i < size; i++) {
    node->array[i] = data[i];
  }
  node->nqueen = queen;

  if (q->size == 0) {
    q->front = node;
    q->rear = node;
    q->size++;
  } else {
    temp = q->rear;
    temp->next = node;
    q->rear = node;
    q->size++;
  }
}

node_t* dequeue(queue_t *q) {
  node_t* temp;
  if (q->size == 0)
    return NULL;
  else {
    temp = q->front;
    q->front = temp->next;
    q->size--;
    return temp;
  }
}

int size(queue_t *q) {
  if(q == NULL)
    return -1;
  else
    return q->size;
}

int copy_array(char *iarray, char *oarray, int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    oarray[i] = 0;
    oarray[i] = iarray[i];
  }
}

// x = q
int promissing(char *array, int q, int p) {
  int i = 0;

  for (i = 0; i < q; i++) {
    if (array[i] == p)
      return -1;
    else if (abs(q-i) == abs(p-array[i]))
      return -1;
  }

  return 0;
}

int print_array(char *array, int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("(%d) ", array[i]);
  }
  printf("\n");
}

int get_nqueen(int n, int *nq) {
  int i = 0;
  char *array = NULL, *tarray = NULL;
  queue_t *q;
  node_t *t;

  *nq = 0;
  q = queue();

  array = (char *)malloc(sizeof(char) * n);
  memset(array, 0x00, sizeof(char) * n);

  for (i = 0; i < n; i++) {
      array[0] = i;
      enqueue(q, array, n, 1);
  }
#if 0
  printf("size(%d), n(%d)\n", size(q), n);
#endif
  while (size(q)) {
    t = dequeue(q);

    if (t->nqueen == n) {
#if 0
  printf("size(%d), n(%d), t->nquuen(%d)\n", size(q), n, t->nqueen);
#endif
      (*nq)++;
      free(t->array);
      free(t);
    } else {

      for (i = 0; i < n; i++) {
          if(promissing(t->array, t->nqueen, i) == 0) {
            copy_array(t->array, array, n);
            array[t->nqueen] = i;
#if 0
            print_array(array, n);
#endif
            enqueue(q, array, n, t->nqueen+1);

          }
      }

      free(t->array);
      free(t);
    }

  }

  free(array);
  
  return 0;
}

int main() {
  int rc = 0;
  int C = 0, N = 0; /* test case */
  int nq = 0;
  int i = 0;

#if 0
  int m, n = 0;
  char temp1[9] = {0};
  char temp2[4] = {0};
  char temp3[8*8] = {0,};
  queue_t* q; 
  node_t* t;
  q = queue();
  printf("size(%d)\n", size(q));
  enqueue(q, temp1, 3, 1);
  enqueue(q, temp2, 3, 1);
  enqueue(q, temp2, 3, 1);
  printf("size(%d)\n", size(q));
  t = dequeue(q); 
  printf("size(%d)\n", size(q));
  for (m = 0; m < 3; m++) {
    for (n = 0; n < 3; n++) {
      printf("(%d) ", t->array[m * 3 + n]);
    }
  }
#endif
#if 1
  scanf("%d", &C);
  for (i = 0; i < C ; i++ ) {
    scanf("%d", &N);
    get_nqueen(N, &nq);
    printf("%d\n", nq);
  }
#endif
  return 0;
}
