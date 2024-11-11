import sys
input = sys.stdin.readline
from itertools import accumulate
MOD = 10**9+7
  
n, k = map(int, input().split())
S = set()
i = 1
while i * i <= n:
  S.add(i)
  S.add(n//i)
  i += 1
L = [0] + sorted(S)
l = len(L) - 1
num = [0]*l
for i in range(l):
  num[i] = L[i+1] - L[i]
dp = [0]*l
dp[0] = 1
for _ in range(k):
  A = list(accumulate(dp))
  for i in range(l):
    dp[i] = A[l-1-i] * num[i]
    dp[i] %= MOD
ans = sum(dp) % MOD
print(ans)