K = list(map(int, input().strip()))
D = int(input())
mod = 10**9+7

dp = [0]*D
dp[0] += 1
S = 0
for k in K:
    dp[S%D] -= 1
    dp2 = [0]*(D+10)
    for j, d in enumerate(dp):
        dp2[j] += d
        dp2[j+10] -= d
    for j in range(1, D+10):
        dp2[j] = (dp2[j-1] + dp2[j]) % mod
    for j in range(10):
        dp2[(D+j)%D] = (dp2[(D+j)%D] + dp2[D+j]) % mod 
    dp = dp2[:D]
    for j in range(k+1):
        dp[(S+j)%D] = (dp[(S+j)%D] + 1)%mod
    S += k
print(dp[0]-1)