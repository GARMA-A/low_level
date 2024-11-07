#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../libs/mylib.h"

typedef uint8_t BYTE;

void textFileWithNameAndAge(void)
{
       FILE *file = fopen("text.txt", "a");
       if (file == NULL)
       {
              return;
       }
       char *name = scan_string();
       char *age = scan_string();
       fprintf(file, "Name: %s, Age: %s\n", name, age);

       free(name);
       free(age);
       fclose(file);
}

int main(int argc, char *argv[])
{
       FILE *src = fopen(argv[1], "rb");
       FILE *dest = fopen(argv[2], "wb");
       if (src == NULL || dest == NULL)
       {
              return 1;
       }
       BYTE b;
       while (fread(&b, sizeof(b), 1, src) == 1)
       {
              fwrite(&b, sizeof(b), 1, dest);
       }
       if (ferror(src)) // Check for errors during reading
       {
              perror("Error reading from source file");
       }

       if (ferror(dest)) // Check for errors during writing
       {
              perror("Error writing to destination file");
       }
       fclose(src);
       fclose(dest);
       return 0;
}
