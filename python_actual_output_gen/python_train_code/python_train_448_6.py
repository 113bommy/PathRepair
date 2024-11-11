import sys
input=sys.stdin.readline

mod=10**9+7

n,m=map(int,input().split())
dp=[1,1]
for i in range(2,max(n,m)+1):
    dp.append((dp[i-1]+dp[i-2])%mod)
print(2*(dp[n]+dp[m]-1))
