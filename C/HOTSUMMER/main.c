#include <stdio.h>
#include <string.h>


int main() {
  int tc = 0; /* test case */
  int i = 0, j = 0, k = 0;
  int T = 0, S = 0, W = 0, temp = 0;

  scanf("%d", &tc);

  for (i = 0; i < tc ; i++ ) {

    W = 0, S = 0;
    scanf("%d", &W);

    for (j = 0; j < 9; j++) {

      temp = 0;
      scanf("%d", &temp);
      S += temp;
    }

    if (S > W)    
      printf("NO\n");
    else
      printf("YES\n");
  }

  return 0;
}
