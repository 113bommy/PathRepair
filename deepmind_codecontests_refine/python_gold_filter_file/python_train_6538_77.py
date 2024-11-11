import itertools
from collections import deque

H, W = [int(_) for _ in input().split()]
A = [list(input()) for _ in range(H)]
Q = deque([])
for i, j in itertools.product(range(H), range(W)):
    if A[i][j] == '#':
        Q += [[i, j, 0]]
while Q:
    i, j, d = Q.popleft()
    for ni, nj in [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]:
        if 0 <= ni < H and 0 <= nj < W and A[ni][nj] == '.':
            A[ni][nj] = '#'
            Q += [[ni, nj, d + 1]]
print(d)
