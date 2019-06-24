/*
g++ -g -o copy copy.cpp
../bin/bin/g++ -g -o copy copy.cpp
clang++ -g -o copy copy.cpp
*/

#include <algorithm>
#include <numeric>

int
main()
{
  float arr[1000];
  std::iota(arr, arr + 1000, 1.0f);

  float brr[1000];
  std::fill(brr, brr + 1000, 0);

  std::copy(arr, arr + 500, brr + 500);
}
