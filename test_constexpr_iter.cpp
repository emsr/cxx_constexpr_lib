/*
  Do we actually have to do anything for P0858R0 - Constexpr iterator requirements?
*/
#include <array>
#include <string_view>

constexpr int
test_array_iter()
{
  constexpr std::array<int, 3> a1{{1, 2, 3}};
  static_assert(1 == *a1.begin());
  auto n = a1[0] * a1[1]* a1[2];
  static_assert(1 == *a1.cbegin());

#if __cplusplus > 201703L
  std::array<int, 3> a2{{0, 0, 0}};
  std::copy(a1.begin(), a1.end(), a2.begin());
#endif

  return n;
}

void
run_test_array_iter()
{
  constexpr int n = test_array_iter();
}

constexpr char
test_string_view_iter()
{
  constexpr std::string_view hw("Hello, World!");
  static_assert('H' == *hw.begin());
  auto ch = hw[4];
  static_assert('W' == *(hw.cbegin() + 7));

#if __cplusplus > 201703L
  std::array<int, hw.size()> a2{{0,0,0,0,0,0,0,0,0,0,0,0,0}};
  std::copy(hw.begin(), hw.end(), a2.begin());
#endif

  return *(hw.cbegin() + 3);
}

void
run_test_string_view_iter()
{
  constexpr char ch = test_string_view_iter();
}
