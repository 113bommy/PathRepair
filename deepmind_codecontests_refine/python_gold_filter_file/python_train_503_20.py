N,A = map(int,input().split())
X = list(map(int,input().split()))
Y = [x-A for x in X]
t = sum(X)
dp = [[0]*(t*2+1) for _ in range(N+1)]
#dp[i][j] -> i枚目まで見る。合計をj-tにするパターン数
#i枚目を使う場合 -> dp[i][j] += dp[i-1][j-Yi]
#i枚目を使わない場合 -> dp[i][j] += dp[i-1][j]
dp[0][t] = 1

for i in range(1,N+1):
    y = Y[i-1]
    for j in range(t*2+1):
        if 0 <= j-y <= t*2:
            dp[i][j] += dp[i-1][j-y]
        dp[i][j] += dp[i-1][j]

print(dp[-1][t]-1)