#ifndef SLUGIFY_ASCII_H
#define SLUGIFY_ASCII_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* slugify_ascii(const char* string) {
  const char replacement_char = '-';
  
  size_t len = strlen(string), j = 0;
  char* result = (char*)malloc(len + 1);

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

    if (i != 0 && i != len - 1 && j != 0 && isspace(c)) {
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
    result = (char*)realloc(result, j + 1);
  }

  result[j] = '\0';

  return result;
}

#endif 

