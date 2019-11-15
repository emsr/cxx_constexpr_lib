/*
/home/ed/bin/bin/g++ -std=c++2a -g -o test_constexpr_misc test_constexpr_misc.cpp
/home/ed/bin/bin/g++ -std=c++17 -g -o test_constexpr_misc test_constexpr_misc.cpp
*/

#include <string>
#include <iterator>

#include <utility>
#include <tuple>

template<typename Flt>
  struct xy
  {
    int id;
    Flt xv, yv;

    constexpr xy(int iid, Flt ix, Flt iy)
    : id{iid}, xv{ix}, yv{iy}
    {}
  };

template<typename Flt>
  struct z
  {
    int id;
    Flt zv;

    constexpr z(int iid, Flt iz)
    : id{iid}, zv{iz}
    {}
  };

bool
test_pair()
{
  auto ok = true;

  using t1_t = std::tuple<int, double, double>;
  const t1_t t1(0, 3.456, 6.789);

  using t2_t = std::tuple<int, double>;
  const t2_t t2(12, 3.142);

  std::pair<t1_t, t2_t> p1(std::piecewise_construct, t1, t2);

  std::pair<xy<double>, z<double>> p3(std::piecewise_construct, t1, t2);

  std::pair<int, int> pi(1,2);
  std::pair<float, float> pf(3.4f,5.6f);
  pf = pi;
  pf = std::move(pi);

  using t1f_t = std::tuple<int, float, float>;
  const t1f_t t1f(0, 3.456f, 6.789f);

  using t2f_t = std::tuple<int, float>;
  const t2f_t t2f(12, 3.142f);

  std::pair<t1f_t, t2f_t> p1f(std::piecewise_construct, t1f, t2f);

  p1 = p1f;

  p1 = std::move(p1f);

  return ok;
}

bool
test_constexpr_misc()
{
  auto ok = true;

  //std::string s = "Hello, World!!!";
  //char cas[8]{};
  //s.copy(cas, 7, 1);

  constexpr std::string_view sv = "Hello, World!!!";
  char casv[8]{};
  sv.copy(casv, 7, 1);

  char das[8]{};
  std::char_traits<char>::move(das, casv, 7);
  std::char_traits<char>::copy(das, casv, 7);
  std::char_traits<char>::assign(das, 7, 'x');

  constexpr std::wstring_view wsv = L"Hello, World!!!";
  wchar_t cawsv[8]{};
  wsv.copy(cawsv, 7, 1);

  wchar_t wdas[8]{};
  std::char_traits<wchar_t>::move(wdas, cawsv, 7);
  std::char_traits<wchar_t>::copy(wdas, cawsv, 7);
  std::char_traits<wchar_t>::assign(wdas, 7, L'x');


  return ok;
}

int
main()
{
  test_constexpr_misc();
  test_pair();
}
