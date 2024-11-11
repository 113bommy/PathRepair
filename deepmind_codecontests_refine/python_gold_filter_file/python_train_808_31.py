n = int(input())
mod = 10**9 + 7
a = list(map(int, input().split()))
b = [sum(1 for x in a if x&(1<<i)) for i in range(60)]
ans = 0
for i in range(60):
  t = b[i]*(n-b[i])
  m = (1<<i)%mod
  ans = (ans + t*m%mod)%mod
print(ans)