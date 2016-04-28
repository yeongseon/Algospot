#include <stdio.h>
#include <stdlib.h>

int main() {
  int tc = 0; /* test case */
  int i, j = 0;
  int k, n = 0;

#if 0
  int k = 5000000;
  int n = 50000000;
  printf("k(%d)\nd(%d)\n", k, n);
#endif
#if 0
  long a = 1;
  for (i = 0; i < 32; i++) {
    printf("%d\t%ld\n", i, a=2*a);
  }
#endif
#if 0
  long  A = 1983;
  int a = A % 10000 + 1;

  for (i = 0; i< 5; i++) {
    printf("a(%d)\n", a);
    A = (A * 214013 + 2531011) % 4294967296;
    a = A % 10000 + 1;
  }
#endif

#if 1
  long A = 1983;
  long S = 0; // Sum
  int *a;
  int index = 0;
  int cnt = 0;

  scanf("%d", &tc);
  for (i = 0; i < tc ; i++ ) {
    S = 0;
    index = 0;
    cnt = 0;
    scanf("%d %d", &k, &n);

    a = (int *)malloc(sizeof(int) * n); 
    
    for (j = 0; j < n; j++) {
      a[j] = A % 10000 + 1;
      S = S + a[j];
#if 0
      printf("n(%d) : a[%d](%d), S(%d), index(%d)\n", n, j, a[j], S, index);
#endif
      if (S == k) {
        cnt++;
        S = S - a[index];
        index++;
      } else if (S > k) {
        while (S > k) {
          S = S - a[index];
          index++;
          if (S == k) {
            printf("index(%d), S(%ld)\n", index, S);
            cnt++;
            S = S - a[index];
            index++;
            
          }
        }
      }
      
      A = (A * 214013 + 2531011) % 4294967296;
    }
    printf("%d\n", cnt);
    free(a);
  }
#endif
  return 0;
}
