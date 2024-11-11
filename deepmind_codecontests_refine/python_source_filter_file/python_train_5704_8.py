import sys

h, w = map(int, input().split())
s = [list(x.rstrip()) for x in sys.stdin.readlines()]
dp = [[1000]*w for _ in range(h)]
if s[0][0] == "#":
    dp[0][0] = 1
else:
    dp[0][0] = 0

for i in range(h):
    for j in range(w):
        for k in range(2):
            nx, ny = i + (k + 1)%2, j + k%2
            if nx >= w or ny >= h:
                continue
            else:
                add = 0
                if s[ny][nx] == "#" and s[j][i] == ".":
                    add = 1
                dp[ny][nx] = min(dp[ny][nx], dp[j][i] + add)
print(dp[h-1][w-1])