/*
/home/ed/bin_constexpr_lib/bin/g++ -std=c++2a -g -o test_constexpr_misc_help test_constexpr_misc_help.cpp
/home/ed/bin_constexpr_lib/bin/g++ -std=c++17 -g -o test_constexpr_misc_help test_constexpr_misc_help.cpp
*/

#include <array>
#include <string>
#include <iterator>
#include <functional> // For default_searcher

#include <utility>
#include <tuple>
#include <list>

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

constexpr bool
test_pair()
{
  auto ok = true;

  using t1_t = std::tuple<int, double, double>;
  const t1_t t1(0, 3.456, 6.789);

  using t2_t = std::tuple<int, double>;
  const t2_t t2(12, 3.142);

  std::pair<t1_t, t2_t> p1(std::piecewise_construct, t1, t2);

  std::pair<xy<double>, z<double>> p3(std::piecewise_construct, t1, t2);

  std::pair<int, int> pi(1, 2);
  std::pair<float, float> pf(3.4f, 5.6f);
  pf = pi;
  pf = std::move(pi);

  using t1f_t = std::tuple<int, float, float>;
  const t1f_t t1f(0, 3.456f, 6.789f);
  using t2f_t = std::tuple<int, float>;
  const t2f_t t2f(12, 3.142f);
  std::pair<t1f_t, t2f_t> p1f(std::piecewise_construct, t1f, t2f);
  p1 = p1f;
  p1 = std::move(p1f);

  std::pair<int, int> pj(3, 4);
  pi.swap(pj);
  std::swap(pi, pj);

  return ok;
}

const std::allocator<int> alloc{};

constexpr bool
test_tuple()
{
  auto ok = true;

  std::tuple<int, double, double> ta(std::allocator_arg, alloc);
  std::tuple<int, double, double> tb(std::allocator_arg, alloc, 0, 3.456, 6.789);
  std::tuple<int, double, double> tc(std::allocator_arg, alloc, 0, 3.456f, 6.789f);
  std::tuple<int, double, double> td(std::allocator_arg, alloc, tb);
  std::tuple<int, double, double> te(std::allocator_arg, alloc, std::move(tb));

  std::tuple<int, float, float> tf(std::allocator_arg, alloc, 0, 3.456f, 6.789f);
  std::tuple<int, double, double> tg(std::allocator_arg, alloc, tf);
  std::tuple<int, double, double> th(std::allocator_arg, alloc, std::move(tf));

  std::pair<int, float> pf(12, 3.142f);
  std::tuple<int, double> ti(std::allocator_arg, alloc, pf);
  std::tuple<int, double> tj(std::allocator_arg, alloc, std::move(pf));

  tb = te;
  te = std::move(tb);
  tb = tf;
  tb = std::move(tf);
  ti = pf;
  tj = std::move(pf);

  tc.swap(td);
  std::swap(tc, td);

  return ok;
}

constexpr bool
test_array()
{
  auto ok = true;

  std::array<float,3> fa{};
  fa.fill(3.333f);

  std::array<float,3> fb{};

  fb.swap(fa);

  fa.fill(1.111f);

  std::swap(fa, fb);

  return ok;
}

constexpr bool
test_char_traits()
{
  auto ok = true;

  char casv[8]{"ello, W"};

  char das[8]{};
  std::char_traits<char>::move(das, casv, 7);
  std::char_traits<char>::copy(das, casv, 7);
  std::char_traits<char>::assign(das, 7, 'x');

  wchar_t cawsv[8]{L"ello, W"};

  wchar_t wdas[8]{};
  std::char_traits<wchar_t>::move(wdas, cawsv, 7);
  std::char_traits<wchar_t>::copy(wdas, cawsv, 7);
  std::char_traits<wchar_t>::assign(wdas, 7, L'x');

  return ok;
}

constexpr bool
test_string_view()
{
  auto ok = true;

  std::string_view sv = "Hello, World!!!";
  char casv[8]{};
  sv.copy(casv, 7, 1);

  std::wstring_view wsv = L"Hello, World!!!";
  wchar_t cawsv[8]{};
  wsv.copy(cawsv, 7, 1);

  return ok;
}

const std::string
version = "UsefulThing Version-3.2.1";

const std::wstring
wversion = L"UsefulThing Version-3.2.1";

constexpr bool
test_string()
{
  auto ok = true;

  char cas[6]{};
  version.copy(cas, 5, 6);

  wchar_t wcas[6]{};
  wversion.copy(wcas, 5, 6);

  return ok;
}

const std::string_view
patt = "World";

constexpr std::string_view
greet = "Hello, Humongous World of Wonder!!!";

const std::wstring_view
wpatt = L"World";

constexpr std::wstring_view
wgreet = L"Hello, Humongous World of Wonder!!!";

constexpr bool
test_searcher()
{
  auto ok = true;

  const std::default_searcher search(patt.begin(), patt.end(),
				     std::equal_to<>());
  const auto find = search(greet.begin(), greet.end());

  const std::default_searcher wsearch(wpatt.begin(), wpatt.end(),
				      std::equal_to<>());
  const auto wfind = wsearch(wgreet.begin(), wgreet.end());

  return ok;
}


template<typename Tp>
  struct listoid
  {
    using value_type = Tp;
    using iterator = size_t;

    constexpr listoid() = default;

    constexpr void push_back(const value_type& value) { return; }
    constexpr void push_back(value_type&& value) { return; }
    constexpr void push_front(const value_type& value) { return; }
    constexpr void push_front(value_type&& value) { return; }
    constexpr iterator insert(iterator pos, const value_type& value) { return pos; }
    constexpr iterator begin() noexcept { return _M_begin; }
    constexpr iterator end() noexcept { return _M_end; }

  private:
    size_t _M_begin = 0;
    size_t _M_end = 0;
  };

constexpr bool
test_insert_iterators()
{
  listoid<int> l;

  auto ok = true;
  const int route = 66;

  constexpr std::array<int, 5> a{1, 2, 3, 4, 5};
  const auto liter = l.begin() + 1;
  const std::insert_iterator<listoid<int>> ii(l, liter);
  std::copy(a.begin(), a.end(), ii);
  auto nii = std::inserter(l, liter);
  nii = route;
  nii = 77;

  constexpr std::array<int, 2> b{89, 99};
  const std::back_insert_iterator<listoid<int>> bi(l);
  std::copy(b.begin(), b.end(), bi);
  auto nbi = std::back_inserter(l);
  nbi = route;
  nbi = 77;

  constexpr std::array<int, 2> f{-1, 0};
  const std::front_insert_iterator<listoid<int>> fi(l);
  std::copy(f.begin(), f.end(), fi);
  auto nfi = std::front_inserter(l);
  nfi = route;
  nfi = 77;

  return ok;
}

int
main()
{
  static_assert(test_array());
  static_assert(test_char_traits());
  static_assert(test_string_view());
  //static_assert(test_string());
  static_assert(test_pair());
  static_assert(test_tuple());
  static_assert(test_searcher());
  static_assert(test_insert_iterators());
}
