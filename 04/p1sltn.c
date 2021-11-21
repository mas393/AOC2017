#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VALSIZE 50

typedef struct tree {
  char val[MAX_VALSIZE];
  struct tree *lt;
  struct tree *gt;
} tree;

int tree_insert(tree *head, tree *new)
{
  int added = 0;
  if (strcmp(new->val, head->val) > 0)
    {
      if (head->lt == NULL)
	{
	  head->lt = new;
	  added = 1;
	}
      else added = tree_insert(head->lt, new); 
    }
  else if (strcmp(new->val, head->val) < 0)
    {
      if (head->gt == NULL)
	{
	  head->gt = new;
	  added = 1;
	}
      else added = tree_insert(head->gt, new);
    }
  else added = 0;

  return added;    
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
      strcpy(t->val, "m");
      strcpy(line2, line);
      
      word = strtok(line, s);
      
      while(word!=NULL)
	{
	  if (word[strlen(word)-1] == '\n') word[strlen(word)-1] = '\0';
	  tree *new = malloc(sizeof(tree));
	  new -> lt = NULL;
	  new -> gt = NULL;
	  strcpy(new->val, word);
	  if (tree_insert(t, new) == 0)
	    {
	      //	      printf("fail line %d, %s\n", l, line2);
	      valid = 0;
	      break;
	    }
	  word = strtok(NULL, s);
	}
      
      tot += valid;
      l++;
    }
  printf("result = %d\n", tot);
  return 0;
}
