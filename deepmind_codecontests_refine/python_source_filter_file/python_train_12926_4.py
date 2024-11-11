from sys import stdout, stdin

n, kk = map(int, stdin.readline().split())
s = stdin.readline().strip()
s += "$"
n = n+1

dp = [[0 for i in range(n)] for j in range(n)]
p = 10**12+5
for i in range(n):
    dp[i][0] = 1
for end in range(n):
    for length in range(1, n):
        seen = []
        ans = 0
        for k in range(end-1, -1, -1):
            if s[k] not in seen:
                seen.append(s[k])
                ans += dp[k][length-1]
                ans %= p
        dp[end][length] = ans

totals = [dp[n-1][length] for length in range(n)]
#print(totals)

ans = 0
idx = n-1
while idx >= 0 and kk > 0:
    ans += min(totals[idx], kk)*(n-1-idx)
    kk -= totals[idx]
    idx -= 1

if kk <= 0:
    stdout.write(str(ans) +"\n")
else:
    print(-1)

