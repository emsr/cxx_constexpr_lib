algo=testsuite/25_algorithms/

mkdir $algo/adjacent_find
mkdir $algo/all_of
mkdir $algo/any_of
mkdir $algo/binary_search
mkdir $algo/copy
mkdir $algo/copy_backward
mkdir $algo/copy_if
mkdir $algo/copy_n
mkdir $algo/count
mkdir $algo/count_if
mkdir $algo/equal
mkdir $algo/equal_range
mkdir $algo/fill
mkdir $algo/fill_n
mkdir $algo/find
mkdir $algo/find_end
mkdir $algo/find_first_of
mkdir $algo/find_if
mkdir $algo/find_if_not
mkdir $algo/for_each
mkdir $algo/generate
mkdir $algo/generate_n
mkdir $algo/is_heap
mkdir $algo/is_heap_until
mkdir $algo/is_partitioned
mkdir $algo/is_permutation
mkdir $algo/is_sorted
mkdir $algo/is_sorted_until
mkdir $algo/lexicographical_compare
mkdir $algo/lower_bound
mkdir $algo/merge
mkdir $algo/mismatch
mkdir $algo/none_of
mkdir $algo/partition_copy
mkdir $algo/partition_point
mkdir $algo/remove
mkdir $algo/remove_copy
mkdir $algo/remove_copy_if
mkdir $algo/remove_if
mkdir $algo/replace_copy
mkdir $algo/replace_copy_if
mkdir $algo/replace_if
mkdir $algo/reverse_copy
mkdir $algo/rotate_copy
mkdir $algo/search
mkdir $algo/search_n
mkdir $algo/set_difference
mkdir $algo/set_intersection
mkdir $algo/set_symmetric_difference
mkdir $algo/set_union
mkdir $algo/transform
mkdir $algo/unique
mkdir $algo/unique_copy
mkdir $algo/upper_bound



for subdir in $(ls $algo)
do
  dir=$algo/$subdir
  ls $dir

touch $dir/constexpr.cc
cat > $dir/constexpr.cc <<- EOM
// Copyright (C) 2019 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// { dg-options "-std=gnu++2a" }
// { dg-do compile { target c++2a } }

#include <algorithm>
#include <array>

constexpr void
test()
{
}
EOM
done

for subdir in $(ls $algo)
do
  dir=$algo/$subdir
  cp $dir/constexpr.cc /home/ed/gcc_git/libstdc++-v3/$dir
done
