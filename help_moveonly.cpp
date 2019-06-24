/*
$HOME/bin/bin/g++ -std=gnu++2a -o help_moveonly help_moveonly.cpp
*/

#include <array>

struct MoveOnly
{
  constexpr MoveOnly()
  { }

  constexpr MoveOnly(int m)
  : _M_m{m}
  { }

  constexpr MoveOnly&
  operator=(MoveOnly&& mo)
  {
    this->_M_m = mo._M_m;
    return *this;
  }

  int _M_m = 0;
};

constexpr void
test()
{
  //std::array<MoveOnly, 5> {{MoveOnly{1},MoveOnly{2},MoveOnly{3},MoveOnly{4},MoveOnly{5}}};
  constexpr std::array<MoveOnly, 5> moa;

  constexpr std::array<MoveOnly, 5> mob;
  std::copy(moa.begin(), moa.end(), mob.begin());
}

int
main()
{
  std::array<MoveOnly, 5> moa;//{{MoveOnly{1},MoveOnly{2},MoveOnly{3},MoveOnly{4},MoveOnly{5}}};
}
