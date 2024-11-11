import sys, copy

n, m = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
for j in range(m - 2, 0, -1):
    for i in range(n - 2, 0, -1):
        if arr[i][j] == 0:
            if arr[i + 1][j] != 0 and arr[i][j + 1] != 0:
                arr[i][j] = min(arr[i + 1][j] - 1, arr[i][j + 1] - 1)
row = True
col = True
for i in range(n):
    for j in range(m - 1, 0, -1):
        if not arr[i][j]:
            row = False
        if arr[i][j] <= arr[i][j - 1]:
            row = False
for j in range(m):
    for i in range(n - 1, 0, -1):
        if not arr[i][j]:
            col = False
        if arr[i][j] <= arr[i - 1][j]:
            col = False
if not row or not col:
    print(-1)
else:
    ans = 0
    for i in range(n):
        for j in range(m):
            ans += arr[i][j]
    print(ans)
