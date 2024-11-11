N,M = map(int,input().split())
A = list(map(int,input().split()))

dp = [-1 for _ in range(1010)]
dp[0] = 0            

MatchNum = [0,2,5,5,4,5,6,3,7,6]

for i in range(1,1005):
    for x in A:          
        if i-MatchNum[x] >= 0:
            tmp = dp[i-MatchNum[x]]*10 + x
            dp[i] = max(tmp,dp[i])
print(dp[N])
