n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
ans = [0]*(1<<n)
ans[0] = 1
mod = 10**9 + 7

def popcnt(x):
  ret = 0
  for i in range(n):
    if x & (1<<i):
      ret += 1
  return ret

for bit in range(1<<n):
  if ans[bit]:
    i = popcnt(bit)
    v = 1
    for j in range(n):
      if not bit & v and a[i][j]:
        ans[bit|v] = (ans[bit|v] + ans[bit])%mod
      v <<= 1
print(ans[-1])
