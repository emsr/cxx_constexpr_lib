
#include <array>
#include <algorithm>

constexpr bool
test_constexpr_algo()
{
  constexpr std::array<int, 12> ca0{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  constexpr std::array<int, 12> ca1{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  constexpr std::array<int, 12> cap{{2, 1, 3, 6, 7, 5, 4, 8, 10, 9, 0, 11}};
  constexpr std::array<int, 12> car{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar0{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar1{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar2{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar3{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar4{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  constexpr std::array<int, 12> aus{{0, 1, 2, 3, 4, 5, 66, 7, 8, 9, 10, 11}};
  std::array<int, 12> ma0{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  constexpr std::array<int, 3> cam{{4, 5, 6}};
  constexpr std::array<int, 3> camm{{-4, -5, -6}};
  std::array<int, 12> ac2{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
  constexpr std::array<int, 12> cas{{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}};
  constexpr std::array<int, 12> cax{{0, 1, 2, 3, 4, 5, 66, 7, 8, 99, 10, 11}};
  constexpr std::array<int, 6> cae{{0, 2, 4, 6, 8, 10}};
  constexpr std::array<int, 6> cao{{1, 3, 5, 7, 9, 11}};
  constexpr std::array<int, 12> caeo{{0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 11}};
  std::array<int, 24> out0{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  std::array<int, 24> out1{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  // heap
  constexpr std::array<int, 23>
  ah{{22,
      21, 20,
      17, 16, 19, 18,
      11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4}};
  // heap
  constexpr std::array<int, 23>
  ahu{{22,
      21, 20,
      17, 16, 19, 18,
      11, 10, 9, 8, 23, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4}};

  const auto out0x = std::adjacent_find(car.begin(), car.end());

  const auto out1x = std::adjacent_find(car.begin(), car.end(),
					std::equal_to<int>());

  const auto out2 = std::all_of(cae.begin(), cae.end(),
			        [](int i){ return i % 2 == 0; });

  const auto out3 = std::any_of(ca0.begin(), ca0.end(),
			        [](int i){ return i % 2 == 0; });

  const auto out4 = std::binary_search(ca0.begin(), ca0.end(), 5);

  const auto out5 = std::binary_search(ca0.begin(), ca0.end(), 5,
				       std::equal_to<int>());

  const auto out6 = std::copy(ca0.begin(), ca0.begin() + 8, ma0.begin() + 2);

  const auto out7 = std::copy_backward(ca0.begin(), ca0.begin() + 8,
				       ma0.begin() + 10);

  std::copy_if(ca0.begin(), ca0.end(), ma0.begin(),
	       [](int i){ return i % 2 == 1; });

  std::copy_n(ca0.begin(), 12, ma0.begin());

  const auto out8 = std::count(ca0.begin(), ca0.end(), 6);

  const auto out9 = std::count_if(ca0.begin(), ca0.end(),
				  [](int i){ return i % 2 == 0; });

  const auto outa = std::equal(ca0.begin(), ca0.end(), ca1.begin());

  const auto outb = std::equal(ca0.begin(), ca0.end(), cas.begin(),
			       [](int i, int j){ return i + 3 == j; });

  const auto outc = std::equal_range(car.begin(), car.end(), 6);

  std::fill(ma0.begin(), ma0.end(), 66);

  const auto outd = std::fill_n(ma0.begin() + 5, 6, 77);

  const auto oute = std::find(ca0.begin(), ca0.end(), 5);

  const auto outf = std::find_end(ca0.begin(), ca0.end(),
				  cam.begin(), cam.end());

  const auto outg = std::find_end(ca0.begin(), ca0.end(),
				  camm.begin(), camm.end(),
				  [](int i, int j){ return i + 1 == -j; });

  const auto outh = std::find_first_of(ca0.begin(), ca0.end(),
				       cas.begin(), cas.end());

  const auto outi = std::find_first_of(ca0.begin(), ca0.end(),
				       cas.begin(), cas.end(),
				       [](int i, int j){ return i + 1 == j; });

  const auto outj = std::find_if(ca0.begin(), ca0.end(),
				 [](int i){ return i == 6; });

  const auto outk = std::find_if_not(ca0.begin(), ca0.end(),
				     [](int i){ return i <= 6; });

  int tot = 0;
  auto sum = [&tot](int i){ tot += i; };
  auto sum2 = std::for_each(ca0.begin(), ca0.end(), sum);

  //void
  std::generate(ma0.begin(), ma0.end(), [](){ return 42; });

  const auto outl = std::generate_n(ma0.begin(), 6, [](){ return 42; });

  const auto outm = std::includes(ca0.begin(), ca0.end(), cam.begin(),
				  cam.end());

  const auto outn = std::includes(ca0.begin(), ca0.end(),
				  camm.begin(), camm.end(),
				  [](int i, int j){ return i == -j; });

  const auto outo = std::is_heap(ah.begin(), ah.end());

  const auto outp = std::is_heap(ah.begin(), ah.end(), std::less<int>());

  const auto outq = std::is_heap_until(ahu.begin(), ahu.end());

  const auto outr = std::is_heap_until(ahu.begin(), ahu.end(),
				       std::less<int>());

  const auto outs = std::is_partitioned(caeo.begin(), caeo.end(),
					[](int i){ return i % 2 == 0; });

  const auto outt = std::is_permutation(ca0.begin(), ca0.end(), cap.begin());

  const auto outu = std::is_permutation(ca0.begin(), ca0.end(), cap.begin(),
				    std::equal_to<int>());

  const auto outv = std::is_sorted(ca0.begin(), ca0.end());

  const auto outw = std::is_sorted(ca0.begin(), ca0.end(),
				   std::equal_to<int>());

  const auto outx = std::is_sorted_until(aus.begin(), aus.end());

  const auto outy = std::is_sorted_until(aus.begin(), aus.end(),
					 std::less<int>());

  const auto outz = !std::lexicographical_compare(ca0.begin(), ca0.end(),
						  ca1.begin(), ca1.end());

  const auto outaa = !std::lexicographical_compare(ca0.begin(), ca0.end(),
						   ca1.begin(), ca1.end(),
						   std::less<int>());

  const auto outbb = std::lower_bound(ca0.begin(), ca0.end(), 6);

  const auto outcc = std::lower_bound(ca0.begin(), ca0.end(), 6,
				      std::less<int>());

  const auto outdd = std::merge(ca0.begin(), ca0.end(),
				cas.begin(), cas.end(), out0.begin());

  const auto outee = std::merge(ca0.begin(), ca0.end(),
				camm.begin(), camm.end(), out0.begin(),
				[](int i, int j){ return i < -j; });

  const auto outff = std::mismatch(ca0.begin(), ca0.end(), cax.begin());

  const auto outgg = std::mismatch(ca0.begin(), ca0.end(), cax.begin(),
				   std::equal_to<int>());

  const auto outhh = std::none_of(ca0.begin(), ca0.end(),
				  [](int i){ return i > 12; });

  const auto outii = std::partition_copy(ca0.begin(), ca0.end(),
					 out0.begin(), out1.begin(),
					 [](int i){ return i % 2 == 0; });

  const auto outjj = std::partition_point(caeo.begin(), caeo.end(),
					  [](int i){ return i % 2 == 0; });

  const auto outkk = std::remove(ar4.begin(), ar4.end(), 7);

  const auto outll = std::remove_if(ac2.begin(), ac2.end(),
				    [](int i){ return i == 7; });

  const auto outmm = std::remove_copy(ca0.begin(), ca0.end(), out0.begin(), 6);

  const auto outnn = std::remove_copy_if(ca0.begin(), ca0.end(), out0.begin(),
					 [](int i){ return i == 7; });

  std::replace(ar0.begin(), ar0.end(), 6, 66);

  std::replace_if(ar0.begin(), ar0.end(), [](int i){ return i % 2 == 1; }, 42);

  const auto outoo = std::replace_copy(ca0.begin(), ca0.end(),
				       out0.begin(), 6, 66);

  const auto outpp = std::replace_copy_if(ca0.begin(), ca0.end(), out0.begin(),
					  [](int i){ return i < 6; }, 66);

  const auto outqq = std::reverse_copy(ca0.rbegin(), ca0.rend(), out0.begin());

  const auto outrr = std::rotate_copy(ca0.begin(), ca0.begin() + 6,
				      ca0.end(), out0.begin());

  const auto outss = std::search(ca0.begin(), ca0.end(),
				 cam.begin(), cam.end());

  const auto outtt = std::search(ca0.begin(), ca0.end(),
				 cam.begin(), cam.end(),
				 std::equal_to<int>());

  const auto outuu = std::search_n(car.begin(), car.end(), 2, 6);

  const auto outvv = std::set_difference(ca0.begin(), ca0.end(),
					 cas.begin(), cas.end(), out0.begin());

  const auto outww = std::set_difference(ca0.begin(), ca0.end(),
				         cas.begin(), cas.end(),
				         out0.begin(), std::less<int>());

  const auto outxx = std::set_intersection(ca0.begin(), ca0.end(),
					   cas.begin(), cas.end(),
					   out0.begin());

  const auto outyy = std::set_intersection(ca0.begin(), ca0.end(),
					   cas.begin(), cas.end(),
					   out0.begin(), std::less<int>());

  const auto outzz = std::set_symmetric_difference(ca0.begin(), ca0.end(),
						   cas.begin(), cas.end(),
						   out0.begin());

  const auto out00 = std::set_symmetric_difference(ca0.begin(), ca0.end(),
						   cas.begin(), cas.end(),
						   out0.begin(),
						   std::less<int>());

  const auto out11 = std::set_union(ca0.begin(), ca0.end(),
				    cas.begin(), cas.end(), out0.begin());

  const auto out22 = std::set_union(ca0.begin(), ca0.end(),
				    cas.begin(), cas.end(),
				    out0.begin(), std::less<int>());

  const auto out99 = std::transform(ca0.begin(), ca0.end(), out0.begin(),
				    [del=6](int i){ return i + del; });

  const auto out123 = std::transform(ca0.begin(), ca0.end(), ca0.begin(),
				     out0.begin(),
				     [](int i, int j){ return i + j; });

  const auto out33 = std::unique(ar1.begin(), ar1.end());

  const auto out44 = std::unique(ar2.begin(), ar2.end(), std::equal_to<int>());

  const auto out55 = std::unique_copy(ar3.begin(), ar3.end(), out0.begin());

  const auto out66 = std::unique_copy(ar3.begin(), ar3.end(), out0.begin(),
				      std::equal_to<int>());

  const auto out77 = std::upper_bound(ca0.begin(), ca0.end(), 6);

  const auto out88 = std::upper_bound(ca0.begin(), ca0.end(), 6,
				      std::less<int>());

  return true;
}

int
main()
{
  static_assert(test_constexpr_algo());
}
