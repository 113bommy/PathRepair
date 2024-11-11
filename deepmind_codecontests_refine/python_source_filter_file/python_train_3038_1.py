
n = int(input())
ans = [[0] * n for i in range(n)]
for i in range(n):
    for j in range(n):
        ans[i][j] = (i % 4) * 4 + j % 4 + 16 * (i // 4) * n + 16 * (j // 4)
for i in range(n):
    print(*ans[i])