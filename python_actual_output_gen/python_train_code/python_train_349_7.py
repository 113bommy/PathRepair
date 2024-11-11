n, d = map(int, input().split())
mat = []
for i in range(n):
    m, s = map(int, input().split())
    mat.append([m, s])
mat.sort(key=lambda x: x[0])
dp = [0] * ( n + 1)
for i in range(1, n + 1):
    dp[i] = dp[i - 1] + mat[i - 1][1]
ans = mat[0][1]
i = 0
j = 0
while i < n and j < n:
    if mat[j][0] - mat[i][0] <= d:
        ans = max(ans, dp[j + 1] - dp[i])
        j += 1
    else:
        i += 1
print(ans)