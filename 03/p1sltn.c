#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
  double input = 347991;
  int sqr = (int)sqrt(input)+1;
  if (sqr % 2 == 0) sqr++;
  int place = input - pow(sqr-2, 2)-1;

  int awayperp = sqr/2 + 1;
  int offset = (sqr - 1)/2 - 1;
  for (int i = 0; i < 4; i++) {
    if ((place - (i*(sqr-1) + offset)) < awayperp)
      {
	awayperp = place - (i*(sqr-1) + offset);
	break;
      }
  }
  
  printf("result = %d\n", awayperp+(sqr/2));

  return 0;
}
