/*
$HOME/bin/bin/g++ -std=c++2a byte.cpp
*/

#include <array>
#include <cstddef>

std::byte b{0};

/* What about overlap? Doesn't move imply possible cobbering of source? */
constexpr std::byte*
memory_move(std::byte* __dest, const std::byte* __begin, const std::byte* __end)
{
  for (; __begin != __end; ++__dest, ++__begin)
    *__dest = *__begin;
  return __dest;
}

constexpr std::byte*
memory_move(std::byte* __dest, const std::byte* __source, std::size_t __num)
{ return memory_move(__dest, __source, __source + __num); }

constexpr int
memory_compare(const std::byte* __ptr, const std::byte* __begin, const std::byte* __end)
{
  for (auto __ii = __begin; __ii != __end; ++__ptr, ++__ii)
    if (*__ptr != *__begin)
      return __ii - __begin;
  return 0;
}

constexpr int
memory_compare(const std::byte* __ptr1, const std::byte* __ptr2, std::size_t __num)
{ return memory_compare(__ptr1, __ptr2, __ptr2 + __num); }

constexpr std::byte*
memory_fill(std::byte* __begin, const std::byte* __end, std::byte __value)
{
  for (; __begin != __end; ++__begin)
    *__begin = __value;
  return __begin;
}

constexpr std::byte*
memory_fill(std::byte* dest, std::byte value, std::size_t num)
{ return memory_fill(dest, dest + num, value); }

int
main()
{
  std::byte arr[100];
  const std::byte* brr = arr;

  constexpr std::array<float, 3> a{{1.0f, 2.0f, 3.0f}};
  constexpr std::array<float, 3> b{{1.0f, 2.0f, 3.0f}};
  constexpr auto ok = memory_compare((const std::byte*)(a.data()), (std::byte*)(b.data()), 3 * sizeof(float));

  std::array<float, 3> c{{0.0f, 0.0f, 0.0f}};
  memory_move((std::byte*)(c.data()), (std::byte*)(a.data()), 3 * sizeof(float));
}
