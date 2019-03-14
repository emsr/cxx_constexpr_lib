
all: constexpr.o test_constexpr_algo

constexpr.o:
	../bin_git_constexpr/bin/g++ -std=c++2a -c constexpr.cc

test_constexpr_algo: test_constexpr_algo.cpp
	../bin_git_constexpr/bin/g++ -std=c++2a -o test_constexpr_algo test_constexpr_algo.cpp

test_algo: test_constexpr_algo.cpp
	../bin_git_constexpr/bin/g++ -std=c++2a -DSTATIC_ASSERT=assert -o test_algo test_constexpr_algo.cpp
