#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORDSIZE 15

typedef struct tree {
  long val;
  char w[MAXWORDSIZE];
  struct tree *lt;
  struct tree *gt;
} tree;

int tree_insert(tree *head, tree *new)
{
  int added = 0;
  if (new->val < head->val)
    {
      if (head->lt == NULL)
	{
	  head->lt = new;
	  added = 1;
	}
      else added = tree_insert(head->lt, new); 
    }
  else if (new->val > head->val)
    {
      if (head->gt == NULL)
	{
	  head->gt = new;
	  added = 1;
	}
      else added = tree_insert(head->gt, new);
    }
  else if (new-> val == head->val)
    {
      added = 0;
    }

  return added;    
}

long asciicount(char *w)
{
  long res = 1;

  for (int i=0; i<strlen(w); i++) res*=(long)w[i];
  
  return res;
}
 

int main(void)
{
  FILE *f = fopen("input.txt", "r");

  int buffsize = 200;
  char line[buffsize];
  char line2[buffsize];
  char *s = " ";
  char *word;
  int tot = 0;
  int l = 0;

  while(fgets(line, buffsize, f))
    {
      int valid = 1;
      tree *t = malloc(sizeof(tree));

      t-> lt = NULL;
      t-> gt = NULL;
      
      strcpy(line2, line);
      
      word = strtok(line, s);
      if (word!=NULL) t->val = asciicount(word);

      word = strtok(NULL, s);
      while(word!=NULL)
	{
	  if (word[strlen(word)-1] == '\n') word[strlen(word)-1] = '\0';

	  tree *new = malloc(sizeof(tree));
	  new -> lt = NULL;
	  new -> gt = NULL;
	  new -> val = asciicount(word);
	  
	  if (tree_insert(t, new) == 0) valid = 0;

	  word = strtok(NULL, s);
	}
      tot += valid;
      l++;
    }
  printf("result = %d\n", tot);
  return 0;
}
