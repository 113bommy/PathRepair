# import sys
# sys.setrecursionlimit(200000)

H, W = [int(_) for _ in input().split()]
S = [input() for _ in range(H)]

move = ((1, 0), (-1, 0), (0, 1), (0, -1))
visited = [[False] * W for _ in range(H)]
b, w = 0, 0

def dfs(i, j):
    global b, w

    visited[i][j] = True

    if S[i][j] == '#':
        b += 1
    else:
        w += 1

    for di, dj in move:
        ni, nj = i + di, j + dj
        if 0 <= ni < H and 0 <= nj < W:
            if S[i][j] != S[ni][nj] and not visited[ni][nj]:
                dfs(ni, nj)


result = 0
for i in range(H):
    for j in range(W):
        if visited[i][j]:
            continue
        b, w = 0, 0
        dfs(i, j)
        result += b * w
print(result)

