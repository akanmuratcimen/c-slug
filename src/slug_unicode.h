#ifndef SLUGIFY_UNICODE_H
#define SLUGIFY_UNICODE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <locale.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <assert.h>

typedef struct unicode_char_map_t {
  wchar_t unicode_char;
  char* ascii_char;
} unicode_char_map_t;

const unicode_char_map_t unicode_char_map[] = {
  { L'À', "a" },
  { L'Á', "a" },
  { L'Â', "a" },
  { L'Ã', "a" },
  { L'Ä', "a" },
  { L'Å', "a" },
  { L'Æ', "ae" },
  { L'Ç', "c" },
  { L'È', "e" },
  { L'É', "e" },
  { L'Ê', "e" },
  { L'Ë', "e" },
  { L'Ì', "i" },
  { L'Í', "i" },
  { L'Î', "i" },
  { L'Ï', "i" },
  { L'Ð', "d" },
  { L'Ñ', "n" },
  { L'Ò', "o" },
  { L'Ó', "o" },
  { L'Ô', "o" },
  { L'Õ', "o" },
  { L'Ö', "o" },
  { L'Ő', "o" },
  { L'Ø', "o" },
  { L'Ù', "u" },
  { L'Ú', "u" },
  { L'Û', "u" },
  { L'Ü', "u" },
  { L'Ű', "u" },
  { L'Ý', "y" },
  { L'Þ', "th" },
  { L'ß', "ss" },
  { L'à', "a" },
  { L'á', "a" },
  { L'â', "a" },
  { L'ã', "a" },
  { L'ä', "a" },
  { L'å', "a" },
  { L'æ', "ae" },
  { L'ç', "c" },
  { L'è', "e" },
  { L'é', "e" },
  { L'ê', "e" },
  { L'ë', "e" },
  { L'ì', "i" },
  { L'í', "i" },
  { L'î', "i" },
  { L'ï', "i" },
  { L'ð', "d" },
  { L'ñ', "n" },
  { L'ò', "o" },
  { L'ó', "o" },
  { L'ô', "o" },
  { L'õ', "o" },
  { L'ö', "o" },
  { L'ő', "o" },
  { L'ø', "o" },
  { L'ù', "u" },
  { L'ú', "u" },
  { L'û', "u" },
  { L'ü', "u" },
  { L'ű', "u" },
  { L'ý', "y" },
  { L'þ', "th" },
  { L'ÿ', "y" },
  { L'ẞ', "ss" },
  { L'α', "a" },
  { L'β', "b" },
  { L'γ', "g" },
  { L'δ', "d" },
  { L'ε', "e" },
  { L'ζ', "z" },
  { L'η', "h" },
  { L'θ', "8" },
  { L'ι', "i" },
  { L'κ', "k" },
  { L'λ', "l" },
  { L'μ', "m" },
  { L'ν', "n" },
  { L'ξ', "3" },
  { L'ο', "o" },
  { L'π', "p" },
  { L'ρ', "r" },
  { L'σ', "s" },
  { L'τ', "t" },
  { L'υ', "y" },
  { L'φ', "f" },
  { L'χ', "x" },
  { L'ψ', "ps" },
  { L'ω', "w" },
  { L'ά', "a" },
  { L'έ', "e" },
  { L'ί', "i" },
  { L'ό', "o" },
  { L'ύ', "y" },
  { L'ή', "h" },
  { L'ώ', "w" },
  { L'ς', "s" },
  { L'ϊ', "i" },
  { L'ΰ', "y" },
  { L'ϋ', "y" },
  { L'ΐ', "i" },
  { L'Α', "a" },
  { L'Β', "b" },
  { L'Γ', "g" },
  { L'Δ', "d" },
  { L'Ε', "e" },
  { L'Ζ', "z" },
  { L'Η', "h" },
  { L'Θ', "8" },
  { L'Ι', "i" },
  { L'Κ', "k" },
  { L'Λ', "l" },
  { L'Μ', "m" },
  { L'Ν', "n" },
  { L'Ξ', "3" },
  { L'Ο', "o" },
  { L'Π', "p" },
  { L'Ρ', "r" },
  { L'Σ', "s" },
  { L'Τ', "t" },
  { L'Υ', "y" },
  { L'Φ', "f" },
  { L'Χ', "x" },
  { L'Ψ', "ps" },
  { L'Ω', "w" },
  { L'Ά', "a" },
  { L'Έ', "e" },
  { L'Ί', "i" },
  { L'Ό', "o" },
  { L'Ύ', "y" },
  { L'Ή', "h" },
  { L'Ώ', "w" },
  { L'Ϊ', "i" },
  { L'Ϋ', "y" },
  { L'ş', "s" },
  { L'Ş', "s" },
  { L'ı', "i" },
  { L'İ', "i" },
  { L'ç', "c" },
  { L'Ç', "c" },
  { L'ü', "u" },
  { L'Ü', "u" },
  { L'ö', "o" },
  { L'Ö', "o" },
  { L'ğ', "g" },
  { L'Ğ', "g" },
  { L'а', "a" },
  { L'б', "b" },
  { L'в', "v" },
  { L'г', "g" },
  { L'д', "d" },
  { L'е', "e" },
  { L'ё', "yo" },
  { L'ж', "zh" },
  { L'з', "z" },
  { L'и', "i" },
  { L'й', "j" },
  { L'к', "k" },
  { L'л', "l" },
  { L'м', "m" },
  { L'н', "n" },
  { L'о', "o" },
  { L'п', "p" },
  { L'р', "r" },
  { L'с', "s" },
  { L'т', "t" },
  { L'у', "u" },
  { L'ф', "f" },
  { L'х', "h" },
  { L'ц', "c" },
  { L'ч', "ch" },
  { L'ш', "sh" },
  { L'щ', "sh" },
  { L'ъ', "u" },
  { L'ы', "y" },
  { L'э', "e" },
  { L'ю', "yu" },
  { L'я', "ya" },
  { L'А', "a" },
  { L'Б', "b" },
  { L'В', "v" },
  { L'Г', "g" },
  { L'Д', "d" },
  { L'Е', "e" },
  { L'Ё', "yo" },
  { L'Ж', "zh" },
  { L'З', "z" },
  { L'И', "i" },
  { L'Й', "j" },
  { L'К', "k" },
  { L'Л', "l" },
  { L'М', "m" },
  { L'Н', "n" },
  { L'О', "o" },
  { L'П', "p" },
  { L'Р', "r" },
  { L'С', "s" },
  { L'Т', "t" },
  { L'У', "u" },
  { L'Ф', "f" },
  { L'Х', "h" },
  { L'Ц', "c" },
  { L'Ч', "ch" },
  { L'Ш', "sh" },
  { L'Щ', "sh" },
  { L'Ъ', "u" },
  { L'Ы', "y" },
  { L'Э', "e" },
  { L'Ю', "yu" },
  { L'Я', "ya" },
  { L'Є', "ye" },
  { L'І', "i" },
  { L'Ї', "yi" },
  { L'Ґ', "g" },
  { L'є', "ye" },
  { L'і', "i" },
  { L'ї', "yi" },
  { L'ґ', "g" },
  { L'č', "c" },
  { L'ď', "d" },
  { L'ě', "e" },
  { L'ň', "n" },
  { L'ř', "r" },
  { L'š', "s" },
  { L'ť', "t" },
  { L'ů', "u" },
  { L'ž', "z" },
  { L'Č', "c" },
  { L'Ď', "d" },
  { L'Ě', "e" },
  { L'Ň', "n" },
  { L'Ř', "r" },
  { L'Š', "s" },
  { L'Ť', "t" },
  { L'Ů', "u" },
  { L'Ž', "z" },
  { L'ą', "a" },
  { L'ć', "c" },
  { L'ę', "e" },
  { L'ł', "l" },
  { L'ń', "n" },
  { L'ó', "o" },
  { L'ś', "s" },
  { L'ź', "z" },
  { L'ż', "z" },
  { L'Ą', "a" },
  { L'Ć', "c" },
  { L'Ę', "e" },
  { L'Ł', "l" },
  { L'Ń', "n" },
  { L'Ś', "s" },
  { L'Ź', "z" },
  { L'Ż', "z" },
  { L'ā', "a" },
  { L'č', "c" },
  { L'ē', "e" },
  { L'ģ', "g" },
  { L'ī', "i" },
  { L'ķ', "k" },
  { L'ļ', "l" },
  { L'ņ', "n" },
  { L'š', "s" },
  { L'ū', "u" },
  { L'ž', "z" },
  { L'Ā', "a" },
  { L'Č', "c" },
  { L'Ē', "e" },
  { L'Ģ', "g" },
  { L'Ī', "i" },
  { L'Ķ', "k" },
  { L'Ļ', "l" },
  { L'Ņ', "n" },
  { L'Š', "s" },
  { L'Ū', "u" },
  { L'Ž', "Z" },
  { L'€', "euro" },
  { L'₢', "cruzeiro" },
  { L'₣', "french franc" },
  { L'£', "pound" },
  { L'₤', "lira" },
  { L'₥', "mill" },
  { L'₦', "naira" },
  { L'₧', "peseta" },
  { L'₨', "rupee" },
  { L'₩', "won" },
  { L'₪', "new shequel" },
  { L'₫', "dong" },
  { L'₭', "kip" },
  { L'₮', "tugrik" },
  { L'₯', "drachma" },
  { L'₰', "penny" },
  { L'₱', "peso" },
  { L'₲', "guarani" },
  { L'₳', "austral" },
  { L'₴', "hryvnia" },
  { L'₵', "cedi" },
  { L'¢', "cent" },
  { L'¥', "yen" },
  { L'元', "yuan" },
  { L'円', "yen" },
  { L'﷼', "rial" },
  { L'₠', "ecu" },
  { L'¤', "currency" },
  { L'฿', "baht" },
  { L'$', "dollar" },
  { L'©', "c" },
  { L'œ', "oe" },
  { L'Œ', "oe" },
  { L'∑', "sum" },
  { L'®', "r" },
  { L'∂', "d" },
  { L'ƒ', "f" },
  { L'™', "tm" },
  { L'℠', "sm" },
  { L'˚', "o" },
  { L'º', "o" },
  { L'ª', "a" },
  { L'∆', "delta" },
  { L'∞', "infinity" },
  { L'♥', "love" },
  { L'&', "and" },
  { L'|', "or" },
  { L'<', "less" },
  { L'>', "greater" }
};

