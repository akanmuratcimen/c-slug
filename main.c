#include <stdio.h>
#include <wchar.h>

#include "slugify_unicode.h"

int main() {
  printf("%s\n", slugify_unicode(L"I ♥ UNICODE"));
}
