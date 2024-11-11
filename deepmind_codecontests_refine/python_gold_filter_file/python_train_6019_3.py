from collections import defaultdict
MOD = 10**9+7
n = int(input())
dp = [1]
d = defaultdict(list)
cur = int(input())
d[cur].append(0)
for i in range(1,n):
  pre,cur = cur,int(input())
  c = dp[-1]
  if pre != cur and d[cur]:
    c += dp[d[cur][-1]]
  dp.append(c%MOD)
  d[cur].append(i)
print(dp[-1])