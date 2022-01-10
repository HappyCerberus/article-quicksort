#include "quicksort.h"

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

TEST(QuickSortTest, Simple) {
  std::vector<std::vector<int>> data = {
      {9, 8, 5, 5, 5, 4, 3, 2, 1},
      {9, 8, 7, 6, 5, 4, 3, 2, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 1},
      {0},
  };
  for (auto &tcase : data) {
    std::vector<int> in = tcase;
    quicksort(in.begin(), in.end());
    EXPECT_TRUE(std::ranges::is_sorted(in));
    EXPECT_TRUE(std::ranges::is_permutation(in, tcase));
  }
}