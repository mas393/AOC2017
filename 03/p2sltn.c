#include <stdio.h>
#include <string.h>
#include <math.h>

int square_calc(int index)
{
  int res = (int)sqrt(index)+1;
  if (res % 2 == 0) res++;
  res = (res-1)/2;
  return res;
}

void step(int x, int y, int *dx, int *dy, int square)
{
  if ((*dx == 1) && (x == square))
    {
      *dx = 0;
      *dy = 1;
    }
  else if ((*dy == 1) && (y == square))
    {
      *dx = -1;
      *dy = 0;
    }
  else if ((*dx == -1) && (x == -square))
    {
      *dx = 0;
      *dy = -1;
    }
  else if ((*dy == -1) && (y == -square))
    {
      *dx = 1;
      *dy = 0;
    }
}

int main(void)
{
  double input = 347991;
  int sqr = 2*(log(input)/log(2)/4)+1;
  sqr += 4; //buffer of 1 on all sides so sum_surrounding does not query unallocated mem at the edge of the array;
  if (sqr % 2 == 0) sqr++;
  int offset = sqr/2 + 1;  

  int vals[sqr][sqr];
  
  memset(vals, 0, sqr*sqr*sizeof(int));

  int sum = 1;
  int square = 0;
  int x = 0+offset;
  int y = 0+offset;
  int dx = 1;
  int dy = 0;
  int i = 0;

  while (sum < input)
    {
      vals[x][y] = sum;
      i++;
      square = square_calc(i);
      step(x-offset, y-offset, &dx, &dy, square);
      x += dx;
      y += dy;

      sum = 0;
      sum += vals[x+1][y];
      sum += vals[x+1][y+1];
      sum += vals[x][y+1];
      sum += vals[x-1][y+1];
      sum += vals[x-1][y];
      sum += vals[x-1][y-1];
      sum += vals[x][y-1];
      sum += vals[x+1][y-1];
    }
  
  printf("result = %d\n", sum);
}
