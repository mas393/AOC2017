#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  int val;
  struct list *next;
} list;

int main(int argc, char **argv)
{
  FILE *f = fopen("input.txt", "r");

  int size = 16;
  list *l;
  int v;
  int checksum = 0;
  
  for (int i = 0; i < size; i++)
    {
      l = (list *)malloc(sizeof(list));
      fscanf(f, "%d", &(l->val));

      l->next = NULL;
      list *temp = (list *)malloc(sizeof(list));
      
      for (int j = 0; j < (size-1); j++)
	{
	  fscanf(f, "%d", &v);
	  

	  temp = l;
	  
	  for(;;)
	    {
	      if ((temp -> val % v) == 0)
		{
		  checksum += temp -> val / v;
		  //printf("row = %d temp -> val = %d v = %d\n", i, temp->val, v);
		  break;	
		}
	      else if ((v % temp -> val) == 0)
		{
		  checksum += v / temp -> val;
		  //printf("row = %d v = %d temp -> val = %d\n", i, v, temp->val);
		  break;
		}

	      if (temp->next == NULL) break;
	      temp = temp -> next;
	    }


	  list *doubletemp = (list *)malloc(sizeof(list));
	  temp -> next = doubletemp;
	  doubletemp -> val = v;
	  doubletemp -> next = NULL;
	}
      
    }

  printf("result = %d\n", checksum);
  
  fclose(f);
  return 0;
}
 
