import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

MOD = 998244353
N, S = lr()
A = lr()
dp = [0] * (S+1)
answer = 0
for a in A:
    dp[0] += 1 # Lの数は１個ずつ加わる
    prev = dp.copy()
    for i in range(S-a+1):
        dp[i+a] += prev[i]
    answer += dp[-1] # その位置をRとした時

print(answer % MOD)
# 26
