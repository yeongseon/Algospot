#include <stdio.h>
#include <string.h>

int get_pos(int *in) {
  if (in[0] == in[1])
    return in[2];
  else if (in[0] == in[2])
    return in[1];
  else return in[0];
}

int main() {
  int tc = 0; /* test case */
  int i = 0, j = 0;
  int x[3], y[3];

  scanf("%d", &tc);

  for (i = 0; i < tc ; i++ ) {
    memset(x, 0x00, sizeof(x));
    memset(y, 0x00, sizeof(y));

    for (j = 0; j < 3; j++) {
      scanf("%d %d", &x[j], &y[j]);
    }
/*
    for (j = 0; j < 3; j++) {
      printf("%d %d\n", x[j], y[j]);
    }
*/
    printf("%d %d\n", get_pos(x), get_pos(y));
  }

  return 0;
}
