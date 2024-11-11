n,*a = map(int,open(0).read().split())
cnt = [3]+[0]*n
ans = 1
mod = 10**9+7
for i in a:
  ans = ans * cnt[i] % mod
  cnt[i] -= 1
  cnt[i+1] += 1
print(ans)