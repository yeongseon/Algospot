#include <stdio.h>
#include <stdlib.h>

char friend[10][10];

void clear_array(char array[][10][10]) {
  int i, j = 0;

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      (*array)[i][j] = 0;
    }
  }
}
#if 0
int make_paring(char *iflag, int in) {
  int rc = 0;
  int i, j = 0;
  int finish = 1;

  for (i = 0; i < in; i++) {
    if (!iflag[i])
      finish = 0;
  }

  if (finish) return 1;

  rc = 0;
  
  for (i = 0; i < in; i++) {
     for (j = 0; i < in ; i++) {
       if (!iflag[i] && !iflag[j] && friend[i][j]) {
          iflag[i] = iflag[j] = 1; 
          rc += make_paring(iflag, in); 
          iflag[i] = iflag[j] = 0; 
       }
     }
  }
  return rc;
}
#endif

int make_paring(char *iflag, int in) {
  int rc = 0;
  int i = 0;
  int free = -1;

  for (i = 0; i < in; i++) {
    if (!iflag[i]) {
      free = i;
      break;
    }
  }

  if (free == -1) return 1;

  rc = 0;

  for (i = free+1; i < in; i++) {
    if (!iflag[free] && !iflag[i] && friend[free][i]) {
#if 0
#endif
      iflag[free] = iflag[i] = 1; 
      rc += make_paring(iflag, in); 
      iflag[free] = iflag[i] = 0; 
    }
  }
  return rc;
}


int get_count(int in, int *on) {
  int i =0;
  char *flag;
  flag = (char *)malloc(sizeof(char) * in);
  for (i = 0; i < in; i++)
    flag[i] = 0;
  *on = make_paring(flag, in); 
  free(flag);
}

int main() {
  int tc = 0; /* test case */
  int m, n = 0;
  int i, j, k, l = 0;
  int count = 0;

  scanf("%d", &tc);

  for (i = 0; i < tc ; i++ ) {

    clear_array(&friend);
      
    scanf("%d %d", &n, &m);

    for (j = 0; j < m; j++) {
      scanf("%d %d", &k, &l);
      friend[k][l] = 1;
      friend[l][k] = 1;
    }

    get_count(n, &count); 

    printf("%d\n", count);

#if 0
    for (k = 0; k < 10; k++) {
      for (l = 0; l < 10; l++) {
        printf("%d ", friend[k][l]);
      }
      printf("\n");
    }
    printf("\n");
#endif
  }

  return 0;
}
