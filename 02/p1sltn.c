#include <stdio.h>

int main(int argc, char **argv)
{
  FILE *f = fopen("input.txt", "r");

  int size = 16;
  int checksum = 0;
  int lowb, upb, val;
  
  for (int i = 0; i < size; i++)
    {
      fscanf(f, "%d", &lowb);
      upb = lowb;
      
      for (int j = 0; j < size-1; j++)
	{
	  fscanf(f, "%d", &val);
	  if (val > upb) upb = val;
	  else if (val < lowb) lowb = val;
	}

      checksum += upb - lowb;   	
    }

  printf("result = %d\n", checksum);
  
  fclose(f);
  return 0;
}
 
