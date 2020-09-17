---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"graph/cycle-detection.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"graph/graph-template.hpp\"\nusing namespace std;\n\
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
    \ d;\n}\n#line 5 \"graph/cycle-detection.hpp\"\n\ntemplate <typename G>\nvector<pair<int,\
    \ int>> CycleDetection(const G& g, bool directed = true) {\n  vector<int> pidx(g.size(),\
    \ -1), vis(g.size(), 0);\n\n  vector<pair<int, int>> cycle;\n  int finish = 0;\n\
    \  auto dfs = [&](auto rec, int cur, int pval, int par) -> int {\n    pidx[cur]\
    \ = pval;\n    vis[cur] = 1;\n    for (auto& dst : g[cur]) {\n      if (finish)\
    \ return -1;\n      if (!directed && dst == par) continue;\n      if (pidx[dst]\
    \ == pidx[cur]) {\n        cycle.emplace_back(cur, dst);\n        return dst;\n\
    \      }\n      if (vis[dst]) continue;\n      int nx = rec(rec, dst, pval, cur);\n\
    \      if (nx != -1) {\n        cycle.emplace_back(cur, dst);\n        if (cur\
    \ == nx) {\n          finish = 1;\n          return -1;\n        }\n        return\
    \ nx;\n      }\n    }\n    pidx[cur] = -1;\n    return -1;\n  };\n\n  for (int\
    \ i = 0; i < (int)g.size(); i++) {\n    if (vis[i]) continue;\n    dfs(dfs, i,\
    \ i, -1);\n\n    if (finish) {\n      reverse(begin(cycle), end(cycle));\n   \
    \   return cycle;\n    }\n  }\n  return vector<pair<int, int>>{};\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n#include \"\
    ./graph-template.hpp\"\n\ntemplate <typename G>\nvector<pair<int, int>> CycleDetection(const\
    \ G& g, bool directed = true) {\n  vector<int> pidx(g.size(), -1), vis(g.size(),\
    \ 0);\n\n  vector<pair<int, int>> cycle;\n  int finish = 0;\n  auto dfs = [&](auto\
    \ rec, int cur, int pval, int par) -> int {\n    pidx[cur] = pval;\n    vis[cur]\
    \ = 1;\n    for (auto& dst : g[cur]) {\n      if (finish) return -1;\n      if\
    \ (!directed && dst == par) continue;\n      if (pidx[dst] == pidx[cur]) {\n \
    \       cycle.emplace_back(cur, dst);\n        return dst;\n      }\n      if\
    \ (vis[dst]) continue;\n      int nx = rec(rec, dst, pval, cur);\n      if (nx\
    \ != -1) {\n        cycle.emplace_back(cur, dst);\n        if (cur == nx) {\n\
    \          finish = 1;\n          return -1;\n        }\n        return nx;\n\
    \      }\n    }\n    pidx[cur] = -1;\n    return -1;\n  };\n\n  for (int i = 0;\
    \ i < (int)g.size(); i++) {\n    if (vis[i]) continue;\n    dfs(dfs, i, i, -1);\n\
    \n    if (finish) {\n      reverse(begin(cycle), end(cycle));\n      return cycle;\n\
    \    }\n  }\n  return vector<pair<int, int>>{};\n}"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/cycle-detection.hpp
  requiredBy: []
  timestamp: '2020-08-15 17:28:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/cycle-detection.hpp
layout: document
redirect_from:
- /library/graph/cycle-detection.hpp
- /library/graph/cycle-detection.hpp.html
title: graph/cycle-detection.hpp
---