#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char *string;

void palyWithPtrStrings();

void stringChangeWithPtr();

void stringCompare();

char *scan_string();

signed main(void)
{
       char *mystr = scan_string();
       // stringCompare();
       // palyWithPtrStrings();
       // stringChangeWithPtr();
       printf("The string is: %s\n", mystr);
       free(mystr);
       return 0;
}

// ------------------- Functions -------------------
// --------------------------------------------------
// --------------------------------------------------
// --------------------------------------------------
void palyWithPtrStrings()
{
       string name = "Hello";   // Points to a read-only string literal
       char name2[5] = "Hello"; // points to stack memory
       //------------
       char *ptr = malloc(6 * sizeof(char)); // Now `name` points to dynamically allocated memory
       printf("variable name before alocation address %p\n", name);
       //------------
       name = ptr;
       strcpy(name, "Hello"); // Copy string into allocated memory
       name[0] = 'h';         // Now it's valid, as `name` is modifiable
       printf("variable name after alocation address %p\n", &name);
       //-----------
       printf("variable name2 array of chars address %p\n", &name2);
       //-----------
       // printf("%d", strcmp(name, name2));
       free(name); // Don't forget to free dynamically allocated memory
}

void stringChangeWithPtr()
{

       char *name = malloc(3 * sizeof(char)); // Points to a read-only string literal
       name[0] = 'H';                         // store in alocated memory can be changed
       name[1] = 'i';                         // store in alocated memory can be changed
       name[2] = '!';                         // store in alocated memory can be changed
       printf("alocate 'name'  first address = %p\n", name);
       //-----------------
       char *firstletter = &name[0];
       printf("alocate firstletter to the same address = %p\n", firstletter);
       //-----------------
       firstletter[0] = 'h';
       printf("after change firstletter first char to 'h' %s\n", name);
       //-----------------
       firstletter[1] = 'I';
       printf("after change firstletter second char to 'I' %s\n", name);
       free(name);
}

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