#include <check.h>
#include <stdlib.h>

#include "slug_ascii.h"

START_TEST(replaces_whitespaces_with_replacement) {
  ck_assert_str_eq(slug_ascii("foo bar baz"), "foo-bar-baz");
} END_TEST 

START_TEST(replaces_trailing_space_if_any) {
  ck_assert_str_eq(slug_ascii(" foo bar baz "), "foo-bar-baz");
} END_TEST 

START_TEST(remove_not_allowed_chars) {
  ck_assert_str_eq(slug_ascii("foo, bar baz"), "foo-bar-baz");
  ck_assert_str_eq(slug_ascii("foo- bar baz"), "foo-bar-baz");
  ck_assert_str_eq(slug_ascii("foo] bar baz"), "foo-bar-baz");
  ck_assert_str_eq(slug_ascii("foo  bar--baz"), "foo-bar-baz");
} END_TEST 

START_TEST(replaces_uppercase_chars_to_lowercase_chars) {
  ck_assert_str_eq(slug_ascii("foo Bar baZ"), "foo-bar-baz");
} END_TEST 

int main(void) {
  Suite *s = suite_create("ascii tests");
  TCase *tc = tcase_create("ascii tests");
  SRunner *sr = srunner_create(s);
  int nf = 0;

  suite_add_tcase(s, tc);

  tcase_add_test(tc, replaces_whitespaces_with_replacement);
  tcase_add_test(tc, replaces_trailing_space_if_any);
  tcase_add_test(tc, remove_not_allowed_chars);
  tcase_add_test(tc, replaces_uppercase_chars_to_lowercase_chars);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf ? EXIT_FAILURE : EXIT_SUCCESS;
}
