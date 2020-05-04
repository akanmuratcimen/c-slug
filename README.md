# c-slug
slugifies ascii and unicode strings.

```c
#include <stdio.h>
#include <wchar.h>

#include "slug_unicode.h"

int main() {
  printf("%s\n", slug_unicode(L"I ♥ UNICODE")); // i-love-unicode
}

```
