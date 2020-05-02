#include <stdio.h>
#include <wchar.h>

#include "slugify_unicode.h"

int main() {
  char* str = slugify_unicode(L"I ♥ UNICODE");
  printf("%s\n", str);
  free(str);
}
