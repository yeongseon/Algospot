#include <stdio.h>
#include <string.h>


int get_str(char *istr, char *ostr) {
  char even[50] = "\0", odd[50] = "\0";
  int cnt = 0, temp = 0;

  while(*istr) {

    if (cnt%2) { // odd
      //printf("%c\n", *istr);
      odd[cnt/2] = *istr;
    } else { // even
      //printf("%d, %c\n", cnt, *istr);
      even[cnt/2] = *istr;
    }

    cnt++;
    istr++;
  }

  cnt = 0;
  while(even[cnt]) {
    //printf("%c", even[cnt]);
    *ostr = even[cnt];

    cnt++;
    ostr++;
  }

  cnt = 0;
  while(odd[cnt]) {
    *ostr = odd[cnt];

    cnt++;
    ostr++;
  }
  

  return 0;
}

int main() {
  int tc = 0; /* test case */
  int i = 0, j = 0;
  char str[100] = "\0";
  char ostr[100] = "\0";

  scanf("%d", &tc);

  if (tc < 0 && tc > 10)
    return -1;

  for (i = 0; i < tc ; i++ ) {
    memset(str, 0x00, sizeof(str));
    memset(ostr, 0x00, sizeof(ostr));
    scanf("%s", str);

    //printf("%s\n", str);
    
    get_str(str, ostr); 
    printf("%s\n", ostr);
  }

  return 0;
}
