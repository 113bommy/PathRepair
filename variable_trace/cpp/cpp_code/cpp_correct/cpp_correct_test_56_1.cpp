#include <bits/stdc++.h>
using namespace std;
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() { return T::value; }
  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod()) value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0) value += mod();
    return *this;
  }
  template <typename U>
  Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U>
  Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) *
                                         rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }
  friend const Type& abs(const Modular& x) { return x.value; }
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};
template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) == rhs;
}
template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value < rhs.value;
}
template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
constexpr int md = (int)1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    int k, n;
    cin >> k >> n;
    vector<long long> a;
    map<long long, int> color;
    for (int i = 0; i < n; i++) {
      long long v;
      string s;
      cin >> v >> s;
      if (s[0] == 'r' || s[0] == 'o') {
        color[v] = 0;
      } else if (s[0] == 'b' || s[0] == 'g') {
        color[v] = 1;
      } else {
        color[v] = 2;
      }
      while (v) {
        a.emplace_back(v);
        v >>= 1;
      }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = (int)a.size();
    vector<vector<int>> G(m);
    for (int i = 0; i < m; i++) {
      auto ls = lower_bound(a.begin(), a.end(), a[i] * 2);
      auto rs = lower_bound(a.begin(), a.end(), a[i] * 2 + 1);
      if (ls != a.end() and *ls == a[i] * 2) {
        G[i].emplace_back(ls - a.begin());
      }
      if (rs != a.end() and *rs == a[i] * 2 + 1) {
        G[i].emplace_back(rs - a.begin());
      }
    }
    vector<vector<Mint>> dp(m, vector<Mint>(3, 0));
    function<void(int)> dfs = [&](int x) {
      if (G[x].empty()) {
        if (color.count(a[x])) {
          for (int i = 0; i < 3; i++) {
            if (i != color[a[x]]) {
              dp[x][i] = 0;
            } else {
              dp[x][i] = 1;
            }
          }
        } else {
          for (int i = 0; i < 3; i++) {
            dp[x][i] = 2;
          }
        }
        return;
      }
      for (int& e : G[x]) {
        dfs(e);
      }
      if ((int)G[x].size() == 1) {
        dp[x][0] += dp[G[x][0]][1] + dp[G[x][0]][2];
        dp[x][1] += dp[G[x][0]][0] + dp[G[x][0]][2];
        dp[x][2] += dp[G[x][0]][0] + dp[G[x][0]][1];
      } else {
        vector<Mint> left(3, 0);
        vector<Mint> right(3, 0);
        left[0] += dp[G[x][0]][1] + dp[G[x][0]][2];
        left[1] += dp[G[x][0]][0] + dp[G[x][0]][2];
        left[2] += dp[G[x][0]][0] + dp[G[x][0]][1];
        right[0] += dp[G[x][1]][1] + dp[G[x][1]][2];
        right[1] += dp[G[x][1]][0] + dp[G[x][1]][2];
        right[2] += dp[G[x][1]][0] + dp[G[x][1]][1];
        dp[x][0] += left[0] * right[0];
        dp[x][1] += left[1] * right[1];
        dp[x][2] += left[2] * right[2];
      }
      if (color.count(a[x])) {
        for (int i = 0; i < 3; i++) {
          if (i != color[a[x]]) {
            dp[x][i] = 0;
          }
        }
      } else {
        for (int i = 0; i < 3; i++) {
          dp[x][i] *= 2;
        }
      }
    };
    dfs(0);
    cout << (dp[0][0] + dp[0][1] + dp[0][2]) *
                power(Mint(4), (1LL << k) - 1 - m)
         << '\n';
  }
  return 0;
}
