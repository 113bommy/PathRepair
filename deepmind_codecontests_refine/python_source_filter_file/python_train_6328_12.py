N = int(input())
dp = [[0]*10 for _ in range(10)]
for a in range(N):
    A = str(a)
    dp[int(A[0])][int(A[-1])] += 1
ans = 0
for i in range(1,10):
    for j in range(1,10):
        ans += dp[i][j]*dp[j][i]
print(ans)