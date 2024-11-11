import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
a.sort(reverse = True)
mod = 10 ** 9 + 7
res = 0
if N == 1:
  print(a[0] * 2 % mod)
  exit(0)
for i in range(N):
  res += a[i] * (pow(2, N - 1, mod) % mod + pow(2, N - 2, mod) * i % mod) % mod
  res %= mod
print(res * pow(2, N, mod) % mod)