
all: constexpr_array.o constexpr_exchange.o test_algo test_constexpr_algo test_constexpr_algo_help

constexpr_array.o:
	../bin_git_constexpr/bin/g++ -std=c++2a -c constexpr_array.cc

constexpr_exchange.o:
	../bin_git_constexpr/bin/g++ -std=c++2a -c constexpr_exchange.cc

test_algo: test_constexpr_algo.cpp
	../bin_git_constexpr/bin/g++ -std=c++2a -DSTATIC_ASSERT=assert -o test_algo test_constexpr_algo.cpp

test_constexpr_algo: test_constexpr_algo.cpp
	../bin_git_constexpr/bin/g++ -std=c++2a -o test_constexpr_algo test_constexpr_algo.cpp

test_constexpr_algo_help: test_constexpr_algo_help.cpp
	../bin_git_constexpr/bin/g++ -std=c++2a -o test_constexpr_algo_help test_constexpr_algo_help.cpp
