#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
  return os << "(" << a.first << ", " << a.second << ")";
};
template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cerr << *i << " ";
  cerr << endl;
}
template <class T>
bool chmin(T &t, const T &f) {
  if (t > f) {
    t = f;
    return true;
  }
  return false;
}
template <class T>
bool chmax(T &t, const T &f) {
  if (t < f) {
    t = f;
    return true;
  }
  return false;
}
template <unsigned M_>
struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_)
      : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {
  }
  constexpr ModInt(long long x_)
      : x(((x_ %= static_cast<long long>(M)) < 0)
              ? (x_ + static_cast<long long>(M))
              : x_) {}
  ModInt &operator+=(const ModInt &a) {
    x = ((x += a.x) >= M) ? (x - M) : x;
    return *this;
  }
  ModInt &operator-=(const ModInt &a) {
    x = ((x -= a.x) >= M) ? (x + M) : x;
    return *this;
  }
  ModInt &operator*=(const ModInt &a) {
    x = (static_cast<unsigned long long>(x) * a.x) % M;
    return *this;
  }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U;
    for (; e; e >>= 1) {
      if (e & 1) b *= a;
      a *= a;
    }
    return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x;
    int y = 0, z = 1;
    for (; b;) {
      const unsigned q = a / b;
      const unsigned c = a - q * b;
      a = b;
      b = c;
      const int w = y - static_cast<int>(q) * z;
      y = z;
      z = w;
    }
    assert(a == 1U);
    return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const {
    ModInt a;
    a.x = x ? (M - x) : 0U;
    return a;
  }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T>
  friend ModInt operator+(T a, const ModInt &b) {
    return (ModInt(a) += b);
  }
  template <class T>
  friend ModInt operator-(T a, const ModInt &b) {
    return (ModInt(a) -= b);
  }
  template <class T>
  friend ModInt operator*(T a, const ModInt &b) {
    return (ModInt(a) *= b);
  }
  template <class T>
  friend ModInt operator/(T a, const ModInt &b) {
    return (ModInt(a) /= b);
  }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) {
    return os << a.x;
  }
};
constexpr unsigned MO = 998244353U;
constexpr unsigned MO2 = 2U * MO;
constexpr int FFT_MAX = 23;
using Mint = ModInt<MO>;
constexpr Mint FFT_ROOTS[FFT_MAX + 1] = {
    1U,         998244352U, 911660635U, 372528824U, 929031873U, 452798380U,
    922799308U, 781712469U, 476477967U, 166035806U, 258648936U, 584193783U,
    63912897U,  350007156U, 666702199U, 968855178U, 629671588U, 24514907U,
    996173970U, 363395222U, 565042129U, 733596141U, 267099868U, 15311432U};
constexpr Mint INV_FFT_ROOTS[FFT_MAX + 1] = {
    1U,         998244352U, 86583718U,  509520358U, 337190230U, 87557064U,
    609441965U, 135236158U, 304459705U, 685443576U, 381598368U, 335559352U,
    129292727U, 358024708U, 814576206U, 708402881U, 283043518U, 3707709U,
    121392023U, 704923114U, 950391366U, 428961804U, 382752275U, 469870224U};
constexpr Mint FFT_RATIOS[FFT_MAX] = {
    911660635U, 509520358U, 369330050U, 332049552U, 983190778U, 123842337U,
    238493703U, 975955924U, 603855026U, 856644456U, 131300601U, 842657263U,
    730768835U, 942482514U, 806263778U, 151565301U, 510815449U, 503497456U,
    743006876U, 741047443U, 56250497U,  867605899U};
constexpr Mint INV_FFT_RATIOS[FFT_MAX] = {
    86583718U,  372528824U, 373294451U, 645684063U, 112220581U, 692852209U,
    155456985U, 797128860U, 90816748U,  860285882U, 927414960U, 354738543U,
    109331171U, 293255632U, 535113200U, 308540755U, 121186627U, 608385704U,
    438932459U, 359477183U, 824071951U, 103369235U};
