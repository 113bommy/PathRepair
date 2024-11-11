D,G = map(int, input().split())
INF = 10**10
# 各点数を得るときの、最小の問題数
n = 2*10**5
dp = [INF] * n
dp[0] = 0
for i in range(1,D+1):
    p,c = map(int, input().split())
    c //= 100
    tmp = dp[:]
    for j in range(G//100+1):
        if tmp[j] == INF: continue
        for k in range(1,p+1):
            dp[j+i*k] = min(tmp[j]+k, dp[j+i*k])
        dp[j+i*p+c] = min(tmp[j]+p, dp[j+i*p+c])
ans = INF
for score in dp[G//100:]:
    if score == INF: continue
    ans = min(score, ans)
print(ans)