size_t map_count() {
  return sizeof(unicode_char_map) / sizeof(unicode_char_map_t);
}

typedef struct map_entry_t {
  wchar_t unicode_char;
  char* ascii_char;
  struct map_entry_t* next;
} map_entry_t;

size_t map_capacity = 512;

static map_entry_t** map_new(void);
static void map_destroy(map_entry_t** map);

static void map_set(map_entry_t** map, 
    const wchar_t unicode_char, char* ascii_char);

static map_entry_t* map_get(
    map_entry_t** map, const wchar_t unicode_char);

char* slug_unicode(const wchar_t* string) {
  const char replacement_char = '-';

  map_entry_t** map = map_new();
  size_t len = wcslen(string), j = 0, capacity = len + 1;
  char* result = malloc(capacity);

  assert(result);

  wchar_t c;

  for (size_t i = 0; i < len; ++i) {
    c = string[i];

    if (j >= capacity) {
      char* rresult = realloc(result, capacity += 20);

      if (rresult == NULL) {
        free(result);

        return NULL;
      }

      result = rresult;
    }

    if (iswdigit(c) || iswlower(c)) {
      result[j++] = c;
      continue;
    }

    if (iswupper(c)) {
      result[j++] = towlower(c);
      continue;
    }

    if (i != 0 && i != len - 1 && j != 0 && 
        (iswspace(c) || c == replacement_char)) {
      if (result[j - 1] != replacement_char) {
        result[j++] = replacement_char;
        continue;
      }
    }

    const map_entry_t* map_entry = map_get(map, c);

    if (map_entry) {
      char* r = map_entry->ascii_char;

      while (*r != '\0') {
        result[j++] = *(r++);
      }
    }
  }

  if (result[j - 1] == replacement_char) {
    j--;
  }

  if (capacity + 1 > j) {
    char* rresult = realloc(result, j + 1);

    if (rresult == NULL) {
      free(result);

      return NULL;
    }

    result = rresult;
  }

  result[j] = '\0';

  map_destroy(map);

  return result;
}

