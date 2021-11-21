#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f = fopen("input.txt", "r");

  fseek(f, 0, SEEK_END);
  int arr_size = ftell(f);
  fseek(f, 0, SEEK_SET);

  int *arr = malloc(arr_size*sizeof(int));

  int i = 0;
  while(!feof(f))
    {
      int v;
      fscanf(f, "%d", &v);
      arr[i] = v;
      i++;
    }

  int index = 0;
  int steps = 0;
  
  while (index <= i-2)
    {
      steps++;
      int shift = arr[index];
      if (arr[index] < 3) arr[index]++;
      else arr[index]--;
      index += shift;
    }
  
  printf("result = %d\n", steps);
  fclose(f);
  free(arr);
  return 1;
}
  
