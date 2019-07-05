#! /bin/bash -x

CXX="$HOME/bin_constexpr_lib/bin/g++ -std=gnu++2a -g -c"

$CXX testsuite/25_algorithms/iter_swap/constexpr.cc
$CXX testsuite/25_algorithms/make_heap/constexpr.cc
$CXX testsuite/25_algorithms/next_permutation/constexpr.cc
$CXX testsuite/25_algorithms/nth_element/constexpr.cc
$CXX testsuite/25_algorithms/partial_sort/constexpr.cc
$CXX testsuite/25_algorithms/partial_sort_copy/constexpr.cc
$CXX testsuite/25_algorithms/partition/constexpr.cc
$CXX testsuite/25_algorithms/pop_heap/constexpr.cc
$CXX testsuite/25_algorithms/prev_permutation/constexpr.cc
$CXX testsuite/25_algorithms/push_heap/constexpr.cc
$CXX testsuite/25_algorithms/reverse/constexpr.cc
$CXX testsuite/25_algorithms/rotate/constexpr.cc
$CXX testsuite/25_algorithms/sort/constexpr.cc
$CXX testsuite/25_algorithms/sort_heap/constexpr.cc
$CXX testsuite/25_algorithms/swap/constexpr.cc
$CXX testsuite/25_algorithms/swap_ranges/constexpr.cc
