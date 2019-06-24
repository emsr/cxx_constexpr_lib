
#CXX = ../bin_git_constexpr/bin/g++ -std=c++2a
CXX = ../bin_constexpr_lib/bin/g++ -std=c++2a

CXX17 = ../bin_constexpr_lib/bin/g++ -std=c++17

all: test_1 \
  copy_69478_cxx20.o copy_69478_cxx17.o \
  copy_backward_69478_cxx20.o copy_backward_69478_cxx17.o \
  move_69478_cxx20.o move_69478_cxx17.o \
  move_backward_69478_cxx20.o move_backward_69478_cxx17.o \
  copy_58982.o copy_n_58982.o uninitialized_copy_64476.o synopsis.o constexpr_array.o constexpr_exchange.o \
  test_algo test_constexpr_algo test_constexpr_algo_help \
  test_constexpr_swap_help

memory: memory.cpp
	$(CXX) -g -o memory memory.cpp

test_1: 1.cc
	$(CXX) -g -I../gcc_git/libstdc++-v3/testsuite/util -o test_1 1.cc

test_constexpr_iter.o: test_constexpr_iter.cpp
	$(CXX) -c -o test_constexpr_iter.o test_constexpr_iter.cpp

copy_69478_cxx20.o: copy_69478.cc
	$(CXX) -c -I../gcc_git/libstdc++-v3/testsuite/util -o copy_69478_cxx20.o copy_69478.cc

copy_69478_cxx17.o: copy_69478.cc
	$(CXX17) -c -I../gcc_git/libstdc++-v3/testsuite/util -o copy_69478_cxx17.o copy_69478.cc

copy_backward_69478_cxx20.o: copy_backward_69478.cc
	$(CXX) -c -I../gcc_git/libstdc++-v3/testsuite/util -o copy_backward_69478_cxx20.o copy_backward_69478.cc

copy_backward_69478_cxx17.o: copy_backward_69478.cc
	$(CXX17) -c -I../gcc_git/libstdc++-v3/testsuite/util -o copy_backward_69478_cxx17.o copy_backward_69478.cc

move_69478_cxx20.o: move_69478.cc
	$(CXX) -c -I../gcc_git/libstdc++-v3/testsuite/util -o move_69478_cxx20.o move_69478.cc

move_69478_cxx17.o: move_69478.cc
	$(CXX17) -c -I../gcc_git/libstdc++-v3/testsuite/util -o move_69478_cxx17.o move_69478.cc

move_backward_69478_cxx20.o: move_backward_69478.cc
	$(CXX) -c -I../gcc_git/libstdc++-v3/testsuite/util -o move_backward_69478_cxx20.o move_backward_69478.cc

move_backward_69478_cxx17.o: move_backward_69478.cc
	$(CXX17) -c -I../gcc_git/libstdc++-v3/testsuite/util -o move_backward_69478_cxx17.o move_backward_69478.cc

copy_58982.o: copy_58982.cc
	$(CXX) -c -I../gcc_git/libstdc++-v3/testsuite/util copy_58982.cc

copy_n_58982.o: copy_58982.cc
	$(CXX) -c -I../gcc_git/libstdc++-v3/testsuite/util copy_58982.cc

uninitialized_copy_64476.o: uninitialized_copy_64476.cc
	$(CXX) -c -I../gcc_git/libstdc++-v3/testsuite/util uninitialized_copy_64476.cc

synopsis.o: synopsis.cc
	$(CXX) -c synopsis.cc

constexpr_array.o: constexpr_array.cc
	$(CXX) -c constexpr_array.cc

constexpr_exchange.o: constexpr_exchange.cc
	$(CXX) -c constexpr_exchange.cc

test_algo: test_constexpr_algo.cpp
	$(CXX) -DSTATIC_ASSERT=assert -o test_algo test_constexpr_algo.cpp

test_constexpr_algo: test_constexpr_algo.cpp
	$(CXX) -o test_constexpr_algo test_constexpr_algo.cpp

test_constexpr_algo_help: test_constexpr_algo_help.cpp
	$(CXX) -o test_constexpr_algo_help test_constexpr_algo_help.cpp

test_constexpr_swap_help: test_constexpr_swap_help.cpp
	$(CXX) -o test_constexpr_swap_help test_constexpr_swap_help.cpp

clean:
	rm -f *.o
	rm -f memory test_1 test_algo test_constexpr_algo test_constexpr_algo_help
