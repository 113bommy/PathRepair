import math
mod = 10**9+7
n, L, R = map(int, input().strip().split())

ini = math.ceil(L/3)
end = math.floor(R/3)

n0 = end-ini+1

n1 = math.floor((R-1)/3)-math.ceil((L-1)/3)+1
n2 = math.floor((R-2)/3)-math.ceil((L-2)/3)+1

dp = [[0 for i in range(n)] for i in range(3)]

# print(n0, n1, n2)

dp[0][0] = n0
dp[1][0] = n1
dp[2][0] = n2

for i in range(1, n):
    dp[0][i] = (dp[1][i-1]*n2 + dp[2][i-1]*n1+dp[0][i-1]*n0)%mod
    dp[1][i] = (dp[0][i-1]*n1 + dp[2][i-1]*n2+dp[1][i-1]*n0)%mod
    dp[2][i] = (dp[0][i-1]*n2 + dp[1][i-1]*n1+dp[2][i-1]*n0)%mod

# for i in dp:
#     print(i)
print(dp[0][-1])


