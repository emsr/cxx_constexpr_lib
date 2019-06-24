
#include <array>
#include <algorithm>

constexpr bool
test_constexpr_swap()
{
  auto ok = true;

  std::array<int, 12> ar0{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  std::array<int, 12> ar1{{11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};

  const auto out01 = std::swap_ranges(ar0.begin(), ar0.begin() + 5,
				      ar1.begin() + 2);

  std::iter_swap(ar0.begin() + 2, ar0.begin() + 5);

  std::reverse(ar0.begin(), ar0.end());

  auto iter1 = std::rotate(ar0.begin(), ar0.begin() + 5, ar0.end());

  auto iter2 = std::partition(ar0.begin(), ar0.end(),
			      [](int i){ return i < 7; });

  std::sort(ar0.begin(), ar0.end());

  std::sort(ar1.begin(), ar1.end(), std::greater<>());

  std::partial_sort(ar1.begin(), ar1.begin() + 5, ar1.end());

  std::partial_sort(ar0.begin(), ar0.begin() + 5, ar0.end(), std::greater<>());

  std::array<int, 12> or0{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::array<int, 12> or1{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::partial_sort_copy(ar0.begin() + 5, ar0.begin() + 10,
			 ar1.begin(), ar1.begin() + 5);

  std::partial_sort_copy(ar0.begin() + 5, ar0.begin() + 10,
			 ar1.begin(), ar1.begin() + 5, std::greater<>());

  std::nth_element(ar0.begin(), ar0.begin() + 5, ar0.end());

  std::nth_element(ar0.begin(), ar0.begin() + 5, ar0.end(), std::greater<>());

  std::array<int, 23>
  ah{{0,
      1, 2,
      3, 4, 5, 6,
      7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22}};
  std::make_heap(ah.begin(), ah.begin() + 21);
  std::push_heap(ah.begin(), ah.begin() + 22);
  std::push_heap(ah.begin(), ah.begin() + 23);
  std::push_heap(ah.begin(), ah.end());
  std::pop_heap(ah.begin(), ah.end());
  std::sort_heap(ah.begin(), ah.end() - 1);

  std::make_heap(ah.begin(), ah.begin() + 21, std::greater<>());
  std::push_heap(ah.begin(), ah.begin() + 22, std::greater<>());
  std::push_heap(ah.begin(), ah.begin() + 23, std::greater<>());
  std::push_heap(ah.begin(), ah.end(), std::greater<>());
  std::pop_heap(ah.begin(), ah.end(), std::greater<>());
  std::sort_heap(ah.begin(), ah.end() - 1, std::greater<>());

  ok = ok && std::prev_permutation(ah.begin(), ah.end());
  ok = ok && std::next_permutation(ah.begin(), ah.end());
  ok = ok && std::next_permutation(ah.begin(), ah.end(), std::greater<>());
  ok = ok && std::prev_permutation(ah.begin(), ah.end(), std::greater<>());

  double asc = 3.1415;
  double bsc = 2.7182;
  std::swap(asc, bsc);
  ok = ok && asc == 2.7182 && bsc == 3.1415;

  float arr[5]{0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
  float brr[5]{5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
  std::swap(arr, brr);
  ok = ok && arr[2] == 7.0f && brr[2] == 2.0f;

  return ok;
}

int
main()
{
  static_assert(test_constexpr_swap());
}
