
#include <array>
#include <algorithm>

#ifdef STATIC_ASSERT
#  include <cassert>
#  define CONSTEXPR
#else
#  define STATIC_ASSERT static_assert
#  define CONSTEXPR constexpr
#endif

//template<typename Tp>
  CONSTEXPR void
  test_constexpr_algo()
  {
    CONSTEXPR std::array<int, 12> a{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
    CONSTEXPR std::array<int, 12> ap{{2, 1, 3, 6, 7, 5, 4, 8, 10, 9, 0, 11}};
    CONSTEXPR std::array<int, 12> ar{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
    CONSTEXPR std::array<int, 12> ar2{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
    CONSTEXPR std::array<int, 12> ar3{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
    CONSTEXPR std::array<int, 12> aus{{0, 1, 2, 3, 4, 5, 66, 7, 8, 9, 10, 11}};
    CONSTEXPR std::array<int, 12> da{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    CONSTEXPR std::array<int, 3> am{{4, 5, 6}};
    CONSTEXPR std::array<int, 3> am12{{-4, -5, -6}};
    CONSTEXPR std::array<int, 12> ac{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
    CONSTEXPR std::array<int, 12> ac2{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
    CONSTEXPR std::array<int, 12> as{{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}};
    CONSTEXPR std::array<int, 12> ax{{0, 1, 2, 3, 4, 5, 66, 7, 8, 99, 10, 11}};
    CONSTEXPR std::array<int, 6> ae{{0, 2, 4, 6, 8, 10}};
    CONSTEXPR std::array<int, 6> ao{{1, 3, 5, 7, 9, 11}};
    CONSTEXPR std::array<int, 12> aeo{{0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 11}};
    CONSTEXPR std::array<int, 24> o{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    CONSTEXPR std::array<int, 24> p{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    // heap
    CONSTEXPR std::array<int, 23>
    ah{{22,
	21, 20,
	17, 16, 19, 18,
	11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4}};
    // heap
    CONSTEXPR std::array<int, 23>
    ahu{{22,
	21, 20,
	17, 16, 19, 18,
	11, 10, 9, 8, 23, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4}};

    STATIC_ASSERT(ar.begin() + 6 == std::adjacent_find(ar.begin(), ar.end()));

    STATIC_ASSERT(ar.begin() + 6
		  == std::adjacent_find(ar.begin(), ar.end(),
					std::equal_to<int>()));

    STATIC_ASSERT(std::all_of(ae.begin(), ae.end(),
			      [](int i){ return i % 2 == 0; }));

    STATIC_ASSERT(std::any_of(a.begin(), a.end(),
			      [](int i){ return i % 2 == 0; }));

    STATIC_ASSERT(std::binary_search(a.begin(), a.end(), 5));

    STATIC_ASSERT(std::binary_search(a.begin(), a.end(), 5,
				     std::equal_to<int>()));

    STATIC_ASSERT(da.begin() + 10
		  == std::copy(a.begin(), a.begin() + 8, da.begin() + 2));

    STATIC_ASSERT(da.begin() + 2
		  == std::copy_backward(a.begin(), a.begin() + 8, da.begin() + 10));

    std::copy_if(a.begin(), a.end(), da.begin(),
		 [](int i){ return i % 2 == 1; });

    std::copy_n(a.begin(), 12, da.begin());

    STATIC_ASSERT(1 == std::count(a.begin(), a.end(), 6));

    STATIC_ASSERT(std::count_if(a.begin(), a.end(),
				[](int i){ return i % 2 == 0; }) == 6);

    STATIC_ASSERT(std::equal(a.begin(), a.end(), ac.begin()));

    STATIC_ASSERT(std::equal(a.begin(), a.end(), as.begin(),
		  [](int i, int j){ return i + 3 == j; }));

    STATIC_ASSERT(std::make_pair(ar.begin() + 6, ar.begin() + 8)
		  == std::equal_range(ar.begin(), ar.end(), 6));

    std::fill(da.begin(), da.end(), 66);

    STATIC_ASSERT(da.begin() + 11 == std::fill_n(da.begin() + 5, 6, 77));

    STATIC_ASSERT(a.begin() + 5 == std::find(a.begin(), a.end(), 5));

    STATIC_ASSERT(a.begin() + 4
		== std::find_end(a.begin(), a.end(),
				 am.begin(), am.end()));

    STATIC_ASSERT(a.begin() + 3
		== std::find_end(a.begin(), a.end(),
				 am12.begin(), am12.end(),
				 [](int i, int j){ return i + 1 == -j; }));

    STATIC_ASSERT(a.begin() + 3
		== std::find_first_of(a.begin(), a.end(),
			as.begin(), as.end()));

    STATIC_ASSERT(a.begin() + 2
		== std::find_first_of(a.begin(), a.end(),
				      as.begin(), as.end(),
				      [](int i, int j){ return i + 1 == j; }));

    STATIC_ASSERT(a.begin() + 6
		  == std::find_if(a.begin(), a.end(),
				  [](int i){ return i == 6; }));

    STATIC_ASSERT(a.begin() + 7
		  == std::find_if_not(a.begin(), a.end(),
				      [](int i){ return i <= 6; }));

    int tot = 0;
    auto sum = [&tot](int i){ tot += i; };
    auto sum2 = std::for_each(a.begin(), a.end(), sum);

    //void
    std::generate(da.begin(), da.end(), [](){ return 42; });

    STATIC_ASSERT(da.begin() + 6
		  == std::generate_n(da.begin(), 6, [](){ return 42; }));

    STATIC_ASSERT(std::includes(a.begin(), a.end(), am.begin(), am.end()));

    STATIC_ASSERT(std::includes(a.begin(), a.end(), am12.begin(), am12.end(),
				[](int i, int j){ return i == -j; }));

    STATIC_ASSERT(std::is_heap(ah.begin(), ah.end()));

    STATIC_ASSERT(std::is_heap(ah.begin(), ah.end(), std::less<int>()));

    STATIC_ASSERT(ahu.begin() + 11
		  == std::is_heap_until(ahu.begin(), ahu.end()));

    STATIC_ASSERT(ahu.begin() + 11
		  == std::is_heap_until(ahu.begin(), ahu.end(),
				        std::less<int>()));

    STATIC_ASSERT(std::is_partitioned(aeo.begin(), aeo.end(),
				      [](int i){ return i % 2 == 0; }));

    STATIC_ASSERT(std::is_permutation(a.begin(), a.end(), ap.begin()));

    STATIC_ASSERT(std::is_permutation(a.begin(), a.end(), ap.begin(),
		  std::equal_to<int>()));

    STATIC_ASSERT(std::is_sorted(a.begin(), a.end()));

    STATIC_ASSERT(std::is_sorted(a.begin(), a.end(), std::equal_to<int>()));

    STATIC_ASSERT(aus.begin() + 7
		  == std::is_sorted_until(aus.begin(), aus.end()));

    STATIC_ASSERT(aus.begin() + 7
		  == std::is_sorted_until(aus.begin(), aus.end(),
		  std::less<int>()));

    STATIC_ASSERT(!std::lexicographical_compare(a.begin(), a.end(),
						ac.begin(), ac.end()));

    STATIC_ASSERT(!std::lexicographical_compare(a.begin(), a.end(),
				 ac.begin(), ac.end(), std::less<int>()));

    STATIC_ASSERT(a.begin() + 6
		  == std::lower_bound(a.begin(), a.end(), 6));

    STATIC_ASSERT(a.begin() + 6
		  == std::lower_bound(a.begin(), a.end(), 6,
				      std::less<int>()));

    STATIC_ASSERT(o.end()
		  == std::merge(a.begin(), a.end(),
				as.begin(), as.end(), o.begin()));

    STATIC_ASSERT(o.begin() + 15
		  == std::merge(a.begin(), a.end(),
				am12.begin(), am12.end(), o.begin(),
				[](int i, int j){ return i < -j; }));

    STATIC_ASSERT(std::make_pair(a.begin() + 6, ax.begin() + 6)
		  == std::mismatch(a.begin(), a.end(), ax.begin()));

    STATIC_ASSERT(std::make_pair(a.begin() + 6, ax.begin() + 6)
		  == std::mismatch(a.begin(), a.end(), ax.begin(),
				   std::equal_to<int>()));

    STATIC_ASSERT(std::none_of(a.begin(), a.end(),
		  [](int i){ return i > 12; }));

    STATIC_ASSERT(std::make_pair(o.begin() + 6, p.begin() + 6)
		  == std::partition_copy(a.begin(), a.end(),
					 o.begin(), p.begin(),
					 [](int i){ return i % 2 == 0; }));

    STATIC_ASSERT(aeo.begin() + 6
		  == std::partition_point(aeo.begin(), aeo.end(),
					  [](int i){ return i % 2 == 0; }));

    STATIC_ASSERT(ac.begin() + 11
		  == std::remove(ac.begin(), ac.end(), 7));

    STATIC_ASSERT(ac2.begin() + 11
		  == std::remove_if(ac2.begin(), ac2.end(),
				    [](int i){ return i == 7; }));

    STATIC_ASSERT(o.begin() + 11
		  == std::remove_copy(a.begin(), a.end(), o.begin(), 6));

    STATIC_ASSERT(o.begin() + 11
		  == std::remove_copy_if(a.begin(), a.end(), o.begin(),
					 [](int i){ return i == 7; }));

    STATIC_ASSERT(o.begin() + 12
		  == std::replace_copy(a.begin(), a.end(), o.begin(), 6, 666));

    STATIC_ASSERT(o.begin() + 12
		  == std::replace_copy_if(a.begin(), a.end(), o.begin(),
			     [](int i){ return i < 6; }, 666));

    STATIC_ASSERT(o.begin() + 12
		  == std::reverse_copy(a.rbegin(), a.rend(), o.begin()));

    STATIC_ASSERT(o.begin() + 12
		  == std::rotate_copy(a.begin(), a.begin() + 6,
				      a.end(), o.begin()));

    STATIC_ASSERT(a.begin() + 4
		  == std::search(a.begin(), a.end(), am.begin(), am.end()));

    STATIC_ASSERT(a.begin() + 4
		  == std::search(a.begin(), a.end(),
				 am.begin(), am.end(),
				 std::equal_to<int>()));

    STATIC_ASSERT(ar.begin() + 6
		  == std::search_n(ar.begin(), ar.end(), 2, 6));

    STATIC_ASSERT(o.begin() + 3
		  == std::set_difference(a.begin(), a.end(),
					 as.begin(), as.end(), o.begin()));

    STATIC_ASSERT(o.begin() + 3
		  == std::set_difference(a.begin(), a.end(),
					 as.begin(), as.end(),
					 o.begin(), std::less<int>()));

    STATIC_ASSERT(o.begin() + 9
		  == std::set_intersection(a.begin(), a.end(),
					   as.begin(), as.end(), o.begin()));

    STATIC_ASSERT(o.begin() + 9
		  == std::set_intersection(a.begin(), a.end(),
					   as.begin(), as.end(),
					   o.begin(), std::less<int>()));

    STATIC_ASSERT(o.begin() + 6
		  == std::set_symmetric_difference(a.begin(), a.end(),
						   as.begin(), as.end(),
						   o.begin()));

    STATIC_ASSERT(o.begin() + 6
		  == std::set_symmetric_difference(a.begin(), a.end(),
					as.begin(), as.end(),
					o.begin(), std::less<int>()));

    STATIC_ASSERT(o.begin() + 15
		  == std::set_union(a.begin(), a.end(),
				    as.begin(), as.end(), o.begin()));

    STATIC_ASSERT(o.begin() + 15
		  == std::set_union(a.begin(), a.end(),
				    as.begin(), as.end(),
				    o.begin(), std::less<int>()));

    STATIC_ASSERT(ar.begin() + 10
		  == std::unique(ar.begin(), ar.end()));

    STATIC_ASSERT(ar2.begin() + 10
		  == std::unique(ar2.begin(), ar2.end(), std::equal_to<int>()));

    STATIC_ASSERT(o.begin() + 10
		  == std::unique_copy(ar3.begin(), ar3.end(), o.begin()));

    STATIC_ASSERT(o.begin() + 10
		  == std::unique_copy(ar3.begin(), ar3.end(), o.begin(),
				      std::equal_to<int>()));

    STATIC_ASSERT(a.begin() + 7
		  == std::upper_bound(a.begin(), a.end(), 6));

    STATIC_ASSERT(a.begin() + 7
		  == std::upper_bound(a.begin(), a.end(), 6,
				      std::less<int>()));

    STATIC_ASSERT(o.begin() + 12
		  == std::transform(a.begin(), a.end(), o.begin(),
				    [del=6](int i){ return i + del; }));

    STATIC_ASSERT(o.begin() + 12
		  == std::transform(a.begin(), a.end(), a.begin(), o.begin(),
				    [](int i, int j){ return i + j; }));
  }

#ifdef STATIC_ASSERT
int
main()
{
  test_constexpr_algo();
}
#endif
