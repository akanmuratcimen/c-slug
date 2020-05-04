#include <stdio.h>

#include "slug_ascii.h"

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("Enter a string to convert to slug.\n");

    return EXIT_FAILURE;
  }
  
  char* str = slug_ascii(argv[1]);
  printf("%s\n", str);

  free(str);

  return EXIT_SUCCESS;
}

