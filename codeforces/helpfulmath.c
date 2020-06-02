#include <stdio.h>
#include <string.h>
int main()
{
  char string[10000];
  scanf("%s", string);
  int len = strlen(string);
  int add_len = (len/2)+1;
  int array[add_len];
  int j = 0;
  for(int i = 0;i<len;i++)
  {
    if(string[i] == '+')
    {
      i++;
    }
    else
    {
      array[j] = string[i]-'0';
      j++;
      i++;
    }
  }

  int array_sort[3];
  for(int i = 0;i<3;i++)
  {
    array_sort[i] = 0;
  }
  for(int i = 0;i<add_len;i++)
  {
    if(array[i]==1)
    {
      array_sort[0]++;
    }
    if(array[i] == 2)
    {
      array_sort[1]++;
    }
    if(array[i] == 3)
    {
      array_sort[2]++;
    }
  }


      while(array_sort[0] > 0)
      {
        printf("1");
        array_sort[0]--;
        if(array_sort[0]>0 || array_sort[1]>0 || array_sort[2]>0)
          printf("+");
      }
      while(array_sort[1] > 0)
      {
        printf("2");
        array_sort[1]--;
        if(array_sort[1]>0 || array_sort[2]>0)
          printf("+");
      }
      while(array_sort[2] > 0)
      {
        printf("3");
        array_sort[2]--;
        if(array_sort[2]>0)
          printf("+");
      }




  return 0;

}
