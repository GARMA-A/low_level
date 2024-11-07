#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char *string;

void palyWithPtrStrings();

void stringChangeWithPtr();

void stringCompare();

char *scan_string();

void allAllocateStaff();

enum
{
       MAX = 100,
       MIN = 0 
};

signed main(void)
{
       printf("%d\n" , MIN);

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

void allAllocateStaff()
{

       // fourth you have the calloc (allocate memory and initialize it with 0)
       // fifth you have the malloc (allocate memory and don't initialize it)
       // second you have the realloc (reallocate memory)
       // third you have the free (free memory)
       // sixth you have the strdup (allocate memory and copy the string to it)
       // seventh you have the strndup (allocate memory and copy the string to it with a limit)
       // eighth you have the alloca (allocate memory in the stack)
       // ninth you have the valloc (allocate memory in the heap and align it to the page size)
       // tenth you have the memalign (allocate memory in the heap and align it to the given size)
       // eleventh you have the posix_memalign (allocate memory in the heap and align it to the given size)
       // twelfth you have the aligned_alloc (allocate memory in the heap and align it to the given size)
       // thirteenth you have the mcheck (check for memory leaks)
       // fourteenth you have the mprobe (check for memory leaks)
       // fifteenth you have the mtrace (check for memory leaks)
       // sixteenth you have the mcheck_pedantic (check for memory leaks)
       // seventeenth you have the mtrace_pedantic (check for memory leaks)
       // eighteenth you have the mprobe_pedantic (check for memory leaks)
       // nineteenth you have the mcheck_check_all (check for memory leaks)
       // twentieth you have the mtrace_check_all (check for memory leaks)
       // twenty-first you have the mprobe_check_all (check for memory leaks)
       // twenty-second you have the mcheck_pedantic_check_all (check for memory leaks)
       // twenty-third you have the mtrace_pedantic_check_all (check for memory leaks)
       //--------------------------------------------------------------------------------------
       //--------------------------------------------------------------------------------------
       //--------------------------------------------------------------------------------------
       //--------------------------------------------------------------------------------------
       //--------------------------------------------------------------------------------------
       int *arr = (int *)calloc(10, sizeof(int)); // Allocates zero-initialized memory for 10 integers
       // memset is a function that fills a block of memory with a particular value.
       // you need to allocate memory before using memset
       memset(arr, 0, 10 * sizeof(int));          // Sets 10 integers in arr to 0
       //memcpy(dest, src, num_bytes); // Copies num_bytes from src to dest
       alloca(10 * sizeof(int)); // Allocates memory on the stack for 10 integers
       // this useful because allocate memory on the stack free automatically when the function ends


}