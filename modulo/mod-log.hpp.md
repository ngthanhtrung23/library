---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/elementary-function.hpp
    title: math/elementary-function.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-log.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"modulo/mod-log.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"math/elementary-function.hpp\"\nusing namespace std;\n\nlong\
    \ long my_gcd(long long x, long long y) {\n  long long z;\n  if (x > y) swap(x,\
    \ y);\n  while (x) {\n    x = y % (z = x);\n    y = z;\n  }\n  return y;\n}\n\
    long long my_lcm(long long x, long long y) {\n  return 1LL * x / my_gcd(x, y)\
    \ * y;\n}\n#define gcd my_gcd\n#define lcm my_lcm\n\n// totient function \u03C6\
    (N)=(1 ~ N , gcd(i,N) = 1)\n// {0, 1, 1, 2, 4, 2, 6, 4, ... }\nvector<int> EulersTotientFunction(int\
    \ N) {\n  vector<int> ret(N + 1, 0);\n  for (int i = 0; i <= N; i++) ret[i] =\
    \ i;\n  for (int i = 2; i <= N; i++) {\n    if (ret[i] == i)\n      for (int j\
    \ = i; j <= N; j += i) ret[j] = ret[j] / i * (i - 1);\n  }\n  return ret;\n}\n\
    \n// Divisor ex) 12 -> {1, 2, 3, 4, 6, 12}\nvector<long long> Divisor(long long\
    \ N) {\n  vector<long long> v;\n  for (long long i = 1; i * i <= N; i++) {\n \
    \   if (N % i == 0) {\n      v.push_back(i);\n      if (i * i != N) v.push_back(N\
    \ / i);\n    }\n  }\n  return v;\n}\n\n// Factorization\n// ex) 18 -> { (2,1)\
    \ , (3,2) }\nvector<pair<long long, int> > PrimeFactors(long long N) {\n  vector<pair<long\
    \ long, int> > ret;\n  for (long long p = 2; p * p <= N; p++)\n    if (N % p ==\
    \ 0) {\n      ret.emplace_back(p, 0);\n      while (N % p == 0) N /= p, ret.back().second++;\n\
    \    }\n  if (N >= 2) ret.emplace_back(N, 1);\n  return ret;\n}\n\n// Factorization\
    \ with Prime Sieve\n// ex) 18 -> { (2,1) , (3,2) }\nvector<pair<long long, int>\
    \ > PrimeFactors(long long N,\n                                           const\
    \ vector<long long> &prime) {\n  vector<pair<long long, int> > ret;\n  for (auto\
    \ &p : prime) {\n    if (p * p > N) break;\n    if (N % p == 0) {\n      ret.emplace_back(p,\
    \ 0);\n      while (N % p == 0) N /= p, ret.back().second++;\n    }\n  }\n  if\
    \ (N >= 2) ret.emplace_back(N, 1);\n  return ret;\n}\n\n// modpow for mod < 2\
    \ ^ 31\nlong long modpow(long long a, long long n, long long mod) {\n  a %= mod;\n\
    \  long long ret = 1;\n  while (n > 0) {\n    if (n & 1) ret = ret * a % mod;\n\
    \    a = a * a % mod;\n    n >>= 1;\n  }\n  return ret % mod;\n};\n\n// Check\
    \ if r is Primitive Root\nbool isPrimitiveRoot(long long r, long long mod) {\n\
    \  r %= mod;\n  if (r == 0) return false;\n  auto pf = PrimeFactors(mod - 1);\n\
    \  for (auto &x : pf) {\n    if (modpow(r, (mod - 1) / x.first, mod) == 1) return\
    \ false;\n  }\n  return true;\n}\n\n// Get Primitive Root\nlong long PrimitiveRoot(long\
    \ long mod) {\n  long long ret = 1;\n  while (isPrimitiveRoot(ret, mod) == false)\
    \ ret++;\n  return ret;\n}\n\n// Euler's phi function\nlong long phi(long long\
    \ n) {\n  auto pf = PrimeFactors(n);\n  long long ret = n;\n  for (auto p : pf)\
    \ {\n    ret /= p.first;\n    ret *= (p.first - 1);\n  }\n  return ret;\n}\n\n\
    // Extended Euclidean algorithm\n// solve : ax + by = gcd(a, b)\n// return : pair(x,\
    \ y)\npair<long long, long long> extgcd(long long a, long long b) {\n  if (b ==\
    \ 0) return make_pair(1, 0);\n  long long x, y;\n  tie(y, x) = extgcd(b, a % b);\n\
    \  y -= a / b * x;\n  return make_pair(x, y);\n}\n\n// Check if n is Square Number\n\
    // true : return d s.t. d * d == n\n// false : return -1\nlong long SqrtInt(long\
    \ long n) {\n  if (n == 0 || n == 1) return n;\n  long long d = (long long)sqrt(n)\
    \ - 1;\n  while (d * d < n) ++d;\n  return (d * d == n) ? d : -1;\n}\n\n// return\
    \ a number of n's digit\n// zero ... return value if n = 0 (default -> 1)\nint\
    \ isDigit(long long n, int zero = 1) {\n  if (n == 0) return zero;\n  int ret\
    \ = 0;\n  while (n) {\n    n /= 10;\n    ret++;\n  }\n  return ret;\n}\n#line\
    \ 6 \"modulo/mod-log.hpp\"\n\nint64_t mod_log(int64_t a, int64_t b, int64_t p)\
    \ {\n  if ((a %= p) < 0) a += p;\n  if ((b %= p) < 0) b += p;\n  int64_t f, g,\
    \ r = 1 % p;\n  for (f = 0; (g = __gcd(a, p)) > 1; ++f) {\n    if (b % g) return\
    \ (r == b) ? f : -1;\n    b /= g;\n    p /= g;\n    (r *= (a / g)) %= p;\n  }\n\
    \  if (p == 1) return f;\n  auto ir = extgcd(r, p);\n  (b *= (ir.first + p)) %=\
    \ p;\n  int64_t k = 0, ak = 1;\n  unordered_map<int64_t, int64_t> baby;\n  for\
    \ (; k * k < p; ++k) {\n    if (!baby.count(ak)) baby[ak] = k;\n    (ak *= a)\
    \ %= p;\n  }\n  auto iak = extgcd(ak, p);\n  if(iak.first < 0) iak.first += p;\n\
    \  for (int64_t i = 0; i < k; ++i) {\n    if (baby.count(b)) return f + i * k\
    \ + baby[b];\n    (b *= iak.first) %= p;\n  }\n  return -1;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../math/elementary-function.hpp\"\n\nint64_t mod_log(int64_t a, int64_t b,\
    \ int64_t p) {\n  if ((a %= p) < 0) a += p;\n  if ((b %= p) < 0) b += p;\n  int64_t\
    \ f, g, r = 1 % p;\n  for (f = 0; (g = __gcd(a, p)) > 1; ++f) {\n    if (b % g)\
    \ return (r == b) ? f : -1;\n    b /= g;\n    p /= g;\n    (r *= (a / g)) %= p;\n\
    \  }\n  if (p == 1) return f;\n  auto ir = extgcd(r, p);\n  (b *= (ir.first +\
    \ p)) %= p;\n  int64_t k = 0, ak = 1;\n  unordered_map<int64_t, int64_t> baby;\n\
    \  for (; k * k < p; ++k) {\n    if (!baby.count(ak)) baby[ak] = k;\n    (ak *=\
    \ a) %= p;\n  }\n  auto iak = extgcd(ak, p);\n  if(iak.first < 0) iak.first +=\
    \ p;\n  for (int64_t i = 0; i < k; ++i) {\n    if (baby.count(b)) return f + i\
    \ * k + baby[b];\n    (b *= iak.first) %= p;\n  }\n  return -1;\n}"
  dependsOn:
  - math/elementary-function.hpp
  isVerificationFile: false
  path: modulo/mod-log.hpp
  requiredBy: []
  timestamp: '2020-09-18 02:08:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-mod-log.test.cpp
documentation_of: modulo/mod-log.hpp
layout: document
redirect_from:
- /library/modulo/mod-log.hpp
- /library/modulo/mod-log.hpp.html
title: modulo/mod-log.hpp
---