#include <stdio.h>

int main(int argc, char **argv)
{
  FILE *f = fopen("input.txt", "r");
  int tot = 0;
  char first, a, b;
  a = fgetc(f);
  first = a;
  
  while (a >= '0')
    {
      b = a;
      a = fgetc(f);
      if (a == b) tot += (b-'0');
    }

  if (b == first) tot += (b-'0');
  printf("total = %d\n", tot);

  fclose(f);
  return 0;
}
 
