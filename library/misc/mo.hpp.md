---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: misc/mo.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#bc957e26ff41470c556ee5d09e96880b">misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/misc/mo.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Mo {
  int width;
  vector< int > left, right, order;
  vector< bool > v;

  Mo(int N, int Q) : width((int) sqrt(N)), order(Q), v(N) {
    iota(begin(order), end(order), 0);
  }

  void insert(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  template<typename ADD,typename DEL,typename REM>
  void run(const ADD &add, const DEL &del, const REM &rem) {
    assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if(ablock != bblock) return ablock < bblock;
      if(ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    auto push = [&](int idx) {
      v[idx].flip();
      if(v[idx]) add(idx);
      else del(idx);
    };
    for(auto idx : order) {
      while(nl > left[idx]) push(--nl);
      while(nr < right[idx]) push(nr++);
      while(nl < left[idx]) push(nl++);
      while(nr > right[idx]) push(--nr);
      rem(idx);
    }
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "misc/mo.hpp"
#include <bits/stdc++.h>
using namespace std;

struct Mo {
  int width;
  vector< int > left, right, order;
  vector< bool > v;

  Mo(int N, int Q) : width((int) sqrt(N)), order(Q), v(N) {
    iota(begin(order), end(order), 0);
  }

  void insert(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  template<typename ADD,typename DEL,typename REM>
  void run(const ADD &add, const DEL &del, const REM &rem) {
    assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if(ablock != bblock) return ablock < bblock;
      if(ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    auto push = [&](int idx) {
      v[idx].flip();
      if(v[idx]) add(idx);
      else del(idx);
    };
    for(auto idx : order) {
      while(nl > left[idx]) push(--nl);
      while(nr < right[idx]) push(nr++);
      while(nl < left[idx]) push(nl++);
      while(nr > right[idx]) push(--nr);
      rem(idx);
    }
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
