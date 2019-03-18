
#CXX = ../bin_git_constexpr/bin/g++ -std=c++2a
CXX = ../bin/bin/g++ -std=c++2a

all: synopsis.o constexpr_array.o constexpr_exchange.o test_algo test_constexpr_algo test_constexpr_algo_help

synopsis.o:
	$(CXX) -c synopsis.cc

constexpr_array.o:
	$(CXX) -c constexpr_array.cc

constexpr_exchange.o:
	$(CXX) -c constexpr_exchange.cc

test_algo: test_constexpr_algo.cpp
	$(CXX) -DSTATIC_ASSERT=assert -o test_algo test_constexpr_algo.cpp

test_constexpr_algo: test_constexpr_algo.cpp
	$(CXX) -o test_constexpr_algo test_constexpr_algo.cpp

test_constexpr_algo_help: test_constexpr_algo_help.cpp
	$(CXX) -o test_constexpr_algo_help test_constexpr_algo_help.cpp
