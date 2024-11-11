n, q = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(n-1)]
px = [list(map(int, input().split())) for _ in range(q)]
dp = [0] * n
ls = [[] for i in range(n)]
for i in ab:
    ls[i[0]-1].append(i[1]-1)
for i in px:
    dp[i[0]-1] += i[1]
for i in range(n):
    for j in ls[i]:
        dp[j] += dp[i]
print(dp)