static void map_set(map_entry_t** map,
    const wchar_t unicode_char, char* ascii_char) {
  const size_t slot = unicode_char % map_capacity;

  map_entry_t* current_entry = map[slot];
  map_entry_t* new_entry = malloc(sizeof(map_entry_t));

  assert(new_entry);

  new_entry->unicode_char = unicode_char;
  new_entry->ascii_char = ascii_char;
  new_entry->next = NULL;

  if (current_entry == NULL) {
    map[slot] = new_entry;

    return;
  }

  map_entry_t* prev = NULL;

  while (current_entry) {
    prev = current_entry;
    current_entry = prev->next;
  }

  prev->next = new_entry;
}

static map_entry_t** map_new(void) {
  map_entry_t** map = malloc(sizeof(map_entry_t) * map_capacity);

  assert(map);

  for (size_t i = 0; i < map_capacity; ++i) {
    map[i] = NULL;
  }

  unicode_char_map_t ucm;

  for (size_t i = 0; i < map_count(); ++i) {
    ucm = unicode_char_map[i];
    map_set(map, ucm.unicode_char, ucm.ascii_char);
  }

  return map;
}

static map_entry_t* map_get(
    map_entry_t** map, const wchar_t unicode_char) {
  map_entry_t* entry = map[unicode_char % map_capacity];

  while (entry) {
    if (entry->unicode_char == unicode_char) {
      return entry;
    }

    entry = entry->next;
  }

  return NULL;
}

static void map_destroy(map_entry_t** map) {
  for (unsigned int i = 0; i < map_capacity; ++i) {
    map_entry_t* entry = map[i];

    while (entry) {
      map_entry_t* next = entry->next;

      free(entry);

      entry = next;
    }
  }

  free(map);
}

#ifdef __cplusplus
}
#endif

#endif 

