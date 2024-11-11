N = int(input())
A = list(map(int, input().split()))
mod = 1e+9 + 7
p = mod - 2
S = []
while p != 0:
  S = [p%2] + S[:]
  p //= 2
frac = 1
for i in range(N - 1):
  frac *= i+1
  frac %= mod
T = 0
for i in range(N - 1):
  k = 1
  for j in range(len(S)):
    if S[j] == 1:
      k *= i+1
      k %= mod
    if j != len(S) - 1:
      k *= k
      k %= mod
  T += (frac * k * (A[N - 1] - A[i])) % mod
  T %= mod
print(T%mod)