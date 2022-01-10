#include "partition.h"

#include <gtest/gtest.h>
#include <vector>

TEST(PartitionTest, SingleLine) {
  std::vector<int> data = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  partition(data.begin(), data.end(), [](auto &e) { return e % 2 == 0; });
  EXPECT_TRUE(std::ranges::is_partitioned(data, [](auto &e) { return e % 2 == 0; }));
}