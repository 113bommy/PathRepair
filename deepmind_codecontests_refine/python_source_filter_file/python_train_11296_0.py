import sys
n, m, k = map(int, input().split())
a = [sys.stdin.readline().rstrip() for _ in range(n)]
dp = [[0]*m for _ in range(n)]

for i in range(1, n-1):
    for j in range(1, m-1):
        if dp[i][j] != 0 or a[i][j] == '*':
            continue

        stack = [(i, j)]
        dp[i][j] = -1
        pic = 0

        while stack:
            y, x = stack.pop()
            for ty, tx in ((y+1, x), (y-1, x), (y, x+1), (y, x-1)):
                if dp[ty][tx] != 0:
                    continue
                if a[ty][tx] == '*':
                    pic += 1
                else:
                    dp[ty][tx] = -1
                    stack.append((ty, tx))

        dp[i][j] = pic
        stack.append((i, j))
        while stack:
            y, x = stack.pop()
            for ty, tx in ((y+1, x), (y-1, x), (y, x+1), (y, -1)):
                if dp[ty][tx] != -1 or a[ty][tx] == '*':
                    continue
                dp[ty][tx] = pic
                stack.append((ty, tx))


ans = [0]*k
for i in range(k):
    x, y = map(int, sys.stdin.readline().split())
    ans[i] = dp[x-1][y-1]

print(*ans, sep='\n')
