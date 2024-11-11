H, N = map(int, input().split())

magic = [list(map(int, input().split())) for _ in range(N)]

dp = [0 for _ in range(H+1)]

for i in range(H):
    dp[i] = min(dp[i-a]+b for a, b in magic)

print(dp[H-1])