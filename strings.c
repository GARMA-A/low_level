#include <stdio.h>  // for printf
#include <stdint.h> // for uint8_t, uint16_t, uint32_t, uint64_t
#include <stdlib.h> // for maloc and free
#include <string.h> // for strcpy
typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef char *string;

signed main(void)
{
       // the string in c is just pointer to first char in the string
       // so the string is just pointer to first char in array of chars
       // and end with null terminator '\0' to know where to end

       string name1 = "Hi!"; // store in read only memory cannot be changed
       // char name1[] = {'H', 'i', '!', '\0'}; // store at stack memory can be changed

       printf("%s\n", name1);
       printf("%p\n", name1);
       printf("%p\n", &name1[0]);
       printf("%p\n", &name1[1]);
       printf("%p\n", &name1[2]);
       printf("%p\n", &name1[3]); // null terminator
       printf("%p\n", &name1[4]); // unsafe to access
       printf("After changing the second char\n");
       //  name1[1] = 'a'; // segmantation fault
       // printf("%s\n", name1); // segmantation fault

       /************************************/
       // better way to changing the string
       string name12 = "Hi!"; // point on read only memory
       printf("%s\n", name12);
       printf("%p\n", name12);
       printf("%p\n", &name12[0]);
       printf("%p\n", &name12[1]);
       printf("%p\n", &name12[2]);
       printf("%p\n", &name12[3]); // null terminator
       printf("%p\n", &name12[4]); // unsafe to access
       printf("After changing the string\n");
       name12 = "Hello!"; // change the pointer to point to new string
       // read only memory management automatically by the compiler and free
       printf("%s\n", name12);
       /****************************************/
       string name = "Hello"; // Points to a read-only string literal
       // create heap memory to store the string
       name = malloc(6 * sizeof(char)); // Now `name` points to dynamically allocated memory
       strcpy(name, "Hello");           // Copy string into allocated memory
       name[0] = 'h';                   // Now it's valid, as `name` is modifiable
       free(name);                      // Don't forget to free dynamically allocated memory
                                        /******************************************/
       char name3[] = "Hello";          // stack memory allocation
       name3[0] = 'h';                  // Now it's valid, as `name` is modifiable
       printf("%s\n", name3);

       //----------------------------------------------



       return 0;
}
