/*
../bin/bin/g++ -std=c++2a -o memory memory.cpp
*/

#include <type_traits>
#include <cstddef>
#include <iterator>
#include <array>
#include <iostream>

  /**
   * A constexpr wrapper for __builtin_memmove.
   * @param __num The number of elements of type _Tp (not bytes).
   */
  template<bool _IsMove, typename _Tp>
    _GLIBCXX20_CONSTEXPR
    inline void*
    __memmove(_Tp* __dst, _Tp* __src, size_t __num)
    {
#if __cplusplus > 201703L
      if (is_constant_evaluated())
	{
	  for(; __num > 0; --__num)
	    {
	      if constexpr (_IsMove)
		*__dst = std::move(*__src);
	      else
		*__dst = *__src;
	      ++__src;
	      ++__dst;
	    }
	  return __dst;
	}
      else
#endif
	return __builtin_memmove(__dst, __src, sizeof(_Tp) * __num);
      return __dst;
    }

  /**
   * A constexpr wrapper for __builtin_memcmp.
   * @param __num The number of elements of type _Tp (not bytes).
   */
  template<typename _Tp>
    _GLIBCXX20_CONSTEXPR
    inline int
    __memcmp(const _Tp* __first1, const _Tp* __first2, size_t __num)
    {
#if __cplusplus > 201703L
      if (is_constant_evaluated())
	{
	  for(; __num > 0; ++__first1, ++__first2, --__num)
	    if (*__first1 != *__first2)
	      return *__first1 < *__first2 ? -1 : 1;
	  return 0;
	}
      else
#endif
	return __builtin_memcmp(__first1, __first2, sizeof(_Tp) * __num);
    }

  /**
   * A constexpr wrapper for __builtin_memset.
   * @param __num The number of elements of type _Tp (not bytes).
  template<typename _Tp>
    _GLIBCXX20_CONSTEXPR
    inline void*
    __memset(const _Tp* __ptr, int __val, size_t __num)
    {
#if __cplusplus > 201703L
      if (is_constant_evaluated())
	{
	  _Tp __fill{};
	  __builtin_memset(&__fill, __val, sizeof(_Tp))
	  for(; __num > 0; --__num)
	    return *(__ptr + __num) = __fill;
	  return __ptr;
	}
      else
#endif
	return __builtin_memset(__ptr, __val, sizeof(_Tp) * __num);
    }
   */

constexpr bool
test_memory()
{
  const int a[5]{1,2,3,4,5};
  int b[5]{0,0,0,0,0};
  __memmove(b, a, 5);

  const std::array<int,5> aa{{1,2,3,4,5}};
  std::array<int,5> bb{{0,0,0,0,0}};
  __memmove(bb.begin(), aa.begin(), 5);

  //int c[5]{0,0,0,0,0};
  //__memset(c, 10, 5);

  return true;
}

int
main()
{
  static_assert(test_memory());
}
