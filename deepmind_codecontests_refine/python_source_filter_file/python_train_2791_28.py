N,K = list(map(int,input().split()))
h = list(map(int,input().split()))

dp = [0]+[float('inf')]*(N-1)
for i in range(1,N):
    for j in range(max(0,i-K),i):
        dp[i] = min(dp[i],dp[j]+abs(h[i]-h[j]))

print(dp[-1])