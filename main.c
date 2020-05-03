#include <stdio.h>
#include <wchar.h>

#include "slug_unicode.h"

int main() {
  char* str = slug_unicode(L"I ♥ UNICODE");
  printf("%s\n", str);
  free(str);
}
