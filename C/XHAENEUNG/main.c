#include <stdio.h>
#include <string.h>

char num[11][10] = {"zero", "one", "two", "three", "four", "five",
  "six", "seven", "eight", "nine", "ten"};

int str2int(char *istr, int *oint) {
  
  if (!strcmp(istr, "zero")) {
    *oint = 0;
    return 0;
  }else if (!strcmp(istr, "one")) {
    *oint = 1;
    return 0;
  } else if (!strcmp(istr, "two")) {
    *oint = 2;
    return 0;
  }else if (!strcmp(istr, "three")) {
    *oint = 3;
    return 0;
  }else if (!strcmp(istr, "four")) {
    *oint = 4;
    return 0;
  }else if (!strcmp(istr, "five")) {
    *oint = 5;
    return 0;
  }else if (!strcmp(istr, "six")) {
    *oint = 6;
    return 0;
  }else if (!strcmp(istr, "seven")) {
    *oint =  7;
    return 0;
  }else if (!strcmp(istr, "eight")) {
    *oint = 8;
    return 0;
  }else if (!strcmp(istr, "nine")) {
    *oint = 9;
    return 0;
  }else if (!strcmp(istr, "ten")) {
    *oint = 10;
    return 0;
  }
  
  return -1;
}

int get_result(char *op, int ia, int ib, int *oc) {

  if (!strcmp(op, "+")) {
    *oc = ia + ib;
  }else if (!strcmp(op, "-")) {
    *oc = ia - ib;
  }else if (!strcmp(op, "*")) {
    *oc = ia * ib;
  }else {
    return -1;
  }

  if (*oc < 0 || *oc > 10) {
    return -1;
  }

  return 0;
}

int check(int ic, char *istr) {
  char *temp = num[ic], *temp2;
  //printf("%s\n", temp);
  //printf("%s\n", istr);

  if (strlen(temp) != strlen(istr))
    return -1;

  while(*temp) {
    temp2 = istr;
    while(*temp2) {
      if (*temp == *temp2)
        *temp2 = 'A';
      temp2++;
    }
    
    temp++;
  }

  while(*istr) {
    if (*istr != 'A')
      return -1;
    istr++;
  }
  return 0;
}

int main() {
  int rc = 0;
  int tc = 0; /* test case */
  int i = 0;
  char A[10] = "\0", B[10] = "\0", C[10] = "\0", operation[10] = "\0", equal[10] = "\0";
  int a = 0, b = 0,  c = 0;

  scanf("%d", &tc);

  for (i = 0; i < tc ; i++ ) {

    scanf("%s %s %s %s %s", A, operation, B, equal, C);
    
    //printf("%s %s %s %s %s\n", A, operation, B, equal, C);
    rc = str2int(A, &a);
    if (rc < 0) {
      printf("No\n");
      continue;
    }
      
    rc = str2int(B, &b);
    if (rc < 0) {
      printf("No\n");
      continue;
    }

    rc = get_result(operation, a, b, &c);
    if (rc < 0) {
      printf("No\n");
      continue;
    }
    //printf("%d, %d, %d\n", a, b, c);

    rc = check(c, C);    
    if (rc < 0) {
      printf("No\n");
      continue;
    } else {
      printf("Yes\n");
      continue;
    }

  }

  return 0;
}
