---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: Binary Indexed Tree(Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/static-graph.hpp
    title: Static Graph
  - icon: ':heavy_check_mark:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  - icon: ':heavy_check_mark:'
    path: tree/euler-tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n#include <deque>\n#include <exception>\n#include\
    \ <forward_list>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iosfwd>\n#include <iostream>\n#include\
    \ <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n#include\
    \ <locale>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <ratio>\n#include\
    \ <regex>\n#include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n\
    #include <streambuf>\n#include <string>\n#include <system_error>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <valarray>\n#include <vector>\n\
    \n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
    \ long;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\n\
    template <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\n\
    using vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\n\
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  T &x() { return first; }\n  const T &x() const { return\
    \ first; }\n  U &y() { return second; }\n  const U &y() const { return second;\
    \ }\n\n  P &operator+=(const P &r) {\n    first += r.first;\n    second += r.second;\n\
    \    return *this;\n  }\n  P &operator-=(const P &r) {\n    first -= r.first;\n\
    \    second -= r.second;\n    return *this;\n  }\n  P &operator*=(const P &r)\
    \ {\n    first *= r.first;\n    second *= r.second;\n    return *this;\n  }\n\
    \  P operator+(const P &r) const { return P(*this) += r; }\n  P operator-(const\
    \ P &r) const { return P(*this) -= r; }\n  P operator*(const P &r) const { return\
    \ P(*this) *= r; }\n};\n\nusing pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing\
    \ vp = V<pl>;\n\nconstexpr int inf = 1001001001;\nconstexpr long long infLL =\
    \ 4004004004004004004LL;\n\ntemplate <typename T>\nint sz(const T &t) {\n  return\
    \ t.size();\n}\ntemplate <typename T, size_t N>\nvoid mem(T (&a)[N], int c) {\n\
    \  memset(a, c, sizeof(T) * N);\n}\n\ntemplate <typename T, typename U>\ninline\
    \ bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate\
    \ <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x < y) ?\
    \ (x = y, true) : false;\n}\n\ntemplate <typename T>\nint lb(const vector<T> &v,\
    \ const T &a) {\n  return lower_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint ub(const vector<T> &v, const T &a) {\n  return upper_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\n\nconstexpr long long TEN(int n) {\n  long long ret\
    \ = 1, x = 10;\n  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return\
    \ ret;\n}\n\ntemplate <typename T, typename U>\npair<T, U> mkp(const T &t, const\
    \ U &u) {\n  return make_pair(t, u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const\
    \ vector<T> &v, bool rev = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev)\
    \ {\n    for (int i = int(v.size()) - 1; i >= 0; i--) ret[i] = v[i] + ret[i +\
    \ 1];\n  } else {\n    for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i]\
    \ + v[i];\n  }\n  return ret;\n};\n\ntemplate <typename T>\nvector<T> mkuni(const\
    \ vector<T> &v) {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\n\
    vector<T> reord(const vector<T> &v, const vector<T> &ord) {\n  int N = v.size();\n\
    \  vector<T> ret(N);\n  for (int i = 0; i < N; i++) ret[i] = v[ord[i]];\n  return\
    \ ret;\n};\n\ntemplate <typename T = int>\nvector<T> mkiota(int N) {\n  vector<T>\
    \ ret(N);\n  iota(begin(ret), end(ret), 0);\n  return ret;\n}\n\ntemplate <typename\
    \ T>\nvector<int> mkinv(vector<T> &v, int max_val = -1) {\n  if (max_val < (int)v.size())\
    \ max_val = v.size() - 1;\n  vector<int> inv(max_val + 1, -1);\n  for (int i =\
    \ 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return inv;\n}\n\n}  // namespace\
    \ Nyaan\n#line 70 \"template/template.hpp\"\n\n// bit operation\n#line 1 \"template/bitop.hpp\"\
    \nnamespace Nyaan {\n\n__attribute__((target(\"popcnt\"))) inline int popcnt(const\
    \ u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\n__attribute__((target(\"bmi\")))\
    \ inline int lsb(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n__attribute__((target(\"\
    bmi\"))) inline int ctz(const u64 &a) {\n  return _tzcnt_u64(a);\n}\n\n__attribute__((target(\"\
    lzcnt\"))) inline int msb(const u64 &a) {\n  return 63 - _lzcnt_u64(a);\n}\n__attribute__((target(\"\
    lzcnt\"))) inline int clz64(const u64 &a) {\n  return _lzcnt_u64(a);\n}\n\ntemplate\
    \ <typename T>\ninline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n\
    }\ntemplate <typename T>\ninline void sbit(T &a, int i, bool b) {\n  a ^= (gbit(a,\
    \ i) == b ? 0 : (T(b) << i));\n}\n\nconstexpr long long PW(int n) { return 1LL\
    \ << n; }\n\nconstexpr long long MSK(int n) { return (1LL << n) - 1; }\n\n}  //\
    \ namespace Nyaan\n#line 73 \"template/template.hpp\"\n\n// inout\n#line 1 \"\
    template/inout.hpp\"\nnamespace Nyaan {\n\ntemplate <typename T, typename U>\n\
    ostream &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \"\
    \ \" << p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream\
    \ &operator>>(istream &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return\
    \ is;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T>\
    \ &v) {\n  int s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \"\
    \ \" : \"\") << v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream\
    \ &is, vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid\
    \ in() {}\ntemplate <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin\
    \ >> t;\n  in(u...);\n}\n\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T &t, const U &... u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n\nvoid outr() {}\n\
    template <typename T, class... U, char sep = ' '>\nvoid outr(const T &t, const\
    \ U &... u) {\n  cout << t;\n  outr(u...);\n}\n\nstruct IoSetupNya {\n  IoSetupNya()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(15);\n    cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\
    \n}  // namespace Nyaan\n#line 76 \"template/template.hpp\"\n\n// debug\n#line\
    \ 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate <typename U, typename\
    \ = void>\nstruct is_specialize : false_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, typename U::iterator, void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<\n    U, typename\
    \ conditional<false, decltype(U::first), void>::type>\n    : true_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value, void>>\
    \ : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid dump(const\
    \ string& t) { cerr << t; }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if (is_signed<T>::value)\n\
    \    if (t == -Nyaan::inf) res = \"-inf\";\n  if (sizeof(T) == 8) {\n    if (t\
    \ == Nyaan::infLL) res = \"inf\";\n    if (is_signed<T>::value)\n      if (t ==\
    \ -Nyaan::infLL) res = \"-inf\";\n  }\n  if (res.empty()) res = to_string(t);\n\
    \  cerr << res;\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>&);\ntemplate <typename T>\nvoid dump(const pair<T*, int>&);\n\ntemplate <typename\
    \ T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename T::iterator>::value>*\
    \ = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin(); it != t.end();)\
    \ {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \", \");\n  }\n  cerr\
    \ << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const pair<T,\
    \ U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n  dump(t.second);\n\
    \  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const pair<T*, int>&\
    \ t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++) {\n    dump(t.first[i]);\n\
    \    cerr << (i == t.second - 1 ? \"\" : \", \");\n  }\n  cerr << \" ]\";\n}\n\
    \nvoid trace() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void trace(Head&& head, Tail&&... tail) {\n  cerr << \" \";\n  dump(head);\n \
    \ if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...)\n#endif\n#line 79 \"template/template.hpp\"\
    \n\n// macro\n#line 1 \"template/macro.hpp\"\n#define each(x, v) for (auto&& x\
    \ : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n#define all(v) (v).begin(),\
    \ (v).end()\n#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)\n\
    #define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n#define\
    \ rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define regr(i, a, b) for (long long i =\
    \ (b)-1; i >= (a); i--)\n#define repc(i, a, cond) for (long long i = (a); (cond);\
    \ i++)\n#define enm(i, val, vec)                                  \\\n  for (long\
    \ long i = 0; i < (long long)(vec).size(); i++) \\\n    if (auto& val = vec[i];\
    \ false)                        \\\n      ;                                  \
    \                 \\\n    else\n\n#define ini(...)   \\\n  int __VA_ARGS__; \\\
    \n  in(__VA_ARGS__)\n#define inl(...)         \\\n  long long __VA_ARGS__; \\\n\
    \  in(__VA_ARGS__)\n#define ins(...)      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n\
    #define inc(...)    \\\n  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s,\
    \ t)                           \\\n  for (int i = 0; i < (int)s.size(); i++) {\
    \ \\\n    in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)\
    \                        \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n\
    \    in(s[i], t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)\
    \                     \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n   \
    \ in(s[i], t[i], u[i], v[i]);             \\\n  }\n\n#define die(...)        \
    \     \\\n  do {                       \\\n    Nyaan::out(__VA_ARGS__); \\\n \
    \   return;                  \\\n  } while (0)\n#line 82 \"template/template.hpp\"\
    \n\nnamespace Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line\
    \ 2 \"data-structure/binary-indexed-tree.hpp\"\n\ntemplate <typename T>\nstruct\
    \ BinaryIndexedTree {\n  int N;\n  vector<T> data;\n\n  BinaryIndexedTree() =\
    \ default;\n\n  BinaryIndexedTree(int size) { init(size); }\n\n  void init(int\
    \ size) {\n    N = size + 2;\n    data.assign(N + 1, 0);\n  }\n\n  // get sum\
    \ of [0,k]\n  T sum(int k) const {\n    if (k < 0) return 0;  // return 0 if k\
    \ < 0\n    T ret = 0;\n    for (++k; k > 0; k -= k & -k) ret += data[k];\n   \
    \ return ret;\n  }\n\n  // getsum of [l,r]\n  inline T sum(int l, int r) const\
    \ { return sum(r) - sum(l - 1); }\n\n  // get value of k\n  inline T operator[](int\
    \ k) const { return sum(k) - sum(k - 1); }\n\n  // data[k] += x\n  void add(int\
    \ k, T x) {\n    for (++k; k < N; k += k & -k) data[k] += x;\n  }\n\n  // range\
    \ add x to [l,r]\n  void imos(int l, int r, T x) {\n    add(l, x);\n    add(r\
    \ + 1, -x);\n  }\n\n  // minimize i s.t. sum(i) >= w\n  int lower_bound(T w) {\n\
    \    if (w <= 0) return 0;\n    int x = 0;\n    for (int k = 1 << __lg(N); k;\
    \ k >>= 1) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n        w -= data[x\
    \ + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n\n  // minimize\
    \ i s.t. sum(i) > w\n  int upper_bound(T w) {\n    if (w < 0) return 0;\n    int\
    \ x = 0;\n    for (int k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <= N -\
    \ 1 && data[x + k] <= w) {\n        w -= data[x + k];\n        x += k;\n     \
    \ }\n    }\n    return x;\n  }\n};\n\n/**\n * @brief Binary Indexed Tree(Fenwick\
    \ Tree)\n * @docs docs/data-structure/binary-indexed-tree.md\n */\n#line 2 \"\
    graph/static-graph.hpp\"\n\nnamespace StaticGraphImpl {\n\ntemplate <typename\
    \ T, bool Cond = is_void<T>::value>\nstruct E;\ntemplate <typename T>\nstruct\
    \ E<T, false> {\n  int to;\n  T cost;\n  E() {}\n  E(const int& v, const T& c)\
    \ : to(v), cost(c) {}\n  operator int() const { return to; }\n};\ntemplate <typename\
    \ T>\nstruct E<T, true> {\n  int to;\n  E() {}\n  E(const int& v) : to(v) {}\n\
    \  operator int() const { return to; }\n};\n\ntemplate <typename T = void>\nstruct\
    \ StaticGraph {\n private:\n  template <typename It>\n  struct Es {\n    It b,\
    \ e;\n    It begin() const { return b; }\n    It end() const { return e; }\n \
    \   int size() const { return int(e - b); }\n    auto&& operator[](int i) const\
    \ { return b[i]; }\n  };\n  \n  int N, M, ec;\n  vector<int> head;\n  vector<pair<int,\
    \ E<T>>> buf;\n  vector<E<T>> es;\n\n  void build() {\n    partial_sum(begin(head),\
    \ end(head), begin(head));\n    es.resize(M);\n    for (auto&& [u, e] : buf) es[--head[u]]\
    \ = e;\n  }\n\n public:\n  StaticGraph(int _n, int _m) : N(_n), M(_m), ec(0),\
    \ head(N + 1, 0) {\n    buf.reserve(M);\n  }\n\n  template <typename... Args>\n\
    \  void add_edge(int u, Args&&... args) {\n#pragma GCC diagnostic ignored \"-Wnarrowing\"\
    \n    buf.emplace_back(u, E<T>{std::forward<Args>(args)...});\n#pragma GCC diagnostic\
    \ warning \"-Wnarrowing\"\n    ++head[u];\n    if ((int)buf.size() == M) build();\n\
    \  }\n\n  Es<typename vector<E<T>>::iterator> operator[](int u) {\n    return\
    \ {begin(es) + head[u], begin(es) + head[u + 1]};\n  }\n  const Es<typename vector<E<T>>::const_iterator>\
    \ operator[](int u) const {\n    return {begin(es) + head[u], begin(es) + head[u\
    \ + 1]};\n  }\n  int size() const { return N; }\n};\n\n}  // namespace StaticGraphImpl\n\
    \nusing StaticGraphImpl::StaticGraph;\n\n/**\n * @brief Static Graph\n * @docs\
    \ docs/graph/static-graph.md\n */\n#line 2 \"misc/fastio.hpp\"\n\n\n\nnamespace\
    \ fastio {\nstatic constexpr int SZ = 1 << 17;\nchar ibuf[SZ], obuf[SZ];\nint\
    \ pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr\
    \ Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int n = i;\n \
    \     for (int j = 3; j >= 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n\
    \        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void load()\
    \ {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n  pir = pir - pil + fread(ibuf +\
    \ pir - pil, 1, SZ - pir + pil, stdin);\n  pil = 0;\n}\ninline void flush() {\n\
    \  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\ninline void rd(char& c) { c\
    \ = ibuf[pil++]; }\ntemplate <typename T>\ninline void rd(T& x) {\n  if (pil +\
    \ 32 > pir) load();\n  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n\
    \  bool minus = 0;\n  if (c == '-') {\n    minus = 1;\n    c = ibuf[pil++];\n\
    \  }\n  x = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n\
    \  }\n  if (minus) x = -x;\n}\ninline void rd() {}\ntemplate <typename Head, typename...\
    \ Tail>\ninline void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n\
    }\n\ninline void wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline\
    \ void wt(T x) {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++]\
    \ = '0';\n    return;\n  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n\
    \  }\n  int i = 12;\n  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf +\
    \ i, pre.num + (x % 10000) * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x\
    \ < 100) {\n    if (x < 10) {\n      wt(char('0' + char(x)));\n    } else {\n\
    \      uint32_t q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x)\
    \ - q * 10;\n      obuf[por + 0] = '0' + q;\n      obuf[por + 1] = '0' + r;\n\
    \      por += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf +\
    \ por, pre.num + (x << 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf\
    \ + por, pre.num + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf +\
    \ por, buf + i + 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate\
    \ <typename Head, typename... Tail>\ninline void wt(Head head, Tail... tail) {\n\
    \  wt(head);\n  wt(tail...);\n}\ntemplate <typename T>\ninline void wtn(T x) {\n\
    \  wt(x, '\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\
    \n}  // namespace fastio\nusing fastio::rd;\nusing fastio::wt;\nusing fastio::wtn;\n\
    #line 2 \"misc/rng.hpp\"\n\n\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t\
    \ rng() {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                   chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ <<\
    \ 7;\n  return x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t\
    \ r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<int64_t> randset(int64_t l, int64_t\
    \ r, int64_t n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n\
    \  for (int64_t i = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n   \
    \ if (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t>\
    \ ret;\n  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\n\
    double rnd() {\n  union raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr\
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n\
    #line 2 \"tree/euler-tour.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\n\n\
    template <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int\
    \ _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src, int _to,\
    \ T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const int\
    \ &x) {\n    to = x;\n    return *this;\n  }\n\n  operator int() const { return\
    \ to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename\
    \ T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\
    \n// Input of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool\
    \ is_directed = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n\
    \    if (!is_directed) g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of\
    \ Weighted Graph\ntemplate <typename T>\nWeightedGraph<T> wgraph(int N, int M\
    \ = -1, bool is_directed = false,\n                        bool is_1origin = true)\
    \ {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _\
    \ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n  \
    \  if (is_1origin) x--, y--;\n    g[x].emplace_back(x, y, c);\n    if (!is_directed)\
    \ g[y].emplace_back(y, x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate\
    \ <typename T>\nEdges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin\
    \ = true) {\n  Edges<T> es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n\
    \    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin >> c;\n    else\n\
    \      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n\
    \  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename T>\n\
    vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n    \
    \                       bool is_directed = false, bool is_1origin = true) {\n\
    \  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++) {\n\
    \    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin\
    \ >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y] =\
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n#line 6 \"tree/euler-tour.hpp\"\
    \n\ntemplate <typename G>\nstruct EulerTour {\n private:\n  struct RMQ {\n   \
    \ int n, s;\n    using P = pair<int, int>;\n    vector<P> seg;\n    P UNIT = P(1\
    \ << 30, -1);\n\n    RMQ(int N) : n(N), s(1) {\n      while (s < N) s <<= 1;\n\
    \      seg.assign(2 * s, UNIT);\n    }\n\n    void set(int k, P x) { seg[k + s]\
    \ = x; }\n\n    P operator[](int k) const { return seg[k + s]; }\n\n    void build()\
    \ {\n      for (int k = s - 1; k > 0; k--) {\n        seg[k] = min(seg[2 * k],\
    \ seg[2 * k + 1]);\n      }\n    }\n\n    P query(int a, int b) const {\n    \
    \  P R = UNIT;\n      for (a += s, b += s; a < b; a >>= 1, b >>= 1) {\n      \
    \  if (a & 1) R = min(R, seg[a++]);\n        if (b & 1) R = min(R, seg[--b]);\n\
    \      }\n      return R;\n    }\n\n    int size() const { return n; }\n  };\n\
    \n  vector<int> down, up;\n  int id;\n  RMQ rmq;\n\n  void init(G &g, int root)\
    \ {\n    dfs(g, root, -1, 0);\n    if (id < rmq.size()) rmq.set(id++, {-1, -1});\n\
    \    for (int i = 0; i < (int)g.size(); i++) {\n      if (down[i] == -1) {\n \
    \       rmq.set(id++, {-1, -1});\n        dfs(g, i, -1, 0);\n        if (id <\
    \ rmq.size()) rmq.set(id++, {-1, -1});\n      }\n    }\n    rmq.build();\n  }\n\
    \n  void dfs(G &g, int c, int p, int dp) {\n    down[c] = id;\n    rmq.set(id++,\
    \ {dp, c});\n    for (auto &d : g[c]) {\n      if (d == p) continue;\n      dfs(g,\
    \ d, c, dp + 1);\n    }\n    up[c] = id;\n    if (p != -1) rmq.set(id++, {dp -\
    \ 1, p});\n  }\n\n public:\n  // remind : because of additional node,\n  // DS\
    \ on tour should reserve 2 * n nodes.\n  EulerTour(G &g, int root = 0)\n     \
    \ : down(g.size(), -1), up(g.size(), -1), id(0), rmq(2 * g.size()) {\n    init(g,\
    \ root);\n  }\n\n  pair<int, int> idx(int i) const { return {down[i], up[i]};\
    \ }\n\n  int lca(int a, int b) const {\n    if (down[a] > down[b]) swap(a, b);\n\
    \    return rmq.query(down[a], down[b] + 1).second;\n  }\n\n  template <typename\
    \ F>\n  void node_query(int a, int b, const F &f) {\n    int l = lca(a, b);\n\
    \    f(down[l], down[a] + 1);\n    f(down[l] + 1, down[b] + 1);\n  }\n\n  template\
    \ <typename F>\n  void edge_query(int a, int b, const F &f) {\n    int l = lca(a,\
    \ b);\n    f(down[l] + 1, down[a] + 1);\n    f(down[l] + 1, down[b] + 1);\n  }\n\
    \n  template <typename F>\n  void subtree_query(int a, const F &f) {\n    f(down[a],\
    \ up[a]);\n  }\n\n  int size() const { return int(rmq.size()); }\n};\n\n/**\n\
    \ * @brief \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n * @docs docs/tree/euler-tour.md\n\
    \ */\n#line 9 \"verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp\"\
    \n\nusing namespace Nyaan; void Nyaan::solve() {\n  int N, Q;\n  rd(N, Q);\n \
    \ vector<int> a(N);\n  rep(i, N) rd(a[i]);\n\n  StaticGraph<void> g(N, 2 * N -\
    \ 2);\n  rep(i, N - 1) {\n    int u, v;\n    rd(u, v);\n    g.add_edge(u, v);\n\
    \    g.add_edge(v, u);\n  }\n\n  EulerTour<decltype(g)> et(g, randint(0, N));\n\
    \  BinaryIndexedTree<ll> bit(et.size());\n\n  rep(i, N) {\n    auto&& [d, u] =\
    \ et.idx(i);\n    bit.add(d, a[i]);\n    bit.add(u, -a[i]);\n  }\n  rep(i, Q)\
    \ {\n    int c, x, y;\n    rd(c, x, y);\n    if (c == 0) {\n      auto&& [d, u]\
    \ = et.idx(x);\n      bit.add(d, y);\n      bit.add(u, -y);\n    } else {\n  \
    \    ll ans = 0;\n      auto f = [&](int u, int v) { ans += bit.sum(u, v - 1);\
    \ };\n      et.node_query(x, y, f);\n      wtn(ans);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../data-structure/binary-indexed-tree.hpp\"\
    \n#include \"../../graph/static-graph.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n#include \"../../misc/rng.hpp\"\n#include \"../../tree/euler-tour.hpp\"\n\n\
    using namespace Nyaan; void Nyaan::solve() {\n  int N, Q;\n  rd(N, Q);\n  vector<int>\
    \ a(N);\n  rep(i, N) rd(a[i]);\n\n  StaticGraph<void> g(N, 2 * N - 2);\n  rep(i,\
    \ N - 1) {\n    int u, v;\n    rd(u, v);\n    g.add_edge(u, v);\n    g.add_edge(v,\
    \ u);\n  }\n\n  EulerTour<decltype(g)> et(g, randint(0, N));\n  BinaryIndexedTree<ll>\
    \ bit(et.size());\n\n  rep(i, N) {\n    auto&& [d, u] = et.idx(i);\n    bit.add(d,\
    \ a[i]);\n    bit.add(u, -a[i]);\n  }\n  rep(i, Q) {\n    int c, x, y;\n    rd(c,\
    \ x, y);\n    if (c == 0) {\n      auto&& [d, u] = et.idx(x);\n      bit.add(d,\
    \ y);\n      bit.add(u, -y);\n    } else {\n      ll ans = 0;\n      auto f =\
    \ [&](int u, int v) { ans += bit.sum(u, v - 1); };\n      et.node_query(x, y,\
    \ f);\n      wtn(ans);\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - data-structure/binary-indexed-tree.hpp
  - graph/static-graph.hpp
  - misc/fastio.hpp
  - misc/rng.hpp
  - tree/euler-tour.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
  requiredBy: []
  timestamp: '2020-12-05 13:58:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
---