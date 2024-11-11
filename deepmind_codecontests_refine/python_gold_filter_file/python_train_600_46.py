n, m = map(int, input().split())
lrc = []
for _ in range(m):
    lrc.append(tuple(map(int, input().split())))
lrc.sort()

inf = 10**15
dp = [inf]*(n+1)
dp[1] = 0

for l, r, c in lrc:
    for i in range(r, l, -1):
        if dp[i] > dp[l] + c:
            dp[i] = dp[l] + c
        else:
            break

ans = -1 if dp[n] == inf else dp[n]
print(ans)
