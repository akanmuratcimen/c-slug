# c-slug
Slugifies a strings.

## overview
This tiny library converts any string to slug. It basically includes two methods: slug_ascii and slug_unicode. If your string does not have unicode characters, you can use the slug_ascii method to convert any ascii string.

If your string contains unicode characters, you must use the slug_unicode method. It has some character maps to convert unicode characters into substitutions. You can add other mappings to the slug_unicode.h file. The slug_unicode method uses hashmap internally, so its complexity is almost o(n), and almost does not matter how many characters you have in hashmap.

## example

```c
#include <stdio.h>
#include <wchar.h>

#include "slug_unicode.h"

int main() {
  printf("%s\n", slug_unicode(L"I ♥ UNICODE")); // i-love-unicode
}

```
