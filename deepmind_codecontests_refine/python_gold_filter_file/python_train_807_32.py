import sys
# def input(): return sys.stdin.readline().rstrip()
# input = sys.stdin.readline
input = sys.stdin.buffer.readline

N = int(input())
A = sorted(zip(map(int, (input().split())) ,range(N)), reverse=True)

dp = [[0]*(N+1) for _ in range(N+1)]
ans = 0
for i in range(N):
    for j in range(i+1):
        dp[i+1][j]   = max(dp[i+1][j], dp[i][j] + A[i][0] * abs(A[i][1] - (N-1-(i-j))))
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + A[i][0] * abs(A[i][1] - j))

for i in range(N):
    ans = max(ans, dp[N][i])

print(ans)
