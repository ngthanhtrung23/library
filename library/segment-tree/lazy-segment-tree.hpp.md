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


# :warning: segment-tree/lazy-segment-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cf992883f659a62542b674f4570b728a">segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment-tree/lazy-segment-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

// LazySegmentTree
template <typename T, typename E, typename F, typename G, typename H>
struct LST {
  int n, height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  LST(int n, F f, G g, H h, T ti, E ei) : f(f), g(g), h(h), ti(ti), ei(ei) {
    init(n);
  }
  LST(const vector<T> &v, F f, G g, H h, T ti, E ei)
      : f(f), g(g), h(h), ti(ti), ei(ei) {
    init((int)v.size());
    build(v);
  }

  void init(int n_) {
    n = 1;
    height = 0;
    while (n < n_) n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }
  void build(const vector<T> &v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++) dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }
  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }
  inline void eval(int k) {
    if (laz[k] == ei) return;
    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }
  inline void thrust(int k) {
    for (int i = height; i; i--) eval(k >> i);
  }
  inline void recalc(int k) {
    while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }
  void update(int a, int b, E x) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }
  T query(int a, int b) {
    thrust(a += n);
    thrust(b += n - 1);
    T vl = ti, vr = ti;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, reflect(l++));
      if (r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "segment-tree/lazy-segment-tree.hpp"
#include <bits/stdc++.h>
using namespace std;

// LazySegmentTree
template <typename T, typename E, typename F, typename G, typename H>
struct LST {
  int n, height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  LST(int n, F f, G g, H h, T ti, E ei) : f(f), g(g), h(h), ti(ti), ei(ei) {
    init(n);
  }
  LST(const vector<T> &v, F f, G g, H h, T ti, E ei)
      : f(f), g(g), h(h), ti(ti), ei(ei) {
    init((int)v.size());
    build(v);
  }

  void init(int n_) {
    n = 1;
    height = 0;
    while (n < n_) n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }
  void build(const vector<T> &v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++) dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }
  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }
  inline void eval(int k) {
    if (laz[k] == ei) return;
    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }
  inline void thrust(int k) {
    for (int i = height; i; i--) eval(k >> i);
  }
  inline void recalc(int k) {
    while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }
  void update(int a, int b, E x) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }
  T query(int a, int b) {
    thrust(a += n);
    thrust(b += n - 1);
    T vl = ti, vr = ti;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, reflect(l++));
      if (r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
