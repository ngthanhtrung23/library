---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: competitive-template.hpp
    title: competitive-template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/rerooting.hpp
    title: tree/rerooting.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
  bundledCode: "#line 1 \"verify/verify-aoj-grl/aoj-grl-5-b.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\n\
    \n#line 1 \"competitive-template.hpp\"\n#pragma region kyopro_template\n#define\
    \ Nyaan_template\n#include <immintrin.h>\n#include <bits/stdc++.h>\n#define pb\
    \ push_back\n#define eb emplace_back\n#define fi first\n#define se second\n#define\
    \ each(x, v) for (auto &x : v)\n#define all(v) (v).begin(), (v).end()\n#define\
    \ sz(v) ((int)(v).size())\n#define mem(a, val) memset(a, val, sizeof(a))\n#define\
    \ ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)  \
    \       \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...) \
    \     \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inc(...)    \\\n\
    \  char __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)                \
    \           \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i]);\
    \                         \\\n  }\n#define in3(s, t, u)                      \
    \  \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i]);\
    \                   \\\n  }\n#define in4(s, t, u, v)                     \\\n\
    \  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i], u[i], v[i]);\
    \             \\\n  }\n#define rep(i, N) for (long long i = 0; i < (long long)(N);\
    \ i++)\n#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)\n\
    #define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)\n#define repr1(i,\
    \ N) for (long long i = (N); (long long)(i) > 0; i--)\n#define reg(i, a, b) for\
    \ (long long i = (a); i < (b); i++)\n#define die(...)      \\\n  do {        \
    \        \\\n    out(__VA_ARGS__); \\\n    return;           \\\n  } while (0)\n\
    using namespace std;\nusing ll = long long;\ntemplate <class T>\nusing V = vector<T>;\n\
    using vi = vector<int>;\nusing vl = vector<long long>;\nusing vvi = vector<vector<int>>;\n\
    using vd = V<double>;\nusing vs = V<string>;\nusing vvl = vector<vector<long long>>;\n\
    using P = pair<long long, long long>;\nusing vp = vector<P>;\nusing pii = pair<int,\
    \ int>;\nusing vpi = vector<pair<int, int>>;\nconstexpr int inf = 1001001001;\n\
    constexpr long long infLL = (1LL << 61) - 1;\ntemplate <typename T, typename U>\n\
    inline bool amin(T &x, U y) {\n  return (y < x) ? (x = y, true) : false;\n}\n\
    template <typename T, typename U>\ninline bool amax(T &x, U y) {\n  return (x\
    \ < y) ? (x = y, true) : false;\n}\ntemplate <typename T, typename U>\nostream\
    \ &operator<<(ostream &os, const pair<T, U> &p) {\n  os << p.first << \" \" <<\
    \ p.second;\n  return os;\n}\ntemplate <typename T, typename U>\nistream &operator>>(istream\
    \ &is, pair<T, U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\ntemplate\
    \ <typename T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int\
    \ s = (int)v.size();\n  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") <<\
    \ v[i];\n  return os;\n}\ntemplate <typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n  for (auto &x : v) is >> x;\n  return is;\n}\nvoid in() {}\n\
    template <typename T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n\
    }\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U>\nvoid out(const\
    \ T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout << \" \";\n\
    \  out(u...);\n}\n\n#ifdef NyaanDebug\n#define trc(...)                   \\\n\
    \  do {                             \\\n    cerr << #__VA_ARGS__ << \" = \"; \\\
    \n    dbg_out(__VA_ARGS__);          \\\n  } while (0)\n#define trca(v, N)   \
    \    \\\n  do {                   \\\n    cerr << #v << \" = \"; \\\n    array_out(v,\
    \ N);     \\\n  } while (0)\n#define trcc(v)                             \\\n\
    \  do {                                      \\\n    cerr << #v << \" = {\"; \
    \                  \\\n    each(x, v) { cerr << \" \" << x << \",\"; } \\\n  \
    \  cerr << \"}\" << endl;                    \\\n  } while (0)\ntemplate <typename\
    \ T>\nvoid _cout(const T &c) {\n  cerr << c;\n}\nvoid _cout(const int &c) {\n\
    \  if (c == 1001001001)\n    cerr << \"inf\";\n  else if (c == -1001001001)\n\
    \    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned int\
    \ &c) {\n  if (c == 1001001001)\n    cerr << \"inf\";\n  else\n    cerr << c;\n\
    }\nvoid _cout(const long long &c) {\n  if (c == 1001001001 || c == (1LL << 61)\
    \ - 1)\n    cerr << \"inf\";\n  else if (c == -1001001001 || c == -((1LL << 61)\
    \ - 1))\n    cerr << \"-inf\";\n  else\n    cerr << c;\n}\nvoid _cout(const unsigned\
    \ long long &c) {\n  if (c == 1001001001 || c == (1LL << 61) - 1)\n    cerr <<\
    \ \"inf\";\n  else\n    cerr << c;\n}\ntemplate <typename T, typename U>\nvoid\
    \ _cout(const pair<T, U> &p) {\n  cerr << \"{ \";\n  _cout(p.fi);\n  cerr << \"\
    , \";\n  _cout(p.se);\n  cerr << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const\
    \ vector<T> &v) {\n  int s = v.size();\n  cerr << \"{ \";\n  for (int i = 0; i\
    \ < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n  }\n  cerr\
    \ << \" } \";\n}\ntemplate <typename T>\nvoid _cout(const vector<vector<T>> &v)\
    \ {\n  cerr << \"[ \";\n  for (const auto &x : v) {\n    cerr << endl;\n    _cout(x);\n\
    \    cerr << \", \";\n  }\n  cerr << endl << \" ] \";\n}\nvoid dbg_out() { cerr\
    \ << endl; }\ntemplate <typename T, class... U>\nvoid dbg_out(const T &t, const\
    \ U &... u) {\n  _cout(t);\n  if (sizeof...(u)) cerr << \", \";\n  dbg_out(u...);\n\
    }\ntemplate <typename T>\nvoid array_out(const T &v, int s) {\n  cerr << \"{ \"\
    ;\n  for (int i = 0; i < s; i++) {\n    cerr << (i ? \", \" : \"\");\n    _cout(v[i]);\n\
    \  }\n  cerr << \" } \" << endl;\n}\ntemplate <typename T>\nvoid array_out(const\
    \ T &v, int H, int W) {\n  cerr << \"[ \";\n  for (int i = 0; i < H; i++) {\n\
    \    cerr << (i ? \", \" : \"\");\n    array_out(v[i], W);\n  }\n  cerr << \"\
    \ ] \" << endl;\n}\n#else\n#define trc(...)\n#define trca(...)\n#define trcc(...)\n\
    #endif\n\ninline int popcnt(unsigned long long a) { return __builtin_popcountll(a);\
    \ }\ninline int lsb(unsigned long long a) { return __builtin_ctzll(a); }\ninline\
    \ int msb(unsigned long long a) { return 63 - __builtin_clzll(a); }\ntemplate\
    \ <typename T>\ninline int getbit(T a, int i) {\n  return (a >> i) & 1;\n}\ntemplate\
    \ <typename T>\ninline void setbit(T &a, int i) {\n  a |= (1LL << i);\n}\ntemplate\
    \ <typename T>\ninline void delbit(T &a, int i) {\n  a &= ~(1LL << i);\n}\ntemplate\
    \ <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\ntemplate\
    \ <typename T>\nint btw(T a, T x, T b) {\n  return a <= x && x < b;\n}\ntemplate\
    \ <typename T, typename U>\nT ceil(T a, U b) {\n  return (a + b - 1) / b;\n}\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  while (n) {\n\
    \    if (n & 1) ret *= x;\n    x *= x;\n    n >>= 1;\n  }\n  return ret;\n}\n\
    template <typename T>\nvector<T> mkrui(const vector<T> &v) {\n  vector<T> ret(v.size()\
    \ + 1);\n  for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n\
    \  return ret;\n};\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v)\
    \ {\n  vector<T> ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n  return ret;\n}\ntemplate <typename F>\nvector<int>\
    \ mkord(int N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n\
    \  sort(begin(ord), end(ord), f);\n  return ord;\n}\ntemplate <typename T = int>\n\
    vector<T> mkiota(int N) {\n  vector<T> ret(N);\n  iota(begin(ret), end(ret), 0);\n\
    \  return ret;\n}\ntemplate <typename T>\nvector<int> mkinv(vector<T> &v) {\n\
    \  vector<int> inv(v.size());\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]]\
    \ = i;\n  return inv;\n}\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  cerr << fixed << setprecision(7);\n  }\n} iosetupnya;\n\nvoid solve();\nint\
    \ main() { solve(); }\n\n#pragma endregion\n#line 3 \"tree/rerooting.hpp\"\nusing\
    \ namespace std;\n\n#line 3 \"graph/graph-template.hpp\"\nusing namespace std;\n\
    \ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int\
    \ to, T cost) : src(-1), to(to), cost(cost) {}\n  edge(int src, int to, T cost)\
    \ : src(src), to(to), cost(cost) {}\n\n  edge &operator=(const int &x) {\n   \
    \ to = x;\n    return *this;\n  }\n\n  operator int() const { return to; }\n};\n\
    template <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename T>\n\
    using WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\
    \n// Input of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool\
    \ is_directed = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n\
    \    if (!is_directed) g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of\
    \ Weighted Graph\ntemplate <typename T>\nWeightedGraph<T> wgraph(int N, int M\
    \ = -1, bool is_directed = false,\n                        bool is_1origin = true)\
    \ {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _\
    \ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n  \
    \  if (is_1origin) x--, y--;\n    g[x].eb(x, y, c);\n    if (!is_directed) g[y].eb(y,\
    \ x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate <typename T>\nEdges<T>\
    \ esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {\n  Edges<T>\
    \ es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n  \
    \  T c;\n    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if\
    \ (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n  }\n  return es;\n}\n\
    \n// Input of Adjacency Matrix\ntemplate <typename T>\nvector<vector<T>> adjgraph(int\
    \ N, int M, T INF, int is_weighted = true,\n                           bool is_directed\
    \ = false, bool is_1origin = true) {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n\
    \  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n\
    \    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if (is_1origin)\
    \ x--, y--;\n    d[x][y] = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return\
    \ d;\n}\n#line 6 \"tree/rerooting.hpp\"\n\n// Rerooting\n// f1(c1, c2) ... merge\
    \ value of child node\n// f2(memo[i], chd, par) ... return value from child node\
    \ to parent node\n// memo[i] ... result of subtree rooted i\n// dp[i] ... result\
    \ of tree rooted i\ntemplate <typename T, typename G, typename F1, typename F2>\n\
    struct Rerooting {\n  const G &g;\n  const F1 f1;\n  const F2 f2;\n  vector<T>\
    \ memo, dp;\n  T I;\n\n  Rerooting(const G &g, const F1 f1, const F2 f2, const\
    \ T &I)\n      : g(g), f1(f1), f2(f2), memo(g.size(), I), dp(g.size(), I), I(I)\
    \ {\n    dfs(0, -1);\n    efs(0, -1, I);\n  }\n\n  const T &operator[](int i)\
    \ const { return dp[i]; }\n\n  void dfs(int cur, int par) {\n    for (auto &dst\
    \ : g[cur]) {\n      if (dst == par) continue;\n      dfs(dst, cur);\n      memo[cur]\
    \ = f1(memo[cur], f2(memo[dst], dst, cur));\n    }\n  }\n\n  void efs(int cur,\
    \ int par, const T &pval) {\n    // get cumulative sum\n    vector<T> buf;\n \
    \   for (auto dst : g[cur]) {\n      if (dst == par) continue;\n      buf.push_back(f2(memo[dst],\
    \ dst, cur));\n    }\n    vector<T> head(buf.size() + 1), tail(buf.size() + 1);\n\
    \    head[0] = tail[buf.size()] = I;\n    for (int i = 0; i < (int)buf.size();\
    \ i++) head[i + 1] = f1(head[i], buf[i]);\n    for (int i = (int)buf.size() -\
    \ 1; i >= 0; i--)\n      tail[i] = f1(tail[i + 1], buf[i]);\n\n    // update\n\
    \    dp[cur] = par == -1 ? head.back() : f1(pval, head.back());\n\n    // propagate\n\
    \    int idx = 0;\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      efs(dst, cur, f2(f1(pval, f1(head[idx], tail[idx + 1])), cur, dst));\n\
    \      idx++;\n    }\n  }\n};\n\n/*\n\nusing T = ;\n// identify element of f1,\
    \ and answer of leaf\nT I = ;\n// merge value of child node\nauto f1 = [&](T x,\
    \ T y) -> T {\n\n};\n// return value from child node to parent node\nauto f2 =\
    \ [&](T x, int chd, int par) -> T {\n\n};\nRerooting<T, decltype(g), decltype(f1),\
    \ decltype(f2)> dp(g, f1, f2, I);\n\n*/\n#line 6 \"verify/verify-aoj-grl/aoj-grl-5-b.test.cpp\"\
    \n\nvoid solve() {\n  ini(N);\n  auto g = wgraph<int>(N, N - 1, false, false);\n\
    \  map<pair<int, int>, int> es;\n  rep(i, N) each(e, g[i]) es[{e.src, e.to}] =\
    \ e.cost;\n\n  using T = int;\n  // identify element of f1, and answer of leaf\n\
    \  T I = 0;\n  // merge value of child node\n  auto f1 = [&](T x, T y) -> T {\
    \ return max(x, y); };\n  // return value from child node to parent node\n  auto\
    \ f2 = [&](T x, int chd, int par) -> T { return x + es[{chd, par}]; };\n  Rerooting<T,\
    \ decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);\n\n  rep(i,N) out(dp.dp[i]);\n\
    }\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#include \"../../competitive-template.hpp\"\n#include \"../../tree/rerooting.hpp\"\
    \n\nvoid solve() {\n  ini(N);\n  auto g = wgraph<int>(N, N - 1, false, false);\n\
    \  map<pair<int, int>, int> es;\n  rep(i, N) each(e, g[i]) es[{e.src, e.to}] =\
    \ e.cost;\n\n  using T = int;\n  // identify element of f1, and answer of leaf\n\
    \  T I = 0;\n  // merge value of child node\n  auto f1 = [&](T x, T y) -> T {\
    \ return max(x, y); };\n  // return value from child node to parent node\n  auto\
    \ f2 = [&](T x, int chd, int par) -> T { return x + es[{chd, par}]; };\n  Rerooting<T,\
    \ decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);\n\n  rep(i,N) out(dp.dp[i]);\n\
    }"
  dependsOn:
  - competitive-template.hpp
  - tree/rerooting.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
  requiredBy: []
  timestamp: '2020-08-01 13:45:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
- /verify/verify/verify-aoj-grl/aoj-grl-5-b.test.cpp.html
title: verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
---