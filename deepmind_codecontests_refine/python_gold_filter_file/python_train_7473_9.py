n = int(input())
c = sorted(list(map(int, input().split())),reverse=True)
mod = 10**9 + 7
ans = 0
two = [1]
for i in range(n*2):
  two += [(two[i]*2) % mod]

for i in range(n):
  ans += (i+2) * c[i]
  ans %= mod
ans *= two[2*n - 2]
print(ans%mod)