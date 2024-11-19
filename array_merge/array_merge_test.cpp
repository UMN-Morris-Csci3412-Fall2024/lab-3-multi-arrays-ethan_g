#include <gtest/gtest.h>
#include "array_merge.h"

void arrays_match(int size, int a[], int b[]) {
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(b[i], a[i]);
  }
}

TEST(ArrayMerge, Handle_empty_list) {
  int* a[] = { };
  int sizes[] = { };
  int expected[] = { 0 };
  int* result;

  result = array_merge(0, sizes, a);
  arrays_match(1, result, expected);
  free(result);  // Free the allocated memory
}

TEST(ArrayMerge, Handle_singleton_list) {
  int num_arrays = 1;
  int sizes[] = { 1 };
  int a0[] = { 5 };
  int* a[] = { a0 };
  int expected[] = { 1, 5 };
  int* result;

  result = array_merge(num_arrays, sizes, a);
  arrays_match(2, result, expected);
  free(result);  // Free the allocated memory
}

TEST(ArrayMerge, Handle_one_longer_list) {
  int num_arrays = 1;
  int sizes[] = { 5 };
  int a0[] = { 1, 2, 3, 4, 5 };
  int* a[] = { a0 };
  int expected[] = { 5, 1, 2, 3, 4, 5 };
  int* result;

  result = array_merge(num_arrays, sizes, a);
  arrays_match(6, result, expected);
  free(result);  // Free the allocated memory
}

TEST(ArrayMerge, Handle_multiple_copies_of_longer_list) {
  int num_arrays = 3;
  int sizes[] = { 5, 5, 5 };
  int a0[] = { 1, 2, 3, 4, 5 };
  int a1[] = { 1, 2, 3, 4, 5 };
  int a2[] = { 1, 2, 3, 4, 5 };
  int* a[] = { a0, a1, a2 };
  int expected[] = { 5, 1, 2, 3, 4, 5 };
  int* result;

  result = array_merge(num_arrays, sizes, a);
  arrays_match(6, result, expected);
  free(result);  // Free the allocated memory
}

TEST(ArrayMerge, Handle_multiple_copies_of_longer_list_different_orders) {
  int num_arrays = 3;
  int sizes[] = { 5, 5, 5 };
  int a0[] = { 1, 2, 3, 4, 5 };
  int a1[] = { 5, 4, 3, 2, 1 };
  int a2[] = { 2, 3, 1, 5, 4 };
  int* a[] = { a0, a1, a2 };
  int expected[] = { 5, 1, 2, 3, 4, 5 };
  int* result;

  result = array_merge(num_arrays, sizes, a);
  arrays_match(6, result, expected);
  free(result);  // Free the allocated memory
}

TEST(ArrayMerge, Handle_different_sizes) {
  int num_arrays = 3;
  int sizes[] = { 3, 2, 4 };
  int a0[] = { 1, 2, 3 };
  int a1[] = { 4, 5 };
  int a2[] = { 6, 7, 8, 9 };
  int* a[] = { a0, a1, a2 };
  int expected[] = { 9, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int* result;

  result = array_merge(num_arrays, sizes, a);
  arrays_match(10, result, expected);
  free(result);  // Free the allocated memory
}

TEST(ArrayMerge, Handle_different_sizes_reversed) {
  int num_arrays = 3;
  int sizes[] = { 4, 2, 3 };
  int a0[] = { 6, 7, 8, 9 };
  int a1[] = { 4, 5 };
  int a2[] = { 1, 2, 3 };
  int* a[] = { a0, a1, a2 };
  int expected[] = { 9, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int* result;
}

  int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
