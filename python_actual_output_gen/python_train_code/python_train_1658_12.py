N, Ma, Mb = map(int,input().split())
L = []
for _ in range(N):
    L.append( list(map(int,input().split())) )
dp = [[[10**10 for _ in range(601)] for _ in range(601)] for _ in range(N+10)]
dp[0][0][0] = 0

for l in range(N):
    for i in range(200):
        for j in range(200):
            dp[l+1][i][j] = min(dp[l+1][i][j],dp[l][i][j])
            dp[l+1][i+L[l][0]][j+L[l][1]] = min(dp[l+1][i+L[l][0]][j+L[l][1]],dp[l][i][j] + L[l][2])


ans = 10**10
for i in range(1,10000):
    try: ans = min(ans, dp[N+1][Ma*i][Mb*i])
    except: pass
if ans == 10**10: print(-1)
else: print(ans)



