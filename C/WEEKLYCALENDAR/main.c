#include <stdio.h>
#include <string.h>

int lastday[12] = {
  31, 28, 31, 30, 31, 30,
  31, 31, 30, 31, 30, 31};

int week2diff(char *iweek, int *diff) {
  if (!strcmp(iweek, "Sunday")) {
    *diff = 0;
    return 0;
  } else if (!strcmp(iweek, "Monday")) {
    *diff = 1;
    return 0;
  } else if (!strcmp(iweek, "Tuesday")) {
    *diff = 2;
    return 0;
  } else if (!strcmp(iweek, "Wednesday")) {
    *diff = 3;
    return 0;
  } else if (!strcmp(iweek, "Thursday")) {
    *diff = 4;
    return 0;
  } else if (!strcmp(iweek, "Friday")) {
    *diff = 5;
    return 0;
  } else if (!strcmp(iweek, "Saturday")) {
    *diff = 6;
    return 0;
  }
  return -1;
}

int main() {
  int rc = 0;
  int tc = 0; /* test case */
  int i = 0, j = 0;
  int imonth = 0, iday = 0, oday = 0;
  char idayofweek[256] = "\0";
  int diff = 0, start = 0, month;

  scanf("%d", &tc);

  for (i = 0; i < tc ; i++ ) {
    imonth = 0, iday = 0;
    memset(idayofweek, 0x00, sizeof(idayofweek));

    scanf("%d %d %s", &imonth, &iday, idayofweek);

    //printf("%d %d %s\n", imonth, iday, idayofweek);
    rc = week2diff(idayofweek, &diff);

    //printf("d(%d)\n", diff);
    if (iday - diff > 0) {
      start = iday - diff;

      month = imonth-1;
      for (j = start; j < start + 7; j++) {
        oday = j%lastday[month];

        if (oday) printf("%d", oday);  
        else printf("%d", lastday[month]);

        printf(" ");
      }
      printf("\n");

    } else {
      //printf("di(%d)\n", iday - diff);

      if (imonth == 1)
        month = 11;
      else
        month = imonth-2;

      start = lastday[month] + (iday - diff);
      //printf("s(%d)\n", start);
      for (j = start; j < start + 7; j++) {
        oday = j%lastday[month];

        if (oday) printf("%d", oday);  
        else printf("%d", lastday[month]);

        printf(" ");
      }
      printf("\n");

    }
  }

  return 0;
}
