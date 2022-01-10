#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <algorithm>
#include <iterator>

template <typename It>
requires std::random_access_iterator<It> && std::indirectly_swappable<It>
void quicksort(It first, It last) {
  if (first == last)
    return;

  auto pivot = std::prev(last);
  std::iter_swap(pivot, first + std::distance(first, last) / 2);

  auto pp1 = std::partition(first, pivot, [pivot](const auto &e) { return e < *pivot; });
  auto pp2 = std::partition(pp1, pivot, [pivot](const auto &e) { return !(*pivot < e); });

  std::iter_swap(pp2, pivot);
  pp2++;

  quicksort(first, pp1);
  quicksort(pp2, last);
}

#endif