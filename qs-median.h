#ifndef QUICKSORT_MEDIAN_H_
#define QUICKSORT_MEDIAN_H_

#include <algorithm>
#include <iterator>

template <typename It> It quick_select(It left, It middle, It right);

template <typename It>
requires std::random_access_iterator<It> && std::indirectly_swappable<It> It median5(It left, It right) {
  for (auto i = std::next(left); i != right; i++)
    for (auto j = i; j != left && *std::prev(j) > *j; j--)
      std::iter_swap(std::prev(j), j);
  return left + std::distance(left, right) / 2;
}

template <typename It>
requires std::random_access_iterator<It> && std::indirectly_swappable<It> It median_of_medians(It left, It right) {
  if (std::distance(left, right) <= 5)
    return median5(left, right);

  It store = left;
  It i = left;
  do {
    It subRight = right;
    if (std::distance(i, right) >= 5)
      subRight = i + 5;

    It med5 = median5(i, subRight);
    std::iter_swap(med5, store);
    store++;
    i = subRight;
  } while (i != right);

  return quick_select(left, left + std::distance(left, store) / 2, store);
}

template <typename It>
requires std::random_access_iterator<It> && std::indirectly_swappable<It> It quick_select(It left, It middle, It right) {
  while (std::next(left) != right) {

    auto pivot = std::prev(right);
    std::iter_swap(pivot, median_of_medians(left, right));

    auto pp1 = std::partition(left, pivot, [pivot](const auto &e) { return e < *pivot; });
    auto pp2 = std::partition(pp1, pivot, [pivot](const auto &e) { return !(*pivot < e); });

    std::iter_swap(pp2, pivot);
    pp2++;

    if (middle < pp1) {
      right = pp1;
    } else if (middle < pp2) {
      return middle;
    } else {
      left = pp2;
    }
  }

  return left;
}

template <typename It>
requires std::random_access_iterator<It> && std::indirectly_swappable<It>
void quicksort_median(It first, It last) {
  if (first == last)
    return;

  auto pivot = std::prev(last);
  std::iter_swap(pivot, median_of_medians(first, last));

  auto pp1 = std::partition(first, pivot, [pivot](const auto &e) { return e < *pivot; });
  auto pp2 = std::partition(pp1, pivot, [pivot](const auto &e) { return !(*pivot < e); });

  std::iter_swap(pp2, pivot);
  pp2++;

  quicksort_median(first, pp1);
  quicksort_median(pp2, last);
}

#endif