void fft(Mint *as, int n) {
  assert(!(n & (n - 1)));
  assert(1 <= n);
  assert(n <= 1 << FFT_MAX);
  int m = n;
  if (m >>= 1) {
    for (int i = 0; i < m; ++i) {
      const unsigned x = as[i + m].x;
      as[i + m].x = as[i].x + MO - x;
      as[i].x += x;
    }
  }
  if (m >>= 1) {
    Mint prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + m; ++i) {
        const unsigned x = (prod * as[i + m]).x;
        as[i + m].x = as[i].x + MO - x;
        as[i].x += x;
      }
      prod *= FFT_RATIOS[__builtin_ctz(++h)];
    }
  }
  for (; m;) {
    if (m >>= 1) {
      Mint prod = 1U;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const unsigned x = (prod * as[i + m]).x;
          as[i + m].x = as[i].x + MO - x;
          as[i].x += x;
        }
        prod *= FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
    if (m >>= 1) {
      Mint prod = 1U;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const unsigned x = (prod * as[i + m]).x;
          as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;
          as[i + m].x = as[i].x + MO - x;
          as[i].x += x;
        }
        prod *= FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;
    as[i].x = (as[i].x >= MO) ? (as[i].x - MO) : as[i].x;
  }
}
void invFft(Mint *as, int n) {
  assert(!(n & (n - 1)));
  assert(1 <= n);
  assert(n <= 1 << FFT_MAX);
  int m = 1;
  if (m < n >> 1) {
    Mint prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + m; ++i) {
        const unsigned long long y = as[i].x + MO - as[i + m].x;
        as[i].x += as[i + m].x;
        as[i + m].x = (prod.x * y) % MO;
      }
      prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
    }
    m <<= 1;
  }
  for (; m < n >> 1; m <<= 1) {
    Mint prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + (m >> 1); ++i) {
        const unsigned long long y = as[i].x + MO2 - as[i + m].x;
        as[i].x += as[i + m].x;
        as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;
        as[i + m].x = (prod.x * y) % MO;
      }
      for (int i = i0 + (m >> 1); i < i0 + m; ++i) {
        const unsigned long long y = as[i].x + MO - as[i + m].x;
        as[i].x += as[i + m].x;
        as[i + m].x = (prod.x * y) % MO;
      }
      prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
    }
  }
  if (m < n) {
    for (int i = 0; i < m; ++i) {
      const unsigned y = as[i].x + MO2 - as[i + m].x;
      as[i].x += as[i + m].x;
      as[i + m].x = y;
    }
  }
  const Mint invN = Mint(n).inv();
  for (int i = 0; i < n; ++i) {
    as[i] *= invN;
  }
}
void fft(vector<Mint> &as) { fft(as.data(), as.size()); }
void invFft(vector<Mint> &as) { invFft(as.data(), as.size()); }
vector<Mint> convolve(vector<Mint> as, vector<Mint> bs) {
  if (as.empty() || bs.empty()) return {};
  const int len = as.size() + bs.size() - 1;
  int n = 1;
  for (; n < len; n <<= 1) {
  }
  as.resize(n);
  fft(as);
  bs.resize(n);
  fft(bs);
  for (int i = 0; i < n; ++i) as[i] *= bs[i];
  invFft(as);
  as.resize(len);
  return as;
}
vector<Mint> square(vector<Mint> as) {
  if (as.empty()) return {};
  const int len = as.size() + as.size() - 1;
  int n = 1;
  for (; n < len; n <<= 1) {
  }
  as.resize(n);
  fft(as);
  for (int i = 0; i < n; ++i) as[i] *= as[i];
  invFft(as);
  as.resize(len);
  return as;
}
constexpr int LIM_INV = 1 << 20;
Mint inv[LIM_INV], fac[LIM_INV], invFac[LIM_INV];
struct ModIntPreparator {
  ModIntPreparator() {
    inv[1] = 1;
    for (int i = 2; i < LIM_INV; ++i)
      inv[i] = -((Mint::M / i) * inv[Mint::M % i]);
    fac[0] = 1;
    for (int i = 1; i < LIM_INV; ++i) fac[i] = fac[i - 1] * i;
    invFac[0] = 1;
    for (int i = 1; i < LIM_INV; ++i) invFac[i] = invFac[i - 1] * inv[i];
  }
} preparator;
static constexpr int LIM_POLY = 1 << 20;
static_assert(LIM_POLY <= 1 << FFT_MAX,
              "Poly: LIM_POLY <= 1 << FFT_MAX must hold.");
static Mint polyWork0[LIM_POLY], polyWork1[LIM_POLY], polyWork2[LIM_POLY],
    polyWork3[LIM_POLY];
