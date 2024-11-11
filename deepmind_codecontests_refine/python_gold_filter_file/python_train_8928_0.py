import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import deque
H, W, K = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
X = [1] * (W + 2)
for _ in range(H):
    X += [1] + [1 if a == "@" else 0 for a in input()] + [1]
X += [1] * (W + 2)
H, W = H+2, W+2
s, t = x1 * W + y1, x2 * W + y2

def BFS(i0=0):
    Q = deque([(i0, 3)])
    D = [-1] * (H * W)
    D[i0] = 0
    while Q:
        x, t = Q.popleft()
        if t & 1:
            for d in (1, -1):
                for y in range(x + d, x + d * K, d):
                    if X[y]: break
                    if 0 <= D[y] <= D[x]: break
                    D[y] = D[x] + 1
                    Q.append((y, 2))
                else:
                    y = x + d * K
                    if X[y] == 0:
                        if D[y] == -1:
                            D[y] = D[x] + 1
                            Q.append((y, 3))
        if t & 2:
            for d in (W, -W):
                for y in range(x + d, x + d * K, d):
                    if X[y]: break
                    if 0 <= D[y] <= D[x]: break
                    D[y] = D[x] + 1
                    Q.append((y, 1))
                else:
                    y = x + d * K
                    if X[y] == 0:
                        if D[y] == -1:
                            D[y] = D[x] + 1
                            Q.append((y, 3))
                        
    return D

print(BFS(s)[t])