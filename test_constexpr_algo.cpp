
#include <array>
#include <algorithm>

#ifdef STATIC_ASSERT
#  include <cassert>
#  define CONSTEXPR
#else
#  define STATIC_ASSERT static_assert
#  define CONSTEXPR constexpr
#endif

CONSTEXPR void
test_constexpr_algo()
{
  CONSTEXPR std::array<int, 12> ca0{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  CONSTEXPR std::array<int, 12> ca1{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  CONSTEXPR std::array<int, 12> cap{{2, 1, 3, 6, 7, 5, 4, 8, 10, 9, 0, 11}};
  CONSTEXPR std::array<int, 12> car{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar1{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar2{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar3{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar4{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  CONSTEXPR std::array<int, 12> aus{{0, 1, 2, 3, 4, 5, 66, 7, 8, 9, 10, 11}};
  std::array<int, 12> ma0{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  CONSTEXPR std::array<int, 3> cam{{4, 5, 6}};
  CONSTEXPR std::array<int, 3> camm{{-4, -5, -6}};
  std::array<int, 12> ac2{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  CONSTEXPR std::array<int, 12> as{{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}};
  CONSTEXPR std::array<int, 12> cax{{0, 1, 2, 3, 4, 5, 66, 7, 8, 99, 10, 11}};
  CONSTEXPR std::array<int, 6> cae{{0, 2, 4, 6, 8, 10}};
  CONSTEXPR std::array<int, 6> cao{{1, 3, 5, 7, 9, 11}};
  CONSTEXPR std::array<int, 12> caeo{{0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 11}};
  std::array<int, 24> out0{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  std::array<int, 24> out1{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
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

  STATIC_ASSERT(car.begin() + 6 == std::adjacent_find(car.begin(), car.end()));

  STATIC_ASSERT(car.begin() + 6
		== std::adjacent_find(car.begin(), car.end(),
				      std::equal_to<int>()));

  STATIC_ASSERT(std::all_of(cae.begin(), cae.end(),
			    [](int i){ return i % 2 == 0; }));

  STATIC_ASSERT(std::any_of(ca0.begin(), ca0.end(),
			    [](int i){ return i % 2 == 0; }));

  STATIC_ASSERT(std::binary_search(ca0.begin(), ca0.end(), 5));

  STATIC_ASSERT(std::binary_search(ca0.begin(), ca0.end(), 5,
				   std::equal_to<int>()));

  STATIC_ASSERT(ma0.begin() + 10
		== std::copy(ca0.begin(), ca0.begin() + 8, ma0.begin() + 2));

  STATIC_ASSERT(ma0.begin() + 2
		== std::copy_backward(ca0.begin(), ca0.begin() + 8,
				      ma0.begin() + 10));

  std::copy_if(ca0.begin(), ca0.end(), ma0.begin(),
	       [](int i){ return i % 2 == 1; });

  std::copy_n(ca0.begin(), 12, ma0.begin());

  STATIC_ASSERT(1 == std::count(ca0.begin(), ca0.end(), 6));

  STATIC_ASSERT(std::count_if(ca0.begin(), ca0.end(),
			      [](int i){ return i % 2 == 0; }) == 6);

  STATIC_ASSERT(std::equal(ca0.begin(), ca0.end(), ca1.begin()));

  STATIC_ASSERT(std::equal(ca0.begin(), ca0.end(), as.begin(),
		[](int i, int j){ return i + 3 == j; }));

  STATIC_ASSERT(std::make_pair(car.begin() + 6, car.begin() + 8)
		== std::equal_range(car.begin(), car.end(), 6));

  std::fill(ma0.begin(), ma0.end(), 66);

  STATIC_ASSERT(ma0.begin() + 11 == std::fill_n(ma0.begin() + 5, 6, 77));

  STATIC_ASSERT(ca0.begin() + 5 == std::find(ca0.begin(), ca0.end(), 5));

  STATIC_ASSERT(ca0.begin() + 4
	      == std::find_end(ca0.begin(), ca0.end(),
			       cam.begin(), cam.end()));

  STATIC_ASSERT(ca0.begin() + 3
	      == std::find_end(ca0.begin(), ca0.end(),
			       camm.begin(), camm.end(),
			       [](int i, int j){ return i + 1 == -j; }));

  STATIC_ASSERT(ca0.begin() + 3
	      == std::find_first_of(ca0.begin(), ca0.end(),
		      as.begin(), as.end()));

  STATIC_ASSERT(ca0.begin() + 2
	      == std::find_first_of(ca0.begin(), ca0.end(),
				    as.begin(), as.end(),
				    [](int i, int j){ return i + 1 == j; }));

  STATIC_ASSERT(ca0.begin() + 6
		== std::find_if(ca0.begin(), ca0.end(),
				[](int i){ return i == 6; }));

  STATIC_ASSERT(ca0.begin() + 7
		== std::find_if_not(ca0.begin(), ca0.end(),
				    [](int i){ return i <= 6; }));

  int tot = 0;
  auto sum = [&tot](int i){ tot += i; };
  auto sum2 = std::for_each(ca0.begin(), ca0.end(), sum);

  //void
  std::generate(ma0.begin(), ma0.end(), [](){ return 42; });

  STATIC_ASSERT(ma0.begin() + 6
		== std::generate_n(ma0.begin(), 6, [](){ return 42; }));

  STATIC_ASSERT(std::includes(ca0.begin(), ca0.end(), cam.begin(), cam.end()));

  STATIC_ASSERT(std::includes(ca0.begin(), ca0.end(), camm.begin(), camm.end(),
			      [](int i, int j){ return i == -j; }));

  STATIC_ASSERT(std::is_heap(ah.begin(), ah.end()));

  STATIC_ASSERT(std::is_heap(ah.begin(), ah.end(), std::less<int>()));

  STATIC_ASSERT(ahu.begin() + 11
		== std::is_heap_until(ahu.begin(), ahu.end()));

  STATIC_ASSERT(ahu.begin() + 11
		== std::is_heap_until(ahu.begin(), ahu.end(),
				      std::less<int>()));

  STATIC_ASSERT(std::is_partitioned(caeo.begin(), caeo.end(),
				    [](int i){ return i % 2 == 0; }));

  STATIC_ASSERT(std::is_permutation(ca0.begin(), ca0.end(), cap.begin()));

  STATIC_ASSERT(std::is_permutation(ca0.begin(), ca0.end(), cap.begin(),
				    std::equal_to<int>()));

  STATIC_ASSERT(std::is_sorted(ca0.begin(), ca0.end()));

  STATIC_ASSERT(std::is_sorted(ca0.begin(), ca0.end(), std::equal_to<int>()));

  STATIC_ASSERT(aus.begin() + 7
		== std::is_sorted_until(aus.begin(), aus.end()));

  STATIC_ASSERT(aus.begin() + 7
		== std::is_sorted_until(aus.begin(), aus.end(),
					std::less<int>()));

  STATIC_ASSERT(!std::lexicographical_compare(ca0.begin(), ca0.end(),
					      ca1.begin(), ca1.end()));

  STATIC_ASSERT(!std::lexicographical_compare(ca0.begin(), ca0.end(),
					      ca1.begin(), ca1.end(),
					      std::less<int>()));

  STATIC_ASSERT(ca0.begin() + 6
		== std::lower_bound(ca0.begin(), ca0.end(), 6));

  STATIC_ASSERT(ca0.begin() + 6
		== std::lower_bound(ca0.begin(), ca0.end(), 6,
				    std::less<int>()));

  STATIC_ASSERT(out0.end()
		== std::merge(ca0.begin(), ca0.end(),
			      as.begin(), as.end(), out0.begin()));

  STATIC_ASSERT(out0.begin() + 15
		== std::merge(ca0.begin(), ca0.end(),
			      camm.begin(), camm.end(), out0.begin(),
			      [](int i, int j){ return i < -j; }));

  STATIC_ASSERT(std::make_pair(ca0.begin() + 6, cax.begin() + 6)
		== std::mismatch(ca0.begin(), ca0.end(), cax.begin()));

  STATIC_ASSERT(std::make_pair(ca0.begin() + 6, cax.begin() + 6)
		== std::mismatch(ca0.begin(), ca0.end(), cax.begin(),
				 std::equal_to<int>()));

  STATIC_ASSERT(std::none_of(ca0.begin(), ca0.end(),
		[](int i){ return i > 12; }));

  STATIC_ASSERT(std::make_pair(out0.begin() + 6, out1.begin() + 6)
		== std::partition_copy(ca0.begin(), ca0.end(),
				       out0.begin(), out1.begin(),
				       [](int i){ return i % 2 == 0; }));

  STATIC_ASSERT(caeo.begin() + 6
		== std::partition_point(caeo.begin(), caeo.end(),
					[](int i){ return i % 2 == 0; }));

  STATIC_ASSERT(ar4.begin() + 11
		== std::remove(ar4.begin(), ar4.end(), 7));

  STATIC_ASSERT(ac2.begin() + 11
		== std::remove_if(ac2.begin(), ac2.end(),
				  [](int i){ return i == 7; }));

  STATIC_ASSERT(out0.begin() + 11
		== std::remove_copy(ca0.begin(), ca0.end(), out0.begin(), 6));

  STATIC_ASSERT(out0.begin() + 11
		== std::remove_copy_if(ca0.begin(), ca0.end(), out0.begin(),
				       [](int i){ return i == 7; }));

  STATIC_ASSERT(out0.begin() + 12
		== std::replace_copy(ca0.begin(), ca0.end(), out0.begin(), 6, 666));

  STATIC_ASSERT(out0.begin() + 12
		== std::replace_copy_if(ca0.begin(), ca0.end(), out0.begin(),
			   [](int i){ return i < 6; }, 666));

  STATIC_ASSERT(out0.begin() + 12
		== std::reverse_copy(ca0.rbegin(), ca0.rend(), out0.begin()));

  STATIC_ASSERT(out0.begin() + 12
		== std::rotate_copy(ca0.begin(), ca0.begin() + 6,
				    ca0.end(), out0.begin()));

  STATIC_ASSERT(ca0.begin() + 4
		== std::search(ca0.begin(), ca0.end(), cam.begin(), cam.end()));

  STATIC_ASSERT(ca0.begin() + 4
		== std::search(ca0.begin(), ca0.end(),
			       cam.begin(), cam.end(),
			       std::equal_to<int>()));

  STATIC_ASSERT(car.begin() + 6
		== std::search_n(car.begin(), car.end(), 2, 6));

  STATIC_ASSERT(out0.begin() + 3
		== std::set_difference(ca0.begin(), ca0.end(),
				       as.begin(), as.end(), out0.begin()));

  STATIC_ASSERT(out0.begin() + 3
		== std::set_difference(ca0.begin(), ca0.end(),
				       as.begin(), as.end(),
				       out0.begin(), std::less<int>()));

  STATIC_ASSERT(out0.begin() + 9
		== std::set_intersection(ca0.begin(), ca0.end(),
					 as.begin(), as.end(), out0.begin()));

  STATIC_ASSERT(out0.begin() + 9
		== std::set_intersection(ca0.begin(), ca0.end(),
					 as.begin(), as.end(),
					 out0.begin(), std::less<int>()));

  STATIC_ASSERT(out0.begin() + 6
		== std::set_symmetric_difference(ca0.begin(), ca0.end(),
						 as.begin(), as.end(),
						 out0.begin()));

  STATIC_ASSERT(out0.begin() + 6
		== std::set_symmetric_difference(ca0.begin(), ca0.end(),
				      as.begin(), as.end(),
				      out0.begin(), std::less<int>()));

  STATIC_ASSERT(out0.begin() + 15
		== std::set_union(ca0.begin(), ca0.end(),
				  as.begin(), as.end(), out0.begin()));

  STATIC_ASSERT(out0.begin() + 15
		== std::set_union(ca0.begin(), ca0.end(),
				  as.begin(), as.end(),
				  out0.begin(), std::less<int>()));

  STATIC_ASSERT(ar1.begin() + 10
		== std::unique(ar1.begin(), ar1.end()));

  STATIC_ASSERT(ar2.begin() + 10
		== std::unique(ar2.begin(), ar2.end(), std::equal_to<int>()));

  STATIC_ASSERT(out0.begin() + 10
		== std::unique_copy(ar3.begin(), ar3.end(), out0.begin()));

  STATIC_ASSERT(out0.begin() + 10
		== std::unique_copy(ar3.begin(), ar3.end(), out0.begin(),
				    std::equal_to<int>()));

  STATIC_ASSERT(ca0.begin() + 7
		== std::upper_bound(ca0.begin(), ca0.end(), 6));

  STATIC_ASSERT(ca0.begin() + 7
		== std::upper_bound(ca0.begin(), ca0.end(), 6,
				    std::less<int>()));

  STATIC_ASSERT(out0.begin() + 12
		== std::transform(ca0.begin(), ca0.end(), out0.begin(),
				  [del=6](int i){ return i + del; }));

  STATIC_ASSERT(out0.begin() + 12
		== std::transform(ca0.begin(), ca0.end(), ca0.begin(),
				  out0.begin(),
				  [](int i, int j){ return i + j; }));
}

#ifdef STATIC_ASSERT
int
main()
{
  test_constexpr_algo();
}
#endif