struct Poly : public vector<Mint> {
  Poly() {}
  explicit Poly(int n) : vector<Mint>(n) {}
  Poly(const vector<Mint> &vec) : vector<Mint>(vec) {}
  Poly(std::initializer_list<Mint> il) : vector<Mint>(il) {}
  int size() const { return vector<Mint>::size(); }
  Mint at(long long k) const {
    return (0 <= k && k < size()) ? (*this)[k] : 0U;
  }
  int ord() const {
    for (int i = 0; i < size(); ++i)
      if ((*this)[i]) return i;
    return -1;
  }
  int deg() const {
    for (int i = size(); --i >= 0;)
      if ((*this)[i]) return i;
    return -1;
  }
  Poly mod(int n) const {
    return Poly(vector<Mint>(data(), data() + min(n, size())));
  }
  friend std::ostream &operator<<(std::ostream &os, const Poly &fs) {
    os << "[";
    for (int i = 0; i < fs.size(); ++i) {
      if (i > 0) os << ", ";
      os << fs[i];
    }
    return os << "]";
  }
  Poly &operator+=(const Poly &fs) {
    if (size() < fs.size()) resize(fs.size());
    for (int i = 0; i < fs.size(); ++i) (*this)[i] += fs[i];
    return *this;
  }
  Poly &operator-=(const Poly &fs) {
    if (size() < fs.size()) resize(fs.size());
    for (int i = 0; i < fs.size(); ++i) (*this)[i] -= fs[i];
    return *this;
  }
  Poly &operator*=(const Poly &fs) {
    if (empty() || fs.empty()) return *this = {};
    const int nt = size(), nf = fs.size();
    int n = 1;
    for (; n < nt + nf - 1; n <<= 1) {
    }
    assert(n <= LIM_POLY);
    resize(n);
    fft(data(), n);
    memcpy(polyWork0, fs.data(), nf * sizeof(Mint));
    memset(polyWork0 + nf, 0, (n - nf) * sizeof(Mint));
    fft(polyWork0, n);
    for (int i = 0; i < n; ++i) (*this)[i] *= polyWork0[i];
    invFft(data(), n);
    resize(nt + nf - 1);
    return *this;
  }
  Poly &operator/=(const Poly &fs) {
    const int m = deg(), n = fs.deg();
    assert(n != -1);
    if (m < n) return *this = {};
    Poly tsRev(m - n + 1), fsRev(min(m - n, n) + 1);
    for (int i = 0; i <= m - n; ++i) tsRev[i] = (*this)[m - i];
    for (int i = 0, i0 = min(m - n, n); i <= i0; ++i) fsRev[i] = fs[n - i];
    const Poly qsRev = tsRev.div(fsRev, m - n + 1);
    resize(m - n + 1);
    for (int i = 0; i <= m - n; ++i) (*this)[i] = qsRev[m - n - i];
    return *this;
  }
  Poly &operator%=(const Poly &fs) {
    const Poly qs = *this / fs;
    *this -= fs * qs;
    resize(deg() + 1);
    return *this;
  }
  Poly &operator*=(const Mint &a) {
    for (int i = 0; i < size(); ++i) (*this)[i] *= a;
    return *this;
  }
  Poly &operator/=(const Mint &a) {
    const Mint b = a.inv();
    for (int i = 0; i < size(); ++i) (*this)[i] *= b;
    return *this;
  }
  Poly operator+() const { return *this; }
  Poly operator-() const {
    Poly fs(size());
    for (int i = 0; i < size(); ++i) fs[i] = -(*this)[i];
    return fs;
  }
  Poly operator+(const Poly &fs) const { return (Poly(*this) += fs); }
  Poly operator-(const Poly &fs) const { return (Poly(*this) -= fs); }
  Poly operator*(const Poly &fs) const { return (Poly(*this) *= fs); }
  Poly operator/(const Poly &fs) const { return (Poly(*this) /= fs); }
  Poly operator%(const Poly &fs) const { return (Poly(*this) %= fs); }
  Poly operator*(const Mint &a) const { return (Poly(*this) *= a); }
  Poly operator/(const Mint &a) const { return (Poly(*this) /= a); }
  friend Poly operator*(const Mint &a, const Poly &fs) { return fs * a; }
  Poly inv(int n) const {
    assert(!empty());
    assert((*this)[0]);
    assert(1 <= n);
    assert(n == 1 || 1 << (32 - __builtin_clz(n - 1)) <= LIM_POLY);
    Poly fs(n);
    fs[0] = (*this)[0].inv();
    for (int m = 1; m < n; m <<= 1) {
      memcpy(polyWork0, data(), min(m << 1, size()) * sizeof(Mint));
      memset(polyWork0 + min(m << 1, size()), 0,
             ((m << 1) - min(m << 1, size())) * sizeof(Mint));
      fft(polyWork0, m << 1);
      memcpy(polyWork1, fs.data(), min(m << 1, n) * sizeof(Mint));
      memset(polyWork1 + min(m << 1, n), 0,
             ((m << 1) - min(m << 1, n)) * sizeof(Mint));
      fft(polyWork1, m << 1);
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
      invFft(polyWork0, m << 1);
      memset(polyWork0, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
      invFft(polyWork0, m << 1);
      for (int i = m, i0 = min(m << 1, n); i < i0; ++i) fs[i] = -polyWork0[i];
    }
    return fs;
  }
  Poly div(const Poly &fs, int n) const {
    assert(!fs.empty());
    assert(fs[0]);
    assert(1 <= n);
    if (n == 1) return {at(0) / fs[0]};
    const int m = 1 << (31 - __builtin_clz(n - 1));
    assert(m << 1 <= LIM_POLY);
    Poly gs = fs.inv(m);
    gs.resize(m << 1);
    fft(gs.data(), m << 1);
    memcpy(polyWork0, data(), min(m, size()) * sizeof(Mint));
    memset(polyWork0 + min(m, size()), 0,
           ((m << 1) - min(m, size())) * sizeof(Mint));
    fft(polyWork0, m << 1);
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= gs[i];
    invFft(polyWork0, m << 1);
    Poly hs(n);
    memcpy(hs.data(), polyWork0, m * sizeof(Mint));
    memset(polyWork0 + m, 0, m * sizeof(Mint));
    fft(polyWork0, m << 1);
    memcpy(polyWork1, fs.data(), min(m << 1, fs.size()) * sizeof(Mint));
    memset(polyWork1 + min(m << 1, fs.size()), 0,
           ((m << 1) - min(m << 1, fs.size())) * sizeof(Mint));
    fft(polyWork1, m << 1);
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
    invFft(polyWork0, m << 1);
    memset(polyWork0, 0, m * sizeof(Mint));
    for (int i = m, i0 = min(m << 1, size()); i < i0; ++i)
      polyWork0[i] -= (*this)[i];
    fft(polyWork0, m << 1);
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= gs[i];
    invFft(polyWork0, m << 1);
    for (int i = m; i < n; ++i) hs[i] = -polyWork0[i];
    return hs;
  }
  Mint divAt(const Poly &fs, long long k) const {
    assert(k >= 0);
    if (size() >= fs.size()) {
      assert(false);
    }
    int h = 0, m = 1;
    for (; m < fs.size(); ++h, m <<= 1) {
    }
    if (k < m) {
      const Poly gs = fs.inv(k + 1);
      Mint sum;
      for (int i = 0, i0 = min<int>(k + 1, size()); i < i0; ++i)
        sum += (*this)[i] * gs[k - i];
      return sum;
    }
    assert(m << 1 <= LIM_POLY);
    polyWork0[0] = Mint(2U).inv();
    for (int hh = 0; hh < h; ++hh)
      for (int i = 0; i < 1 << hh; ++i)
        polyWork0[1 << hh | i] = polyWork0[i] * INV_FFT_ROOTS[hh + 2];
    const Mint a = FFT_ROOTS[h + 1];
    memcpy(polyWork2, data(), size() * sizeof(Mint));
    memset(polyWork2 + size(), 0, ((m << 1) - size()) * sizeof(Mint));
    fft(polyWork2, m << 1);
    memcpy(polyWork1, fs.data(), fs.size() * sizeof(Mint));
    memset(polyWork1 + fs.size(), 0, ((m << 1) - fs.size()) * sizeof(Mint));
    fft(polyWork1, m << 1);
    for (;;) {
      if (k & 1) {
        for (int i = 0; i < m; ++i)
          polyWork2[i] =
              polyWork0[i] * (polyWork2[i << 1 | 0] * polyWork1[i << 1 | 1] -
                              polyWork2[i << 1 | 1] * polyWork1[i << 1 | 0]);
      } else {
        for (int i = 0; i < m; ++i) {
          polyWork2[i] = polyWork2[i << 1 | 0] * polyWork1[i << 1 | 1] +
                         polyWork2[i << 1 | 1] * polyWork1[i << 1 | 0];
          polyWork2[i].x =
              ((polyWork2[i].x & 1) ? (polyWork2[i].x + MO) : polyWork2[i].x) >>
              1;
        }
      }
      for (int i = 0; i < m; ++i)
        polyWork1[i] = polyWork1[i << 1 | 0] * polyWork1[i << 1 | 1];
      if ((k >>= 1) < m) {
        invFft(polyWork2, m);
        invFft(polyWork1, m);
        const Poly gs =
            Poly(vector<Mint>(polyWork1, polyWork1 + k + 1)).inv(k + 1);
        Mint sum;
        for (int i = 0; i <= k; ++i) sum += polyWork2[i] * gs[k - i];
        return sum;
      }
      memcpy(polyWork2 + m, polyWork2, m * sizeof(Mint));
      invFft(polyWork2 + m, m);
      memcpy(polyWork1 + m, polyWork1, m * sizeof(Mint));
      invFft(polyWork1 + m, m);
      Mint aa = 1;
      for (int i = m; i < m << 1; ++i) {
        polyWork2[i] *= aa;
        polyWork1[i] *= aa;
        aa *= a;
      }
      fft(polyWork2 + m, m);
      fft(polyWork1 + m, m);
    }
  }
  Poly log(int n) const {
    assert(!empty());
    assert((*this)[0].x == 1U);
    assert(n <= LIM_INV);
    Poly fs = mod(n);
    for (int i = 0; i < fs.size(); ++i) fs[i] *= i;
    fs = fs.div(*this, n);
    for (int i = 1; i < n; ++i) fs[i] *= ::inv[i];
    return fs;
  }
  Poly exp(int n) const {
    assert(!empty());
    assert(!(*this)[0]);
    assert(1 <= n);
    assert(n == 1 ||
           1 << (32 - __builtin_clz(n - 1)) <= min(LIM_INV, LIM_POLY));
    if (n == 1) return {1U};
    if (n == 2) return {1U, at(1)};
    Poly fs(n);
    fs[0].x = polyWork1[0].x = polyWork1[1].x = polyWork2[0].x = 1U;
    int m;
    for (m = 1; m << 1 < n; m <<= 1) {
      for (int i = 0, i0 = min(m, size()); i < i0; ++i)
        polyWork0[i] = i * (*this)[i];
      memset(polyWork0 + min(m, size()), 0,
             (m - min(m, size())) * sizeof(Mint));
      fft(polyWork0, m);
      for (int i = 0; i < m; ++i) polyWork0[i] *= polyWork1[i];
      invFft(polyWork0, m);
      for (int i = 0; i < m; ++i) polyWork0[i] -= i * fs[i];
      memset(polyWork0 + m, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);
      memcpy(polyWork3, polyWork2, m * sizeof(Mint));
      memset(polyWork3 + m, 0, m * sizeof(Mint));
      fft(polyWork3, m << 1);
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork3[i];
      invFft(polyWork0, m << 1);
      for (int i = 0; i < m; ++i) polyWork0[i] *= ::inv[m + i];
      for (int i = 0, i0 = min(m, size() - m); i < i0; ++i)
        polyWork0[i] += (*this)[m + i];
      memset(polyWork0 + m, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
      invFft(polyWork0, m << 1);
      memcpy(fs.data() + m, polyWork0, m * sizeof(Mint));
      memcpy(polyWork1, fs.data(), (m << 1) * sizeof(Mint));
      memset(polyWork1 + (m << 1), 0, (m << 1) * sizeof(Mint));
      fft(polyWork1, m << 2);
      for (int i = 0; i < m << 1; ++i)
        polyWork0[i] = polyWork1[i] * polyWork3[i];
      invFft(polyWork0, m << 1);
      memset(polyWork0, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork3[i];
      invFft(polyWork0, m << 1);
      for (int i = m; i < m << 1; ++i) polyWork2[i] = -polyWork0[i];
    }
    for (int i = 0, i0 = min(m, size()); i < i0; ++i)
      polyWork0[i] = i * (*this)[i];
    memset(polyWork0 + min(m, size()), 0, (m - min(m, size())) * sizeof(Mint));
    fft(polyWork0, m);
    for (int i = 0; i < m; ++i) polyWork0[i] *= polyWork1[i];
    invFft(polyWork0, m);
    for (int i = 0; i < m; ++i) polyWork0[i] -= i * fs[i];
    memcpy(polyWork0 + m, polyWork0 + (m >> 1), (m >> 1) * sizeof(Mint));
    memset(polyWork0 + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    memset(polyWork0 + m + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    fft(polyWork0, m);
    fft(polyWork0 + m, m);
    memcpy(polyWork3 + m, polyWork2 + (m >> 1), (m >> 1) * sizeof(Mint));
    memset(polyWork3 + m + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    fft(polyWork3 + m, m);
    for (int i = 0; i < m; ++i)
      polyWork0[m + i] =
          polyWork0[i] * polyWork3[m + i] + polyWork0[m + i] * polyWork3[i];
    for (int i = 0; i < m; ++i) polyWork0[i] *= polyWork3[i];
    invFft(polyWork0, m);
    invFft(polyWork0 + m, m);
    for (int i = 0; i < m >> 1; ++i)
      polyWork0[(m >> 1) + i] += polyWork0[m + i];
    for (int i = 0; i < m; ++i) polyWork0[i] *= ::inv[m + i];
    for (int i = 0, i0 = min(m, size() - m); i < i0; ++i)
      polyWork0[i] += (*this)[m + i];
    memset(polyWork0 + m, 0, m * sizeof(Mint));
    fft(polyWork0, m << 1);
    for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork1[i];
    invFft(polyWork0, m << 1);
    memcpy(fs.data() + m, polyWork0, (n - m) * sizeof(Mint));
    return fs;
  }
  Poly pow(Mint a, int n) const {
    assert(!empty());
    assert((*this)[0].x == 1U);
    assert(1 <= n);
    return (a * log(n)).exp(n);
  }
  Poly pow(long long a, int n) const {
    assert(a >= 0);
    assert(1 <= n);
    if (a == 0) {
      Poly gs(n);
      gs[0].x = 1U;
      return gs;
    }
    const int o = ord();
    if (o == -1 || o > (n - 1) / a) return Poly(n);
    const Mint b = (*this)[o].inv(), c = (*this)[o].pow(a);
    const int ntt = min<int>(n - a * o, size() - o);
    Poly tts(ntt);
    for (int i = 0; i < ntt; ++i) tts[i] = b * (*this)[o + i];
    tts = tts.pow(Mint(a), n - a * o);
    Poly gs(n);
    for (int i = 0; i < n - a * o; ++i) gs[a * o + i] = c * tts[i];
    return gs;
  }
  Poly sqrt(int n) const {
    assert(!empty());
    assert((*this)[0].x == 1U);
    assert(1 <= n);
    assert(n == 1 || 1 << (32 - __builtin_clz(n - 1)) <= LIM_POLY);
    if (n == 1) return {1U};
    if (n == 2) return {1U, at(1) / 2};
    Poly fs(n);
    fs[0].x = polyWork1[0].x = polyWork2[0].x = 1U;
    int m;
    for (m = 1; m << 1 < n; m <<= 1) {
      for (int i = 0; i < m; ++i) polyWork1[i] *= polyWork1[i];
      invFft(polyWork1, m);
      for (int i = 0, i0 = min(m, size()); i < i0; ++i)
        polyWork1[i] -= (*this)[i];
      for (int i = 0, i0 = min(m, size() - m); i < i0; ++i)
        polyWork1[i] -= (*this)[m + i];
      memset(polyWork1 + m, 0, m * sizeof(Mint));
      fft(polyWork1, m << 1);
      memcpy(polyWork3, polyWork2, m * sizeof(Mint));
      memset(polyWork3 + m, 0, m * sizeof(Mint));
      fft(polyWork3, m << 1);
      for (int i = 0; i < m << 1; ++i) polyWork1[i] *= polyWork3[i];
      invFft(polyWork1, m << 1);
      for (int i = 0; i < m; ++i) {
        polyWork1[i] = -polyWork1[i];
        fs[m + i].x =
            ((polyWork1[i].x & 1) ? (polyWork1[i].x + MO) : polyWork1[i].x) >>
            1;
      }
      memcpy(polyWork1, fs.data(), (m << 1) * sizeof(Mint));
      fft(polyWork1, m << 1);
      for (int i = 0; i < m << 1; ++i)
        polyWork0[i] = polyWork1[i] * polyWork3[i];
      invFft(polyWork0, m << 1);
      memset(polyWork0, 0, m * sizeof(Mint));
      fft(polyWork0, m << 1);
      for (int i = 0; i < m << 1; ++i) polyWork0[i] *= polyWork3[i];
      invFft(polyWork0, m << 1);
      for (int i = m; i < m << 1; ++i) polyWork2[i] = -polyWork0[i];
    }
    for (int i = 0; i < m; ++i) polyWork1[i] *= polyWork1[i];
    invFft(polyWork1, m);
    for (int i = 0, i0 = min(m, size()); i < i0; ++i)
      polyWork1[i] -= (*this)[i];
    for (int i = 0, i0 = min(m, size() - m); i < i0; ++i)
      polyWork1[i] -= (*this)[m + i];
    memcpy(polyWork1 + m, polyWork1 + (m >> 1), (m >> 1) * sizeof(Mint));
    memset(polyWork1 + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    memset(polyWork1 + m + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    fft(polyWork1, m);
    fft(polyWork1 + m, m);
    memcpy(polyWork3 + m, polyWork2 + (m >> 1), (m >> 1) * sizeof(Mint));
    memset(polyWork3 + m + (m >> 1), 0, (m >> 1) * sizeof(Mint));
    fft(polyWork3 + m, m);
    for (int i = 0; i < m; ++i)
      polyWork1[m + i] =
          polyWork1[i] * polyWork3[m + i] + polyWork1[m + i] * polyWork3[i];
    for (int i = 0; i < m; ++i) polyWork1[i] *= polyWork3[i];
    invFft(polyWork1, m);
    invFft(polyWork1 + m, m);
    for (int i = 0; i < m >> 1; ++i)
      polyWork1[(m >> 1) + i] += polyWork1[m + i];
    for (int i = 0; i < n - m; ++i) {
      polyWork1[i] = -polyWork1[i];
      fs[m + i].x =
          ((polyWork1[i].x & 1) ? (polyWork1[i].x + MO) : polyWork1[i].x) >> 1;
    }
    return fs;
  }
  template <class F>
  Poly sqrt(int n, F modSqrt) const {
    assert(1 <= n);
    const int o = ord();
    if (o == -1) return Poly(n);
    if (o & 1) return {};
    const Mint c = modSqrt((*this)[o]);
    if (c * c != (*this)[o]) return {};
    if (o >> 1 >= n) return Poly(n);
    const Mint b = (*this)[o].inv();
    const int ntt = min(n - (o >> 1), size() - o);
    Poly tts(ntt);
    for (int i = 0; i < ntt; ++i) tts[i] = b * (*this)[o + i];
    tts = tts.sqrt(n - (o >> 1));
    Poly gs(n);
    for (int i = 0; i < n - (o >> 1); ++i) gs[(o >> 1) + i] = c * tts[i];
    return gs;
  }
};
Mint linearRecurrenceAt(const vector<Mint> &as, const vector<Mint> &cs,
                        long long k) {
  assert(!cs.empty());
  assert(cs[0]);
  const int d = cs.size() - 1;
  assert(as.size() >= static_cast<size_t>(d));
  return (Poly(vector<Mint>(as.begin(), as.begin() + d)) * cs)
      .mod(d)
      .divAt(cs, k);
}
struct SubproductTree {
  int logN, n, nn;
  vector<Mint> xs;
  vector<Mint> buf;
  vector<Mint *> gss;
  Poly all;
  SubproductTree(const vector<Mint> &xs_) {
    n = xs_.size();
    for (logN = 0, nn = 1; nn < n; ++logN, nn <<= 1) {
    }
    xs.assign(nn, 0U);
    memcpy(xs.data(), xs_.data(), n * sizeof(Mint));
    buf.assign((logN + 1) * (nn << 1), 0U);
    gss.assign(nn << 1, nullptr);
    for (int h = 0; h <= logN; ++h)
      for (int u = 1 << h; u < 1 << (h + 1); ++u) {
        gss[u] =
            buf.data() + (h * (nn << 1) + ((u - (1 << h)) << (logN - h + 1)));
      }
    for (int i = 0; i < nn; ++i) {
      gss[nn + i][0] = -xs[i] + 1;
      gss[nn + i][1] = -xs[i] - 1;
    }
    if (nn == 1) gss[1][1] += 2;
    for (int h = logN; --h >= 0;) {
      const int m = 1 << (logN - h);
      for (int u = 1 << (h + 1); --u >= 1 << h;) {
        for (int i = 0; i < m; ++i)
          gss[u][i] = gss[u << 1][i] * gss[u << 1 | 1][i];
        memcpy(gss[u] + m, gss[u], m * sizeof(Mint));
        invFft(gss[u] + m, m);
        if (h > 0) {
          gss[u][m] -= 2;
          const Mint a = FFT_ROOTS[logN - h + 1];
          Mint aa = 1;
          for (int i = m; i < m << 1; ++i) {
            gss[u][i] *= aa;
            aa *= a;
          };
          fft(gss[u] + m, m);
        }
      }
    }
    all.resize(nn + 1);
    all[0] = 1;
    for (int i = 1; i < nn; ++i) all[i] = gss[1][nn + nn - i];
    all[nn] = gss[1][nn] - 1;
  }
  vector<Mint> multiEval(const Poly &fs) const {
    vector<Mint> work0(nn), work1(nn), work2(nn);
    {
      const int m = max(fs.size(), 1);
      auto invAll = all.inv(m);
      std::reverse(invAll.begin(), invAll.end());
      int mm;
      for (mm = 1; mm < m - 1 + nn; mm <<= 1) {
      }
      invAll.resize(mm, 0U);
      fft(invAll);
      vector<Mint> ffs(mm, 0U);
      memcpy(ffs.data(), fs.data(), fs.size() * sizeof(Mint));
      fft(ffs);
      for (int i = 0; i < mm; ++i) ffs[i] *= invAll[i];
      invFft(ffs);
      memcpy(((logN & 1) ? work1 : work0).data(), ffs.data() + m - 1,
             nn * sizeof(Mint));
    }
    for (int h = 0; h < logN; ++h) {
      const int m = 1 << (logN - h);
      for (int u = 1 << h; u < 1 << (h + 1); ++u) {
        Mint *hs = (((logN - h) & 1) ? work1 : work0).data() +
                   ((u - (1 << h)) << (logN - h));
        Mint *hs0 = (((logN - h) & 1) ? work0 : work1).data() +
                    ((u - (1 << h)) << (logN - h));
        Mint *hs1 = hs0 + (m >> 1);
        fft(hs, m);
        for (int i = 0; i < m; ++i) work2[i] = gss[u << 1 | 1][i] * hs[i];
        invFft(work2.data(), m);
        memcpy(hs0, work2.data() + (m >> 1), (m >> 1) * sizeof(Mint));
        for (int i = 0; i < m; ++i) work2[i] = gss[u << 1][i] * hs[i];
        invFft(work2.data(), m);
        memcpy(hs1, work2.data() + (m >> 1), (m >> 1) * sizeof(Mint));
      }
    }
    work0.resize(n);
    return work0;
  }
  Poly interpolate(const vector<Mint> &ys) const {
    assert(static_cast<int>(ys.size()) == n);
    Poly gs(n);
    for (int i = 0; i < n; ++i) gs[i] = (i + 1) * all[n - (i + 1)];
    const vector<Mint> denoms = multiEval(gs);
    vector<Mint> work(nn << 1, 0U);
    for (int i = 0; i < n; ++i) {
      assert(denoms[i]);
      work[i << 1] = work[i << 1 | 1] = ys[i] / denoms[i];
    }
    for (int h = logN; --h >= 0;) {
      const int m = 1 << (logN - h);
      for (int u = 1 << (h + 1); --u >= 1 << h;) {
        Mint *hs = work.data() + ((u - (1 << h)) << (logN - h + 1));
        for (int i = 0; i < m; ++i)
          hs[i] = gss[u << 1 | 1][i] * hs[i] + gss[u << 1][i] * hs[m + i];
        if (h > 0) {
          memcpy(hs + m, hs, m * sizeof(Mint));
          invFft(hs + m, m);
          const Mint a = FFT_ROOTS[logN - h + 1];
          Mint aa = 1;
          for (int i = m; i < m << 1; ++i) {
            hs[i] *= aa;
            aa *= a;
          };
          fft(hs + m, m);
        }
      }
    }
    invFft(work.data(), nn);
    return Poly(vector<Mint>(work.data() + nn - n, work.data() + nn));
  }
};
int N;
Int M;
int main() {
  for (; ~scanf("%d%lld", &N, &M);) {
    Mint ans = 0;
    if (N % 2 == 0) {
      Poly fs(N + 1), gs(N + 1);
      {
        Mint bn = 1;
        for (int i = 1; 2 * i <= N; ++i) {
          bn *= Mint(M + i);
          bn *= Mint(M - 1 - i);
          bn *= inv[2 * i - 1];
          bn *= inv[2 * i];
          fs[2 * i] += bn;
          gs[2 * i] += Mint(i) * bn;
        }
      }
      fs[0] += 1;
      Poly hs = gs.div(fs, N + 1);
      ans += (((N / 2 - 1) & 1) ? -1 : +1) * hs[N];
    } else {
      Poly ffs(N + 1), ggs(N + 1);
      {
        Mint bn = 1;
        for (int i = 1; 2 * i <= N; ++i) {
          bn *= Mint(M / 2 + i);
          bn *= Mint(M / 2 + 1 - i);
          bn *= inv[2 * i - 1];
          bn *= inv[2 * i];
          ffs[2 * i] += bn;
        }
      }
      {
        Mint bn = Mint(M / 2);
        for (int i = 0; 2 * i + 1 <= N; ++i) {
          if (i >= 1) {
            bn *= Mint(M / 2 + i);
            bn *= Mint(M / 2 - i);
            bn *= inv[2 * i];
            bn *= inv[2 * i + 1];
          }
          ggs[2 * i + 1] += bn;
        }
      }
      ffs[0] += 1;
      Poly hhs = ggs.div(ffs, N + 1);
      for (int i = 1; i <= N; i += 2) {
        hhs[i] *= ((((i - 1) / 2) & 1) ? -1 : +1);
      }
      Poly fs = hhs;
      fs[1] = M - M / 2;
      Poly gs = fs;
      for (int i = 0; i <= N; ++i) {
        gs[i] *= i;
      }
      fs *= -1;
      fs[0] += 1;
      const Poly hs = gs.div(fs, N + 1);
      ans += hs[N];
    }
    printf("%u\n", ans.x);
  }
  return 0;
}
