/*
../bin/bin/g++ -std=c++2a -o memory memory.cpp
*/

#include <type_traits>
#include <cstddef>
#include <iterator>
#include <array>
#include <iostream>

  template<bool, bool, typename>
    struct __copy_move
    {
      template<typename _II, typename _OI>
	_GLIBCXX20_CONSTEXPR
	static _OI
	__copy_m(_II __first, _II __last, _OI __result)
	{
	  for (; __first != __last; ++__result, (void)++__first)
	    *__result = *__first;
	  return __result;
	}
    };

#if __cplusplus >= 201103L
  template<typename _Category>
    struct __copy_move<true, false, _Category>
    {
      template<typename _II, typename _OI>
	_GLIBCXX20_CONSTEXPR
	static _OI
	__copy_m(_II __first, _II __last, _OI __result)
	{
	  for (; __first != __last; ++__result, (void)++__first)
	    *__result = std::move(*__first);
	  return __result;
	}
    };
#endif

  template<>
    struct __copy_move<false, false, std::random_access_iterator_tag>
    {
      template<typename _II, typename _OI>
	_GLIBCXX20_CONSTEXPR
	static _OI
	__copy_m(_II __first, _II __last, _OI __result)
	{
	  typedef typename std::iterator_traits<_II>::difference_type _Distance;
	  for(_Distance __n = __last - __first; __n > 0; --__n)
	    {
	      *__result = *__first;
	      ++__first;
	      ++__result;
	    }
	  return __result;
	}
    };

#if __cplusplus >= 201103L
  template<>
    struct __copy_move<true, false, std::random_access_iterator_tag>
    {
      template<typename _II, typename _OI>
	_GLIBCXX20_CONSTEXPR
	static _OI
	__copy_m(_II __first, _II __last, _OI __result)
	{
	  typedef typename std::iterator_traits<_II>::difference_type _Distance;
	  for(_Distance __n = __last - __first; __n > 0; --__n)
	    {
	      *__result = std::move(*__first);
	      ++__first;
	      ++__result;
	    }
	  return __result;
	}
    };
#endif

template<typename _Tp>
  constexpr void*
  memory_move(_Tp* dst, const _Tp* src, size_t num)
  {
    // This works!
    //return __copy_move<false, false, std::random_access_iterator_tag>::__copy_m(src, src + num, dst);
    // This works!
    return __copy_move<true, false, std::random_access_iterator_tag>::__copy_m(src, src + num, dst);
  }

constexpr bool
test_memory_move()
{
  const int a[5]{1,2,3,4,5};
  int b[5]{0,0,0,0,0};
  memory_move(b, a, 5);

  const std::array<int,5> aa{{1,2,3,4,5}};
  std::array<int,5> bb{{0,0,0,0,0}};
  memory_move(bb.begin(), aa.begin(), 5);

  return true;
}

int
main()
{
  static_assert(test_memory_move());
}
