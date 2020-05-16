#include <check.h>
#include <stdlib.h>
#include <wchar.h>

#include "slug_unicode.h"

START_TEST(replaces_whitespaces_with_replacement) {
  char* str = slug_unicode(L"foo bar baz");
  ck_assert_str_eq(str, "foo-bar-baz");
  free(str);
} END_TEST

START_TEST(replaces_trailing_space_if_any) {
  char* str = slug_unicode(L" foo bar baz ");
  ck_assert_str_eq(str, "foo-bar-baz");
  free(str);
} END_TEST

START_TEST(remove_not_allowed_chars) {
  char* str_1 = slug_unicode(L"foo, bar baz");
  ck_assert_str_eq(str_1, "foo-bar-baz");
  free(str_1);

  char* str_2 = slug_unicode(L"foo- bar baz");
  ck_assert_str_eq(str_2, "foo-bar-baz");
  free(str_2);

  char* str_3 = slug_unicode(L"foo] bar baz");
  ck_assert_str_eq(str_3, "foo-bar-baz");
  free(str_3);

  char* str_4 = slug_unicode(L"foo  bar--baz");
  ck_assert_str_eq(str_4, "foo-bar-baz");
  free(str_4);
} END_TEST

START_TEST(replaces_uppercase_chars_to_lowercase_chars) {
  char* str = slug_unicode(L"foo Bar baZ");
  ck_assert_str_eq(str, "foo-bar-baz");
  free(str);
} END_TEST

START_TEST(replaces_unicode_chars) {
  char* str = slug_unicode(L"I ♥ UNICODE");
  ck_assert_str_eq(str, "i-love-unicode");
  free(str);
} END_TEST

START_TEST(ignores_trailing_replacement_chars) {
  char* str = slug_unicode(L"foo-bar-baz --");
  ck_assert_str_eq(str, "foo-bar-baz");
  free(str);
} END_TEST

START_TEST(result_should_be_empty) {
  char* str_1 = slug_unicode(L"");
  ck_assert_str_eq(str_1, "");
  free(str_1);

  char* str_2 = slug_unicode(L" ");
  ck_assert_str_eq(str_2, "");
  free(str_2);

  char* str_3 = slug_unicode(L"-");
  ck_assert_str_eq(str_3, "");
  free(str_3);

  char* str_4 = slug_unicode(L" - ");
  ck_assert_str_eq(str_4, "");
  free(str_4);

  char* str_5 = slug_unicode(L"- -");
  ck_assert_str_eq(str_5, "");
  free(str_5);

  char* str_6 = slug_unicode(L"*");
  ck_assert_str_eq(str_6, "");
  free(str_6);

  char* str_7 = slug_unicode(L" * ");
  ck_assert_str_eq(str_7, "");
  free(str_7);

  char* str_8 = slug_unicode(L"* *");
  ck_assert_str_eq(str_8, "");
  free(str_8);

  char* str_9 = slug_unicode(L"***");
  ck_assert_str_eq(str_9, "");
  free(str_9);

  char* str_11 = slug_unicode(L"-*-");
  ck_assert_str_eq(str_11, "");
  free(str_11);

  char* str_12 = slug_unicode(L"*-*");
  ck_assert_str_eq(str_12, "");
  free(str_12);
} END_TEST

int main(void) {
  Suite *s = suite_create("unicode tests");
  TCase *tc = tcase_create("unicode tests");
  SRunner *sr = srunner_create(s);

  suite_add_tcase(s, tc);

  tcase_add_test(tc, replaces_whitespaces_with_replacement);
  tcase_add_test(tc, replaces_trailing_space_if_any);
  tcase_add_test(tc, remove_not_allowed_chars);
  tcase_add_test(tc, replaces_uppercase_chars_to_lowercase_chars);
  tcase_add_test(tc, replaces_unicode_chars);
  tcase_add_test(tc, ignores_trailing_replacement_chars);
  tcase_add_test(tc, result_should_be_empty);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  int nf = srunner_ntests_failed(sr);

  srunner_free(sr);

  return nf ? EXIT_FAILURE : EXIT_SUCCESS;
}

