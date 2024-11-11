from collections import deque
H, W = [int(i) for i in input().split()]
A = [list(input()) for _ in range(H)]

Q = deque()
for i in range(H):
    for j in range(W):
        if A[i][j] == "#":
            Q.append((i, j, 0))

ans = 0
while Q:
    i, j, dist = Q.popleft()
    ans = max(ans, dist)
    for di, dj in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        ni, nj = i + di, j + dj
        if 0 <= ni < H and 0 <= nj < W and A[ni][nj] == ".":
            A[ni][nj] = "#"
            Q.append((ni, nj, dist + 1))

print(ans)
