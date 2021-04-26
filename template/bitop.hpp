namespace Nyaan {
__attribute__((target("popcnt"))) inline int popcnt(const u64 &a) {
  return _mm_popcnt_u64(a);
}
inline int lsb(const u64 &a) {
  return a ? __builtin_ctzll(a) : 64;
}
inline int ctz(const u64 &a) {
  return a ? __builtin_ctzll(a) : 64;
}
inline int msb(const u64 &a) {
  return a ? 63 - __builtin_clzll(a) : -1;
}
template <typename T>
inline int gbit(const T &a, int i) {
  return (a >> i) & 1;
}
template <typename T>
inline void sbit(T &a, int i, bool b) {
  a ^= (gbit(a, i) == b ? 0 : (T(b) << i));
}
constexpr long long PW(int n) { return 1LL << n; }
constexpr long long MSK(int n) { return (1LL << n) - 1; }
}  // namespace Nyaan
