N,K = map(int,input().split())
H = list(map(int,input().split()))
dp = [10**18]*N
dp[0] = 0
for i in range(1,N):
    for j in range(max(0,i-K),i):
        dp[i] = min(dp[i], dp[j] + abs(H[i]-H[j]))
print(dp[-1])
