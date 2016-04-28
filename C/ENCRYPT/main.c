#include <stdio.h>
#include <string.h>

int get_output(char *istr, char *ostr) {
  int cnt = 0;

  while(*istr) {
    if (cnt%2) {
      //printf("%c", *istr);
      *ostr = *istr;
      ostr++;
    } else {
      printf("%c", *istr);
    }

    istr++;
    cnt++;
  }
}

int main() {
  int tc = 0; /* test case */
  int i = 0, j = 0;
  char istr[100 + 1] = "\0";
  char ostr[100 + 1] = "\0";

  scanf("%d", &tc);

  if (tc < 0 && tc > 10)
    return -1;

  for (i = 0; i < tc ; i++ ) {
    memset(istr, 0x00, sizeof(istr));
    memset(ostr, 0x00, sizeof(ostr));
    scanf("%s", istr);

    //printf("%s\n", str);
    
    get_output(istr, ostr);
    printf("%s\n", ostr);
    
  }

  return 0;
}
