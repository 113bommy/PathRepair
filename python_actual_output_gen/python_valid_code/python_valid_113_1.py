N = int(input())
hs =[0]+ list(map(int, input().split()))
dp = [0] * (N+1)
for i in range(2, N+1):
    dp[i] = min(dp[i-1]+abs(hs[i]-hs[i-1]), dp[i-2]+abs(hs[i]-hs[i-2]))
print(dp[N])