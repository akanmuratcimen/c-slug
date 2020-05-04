#include <stdio.h>
#include <wchar.h>
#include <string.h>

#include "slug_unicode.h"

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("Enter a string to convert to slug.\n");

    return EXIT_FAILURE;
  }
  
  size_t len = strlen(argv[1]);
  wchar_t* buffer = (wchar_t*)malloc(sizeof(wchar_t) * len); 
  mbstowcs(buffer, argv[1], len);
  char* str = slug_unicode(buffer);

  printf("%s\n", str);

  free(str);

  return EXIT_SUCCESS;
}
