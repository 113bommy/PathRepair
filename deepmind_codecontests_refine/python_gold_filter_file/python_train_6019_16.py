N = int(input())
C = [int(input()) for _ in range(N)]
MOD = 10**9 + 7

if N <= 2:
    print(1)
    exit()

dp = [1,1]
last_idx = [-1]*(2*10**5 + 1)
last_idx[C[0]] = 0
last_idx[C[1]] = 1

for i in range(2, N):
    if C[i-1] == C[i] or last_idx[C[i]] == -1:
        dp.append(dp[-1] % MOD)
    else:
        dp.append((dp[-1] + dp[last_idx[C[i]]]) % MOD)
    last_idx[C[i]] = i

print(dp[-1])