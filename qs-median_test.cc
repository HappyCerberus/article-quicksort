#include "qs-median.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

TEST(MedianOfMediansTest, QuickSort) {
  std::vector<std::vector<int>> data = {
      {9, 8, 5, 5, 5, 4, 3, 2, 1},
      {9, 8, 7, 6, 5, 4, 3, 2, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 1},
      {0},
  };
  for (auto &tcase : data) {
    std::vector<int> in = tcase;
    quicksort_median(in.begin(), in.end());
    EXPECT_TRUE(std::ranges::is_sorted(in));
    EXPECT_TRUE(std::ranges::is_permutation(in, tcase));
  }
}

TEST(MedianOfMediansTest, QuickSelect) {
  std::vector<int> data = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  for (size_t i = 0; i < data.size(); i++) {
    std::vector<int> in = data;
    EXPECT_EQ(*quick_select(in.begin(), in.begin() + i, in.end()), i + 1);
    EXPECT_TRUE(std::ranges::is_permutation(in, data));
  }
}