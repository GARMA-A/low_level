#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"


char *scan_string()
{
       char *str = NULL;
       char ch;
       int size = 0;
       str = malloc(sizeof(char));
       if (str == NULL)
       {
              printf("Memory not allocated.\n");
              exit(0);
       }
       printf("Enter a string: ");
       while (1)
       {
              ch = getchar();
              if (ch == '\n')
              {
                     break;
              }
              str = realloc(str, (++size + 1) * sizeof(char));
              if (str == NULL)
              {
                     printf("Memory reallocate faild.\n");
                     exit(0);
              }
              *(str + size - 1) = ch;
       }
       str[size] = '\0';
       return str;
}