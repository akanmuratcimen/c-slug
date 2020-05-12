#ifndef SLUGIFY_ASCII_H
#define SLUGIFY_ASCII_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* slug_ascii(const char* string) {
  const char replacement_char = '-';

  size_t len = strlen(string), j = 0;
  char* result = malloc(len + 1);

  assert(result);

  char c;

  for (size_t i = 0; i < len; ++i) {
    c = string[i];

    if (isdigit(c) || islower(c)) {
      result[j++] = c;
      continue;
    }

    if (isupper(c)) {
      result[j++] = tolower(c);
      continue;
    }

    if (i != 0 && i != len - 1 && j != 0 && 
        (isspace(c) || c == replacement_char)) {
      if (result[j - 1] != replacement_char) {
        result[j++] = replacement_char;
        continue;
      }
    }
  }

  if (result[j - 1] == replacement_char) {
    j--;
  }

  if (len != j) {
    char* rresult = realloc(result, j + 1);

    if (rresult == NULL) {
      free(result);

      return NULL;
    }
 
    result = rresult;
  }

  result[j] = '\0';

  return result;
}

#ifdef __cplusplus
}
#endif

#endif 

