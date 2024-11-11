N = int(input())
arr = list(map(int, input().split()))
dp = [1000]*N
for i in range(1,N):
    dp[i] = max((dp[i-1]//arr[i-1])*arr[i]+dp[i-1]%arr[i-1],dp[i-1])
print(dp[-1])