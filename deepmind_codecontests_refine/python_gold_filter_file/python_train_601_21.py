N,M = map(int,input().split())
S = list(map(int,input().split()))
T = list(map(int,input().split()))
dp = [[1]+[0]*(len(T))for i in range(len(S)+1)]
dp[0] = [1]*(len(T)+1)
dp_sum = [[1]+[0]*(len(T))for i in range(len(S)+1)]
dp_sum[0] = [1]*(len(T)+1)
for i in range(len(S)):
    for j in range(len(T)):
        if S[i] == T[j]:
            dp[i+1][j+1] = dp_sum[i][j]
        dp_sum[i+1][j+1] = (dp[i+1][j+1]+dp_sum[i+1][j]+\
            dp_sum[i][j+1]-dp_sum[i][j])%(10**9+7)
print(dp_sum[-1][-1])