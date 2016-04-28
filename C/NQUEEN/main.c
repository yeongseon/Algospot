#include <stdio.h>
#include <stdlib.h>

int get_nqueen(int in, int *onq) {
  int i, j = 0;
  char *col;
  
  for (i = 0; i < in; i++) {
    col = (char *)malloc(sizeof(char)*in);

    for (j = i; j < in; j++) {
      
    }
    free(col);

  }
}

int main() {
  int rc = 0;
  int tc = 0; /* test case */
  int n = 0;
  int i = 0, nq = 0;

  scanf("%d", &tc);

  for (i = 0; i < tc ; i++ ) {
    scanf("%d", &n);
    rc = get_nqueen(n, &nq);
    printf("%d\n", nq);
  }

  return 0;
}
