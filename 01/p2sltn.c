#include <stdio.h>

int main(int argc, char *argv)
{
  FILE *f = fopen("input.txt", "r");
  FILE *f2 = fopen("input.txt", "r");
  int tot = 0;

  fseek(f2, 0, SEEK_END);
  fseek(f2, ftell(f2)/2, SEEK_SET);

  char c1, c2;
  c1 = fgetc(f);
  c2 = fgetc(f2);
  
  while (c2 >= '0')
    {
      if (c1 == c2) tot += (c1-'0')<<1;
      c1 = fgetc(f);
      c2 = fgetc(f2);
    }

  printf("total = %d\n", tot);

  fclose(f);
  fclose(f2);
  return 0;
}
 
