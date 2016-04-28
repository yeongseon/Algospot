#include <stdio.h>
#include <stdlib.h>
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

  node->array = (char *)malloc(sizeof(char)*size*size);
  for(i = 0; i < size*size; i++) {
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

int print_array(char *array, int n) {
  int i, j = 0;
  for (i = 0; i < n; i++) { // column
    for (j = 0; j < n; j++) {
      printf("%d ", array[i*n + j]);
    }
    printf("\n");
  }

  printf("\n");
  for (i = 0; i < n*n; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int set_array(char *array, int n, int x, int y) {
  int i, j = 0;

  // pos = x + column * y
  array[(x)*n + (y)] = 1;

  for (i = 0; i < n; i++) {
    array[n*i + y] = 1;
    array[n*(x) + i] = 1;
  }

  for (i = x, j = y; i < n && j < n; i++, j++) {
    array[n*(i) + (j)] = 1;
  }

  for (i = x, j = y; i > -1 && j > -1; i--, j--) {
    array[n*(i) + (j)] = 1;
  }

  for (i = x, j = y; i < n  && j > -1; i++, j--) {
    array[n*(i) + (j)] = 1;
  }

  for (i = x, j = y; i > -1 && j < n; i--, j++) {
    array[n*(i) + (j)] = 1;
  }
}

int copy_array(char *iarray, char *oarray, int n) {
  int i = 0;

  for (i = 0; i < n*n ; i++) {
    oarray[i] = iarray[i];
  }
}

int get_nqueen(int n, int *nq) {
  int i, j = 0;
  char *array = NULL, *tarray = NULL;
  queue_t *q;
  node_t *t;

  q = queue();

  array = (char *)malloc(sizeof(char) * n*n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      memset(array, 0x00, sizeof(char) * n*n);
      set_array(array, n, i, j);
#if 1
  print_array(array, n);
#endif
      enqueue(q, array, n, 1);
    }
  }

  //printf("size(%d)\n", size(q));
  while (size(q)) {
    t = dequeue(q);

    //printf("nq(%d), n(%d)\n", t->nqueen, n);

    if (t->nqueen == n) {
      (*nq)++;
      free(t->array);
      free(t);
    } else {

      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          copy_array(t->array, array, n);

          if(array[i*n + j]) {
            continue;
          } else {
            set_array(array, n, i, j);
            enqueue(q, array, n, t->nqueen+1);
          }
        }
      }
      free(t->array);
      free(t);
    }

  }
  
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
#if 0
  char temp3[4*4] = {0};
  int m, n = 0;

  for (m = 0; m < 4; m++) {
    for (n = 0; n < 4; n++) {
      memset(&temp3, 0x00, sizeof(temp3));
      set_array(temp3, 4, m, n); 
      print_array(temp3, 4);
    }
  }
  print_array(temp3, 4);
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
